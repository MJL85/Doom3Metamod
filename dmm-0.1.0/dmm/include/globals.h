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
 *	$Header: /cvsroot/doommod/dmm/include/globals.h,v 1.1.1.1 2005/10/20 21:36:10 paralizer Exp $
 *
 */
 
/**
 * @file globals.h
 * @brief Global variables defined here.
*/
 
#ifndef _GLOBALS_H
#define _GLOBALS_H


/*
 *	Include sourcehook.
 */
#include "definitions.h"


/*
 *	Global variables.
 *
 *	This big #ifdef __DMM__ thing is just an "easy"
 *	way to keep track of global variables, and
 *	initialize them at the same time.
 */
#ifdef __DMM__
	#define DMM_GLOBAL
	#define DMM_GPTR_INIT		= NULL					/* initialize global pointers to NULL */
	#define DMM_SH_PLID_INIT	= 0
#else
	#define DMM_GLOBAL			extern
	#define DMM_GPTR_INIT
	#define DMM_SH_PLID_INIT
#endif

DMM_GLOBAL gameExport_t g_mod;										/*!< mod interface	*/
DMM_GLOBAL engine_t g_engine;										/*!< engine interface */

DMM_GLOBAL struct plugin_t* g_plugins 			DMM_GPTR_INIT;		/*!< loaded plugin linked list */
DMM_GLOBAL struct dmm_t g_dmm_papi;									/*!< structure passed to plugins */
DMM_GLOBAL int g_loaded_plugins;									/*!< number of currently loaded plugins	*/

DMM_GLOBAL paths_t g_paths;											/*!< paths to required files */

DMM_GLOBAL struct pdb* g_dbptr					DMM_GPTR_INIT;		/*!< loaded config file	*/

DMM_GLOBAL SourceHook::CSourceHookImpl g_SourceHook;				/*!< sourcehook api instance */
DMM_GLOBAL SourceHook::ISourceHook* g_SHPtr		DMM_GPTR_INIT;		/*!< sourcehook internal casted pointer */
DMM_GLOBAL int g_PLID							DMM_SH_PLID_INIT;	/*!< DMM's unid for sourcehook */


#endif /* _GLOBALS_H */
