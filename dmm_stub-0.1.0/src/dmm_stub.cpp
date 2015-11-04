/*
 *	DMM - Doom 3 MultiMod (Stub Plugin)
 *
 *	Written By:
 *		Michael Laforest	< para >
 *		Email: < paralizer -AT- users -DOT- sourceforge -DOT- net >
 *
 *	Copyright 2005
 *
 *	This file is part of DMM Stub.
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
 *	$Header: /cvsroot/doommod/dmm_stub/src/dmm_stub.cpp,v 1.2 2005/10/25 19:32:01 paralizer Exp $
 *
 */

#define _DMM_PLUGIN_					/* define this only in the main plugin file */
#include <stdio.h>
#include "doom_sdk.h"
#include "dmmapi.h"						/* DMM application interface	*/
#include "dmmglobals.h"					/* DMM plugin global variables	*/

#include <stdarg.h>


/*
 *	Plugin information passed
 *	back to DMM.
 */
struct plugin_info_t plugin = {
	"dmm_stub",							/* name			*/
	"Michael Laforest <para>",			/* author		*/
	"http://",							/* URL			*/
	"0.1",								/* version		*/
	1,									/* pausable		*/
	1									/* unloadable	*/
};

/*
 *	The DMM plugin entry point.
 *	Called when the plugin is loaded.
 */
C_DLLEXPORT void dmm_main(struct plugin_info_t** pinfo, struct dmm_t* dmm_api, int unid) {
	/*
	 *	Initialize the plugin data structures - this is required.
	 */
	PLUGIN_INIT();
}


/*
 *	The DMM plugin exit point.
 *	Called when the plugin is unloaded.
 *
 *	It is a good idea to unhook any functions here,
 *	but DMM will clean them up for you if you don't.
 */
C_DLLEXPORT int dmm_shutdown() {
	return DMM_SHUTDOWN_CLEANLY;
}
