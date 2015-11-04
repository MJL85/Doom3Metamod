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
 *	$Header: /cvsroot/doommod/dmm/include/definitions.h,v 1.2 2005/10/25 19:27:55 paralizer Exp $
 *
 */

#ifndef _DEFINITIONS_H
#define _DEFINITIONS_H

/*
 *	DMM version information.
 *	Please do not change these.
 */
#define DMM_VERSION		"0.1.0"
#define DMM_URL			"http://doommod.sf.net/"

/*
 *	If you modified the DMM code, feel free to add
 *	a build string here.  The DMM version will
 *	be displayed as:
 *		DMM v<version> <build>
 *
 *	For example, if you modify DMM version 0.1.0,
 *	you may se DMM_BUILD to be "Enhanced, by ZX",
 *	and the DMM version will appear as:
 *		DMM v0.1.0 (Enhanced, by ZX)
 */
#define DMM_BUILD		"development"


/*
 *	Include operating system dependent macros.
 */
#include "osdef.h"


#ifdef __cplusplus
		#define C_DLLEXPORT extern "C" DLLEXPORT
#else
		#define C_DLLEXPORT DLLEXPORT
#endif


/**
 *	Maximum size of a full file path.
 */
#define MAX_PATH_SIZE		1024


/**
 *	What subdirectory under the base doom directory in
 *	the users home directory is DMM?
 *
 *	Ie: If DMM is at:	/home/para/.doom3/.dmm/
 *		set this to ".dmm/"
 */
#ifdef WIN32
	#define DMM_PATH		"dmm\\"
#else
	#define DMM_PATH		".dmm/"
#endif


/**
 *	Uncomment this to enable high detail output.
 *	This will output more information about DMM operation
 *	than usual.  It's not quite debug information however.
 */
#define DMM_DETAIL


/*
 *	Sourcehook :)
 */
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
#include "sourcehook_impl.h"
#ifdef vsnprintf
	#undef vsnprintf
#endif
#ifdef doom_vsn
	#define vsnprintf doom_vsn
	#undef doom_vsm
#endif


/**
 *	Path to the pdb library.
 */
#ifdef WIN32
	#define PDB_LIB		"pdb.dll"
#else
	#define PDB_LIB		"pdb.so"
#endif


/**
 *	Default DMM configuration file.
 */
#define DMM_CONFIG_FILE		"dmm.conf"


/*
 *	str.h needs to be included for its BUFSIZE
 *	macro, which is the maximum size for buffers.
 */
#include "str.h"


/**
 *	Store the absolute path to a file in
 *	the passed buffer.
 *	Buf can be at most size BUFSIZE
 *
 *	_CREATE_PATH will create an abstract path
 *		ex: path = "/foo/bar"
 *			file = "asdf"
 *			the return is: "/foo/bar/asdf"
 *
 *	ABSOLUTE_PATH will create a path to the doom3 directory
 *		ex: if the doom3 directory = "/opt/doom3/"
 *			file = "asdf"
 *			the return is: "/opt/doom3/asdf"
 *
 *	ABSOLUTE_DMM_PATH will create a path to the DMM directory
 *		ex: if the doom3 directory = "/opt/doom3/"
 *			if the DMM relative directory is "dmm/"
 *			file = "asdf"
 *			the return is "/opt/doom3/dmm/asdf"
 *
 *	A little ugly, I know :\
 */
#define _CREATE_PATH(buf, path, file)	do { \
											*buf = 0; \
											if ((strlen(path) + strlen(file) + 1 + \
												(*(path + strlen(path) - 1) == OS_DIR_DIV ? 1 : 0)) \
												> BUFSIZE) \
												/* too big for buffer */ \
												break; \
											strcat(buf, path); \
											*(buf + strlen(path) + 1) = 0; \
											if (*(path + strlen(path) - 1) != OS_DIR_DIV) { \
												*(buf + strlen(path)) = OS_DIR_DIV; \
												*(buf + strlen(path) + 1) = 0; \
											} \
											strcat(buf, file); \
											*(buf + strlen(path) + strlen(file) + 1) = 0; \
										} while(0)

#define ABSOLUTE_PATH(buf, file)		_CREATE_PATH(buf, g_paths.base, file)
#define ABSOLUTE_DMM_PATH(buf, file)	do { \
											*buf = 0; \
											if ((strlen(g_paths.base) + strlen(g_paths.dmm) + strlen(file) + 1 > BUFSIZE))\
												/* too big for buffer */ \
												break; \
											_CREATE_PATH(buf, g_paths.base, g_paths.dmm); \
											_CREATE_PATH((buf + strlen(g_paths.base) + strlen(g_paths.dmm) - 1), \
												"", file); \
										} while(0)
#define ABSOLUTE_GAME_PATH(buf, file)	do { \
											*buf = 0; \
											if ((strlen(g_paths.base) + strlen(g_paths.game) + strlen(file) + 1 > BUFSIZE))\
												/* too big for buffer */ \
												break; \
											_CREATE_PATH(buf, g_paths.base, g_paths.game); \
											_CREATE_PATH((buf + strlen(g_paths.base) + strlen(g_paths.game) - 1), \
												"", file); \
										} while(0)


/*
 *	Random macros.
 */
#define GRAMMAR_PLURAL(i)			((i != 1) ? "s" : "")

typedef unsigned char	byte;

/*
 *	Macro for various _direct_ Doom engine calls.
 */
#define CONSOLE_PRINTF		SH_CALL(g_engine.common, &idCommon::Printf)
#define REGISTER_COMMAND	SH_CALL(g_engine.cmdSystem, &idCmdSystem::AddCommand)
#define UNREG_COMMAND		SH_CALL(g_engine.cmdSystem, &idCmdSystem::RemoveCommand)
#define SERVER_MSG			SH_CALL(g_engine.networkSystem, &idNetworkSystem::ServerSendReliableMessage)
										
/*
 *	You should prepend one of the following to
 *	string literals of all uses of CONSOLE_PRINTF.
 */
#define CINFO			"[DMM] "
#define CERROR			"[DMM] [ERROR] "
#define CWARNING		"[DMM] [WARNING] "
#define CDEBUG			"[DMM] [DEBUG] "
										
#endif /* _DEFINITIONS_H */
