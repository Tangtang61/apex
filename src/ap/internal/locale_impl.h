/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#ifndef _LOCALE_IMPL_H
#define _LOCALE_IMPL_H

#include <locale.h>
#include <stdlib.h>
#include "libc.h"

#define LOCALE_NAME_MAX 15

struct __locale_map {
	const void *map;
	size_t map_size;
	char name[LOCALE_NAME_MAX+1];
	const struct __locale_map *next;
};

extern const struct __locale_map __c_dot_utf8;
extern const struct __locale_struct __c_locale;
extern const struct __locale_struct __c_dot_utf8_locale;

const struct __locale_map *__get_locale(int, const char *);
const char *__mo_lookup(const void *, size_t, const char *);
const char *__lctrans(const char *, const struct __locale_map *);
const char *__lctrans_cur(const char *);

#define LCTRANS(msg, lc, loc) __lctrans(msg, (loc)->cat[(lc)])
#define LCTRANS_CUR(msg) __lctrans_cur(msg)

#define C_LOCALE ((locale_t)&__c_locale)
#define UTF8_LOCALE ((locale_t)&__c_dot_utf8_locale)

#endif
