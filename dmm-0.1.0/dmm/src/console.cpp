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
 *	$Header: /cvsroot/doommod/dmm/src/console.cpp,v 1.2 2005/10/25 19:29:56 paralizer Exp $
 *
 */

/**
 *	@file console.cpp
 *	@brief	Registers and handles Doom 3 console commands.
 */

#include <stdio.h>
#include "doom_sdk.h"
#include "utils.h"
#include "str.h"
#include "engine.h"
#include "plugins.h"
#include "console.h"
#include "globals.h"
#include "definitions.h"


static void cmd_dmm_cmds(const idCmdArgs& args);
static void cmd_dmm_help(const idCmdArgs& args);
static void cmd_dmm_list(const idCmdArgs& args);
static void cmd_dmm_info(const idCmdArgs& args);
static void cmd_dmm_pause(const idCmdArgs& args);
static void cmd_dmm_unpause(const idCmdArgs& args);
static void cmd_dmm_load(const idCmdArgs& args);
static void cmd_dmm_unload(const idCmdArgs& args);


/**
 *	The commands DMM will attempt to register with
 *	the Doom console.
 */
static struct doom_console_cmd_t dmm_cmds[] = {
	{ "dmm",	cmd_dmm,	CMD_FL_SYSTEM,	"List information for DMM",		NULL	},
	{ NULL,		NULL,		0,				NULL,							NULL	}
};

/**
 *	Available subcommands for the "dmm" command.
 */
static struct dmm_subcommands_t dmm_scmds[] = {
	{
		"help",				0,				"",
		"Help subsystem",
		cmd_dmm_help
	},
	{
		"cmds",				0,				"",
		"List available DMM commands.",
		cmd_dmm_cmds
	},
	{
		"list",				0,				"[\"zombies\"]",
		"List current loaded plugins.",
		cmd_dmm_list
	},
	{
		"info",				1,				"<plugin unid>",
		"Display information about a loaded plugin.",
		cmd_dmm_info
	},
	{
		"pause",			1,				"<plugin unid> [\"force\"]",
		"Pause the specified plugin.",
		cmd_dmm_pause
	},
	{
		"unpause",			1,				"<plugin unid>",
		"Unpause the specified plugin.",
		cmd_dmm_unpause
	},
	{
		"load",				1,				"<file>",
		"Load a plugin.",
		cmd_dmm_load
	},
	{
		"unload",				1,				"<plugin unid> [\"force\"]",
		"Unload a plugin.",
		cmd_dmm_unload
	},
	
	{ NULL,					0,				NULL,	NULL,					NULL				}
};


/**
 *	Register DMM console commands with
 *	the Doom3 engine.
 */
void register_console_commands() {
	#ifdef DMM_DETAIL
		CONSOLE_PRINTF(CINFO "Registering console commands ...\n");
	#endif

	int i = 0;
	while (dmm_cmds[i].cmdName) {
		#ifdef DMM_DETAIL
			CONSOLE_PRINTF(CINFO "  Registering command: \"%s\"\n", dmm_cmds[i].cmdName);
		#endif
		
		REGISTER_COMMAND(dmm_cmds[i].cmdName, dmm_cmds[i].function, dmm_cmds[i].flags,
			dmm_cmds[i].description, dmm_cmds[i].argCompletion);
		
		++i;
	}

	#ifdef DMM_DETAIL
		CONSOLE_PRINTF(CINFO "Attempted to register %i command%s.\n", i, GRAMMAR_PLURAL(i));
	#endif
}


/**
 *	Console command handler:	dmm
 */
void cmd_dmm(const idCmdArgs& args) {
	int i = 0;
	
	if (args.argc < 2) {
		/*
		 *	Called with no parameters.
		 */
		CONSOLE_PRINTF(CINFO "Doom 3 Metamod (DMM) v" DMM_VERSION " (" DMM_BUILD ") [" OS_ID_STR "] by Para\n");
		CONSOLE_PRINTF(CINFO "Build: " __DATE__ " at " __TIME__ "\n");
		CONSOLE_PRINTF(CINFO "URL: http://doommod.net/ " DMM_URL "\n");
		CONSOLE_PRINTF(CINFO "For available commands, use: dmm cmds\n");
		return;
	}

	/*
	 *	Find the subcommand and execute the callback handler.
	 */
	while (dmm_scmds[i].cmd) {
		if (!strcmp(args.argv[1], dmm_scmds[i].cmd)) {
			if (dmm_scmds[i].cb) {
				if (args.argc >= (dmm_scmds[i].params + 2))
					(*dmm_scmds[i].cb)(args);
				else
					CONSOLE_PRINTF(CINFO "Command syntax: dmm %s %s\n", dmm_scmds[i].cmd, dmm_scmds[i].syntax);
			} else
				CONSOLE_PRINTF(CWARNING "Command: \"dmm %s\" has no callback function.\n", dmm_scmds[i].cmd);
			break;
		}
		++i;
	}
}


/**
 *	Console command handler:	dmm cmds
 */
