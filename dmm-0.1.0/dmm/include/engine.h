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
 *	$Header: /cvsroot/doommod/dmm/include/engine.h,v 1.2 2005/10/25 19:27:55 paralizer Exp $
 *
 */
 
#ifndef _ENGINE_H
#define _ENGINE_H

#include "definitions.h"

struct engine_t {
	gameImport_t engine;				/*!< real engine interface (hookable by plugins)	*/
	
	/*
	 *	These are "clones" of various classes in
	 *	gameImport_t which SourceHook has declared
	 *	"unhookable", so there's no need to worry
	 *	about plugins intercepting and changing
	 *	DMM functionality.
	 */
	SourceHook::CallClass<idCommon>* common;				/*!< idCommon SourceHook callclass			*/
	SourceHook::CallClass<idCmdSystem>* cmdSystem;			/*!< idCmdSystem SourceHook callclass		*/
	SourceHook::CallClass<idNetworkSystem>* networkSystem;	/*!< idNetworkSystem SourceHook callclass	*/
};


#ifdef __cplusplus
extern "C"
{
#endif

void init_engine(gameImport_t* import);
void free_engine();

#ifdef __cplusplus
}
#endif


#endif /* _ENGINE_H */
