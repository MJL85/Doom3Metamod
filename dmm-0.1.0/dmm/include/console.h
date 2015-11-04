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
 *	$Header: /cvsroot/doommod/dmm/include/console.h,v 1.1.1.1 2005/10/20 21:36:10 paralizer Exp $
 *
 */
 
#ifndef _CONSOLE_H
#define _CONSOLE_H

#include "doom_sdk.h"


/*
 *	General error macros for console commands.
 *	These are for subcommands of the "dmm" command.
 */
#define INVALID_PARAMS(cmd)				"Invalid parameters.  Use \"dmm help " cmd "\" for usage.\n"


/**
 *	This structure defines what parameters
 *	must be passed to Doom's AddCommand()
 *	function.
 */
struct doom_console_cmd_t {
	const char* cmdName;
	cmdFunction_t function;
	int flags;
	const char* description;
	argCompletion_t argCompletion;
};


/**
 *	This structure defines what subcommands
 *	the "dmm" command will accept.
 */
typedef void (*pfn_dmm_scmd_t)(const idCmdArgs& args);	/*!< subcommand callback */
struct dmm_subcommands_t {
	char* cmd;					/*!< command name			*/
	int params;					/*!< required parameters	*/
	char* syntax;				/*!< command syntax			*/
	char* desc;					/*!< description			*/
	pfn_dmm_scmd_t cb;			/*!< callback	handler		*/
};


#ifdef __cplusplus
extern "C"
{
#endif

void register_console_commands();
void cmd_dmm(const idCmdArgs& args);

#ifdef __cplusplus
}
#endif

#endif /* _CONSOLE_H */
