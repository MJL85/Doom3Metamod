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
 *	$Header: /cvsroot/doommod/dmm_stub/include/dmmglobals.h,v 1.1.1.1 2005/10/20 21:42:34 paralizer Exp $
 *
 */
 
#ifndef _DMMGLOBALS_H
#define _DMMGLOBALS_H


#ifdef _DMM_PLUGIN_
	#define PLUGIN_GLOBAL
#else
	#define PLUGIN_GLOBAL	extern
#endif


/*
 *	Global variables.
 */
PLUGIN_GLOBAL SourceHook::ISourceHook* g_SHPtr;		/* sourcehook instance */
PLUGIN_GLOBAL struct dmm_t dmm;
PLUGIN_GLOBAL int g_PLID;


#endif /* _DMMGLOBALS_H */
