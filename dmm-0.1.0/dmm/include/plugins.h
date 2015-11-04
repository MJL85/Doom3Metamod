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
 *	$Header: /cvsroot/doommod/dmm/include/plugins.h,v 1.1.1.1 2005/10/20 21:36:10 paralizer Exp $
 *
 */
 
#ifndef _PLUGINS_H
#define _PLUGINS_H

#include "doom_sdk.h"
#include "definitions.h"

/**
 *	dmm_shutdown() returns.
 */
enum {
	DMM_SHUTDOWN_ERROR = 0,
	DMM_SHUTDOWN_CLEANLY
};

/**
 *	Useful macros for operating on plugin_t structures.
 */
#define PLUGIN_PAUSED(plugin)		((plugin->flags & F_PLUGIN_PAUSED) == F_PLUGIN_PAUSED)
#define PLUGIN_FPAUSED(plugin)		((plugin->flags & F_PLUGIN_FORCED_PAUSED) == F_PLUGIN_FORCED_PAUSED)
#define PLUGIN_SPAUSED(plugin)		((plugin->flags & F_PLUGIN_SELF_PAUSED) == F_PLUGIN_SELF_PAUSED)
#define PLUGIN_ZOMBIE(plugin)		((plugin->flags & F_PLUGIN_ZOMBIE) == F_PLUGIN_ZOMBIE)


/**
 *	Valid plugin flags.
 */
#define F_PLUGIN_INIT			0x00		/*!< initial flags							*/
#define F_PLUGIN_ZOMBIE			0x01		/*!< plugin is "unloaded" but still linked	*/
#define F_PLUGIN_PAUSED			0x02		/*!< is plugin paused?						*/
#define F_PLUGIN_FORCED_PAUSED	0x04		/*!< was plugin forcefully paused?			*/
#define F_PLUGIN_SELF_PAUSED	0x08		/*!< did plugin pause itself?					*/


/**
 *	The structure a plugin gets
 *	through the entry point.
 *	It stores all information
 *	about a given plugin.
 */
struct plugin_info_t {
	char* name;						/*!< plugin name					*/
	char* author;					/*!< plugin author					*/
	char* url;						/*!< plugin URL						*/
	char* version;					/*!< plugin version					*/
	int can_pause;					/*!< can this plugin be paused?		*/
	int can_unload;					/*!< can this plugin be unloaded?	*/
};


/**
 *	A list of console commands
 *	a plugin has registered
 *	with the Doom 3 engine.
 */
struct plugin_concommand_t {
	struct plugin_concommand_t* rptr;
	char* cmd;							/*!< registered command			*/
	int regged;							/*!< currently registered?		*/

	/*! for reregistration */
	cmdFunction_t function;
	int flags;
	char* description;
	argCompletion_t argCompletion;
};


/**
 *	The structure DMM holds
 *	for plugins.  Plugins do
 *	not get this structure.
 */
struct plugin_t {
	struct plugin_t* rptr;				/*!< next plugin					*/
	struct plugin_t* lptr;				/*!< previous plugin				*/
	char* file;							/*!< absolte file path to plugin	*/
	void* so;							/*!< return from dlopen()			*/
	int unid;							/*!< unique plugin id				*/
	int flags;							/*!< flags, see above				*/
	struct plugin_concommand_t* cmds;	/*!< registered console commands	*/
	struct plugin_info_t* info;			/*!< plugin information			*/
};


/**
 *	This structure is passed to all
 *	plugins when they are loaded.
 */
struct dmm_t {
	gameImport_t* engine;
	gameExport_t* mod;
	SourceHook::ISourceHook* sourcehook;
	int (*pause)(struct plugin_info_t* pi);
	int (*unpause)(struct plugin_info_t* pi);
	int (*unload)(struct plugin_info_t* pi);
	int (*register_command)(struct plugin_info_t* pi, const char* cmdName, cmdFunction_t function,
		int flags, const char* description, argCompletion_t argCompletion);
};


/**
 *	Plugin API returns.
 */
typedef enum {
	DMM_FAIL = 0,		/*!< API call failed							*/
	DMM_SUCCESS,		/*!< API call succeeded							*/
	DMM_OP_ALREADY		/*!< the requested operation was already set	*/
} DMM_API_RET;


typedef void (*pfn_pluginentry)(struct plugin_info_t**, struct dmm_t*, int);
typedef int (*pfn_pluginexit)();

#ifdef __cplusplus
extern "C"
{
#endif

void load_plugins();
int load_plugin(char* file);
void free_plugins();
int unload_plugin(struct plugin_t* plugin);

void plugin_list(int show_zombies);
void plugin_info(int unid);

void delete_plugin_hooks(int unid);
struct plugin_t* get_plugin_by_unid(int unid);
struct plugin_t* get_plugin_by_info(struct plugin_info_t* pi);

int pause_plugin_by_unid(int unid, int force);
int unpause_plugin_by_unid(int unid);
int unload_plugin_by_unid(int unid, int force);

int plugin_api_pause(struct plugin_info_t* pi);
int plugin_api_unpause(struct plugin_info_t* pi);
int plugin_api_unload(struct plugin_info_t* pi);
int plugin_api_registercommand(struct plugin_info_t* pi, const char* cmdName, cmdFunction_t function, int flags,
	const char* description, argCompletion_t argCompletion);

#ifdef __cplusplus
}
#endif

#endif /* _PLUGINS_H */
