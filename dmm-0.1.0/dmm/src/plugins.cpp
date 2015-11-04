/*
 *	This file is part of DMM.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 *	$Header: /cvsroot/doommod/dmm/src/plugins.cpp,v 1.2 2005/10/25 19:29:56 paralizer Exp $
 *
 */

/**
 *	@file plugins.cpp
 *	@brief	Handles all plugin interaction.
 */

/**
 *	Functions in the form:		plugin_api_*()
 *	Are called by the plugins themselves.
 *
 *	These functions always have a pointer to the
 *	plugin's plugin_info_t structure, so that DMM
 *	can validate that it is the correct plugin
 *	working on itself.
 *	Of course this could be hacked, but generally
 *	you won't have a mod doing that kind of work
 *	without you knowing. 
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "doom_sdk.h"
#include "str.h"
#include "pdb.h"
#include "utils.h"
#include "engine.h"
#include "plugins.h"
#include "globals.h"
#include "definitions.h"

static int last_unid = 1;		/* next available plugin unid 			*/

static inline int plugin_generate_unid();
static void plugin_free_cmds(struct plugin_t* plugin, int free_list);
static void plugin_reregister_cmds(struct plugin_t* plugin);
	
/**
 *	Load initial plugins.
 */
void load_plugins() {
	CONSOLE_PRINTF(CINFO "Loading plugins ...\n");
	g_loaded_plugins = 0;
	g_plugins = NULL;
	
	struct pdb_linkList* lptr = (struct pdb_linkList*)pdb_query(g_dbptr, "plugins");
	if (!lptr) {
		/* no plugins defined */
		CONSOLE_PRINTF(CWARNING "No plugin list defined in configuration file (\"plugins\").\n");
		return;
	}
	
	int attempted = 0;
	
	struct pdb_linkNode* lnptr = lptr->root;
	struct pdb_node_t* nptr = NULL;
	int load = 0;
	while (lnptr) {
		nptr = (struct pdb_node_t*)lnptr->data;
		++attempted;

		load = load_plugin(nptr->id);
		if (load == 0)
			/* failed to load - stop */
			break;
		
		lnptr = lnptr->next;
	}

	
	CONSOLE_PRINTF(CINFO "Attempted to load %i plugin%s.\n", attempted, GRAMMAR_PLURAL(attempted));
	CONSOLE_PRINTF(CINFO "Successfully loaded %i plugin%s.\n", g_loaded_plugins, GRAMMAR_PLURAL(g_loaded_plugins));
}


/**
 *	Load a plugin.
 *
 *	@param file The plugin file to load.  The path should be relative to dmm.
 *
 *	@return
 *		0 - failed, too many loaded plugins
 *		1 - success
 *		2 - failed, could not link
 *		3 - failed, no entry point
 */
