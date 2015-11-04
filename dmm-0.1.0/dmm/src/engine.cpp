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
 *	$Header: /cvsroot/doommod/dmm/src/engine.cpp,v 1.2 2005/10/25 19:29:56 paralizer Exp $
 *
 */

/**
 *	@file engine.cpp
 *	@brief	Stores and keeps track of engine interface(s).
 */

#include <stdio.h>
#include "doom_sdk.h"
#include "utils.h"
#include "engine.h"
#include "globals.h"
#include "definitions.h"


/**
 *	Initialize the engine interface.
 *
 *	Initialize sourcehook classes used for invoking
 *	engine functions which do not have the ability
 *	to be hooked by plugins.
 *
 *	@param import The engine API.
 */
void init_engine(gameImport_t* import) {
	/* copy the engine interface structure */
	memcpy(&g_engine, import, sizeof(gameImport_t));
	
	/* SH - call classes */
	g_engine.common = SH_GET_CALLCLASS(import->common);
	g_engine.cmdSystem = SH_GET_CALLCLASS(import->cmdSystem);
	g_engine.networkSystem = SH_GET_CALLCLASS(import->networkSystem);
}


/**
 *	Deallocate any memory used for the engine API.
 */
void free_engine() {
	/* SH - idCommon */
	SH_RELEASE_CALLCLASS(g_engine.common);
	g_engine.engine.common = NULL;

	/* SH - idCmdSystem */
	SH_RELEASE_CALLCLASS(g_engine.cmdSystem);
	g_engine.engine.cmdSystem = NULL;

	/* SH - idNetworkSystem */
	SH_RELEASE_CALLCLASS(g_engine.networkSystem);
	g_engine.engine.networkSystem = NULL;
}
