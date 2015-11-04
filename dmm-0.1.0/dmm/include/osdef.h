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
 *	$Header: /cvsroot/doommod/dmm/include/osdef.h,v 1.2 2005/10/25 19:27:55 paralizer Exp $
 *
 */

/*
 *	Operating system dependent
 *	headers and macros.
 */
#ifdef WIN32
		#define OS_ID_STR				"Windows"

		#define WIN32_LEAN_AND_MEAN
        #include <windows.h>

		#define DLLEXPORT				__declspec(dllexport)
		#define OS_DIR_DIV				'\\'

        #define dlopen(file, x)         (void*)LoadLibrary(file)
        #define dlsym(dll, func)        (void*)GetProcAddress((HMODULE)(dll), (func))
        #define dlclose(dll)            FreeLibrary((HMODULE)(dll))
		#define Dl_info					MEMORY_BASIC_INFORMATION
		#define dladdr(func, inf)		VirtualQuery(func, inf, sizeof(*inf))

		char* _dlerror();
		#define dlerror()				_dlerror()

		#ifdef vsnprintf
			#undef vsnprintf
		#endif
		#define vsnprintf(buf, size, fmt, argptr)	_vsnprintf(buf, size, fmt, argptr)
#else
		#define OS_ID_STR				"Linux"

		#include <stdio.h>
        #include <dlfcn.h>

		#define DLLEXPORT
		#define OS_DIR_DIV				'/'
#endif