int load_plugin(char* file) {
	char plugin_path[BUFSIZE];
	int unid;
	
	/*
	 *	Make sure we can load another plugin
	 *	by generating a UNID for it.
	 */
	unid = plugin_generate_unid();
	if (unid == -1) {
		CONSOLE_PRINTF(CERROR "Unable to load additional plugins; maximum of %i has been reached\n", INT_MAX);
		return 0;
	}
		
	/*
	 *	Generate the plugin path.
	 */
	ABSOLUTE_DMM_PATH(plugin_path, file);
		
	/*
	 *	Attempt to load the plugin.
	 */
	CONSOLE_PRINTF(CINFO "  Attempting to load plugin \"%s\" ...\n", plugin_path);
	void* plugin = dlopen(plugin_path, RTLD_NOW);
	if (plugin) {
		CONSOLE_PRINTF(CINFO "  Successfully linked plugin.\n");
	} else {
		CONSOLE_PRINTF(CINFO "  Failed to load plugin (%s); %s\n", plugin_path, dlerror());
		return 2;
	}
	
	/*
	 *	Invoke the plugin's entry point.
	 */
	pfn_pluginentry plugin_entry = (pfn_pluginentry)dlsym(plugin, "dmm_main");
	if (!plugin_entry) {
		CONSOLE_PRINTF(CERROR "  Plugin does not have dmm_main() entry point; unable to load.\n");
		return 3;
	}
	
	/*
	 *	Create the plugin structure and link with global plugin list.
	 */
	struct plugin_t* plugin_node = (struct plugin_t*)malloc(sizeof(struct plugin_t));
	plugin_node->lptr = NULL;
	plugin_node->rptr = NULL;
	plugin_node->info = NULL;
	plugin_node->cmds = NULL;
	plugin_node->so = plugin;
	plugin_node->unid = unid;
	plugin_node->flags = F_PLUGIN_INIT;
	plugin_node->file = strdup(plugin_path);

	if (!g_plugins) {
		/* first plugin */
		g_plugins = plugin_node;
	} else {
		struct plugin_t* nptr = g_plugins;
		while (nptr->rptr)
			nptr = nptr->rptr;

		/* link plugin node after this node */
		nptr->rptr = plugin_node;
	}
		
	/*
	 *	Duplicate the dmm_t structure so that
	 *	plugin's can't change some pointers
	 *	and mess stuff up for other plugins.
	 */
	struct dmm_t papi;
	memcpy(&papi, &g_dmm_papi, sizeof(struct dmm_t));
				
	/*
	 *	Invoke the plugin's entry point.
	 */
	plugin_entry(&(plugin_node->info), &papi, plugin_node->unid);
	++g_loaded_plugins;
		
	CONSOLE_PRINTF(CINFO "  Successfully loaded plugin.\n");
	return 1;
}


/**
 *	Unload and free all loaded plugins.
 */
void free_plugins() {
	struct plugin_t* nptr = g_plugins;

	CONSOLE_PRINTF(CINFO "Shutting down plugins ...\n");
	int attempted = 0;
	int cleanly = 0;

	while (g_plugins) {
		/*
		 *	unload_plugin() may change
		 *	the g_plugins pointer, so
		 *	cache the next plugin pointer.
		 */
		nptr = g_plugins->rptr;
		if (unload_plugin(g_plugins))
			++cleanly;
		++attempted;
		g_plugins = nptr;
	}

	CONSOLE_PRINTF(CINFO "Attempted to shut down %i plugin%s.\n", attempted, GRAMMAR_PLURAL(attempted));
	CONSOLE_PRINTF(CINFO "Cleanly shut down %i plugin%s.\n", cleanly, GRAMMAR_PLURAL(cleanly));
}


/**
 *	Unload a plugin.
 *
 *	@param plugin The plugin structure.
 *	@return
 *		1 if the plugin cleanly shutdown (ie, invoked dmm_shutdown()),
 *		0 if not.
 */
int unload_plugin(struct plugin_t* plugin) {
	if (!plugin)
		return 0;

	int clean = 0;

	pfn_pluginexit plugin_exit = (pfn_pluginexit)dlsym(plugin->so, "dmm_shutdown");
	if (!plugin_exit) {
		CONSOLE_PRINTF(CINFO "  - Plugin does not have dmm_shutdown() exit point (%s).\n", plugin->file);
	} else {
		CONSOLE_PRINTF(CINFO "  + Invoking dmm_shutdown() exit point (%s).\n", plugin->file);
		if (plugin_exit() == DMM_SHUTDOWN_CLEANLY)
			clean = 1;
	}
	
	/*
	 *	Unregister all hooked functions.
	 *	If this is not done, and the plugin didn't
	 *	do it in the shutdown function, Doom will
	 *	segfault by sourcehook calling an invalid
	 *	function pointer.
	 */
	CONSOLE_PRINTF(CINFO "  + Cleaning up any left over function hooks ...\n");
	delete_plugin_hooks(plugin->unid);
	
	/*
	 *	Free registered commands for this plugin.
	 */
	plugin_free_cmds(plugin, 1);
	
	free(plugin->file);
	dlclose(plugin->so);

	/*
	 *	Delink this plugin node.
	 */
	if (plugin->lptr)
		plugin->lptr->rptr = plugin->rptr;
	if (plugin->rptr)
		plugin->rptr->lptr = plugin->lptr;

	/*
	 *	If this node was the root,
	 *	make the next node the root.
	 */
	if (g_plugins == plugin)
		g_plugins = plugin->rptr;

	free(plugin);

	--g_loaded_plugins;
	
	return clean;
}


