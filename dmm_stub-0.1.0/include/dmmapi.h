/*
 *	DMM - Doom 3 MultiMod
 *
 *	Written By:
 *		Michael Laforest	< para >
 *		Email: < paralizer -AT- users -DOT- sourceforge -DOT- net >
 *
 *	Copyright © 2005
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
 *	$Header: /cvsroot/doommod/dmm_stub/include/dmmapi.h,v 1.1.1.1 2005/10/20 21:42:34 paralizer Exp $
 *
 */
 
#ifndef _DMMAPI_H
#define _DMMAPI_H


#ifdef WIN32
        #define WIN32_LEAN_AND_MEAN
		#define DLLEXPORT __declspec(dllexport)
#else
		#define DLLEXPORT
#endif
#ifdef __cplusplus
		#define C_DLLEXPORT extern "C" DLLEXPORT
#else
		#define C_DLLEXPORT DLLEXPORT
#endif


#if defined __GNUC__
	#include <stdint.h>
#endif

/*
 *	Doom uses a custom vsnprintf function.
 *	Store what it's defined as and undef
 *	it so SourceHook can redefine it.
 *	It will be restored to Doom's afterwards.
 */
#ifdef vsnprintf
	#define doom_vsn vsnprintf
	#undef vsnprintf
#endif
#include "sourcehook.h"
#ifdef vsnprintf
	#undef vsnprintf
#endif
#ifdef doom_vsn
	#define vsnprintf doom_vsn
	#undef doom_vsm
#endif

/*
 *	dmm_shutdown() returns.
 *	dmm_shutdown() should return one of these.
 */
enum {
	DMM_SHUTDOWN_ERROR = 0,
	DMM_SHUTDOWN_CLEANLY
};


/*
 *	The structure a plugin gets
 *	through the entry point.
 *	It stores all information
 *	about a given plugin.
 */
struct plugin_info_t {
	char* name;
	char* author;
	char* url;
	char* version;
	int can_pause;
	int can_unload;
};


/*
 *	Macro to initialize plugin with SourceHook.
 *
 *	Setup the required globals.
 *	dmm isn't required, but DMM will
 *	not keep the pointer passed to this
 *	function, so it's a good idea to
 *	make a local copy here.
 *
 *	g_SHPtr is required.
 *	g_PLID is required.
 */
#define PLUGIN_INIT()	do { \
							memcpy(&dmm, dmm_api, sizeof(struct dmm_t)); \
							g_SHPtr = dmm.sourcehook; \
							g_PLID = unid; \
							*pinfo = &plugin; \
						} while (0)

/*
 *	Plugin API returns.
 */
enum {
	DMM_FAIL = 0,
	DMM_SUCCESS,
	DMM_OP_ALREADY		/* the requested operation was already set */
};


/*
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


#ifdef __cplusplus
extern "C"
{
#endif



#ifdef __cplusplus
}
#endif

#endif /* _DMMAPI_H */
