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
 *	$Header: /cvsroot/doommod/dmm/include/mod.h,v 1.1.1.1 2005/10/20 21:36:10 paralizer Exp $
 *
 */
 
#ifndef _MOD_H
#define _MOD_H

#include "doom_sdk.h"

/**
 *	Game entry point.
 */
typedef gameExport_t* (*pfnGetGameAPI)(gameImport_t*);

#ifdef __cplusplus
extern "C"
{
#endif

gameExport_t* load_mod();
void mod_init_hooks();
void mod_free_hooks();

#ifdef __cplusplus
}
#endif

#endif /* _MOD_H */