/**
 *	Return the next unique identification number for a plugin.
 *
 *	Unid 0 is reserved for DMM.
 *
 *	No more than INT_MAX plugins can be loaded at once.
 *	Return -1 if there are too many loaded, indicating an error.
 */
static inline int plugin_generate_unid() {
	if (last_unid < INT_MAX) {
		++last_unid;
		return (last_unid - 1);
	}
	return -1;
}

	
/**
 *	Free commands for this plugin.
 *	Unregister them if needed.
 *
 *	If free_list is 1, delete the list off
 *	commands.  Otherwise just flag them
 *	as not being registered.  This is useful
 *	for plugin pausing.
 *
 *	@param plugin The plugin structure.
 *	@param free_list See above.
 */
static void plugin_free_cmds(struct plugin_t* plugin, int free_list) {
	struct plugin_concommand_t* first = plugin->cmds;
	while (plugin->cmds) {
		if (plugin->cmds->regged) {
			#ifdef DMM_DETAIL
				CONSOLE_PRINTF(CINFO "  + Unregistering plugin unid %i command: \"%s\".\n",
					plugin->unid, plugin->cmds->cmd);
			#endif
			UNREG_COMMAND(plugin->cmds->cmd);
		}
		
		if (free_list) {
			free(plugin->cmds->cmd);
			free(plugin->cmds->description);
		} else
			plugin->cmds->regged = 0;

		plugin->cmds = plugin->cmds->rptr;
	}
	if (free_list)
		plugin->cmds = NULL;
	else
		plugin->cmds = first;
}


/**
 *	Reregister all commands this plugin
 *	requested be registered.
 *
 *	@param plugin The plugin structure.
 */
static void plugin_reregister_cmds(struct plugin_t* plugin) {
	struct plugin_concommand_t* first = plugin->cmds;
	while (plugin->cmds) {
		if (!plugin->cmds->regged) {
			#ifdef DMM_DETAIL
				CONSOLE_PRINTF(CINFO "  + Reregistering plugin unid %i command: \"%s\".\n",
					plugin->unid, plugin->cmds->cmd);
			#endif
			REGISTER_COMMAND(plugin->cmds->cmd,
				plugin->cmds->function,
				plugin->cmds->flags,
				plugin->cmds->description,
				plugin->cmds->argCompletion);
		}
		plugin->cmds = plugin->cmds->rptr;
	}
	plugin->cmds = first;
}


/**
 *	This is only called from console.cpp.
 *	Display a list of loaded plugins to the console.
 *
 *	@param show_zombies If 1, include zombies in the list.
 */
void plugin_list(int show_zombies) {
	struct plugin_t* n = g_plugins;
	
	CONSOLE_PRINTF(CINFO "Plugins:  (%i loaded plugin%s)\n", g_loaded_plugins, GRAMMAR_PLURAL(g_loaded_plugins));
	CONSOLE_PRINTF(CINFO "  unid          Name                      Version      Paused\n");
	CONSOLE_PRINTF(CINFO "  ----          ----                      -------      ------\n");

	char buf_name[26];
	char buf_ver[13];
	int zombies = 0;	
	
	while (n) {
		/*
		 *	Skip this plugin if it's a zombie.
		 */
		if (!show_zombies && PLUGIN_ZOMBIE(n)) {
			++zombies;
			n = n->rptr;
			continue;
		}
		
		/*
		 *	Truncate plugin name to 25 characters.
		 *	Truncate plugin version to 12 character (sufficient for rev.maj.min[a/b] version notation).
		 */
		strncpy(buf_name, (n->info ? n->info->name : "Unnamed plugin"), 25);
		*(buf_name + 25) = 0;
		strncpy(buf_ver, (n->info ? n->info->version : "n/a"), 12);
		*(buf_ver + 12) = 0;
		
		CONSOLE_PRINTF(CINFO "  %4i          %-25s %-12s %*s%s\n",
			n->unid,
			buf_name,
			buf_ver,
			(6 - PLUGIN_FPAUSED(n)),
			(PLUGIN_ZOMBIE(n) ? "zombie" : (PLUGIN_PAUSED(n) ? "1" : "0")),
			(PLUGIN_FPAUSED(n) ? "f" : (PLUGIN_SPAUSED(n) ? "s" : ""))
		);

		n = n->rptr;
	}

	if (!show_zombies && zombies)
		CONSOLE_PRINTF(CINFO "( %i zombie plugin%s not displayed )\n", zombies, GRAMMAR_PLURAL(zombies));
		
	CONSOLE_PRINTF(CINFO "End plugin list.\n");
}


