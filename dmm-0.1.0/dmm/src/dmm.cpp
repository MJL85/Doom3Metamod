/*
 *	DMM - Doom 3 MetaMod
 *
 *	Written By:
 *		Michael Laforest	< para >
 *		Email: < paralizer -AT- users -DOT- sourceforge -DOT- net >
 *
 *	Special thanks:
 *		Kevin Masterson		< CyberMind >
 *		David Anderson		< Bailopan >
 *		Pavol Marko			< PMOnoTo >
 *
 *	Copyright 2005
 *
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
 *	$Header: /cvsroot/doommod/dmm/src/dmm.cpp,v 1.2 2005/10/25 19:29:56 paralizer Exp $
 *
 */
 
/**
 *	@file dmm.cpp
 *	@brief	Entry point.
 */

#define __DMM__				/* this should only be declared in this file; its for global variable declartions */

#include <stdio.h>
#include <string.h>

#include "doom_sdk.h"
#include "pdb.h"
#include "mod.h"
#include "config.h"
#include "engine.h"
#include "console.h"
#include "plugins.h"
#include "utils.h"
#include "dmm.h"
#include "definitions.h"
#include "globals.h"

static void init_plugin_api();

/**
 *	The Doom3 module entry point.
 *
 *	@param import Engine API.
 *	@return Game API.
 */
C_DLLEXPORT gameExport_t* GetGameAPI(gameImport_t* import) {
	import->common->Printf(CINFO "DMM starting up ...\n");

	/* initialize Sourcehook required global */
	g_SHPtr = static_cast<SourceHook::ISourceHook*>(&g_SourceHook);
	
	/* Initialize engine */
	init_engine(import);
	
	/* Find path to this module */
	if (!determine_paths()) {
		/*
		 *	We really have no choice here, we cannot load the game
		 *	and return the interface to the engine since we do
		 *	not know where the game is located.
		 *	We have to return NULL, thereby segfaulting the engine.
		 *
		 *	We may have found something and allocated some memory,
		 *	so try to free all the paths (if needed) to avoid
		 *	any leaks.
		 */
		free_paths();		
		return NULL;
	}

	/* Load the DMM configuration file */
	if (!load_config())
		/* crash me again please (temp of course) */
		return NULL;

	/* Register DMM console commands */
	register_console_commands();

	/* Load the mod file */
	gameExport_t* mod_export = NULL;
	if (!(mod_export = load_mod()))
		return NULL;
	
	/* Make all required mod hooks */
	mod_init_hooks();
	
	/* Set the dmm_t plugin interface structure */
	init_plugin_api();
	
	/* Load plugins */
	load_plugins();

	CONSOLE_PRINTF(CINFO "Returning game interface to engine ...\n");
	
	return mod_export;
}


/**
 *	Cleanup any allocated data.
 */
void dmm_shutdown() {
	CONSOLE_PRINTF(CINFO "DMM shutting down ...\n");

	/* free various allocated strings */
	free_paths();

	/* Unload config file and pdb */
	unload_config();
	
	/* Unhook all game functions */
	mod_free_hooks();
	
	/* Unload plugins */
	free_plugins();
	
	/* Free engine stuff */
	free_engine();
}


/**
 *	Initialize the plugin API interface.
 */
static void init_plugin_api() {
	g_dmm_papi.engine = &(g_engine.engine);
	g_dmm_papi.mod = &g_mod;
	g_dmm_papi.sourcehook = g_SHPtr;

	g_dmm_papi.pause = plugin_api_pause;
	g_dmm_papi.unpause = plugin_api_unpause;
	g_dmm_papi.unload = plugin_api_unload;
	g_dmm_papi.register_command = plugin_api_registercommand;
}
