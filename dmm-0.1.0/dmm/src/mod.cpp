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
 *	$Header: /cvsroot/doommod/dmm/src/mod.cpp,v 1.2 2005/10/25 19:29:56 paralizer Exp $
 *
 */
 
/**
 *	@file mod.cpp
 *	@brief	Handles all mod operations.
 */

#include <stdio.h>
#include <string.h>
#include "doom_sdk.h"
#include "pdb.h"
#include "utils.h"
#include "engine.h"
#include "dmm.h"
#include "mod.h"
#include "globals.h"
#include "definitions.h"

/*
 *	Compile time hook functions.
 */ 
SH_DECL_HOOK0_void(idGame, Shutdown, SH_NOATTRIB, 0);					/* idGame::Shutdown	*/
SH_DECL_HOOK1_void(idGame, ServerClientBegin, SH_NOATTRIB, 0, int);		/* idGame::ServerClientBegin	*/

static void mod_banner(int clientNum);

/**
 *	Attempt to load the module and execute the entry point.
 *
 *	It's important we return to the engine the same pointer
 *	the game gave us.  This is because the game does not
 *	allocate this structure on the stack, so it still has
 *	control over its contents after the entry point returns.
 *
 *	@return The loaded mod's interface structure.
 */
gameExport_t* load_mod() {
	/*
	 *	Get the mod file we're supposed to load.
	 */
	g_paths.mod_file = (char*)pdb_query(g_dbptr, "mod");
	if (!g_paths.mod_file) {
		CONSOLE_PRINTF(CINFO "Unable to find mod file; no entry in configuration file.\n");
		return 0;
	}
	
	/*
	 *	Attempt to load the mod.
	 */
	CONSOLE_PRINTF(CINFO "Attempting to load mod \"%s\" ...\n", g_paths.mod_file);
	void* mod = dlopen(g_paths.mod_file, RTLD_NOW);
	if (mod)
		CONSOLE_PRINTF(CINFO "Successfully loaded mod.\n");
	else {
		CONSOLE_PRINTF(CINFO "Failed to load mod.\n");
		return 0;
	}

	/*
	 *	Invoke the mod's entry point.
	 */
	pfnGetGameAPI mod_entry = (pfnGetGameAPI)dlsym(mod, "GetGameAPI");
	if (!mod_entry) {
		CONSOLE_PRINTF(CERROR "Mod does not have GetGameAPI() entry point; unable to load.\n");
		return 0;
	}

	CONSOLE_PRINTF(CINFO "Invoking mod entry point ...\n");
	gameExport_t* mod_export = mod_entry(&g_engine.engine);
	
	/*
	 *	It is doubtful DMM will actually need the game
	 *	interface, but we might as cache it while we have it.
	 */
	memcpy(&g_mod, mod_export, sizeof(gameExport_t));
	
	return mod_export;
}


/**
 *	Hook all the functions DMM needs from the mod.
 */
void mod_init_hooks() {
	#ifdef DMM_DETAIL
		CONSOLE_PRINTF(CINFO "Hooking game functions ...\n");
	#endif
	
	/* SH - idGame */
	SH_ADD_HOOK_STATICFUNC(idGame, Shutdown, g_mod.game, dmm_shutdown, 0);
	SH_ADD_HOOK_STATICFUNC(idGame, ServerClientBegin, g_mod.game, mod_banner, 1);
}


/**
 *	Unhook all game hooks made.
 */
void mod_free_hooks() {
	#ifdef DMM_DETAIL
		CONSOLE_PRINTF(CINFO "Unhooking game functions ...\n");
	#endif
	
	/* SH - idGame */
	SH_REMOVE_HOOK_STATICFUNC(idGame, Shutdown, g_mod.game, dmm_shutdown, 0);
	SH_REMOVE_HOOK_STATICFUNC(idGame, ServerClientBegin, g_mod.game, mod_banner, 1);
}


/*
 *	Gives potentially valuable server
 *	information to users.
 *	This also gives us credit so please
 *	don't remove it :)
 */
static void mod_banner(int clientNum) {
	char* banner[] = {
		"This server is running ^1Doom 3 Metamod^0 v" DMM_VERSION " (" DMM_BUILD ") [" OS_ID_STR "] by Para",
		"http://doommod.net " DMM_URL,
		NULL
	};
	int i = 0;
	
	while (banner[i]) {
		idBitMsg outMsg;
		byte msgBuf[MAX_GAME_MESSAGE_SIZE];

		outMsg.Init(msgBuf, sizeof(msgBuf));
		outMsg.BeginWriting();
		outMsg.WriteByte(GAME_RELIABLE_MESSAGE_CHAT);
		outMsg.WriteString("^1DMM^0");
		outMsg.WriteString(banner[i], -1, 0);
		SERVER_MSG(clientNum, outMsg);
		
		++i;
	}
}