/**
 *	This is only called from console.cpp.
 *	Display plugin info to the console.
 *
 *	@param unid The plugin unique identification number.
 */
void plugin_info(int unid) {
	struct plugin_t* n = get_plugin_by_unid(unid);
	if (!n) {
		CONSOLE_PRINTF(CINFO "No such plugin with unid %i.\n", unid);
		return;
	}
	
	CONSOLE_PRINTF(CINFO "Plugin information for unid %i:\n", unid);
	CONSOLE_PRINTF(CINFO "  Name: %s\n", (n->info ? n->info->name : "Unnamed plugin"));
	CONSOLE_PRINTF(CINFO "  Version: %s\n", (n->info ? n->info->version : "(unknown version)"));
	CONSOLE_PRINTF(CINFO "  Author: %s\n", (n->info ? n->info->author : "n/a"));
	CONSOLE_PRINTF(CINFO "  URL: %s\n", (n->info ? n->info->url : "n/a"));
	CONSOLE_PRINTF(CINFO "  File: %s\n", n->file);
	CONSOLE_PRINTF(CINFO "  Pausable: %s\n", (n->info ? (n->info->can_pause ? "yes" : "no") : "yes by default"));
	CONSOLE_PRINTF(CINFO "  Unloadable: %s\n", (n->info ? (n->info->can_unload ? "yes" : "no") : "yes by default"));
	
	if (PLUGIN_ZOMBIE(n))
		CONSOLE_PRINTF(CINFO "  This plugin is currently in \"zombie\" mode.\n");	
}


/**
 *	Tell sourcehook to remove all funtion hooks
 *	the given plugin id made.
 *
 *	@param unid The plugin unique identification number.
 */
void delete_plugin_hooks(int unid) {
	struct plugin_t* p = get_plugin_by_unid(unid);
	if (!p) {
		CONSOLE_PRINTF(CINFO "Invalid plugin unid %i.\n", unid);
		return;
	}

	g_SourceHook.UnloadPlugin(unid);
}


/**
 *	Return a plugin_t assoicated with the given
 *	plugin unique identification number.
 *
 *	@param unid The plugin unique identification number.
 *	@return The assoicated plugin structure.
 */
struct plugin_t* get_plugin_by_unid(int unid) {
	struct plugin_t* n = g_plugins;
	while (n) {
		if (n->unid == unid)
			return n;
		n = n->rptr;
	}
	return NULL;
}


/**
 *	Return a plugin_t assoicated with the given
 *	plugin_info_t structure pointer.
 *
 *	@param unid The plugin information structure.
 *	@return The assoicated plugin structure.
 */
struct plugin_t* get_plugin_by_info(struct plugin_info_t* pi) {
	struct plugin_t* n = g_plugins;
	while (n) {
		if (n->info == pi)
			return n;
		n = n->rptr;
	}
	return NULL;
}


/**
 *	Pause a plugin by its unid.
 *
 *	If force is set to 1, the plugin will
 *	be paused whether the plugin says it's
 *	allowed to or not.
 *
 *	@param unid The plugin information structure.
 *	@param force Force a pause?
 *	@return
 *		-1 - plugin is a zombie
 *		 0 - plugin not found
 *		 1 - successful
 *		 2 - already paused
 *		 3 - plugin cannot be paused
 */
