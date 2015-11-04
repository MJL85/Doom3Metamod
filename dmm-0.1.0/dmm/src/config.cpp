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
 *	$Header: /cvsroot/doommod/dmm/src/config.cpp,v 1.1.1.1 2005/10/20 21:36:28 paralizer Exp $
 *
 */

/**
 *	@file config.cpp
 *	@brief	Wrapper for pdb; handles configuration file.
 */

#include <stdio.h>
#include <string.h>
#include "doom_sdk.h"
#include "pdb.h"
#include "str.h"
#include "config.h"
#include "utils.h"
#include "engine.h"
#include "globals.h"
#include "definitions.h"

/**
 *	Load the configuration file.
 *
 *	@return 1 on success, 0 on failure
 */
int load_config() {
	/*
	 *	Load the pdb library.
	 */
	char buf[BUFSIZE];
	ABSOLUTE_DMM_PATH(buf, PDB_LIB);
	
	CONSOLE_PRINTF(CINFO "Loading pdb library (%s) ...\n", buf);
	if (load_pdb_lib(buf))
		CONSOLE_PRINTF(CINFO "Successfully loaded pdb library.\n");
	else {
		CONSOLE_PRINTF(CERROR "Failed to load pdb library.\n");
		return 0;
	}

	/*
	 *	Load the configuration file.
	 */
	ABSOLUTE_DMM_PATH(buf, DMM_CONFIG_FILE);
	CONSOLE_PRINTF(CINFO "Attempting to load configuration file (%s) ...\n", buf);
	g_dbptr = pdb_load(buf);
	if (g_dbptr)
		CONSOLE_PRINTF(CINFO "Successfully loaded configuration file.\n");
	else {
		CONSOLE_PRINTF(CERROR "Failed to load configuration file.\n");
		return 0;
	}
	
	return 1;	
}


/**
 *	Unload the configuration file and the pdb library.
 */
void unload_config() {
	if (g_dbptr) {
		CONSOLE_PRINTF(CINFO "Unloading configuration file ...\n");
		pdb_unload(g_dbptr);
		g_dbptr = NULL;
	}

	CONSOLE_PRINTF(CINFO "Unloading pdb library ...\n");
	unload_pdb_lib();
}
