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
 *	$Header: /cvsroot/doommod/dmm/src/utils.cpp,v 1.2 2005/10/25 19:29:56 paralizer Exp $
 *
 */

/**
 *	@file utils.cpp
 *	@brief General utility functions.
 */

/*
 *	General utility functions not specific to any
 *	given area of DMM operation.
 */

#include <stdio.h>
#include "utils.h"
#include "doom_sdk.h"
#include "engine.h"
#include "definitions.h"
#include "globals.h"


/*!	Avoid the need to malloc() for g_paths.dmm	*/
static char* _dmm_path = DMM_PATH;


/**
 *	This function uses a pointer to itself in attempt to
 *	find it's absolute path on the filesystem.
 *
 *	For this to parse correctly, DMM must be in a subfolder of
 *	Doom3.
 *	Example:
 *		If you are on Linux using the home-path Doom directory,
 *		your Doom3 files would be in:
 *			/home/your_name/.doom3/
 *		Therefore, DMM should be in:
 *			/home/your_name/.doom3/.dmm/
 *		Check definitions.h macro DMM_PATH for the real
 *		relative path used.
 *
 *	If running on Linux:
 *		If DMM is in the installation directory (ie: /opt/doom3),
 *		Doom3 will copy DMM into your home directory.
 *		For this reason, DMM will always assume DMM files are
 *		in your home directory, so put them there, not the
 *		installation path.
 *
 *		It is a good idea to not run DMM as a "mod" (ie +set fs_game),
 *		instead, make a symlink in the game directory to DMM,
 *		and change the permission of DMM to 444.
 *		This will prevent Doom from being able to copy the real
 *		mod into place and allow Doom to run in pure mode while using DMM.
 *
 *	This method required GLIBC, dladdr() is not defined in POSIX.
 *
 *	@return 1 on success, 0 on failure.
 */
int determine_paths() {
	/*
	 *	Initialize the paths.
	 */
	g_paths.mod_file = NULL;
	g_paths.base = NULL;
	g_paths.game = NULL;
	g_paths.dmm = _dmm_path;
	
	/*
	 *	Request information on this module
	 *	from the operating system.
	 */	
	Dl_info self_info;
	if (!dladdr((void*)&determine_paths, &self_info)) {
		CONSOLE_PRINTF(CERROR "Failed to find absolute path to DMM; expect a segfault.\n");
		return 0;
	}

	#ifdef WIN32
		char filename[MAX_PATH_SIZE];
		if (!GetModuleFileName((HMODULE)self_info.AllocationBase, filename, MAX_PATH_SIZE)) {
			CONSOLE_PRINTF(CERROR "Failed to find absolute path to DMM; expect a segfault.\n");
			return 0;
		}
		filename[MAX_PATH_SIZE - 1] = '\0';
	#endif

	char* s = NULL;
	
	#ifdef WIN32
		s = (filename + strlen(filename) - 1);
	#else
		s = (char*)(self_info.dli_fname + strlen(self_info.dli_fname) - 1);
	#endif

	/*
	 *	Parse the returned path.
	 */
	int level = 0;
	for (; s > 0; --s) {
		if (*s == OS_DIR_DIV) {
			++level;
			if (level == 1) {
				/* found game path */
				*(s + 1) = 0;
			} else if (level == 2) {
				/* found base path */
				g_paths.game = strdup(s + 1);				/* copy game path */
				*(s + 1) = 0;
				#ifdef WIN32
					g_paths.base = strdup(filename);			/* copy base path */
				#else
					g_paths.base = strdup(self_info.dli_fname);	/* copy base path */
				#endif
				break;
			}
		}
	}

	if (g_paths.base) {
		CONSOLE_PRINTF(CINFO "Found path to Doom 3: \"%s\".\n", g_paths.base);
		CONSOLE_PRINTF(CINFO "Found relative path to game: \"%s\".\n", g_paths.game);
		CONSOLE_PRINTF(CINFO "Using relative path to DMM: \"%s\".\n", g_paths.dmm);
	} else
		CONSOLE_PRINTF(CERROR "Unable to find path to Doom3; expect a segfault\n");

	return (g_paths.base ? 1 : 0);
}


/**
 *	Deallocate the memory used for paths.
 */
void free_paths() {
	g_paths.mod_file = NULL;
	if (g_paths.base) {
		free(g_paths.base);
		g_paths.base = NULL;
	}
	if (g_paths.game) {
		free(g_paths.game);
		g_paths.game = NULL;
	}
}