int pause_plugin_by_unid(int unid, int force) {
	struct plugin_t* p = get_plugin_by_unid(unid);
	if (!p)
		return 0;
	
	if (PLUGIN_PAUSED(p))
		return 2;
	
	if (!force && (p->info ? !(p->info->can_pause) : 0))
		/* if not a force and plugin cant pause, stop */
		return 3;
	if (PLUGIN_ZOMBIE(p))
		/* cannot pause a zombie */
		return -1;

	g_SourceHook.PausePlugin(unid);

	/*
	 *	Unregister commands for this plugin.
	 */
	plugin_free_cmds(p, 0);

	p->flags |= F_PLUGIN_PAUSED;
	
	if (force && (p->info ? !(p->info->can_pause) : 0))
		/* if force was used and the plugin can not be paused, flag it */
		p->flags |= F_PLUGIN_FORCED_PAUSED;
		
	return 1;
}


/**
 *	Unpause a plugin by its unid.
 *
 *	@param unid The plugin information structure.
 *	@return
 *		-1 - cannot unpause a zombie
 *		 0 - plugin not found
 *		 1 - successful
 *		 2 - already unpaused
 */
int unpause_plugin_by_unid(int unid) {
	struct plugin_t* p = get_plugin_by_unid(unid);
	if (!p)
		return 0;
	
	if (!(PLUGIN_PAUSED(p)))
		return 2;
	if (PLUGIN_ZOMBIE(p))
		/* cannot unpause a zombie */
		return -1;

	g_SourceHook.UnpausePlugin(unid);

	/*
	 *	Reregister commands for this plugin.
	 */
	plugin_reregister_cmds(p);

	p->flags &= ~F_PLUGIN_PAUSED;
	p->flags &= ~F_PLUGIN_FORCED_PAUSED;
	p->flags &= ~F_PLUGIN_SELF_PAUSED;
	
	return 1;
}


/**
 *	Unload a plugin by unid.
 *
 *	If force is set to 1, the plugin will
 *	be paused whether the plugin says it's
 *	allowed to or not.
 *
 *	@param unid The plugin information structure.
 *	@param force Force an unload?
 *	@return
 *		0 - plugin not found
 *		1 - successful (cleanly)
 *		2 - successful (not clean)
 *		3 - plugin cannot be unloaded
 */
int unload_plugin_by_unid(int unid, int force) {
	struct plugin_t* p = get_plugin_by_unid(unid);
	if (!p)
		return 0;
	
	if (!force && (p->info ? !(p->info->can_unload) : 0))
		/* if not a force and plugin cant unload, stop */
		return 3;

	return ((unload_plugin(p) == 1) ? 1 : 2);
}


/**
 *	PLUGIN API FUNCTION
 *
 *	Pause the calling plugin.
 *
 *	@param pi Plugin information structure.
 *	@return A DMM_API_RET
 */
int plugin_api_pause(struct plugin_info_t* pi) {
	struct plugin_t* p = get_plugin_by_info(pi);
	if (!p)
		return DMM_FAIL;
	
	if (p->flags & F_PLUGIN_PAUSED)
		/* failed - already paused (this shouldn't be possible) */
		return (DMM_FAIL | DMM_OP_ALREADY);
	if (PLUGIN_ZOMBIE(p))
		/* cannot pause a zombie */
		return DMM_FAIL;

	/* flag this plugin as having been self paused */
	p->flags |= F_PLUGIN_PAUSED;
	p->flags |= F_PLUGIN_SELF_PAUSED;

	g_SourceHook.PausePlugin(p->unid);
	
	/*
	 *	Unregister commands for this plugin.
	 */
	plugin_free_cmds(p, 0);

	CONSOLE_PRINTF(CINFO "Plugin unid %i paused itself.\n", p->unid);
	
	return DMM_SUCCESS;
}


