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
 *	$Header: /cvsroot/doommod/dmm/src/str.c,v 1.1.1.1 2005/10/20 21:36:29 paralizer Exp $
 *
 */

 
/*
 *	This file includes string
 *	related functions.
 */

#include <stdio.h>
#include <stdarg.h>
#include <malloc.h>
#include <string.h>

/*
 *	The MSVC compiler generates an internal
 *	error with this file included.
 */
#ifndef WIN32
	#include <ctype.h>
#endif

#include "osdef.h"
#include "str.h"

/*
 *	Parse a token into an array.
 *	The resulting array contains
 *	character pointers to specific
 *	locations in the first token, which
 *	is a copy of the passed token.
 *	Thus, after calling this function,
 *	the passed token will no longer be
 *	needed, so it may be freed.
 *
 *	Each element in the array starting
 *	with the first is a pointer to
 *	part of the tokenized string.
 *	The array is terminated by a NULL
 *	element.
 *	After the NULL element is an
 *	additional entry with a pointer
 *	to the duplicated parsed string
 *	block.
 *
 *	The delim is the delimiter in which
 *	the token will be split.
 *	The dump character is that in which
 *	if encountered will terminate parsing
 *	and put the rest of the token in the
 *	next element. Pass NULL if you do not
 *	wish to use this feature.
 *
 *	Be sure to free the resulting array
 *	when it is no longer needed.
 */
char** token_parse(char* token, char delim, char* dump) {
	int size = 2;
	char* ctoken = token;
	char** tok_arr = NULL;
	char* cpy = NULL;
	int index = 0;
	char* last = NULL;

	/*
	 *	Determine the number of elements.
	 */
	while (*ctoken) {
		if (*ctoken == delim)
			++size;
		else if (dump != NULL) {
			if (*ctoken == *dump) {
				++size;
				break;
			}
		}
		++ctoken;
	}
	
	/*
	 *	Allocate memory for the array.
	 */
	tok_arr = (char**)malloc(sizeof(char*) * size + sizeof(char*));
	
	/*
	 *	Copy token to first index of array.
	 */
	cpy = (char*)malloc(sizeof(char) * strlen(token) + sizeof(char));
	strcpy(cpy, token);
	token = cpy;
	
	/*
	 *	Parse the token.
	 */
	index = 0;
	last = token;
	while (*token) {
		if (*token == delim) {
			tok_arr[index] = last;
			*token = '\0';
			last = (token + 1);
			++index;
		} else if (dump != NULL) {
			if (*token == *dump) {
				last++;
				break;
			}
		}
		++token;
	}
	tok_arr[index] = last;
	tok_arr[index + 1] = NULL;
	tok_arr[index + 2] = cpy;

	return tok_arr;
}


/*
 *	Remove a given index
 *	from a parsed token array.
 */
void token_rm_index(char** tok_arr, int index) {
	int i = 0;

	for (; i < index; i++)
		if (!tok_arr[i])
			return;
	
	while (tok_arr[i]) {
		tok_arr[i] = tok_arr[i + 1];
		++i;
	}
	tok_arr[i] = tok_arr[i + 1];
}


/*
 *	Combine all tokens
 *	including and after
 *	index.
 */
char* token_concat(char** tok_arr, int index) {
	int i = 0;
	char* ret = NULL;

	for (; i < index; i++)
		if (!tok_arr[i])
			return NULL;
	
	ret = (char*)malloc(sizeof(char));
	*ret = '\0';
		
	while (tok_arr[i]) {
		ret = (char*)realloc(ret, (sizeof(char) *
			(strlen(ret) + strlen(tok_arr[i])) + (sizeof(char))));
		strcat(ret, tok_arr[i]);
		++i;
		if (tok_arr[i]) {
			ret = (char*)realloc(ret, (sizeof(char) * (strlen(ret) + 2)));
			strcat(ret, " ");
		}
	}
	
	return ret;
}


/*
 *	Return a pointer to the
 *	token array data index.
 */
char* token_data(char** tok_arr) {
	int i = 0;

	while (tok_arr[i])
		++i;
	return tok_arr[i + 1];
}


/*
 *	Free a parsed token array
 *	created by token_parse()
 */
void token_free(char** tok_arr) {
	int i = 0;

	while (tok_arr[i])
		++i;
	free(tok_arr[i + 1]);
	free(tok_arr);
}


/*
 *	Format a string per printf()
 *	specifications.
 *  Length is limited to BUFSIZE.
 */
int va(char* buf, char* fmt, ...) {
	int ret = 0;
	va_list argptr;
	
	if (!fmt) {
		*buf = 0;
		return 0;
	}
	
	va_start(argptr, fmt);
	ret = vsnprintf(buf, BUFSIZE, fmt, argptr);	
	va_end(argptr);
	
	buf[ret] = '\0';
	
	return ret;
}


/*
 *  Similar to va() except the size is dynamic
 *  and depends on how many characters the
 *  resulting string will require.
 */
char* d_va(char* str, char* format, ...) {
	va_list argptr;
	int size = (sizeof(char) * strlen(format) + sizeof(char));
	int ret_size = 0;

	if (!str)
		str = (char*)malloc(size);
	else
		str = (char*)realloc(str, size);
	if (!str)
		return NULL;
	memset(str, 0, size);
	
	while (1) {
		va_start(argptr, format);
		ret_size = vsnprintf(str, size, format, argptr);
		va_end(argptr);
		
		if (!str)
			return NULL;
		
		if (ret_size >= size)
			/*	truncated	*/
			size *= 2;
		else
			/*	format done	*/
			break;
		
		str = (char*)realloc(str, size);
	}
	
	/*	drop unused memory	*/
	str = (char*)realloc(str, sizeof(char) * strlen(str) + sizeof(char));
	if (!str)
		return NULL;

	/*	be sure last character is a terminater	*/
	*(str + (sizeof(char) * strlen(str))) = 0;
	return str;
}


/*
 *	Case insensitive string compare.
 *	Return:
 *		-1	s1 < s2
 *		0	s1 = s2
 *		1	s1 > s2
 */
int cstrcmp(char* s1, char* s2) {
	if (!s1 && s2)			return -1;
	else if (s1 && !s2)		return 1;
	else if (!s1 && !s2)	return 0;
	
	while (*s1) {
		if (!*s2)
			return 1;
		if (tolower(*s1) > tolower(*s2))
			return 1;
		else if (tolower(*s1) < tolower(*s2))
			return -1;
		++s1;
		++s2;
	}
	return (*s2 ? -1 : 0);
}
