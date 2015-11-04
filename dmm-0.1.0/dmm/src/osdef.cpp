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
 *	$Header: /cvsroot/doommod/dmm/src/osdef.cpp,v 1.1.1.1 2005/10/20 21:36:29 paralizer Exp $
 *
 */

/**
 *	@file osdef.cpp
 *	@brief	Contains functions specific to an operating system.
 */

#include "definitions.h"
#include "str.h"
#include "osdef.h"

/**
 *	Win32 wrapper for the Linux dlerror() system call.
 *
 *	@return A string containing the last system error.
 */
#ifdef WIN32
char* dlerror() {
	static char buf[BUFSIZE];

	memset((void*)buf, 0, 1024);
	
	FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, NULL, GetLastError(), 0, buf, BUFSIZE, NULL);

	return buf;
}
#endif