/**
 *	PLUGIN API FUNCTION
 *
 *	Unpause the calling plugin.
 *	This shouldn't be possible, but if someone works out
 *	some cool hack to get other plugin structures, they
 *	might as well get a function to use with it.
 *
 *	@param pi Plugin information structure.
 *	@return A DMM_API_RET
 */
int plugin_api_unpause(struct plugin_info_t* pi) {
	struct plugin_t* p = get_plugin_by_info(pi);
	if (!p)
		return DMM_FAIL;
	
	if (!(p->flags & F_PLUGIN_PAUSED))
		/* failed - plugin not paused */
		return DMM_OP_ALREADY;
	if (PLUGIN_ZOMBIE(p))
		/* cannot unpause a zombie */
		return DMM_FAIL;
	
	/* remove plugin paused flags */
	p->flags &= ~F_PLUGIN_PAUSED;
	p->flags &= ~F_PLUGIN_FORCED_PAUSED;
	p->flags &= ~F_PLUGIN_SELF_PAUSED;

	g_SourceHook.UnpausePlugin(p->unid);

	/*
	 *	Reregister commands for this plugin.
	 */
	plugin_reregister_cmds(p);

	CONSOLE_PRINTF(CWARNING "Plugin unid %i unpaused itself; **POSSIBLE HACK BY ANOTHER PLUGIN**\n", p->unid);

	return DMM_SUCCESS;
}


/**
 *	PLUGIN API FUNCTION
 *
 *	Unload the calling plugin.
 *
 *	@param pi Plugin information structure.
 *	@return A DMM_API_RET
 */
int plugin_api_unload(struct plugin_info_t* pi) {
	struct plugin_t* p = get_plugin_by_info(pi);
	int unid = 0;
	if (!p)
		return DMM_FAIL;
	
	unid = p->unid;
	
	g_SourceHook.PausePlugin(p->unid);
	
	CONSOLE_PRINTF(CINFO "Plugin unid %i flagged itself as unloaded (now a zombie).\n", unid);
	
	/*
	 *	Flag this plugin as a zombie for now.
	 *	Later we will do a real unload.
	 */
	p->flags |= F_PLUGIN_ZOMBIE;

	/*
	 *	Free registered commands for this plugin.
	 */
	plugin_free_cmds(p, 1);

	return DMM_SUCCESS;
}


/**
 *	PLUGIN API FUNCTION
 *
 *	Register a console command with the Doom 3 engine.
 *	This keeps track of what commands a plugin registered
 *	so that they can be unregistered when the plugin
 *	is no longer active.
 *
 *	@param pi				Plugin information structure.
 *	@param cmdName			The console command name.
 *	@param cmdFunction_t	Callback function when the command is executed.
 *	@param flags			Flags assoicated with this command.
 *	@param description		The console command description.
 *	@param argCompletion_t	Console auto-completion type.
 *	@return A DMM_API_RET
 */
int plugin_api_registercommand(struct plugin_info_t* pi, const char* cmdName, cmdFunction_t function, int flags,
	const char* description, argCompletion_t argCompletion)
{
	struct plugin_t* p = get_plugin_by_info(pi);
	if (!p)
		return DMM_FAIL;
	
	/*
	 *	Create the cmd information node.
	 */
	struct plugin_concommand_t* cn = (struct plugin_concommand_t*)malloc(sizeof(struct plugin_concommand_t));
	cn->rptr = NULL;
	cn->cmd = strdup(cmdName);
	cn->regged = 1;
	cn->function = function;
	cn->flags = flags;
	cn->description = strdup(description);
	cn->argCompletion = argCompletion;

	/*
	 *	Link this command into the list
	 *	for this plugin.
	 */
	struct plugin_concommand_t* root = p->cmds;
	p->cmds = cn;
	cn->rptr = root;
		
	/*
	 *	Register the command with the Doom 3 engine.
	 */
	REGISTER_COMMAND(cmdName, function, flags, description, argCompletion);
	
	#ifdef DMM_DETAIL
		CONSOLE_PRINTF(CINFO "Plugin unid %i registered command: \"%s\".\n", p->unid, cmdName);
	#endif
	
	return DMM_SUCCESS;
}