static void cmd_dmm_cmds(const idCmdArgs& args) {
	int i = 0;
	
	CONSOLE_PRINTF(CINFO "Command syntax: dmm <command> [parameters]\n");
	CONSOLE_PRINTF(CINFO "The following subcommands are available:\n");
		
	while (dmm_scmds[i].cmd) {
		CONSOLE_PRINTF(CINFO "  %-10s - %s\n", dmm_scmds[i].cmd, dmm_scmds[i].desc);
		++i;
	}

	CONSOLE_PRINTF(CINFO "End command listing.\n");
}


/**
 *	Console command handler:	dmm help
 */
static void cmd_dmm_help(const idCmdArgs& args) {
	char* scmd = "help";
	int i = 0;
	
	if (args.argc > 2)
		scmd = args.argv[2];
	
	while (dmm_scmds[i].cmd) {
		if (!cstrcmp(scmd, dmm_scmds[i].cmd)) {
			CONSOLE_PRINTF(CINFO "Help: dmm %s\n", dmm_scmds[i].cmd);
			CONSOLE_PRINTF(CINFO "  Syntax: dmm %s %s\n", dmm_scmds[i].cmd, dmm_scmds[i].syntax);
			CONSOLE_PRINTF(CINFO "  Description: %s\n", dmm_scmds[i].desc);
			return;
		}
		++i;
	}
}


/**
 *	Console command handler:	dmm list
 */
static void cmd_dmm_list(const idCmdArgs& args) {
	int zombies = 0;
	
	if (args.argc > 2) {
		if (!cstrcmp(args.argv[2], "zombies")) {
			CONSOLE_PRINTF(CINFO INVALID_PARAMS("list"));
			return;
		} else
			zombies = 1;
	}
	
	plugin_list(zombies);
}


/**
 *	Console command handler:	dmm info
 */
static void cmd_dmm_info(const idCmdArgs& args) {
	int unid = 0;
	if (sscanf(args.argv[2], "%i", &unid) < 1) {
		/* invalid conversion - bad parameter */
		CONSOLE_PRINTF(CINFO INVALID_PARAMS("info"));
		return;
	}
	
	plugin_info(unid);
}


/**
 *	Console command handler:	dmm pause
 */
static void cmd_dmm_pause(const idCmdArgs& args) {
	int unid = 0;
	int force = 0;
	
	if (sscanf(args.argv[2], "%i", &unid) < 1) {
		/* invalid conversion - bad parameter */
		CONSOLE_PRINTF(CINFO INVALID_PARAMS("pause"));
		return;
	}
	
	if (args.argc >= 4)
		/* force specified? */
		if (!cstrcmp(args.argv[3], "force"))
			force = 1;
	
	int op = pause_plugin_by_unid(unid, force);

	if (op == 0)
		CONSOLE_PRINTF(CINFO "Invalid plugin unid %i.\n", unid);
	else if (op == 1)
		CONSOLE_PRINTF(CINFO "Successfully paused plugin unid %i.\n", unid);
	else if (op == 2)
		CONSOLE_PRINTF(CINFO "Plugin unid %i already paused.\n", unid);
	else if (op == -1)
		CONSOLE_PRINTF(CINFO "Pausing a zombie plugin is not permitted.\n", unid);
	else
		CONSOLE_PRINTF(CINFO "Plugin unid %i can not be paused.\n", unid);
}


/**
 *	Console command handler:	dmm unpause
 */
static void cmd_dmm_unpause(const idCmdArgs& args) {
	int unid = 0;
	if (sscanf(args.argv[2], "%i", &unid) < 1) {
		/* invalid conversion - bad parameter */
		CONSOLE_PRINTF(CINFO INVALID_PARAMS("unpause"));
		return;
	}
	
	int op = unpause_plugin_by_unid(unid);

	if (op == 0)
		CONSOLE_PRINTF(CINFO "Invalid plugin unid %i.\n", unid);
	else if (op == 1)
		CONSOLE_PRINTF(CINFO "Successfully unpaused plugin unid %i.\n", unid);
	else if (op == -1)
		CONSOLE_PRINTF(CINFO "Unpausing a zombie plugin is not permitted.\n", unid);
	else
		CONSOLE_PRINTF(CINFO "Plugin unid %i already paused.\n", unid);
}


/**
 *	Console command handler:	dmm load
 */
static void cmd_dmm_load(const idCmdArgs& args) {
	load_plugin(args.argv[2]);
}


/**
 *	Console command handler:	dmm unload
 */
static void cmd_dmm_unload(const idCmdArgs& args) {
	int unid = 0;
	int force = 0;

	if (sscanf(args.argv[2], "%i", &unid) < 1) {
		/* invalid conversion - bad parameter */
		CONSOLE_PRINTF(CINFO INVALID_PARAMS("unload"));
		return;
	}
	
	if (args.argc >= 4)
		/* force specified? */
		if (!cstrcmp(args.argv[3], "force"))
			force = 1;

	int op = unload_plugin_by_unid(unid, force);
		
	if (op == 0)
		CONSOLE_PRINTF(CINFO "Invalid plugin unid %i.\n", unid);
	else if ((op == 1) || (op == 2))
		CONSOLE_PRINTF(CINFO "Successfully unloaded plugin unid %i (%scleanly).\n", unid, (op == 1 ? "" : "not "));
	else 
		CONSOLE_PRINTF(CINFO "Plugin unid %i can not be unloaded.\n", unid);
}
