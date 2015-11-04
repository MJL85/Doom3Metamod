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
 *	$Header: /cvsroot/doommod/dmm/include/utils.h,v 1.1.1.1 2005/10/20 21:36:10 paralizer Exp $
 *
 */
 
#ifndef _UTILS_H
#define _UTILS_H


/**
 *	A structure which holds all the
 *	paths DMM keeps track of.
 */
struct paths_t {
	char* mod_file;					/*!< the mod file to load			*/
	char* base;						/*!< the absolute path to doom		*/
	char* game;						/*!< the relative game path			*/
	char* dmm;						/*!< the relative path to DMM		*/
};


#ifdef __cplusplus
extern "C"
{
#endif

int determine_paths();
void free_paths();

#ifdef __cplusplus
}
#endif

#endif /* _UTILS_H */
