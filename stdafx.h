/* $Id$ */

/** @file stdafx.h Definition of base types and functions in a cross-platform compatible way. */

#ifndef STDAFX_H
#define STDAFX_H

#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <assert.h>
#include <errno.h>
#include <string>

#if defined(_MSC_VER)
	typedef unsigned char    uint8_t;
	typedef unsigned short   uint16_t;
	typedef unsigned int     uint32_t;
	#define UNUSED

	#define fileno _fileno
	#pragma warning(disable: 4996)   // 'strdup' was declared deprecated
#elif defined(__GNUC__)
	#include <stdint.h>
	#define UNUSED __attribute__((unused))
#else
	#warning "Unknown compiler type, might not compile!"
	#include <stdint.h>
	#define UNUSED
#endif

#if defined(WIN32)
	#include <io.h>
	#define isatty _isatty
	#define unlink _unlink
#endif

#define assert_compile(expr) extern const int __ct_assert__[1 - 2 * !(expr)] UNUSED

/* Check if the types have the bitsizes like we are using them */
assert_compile(sizeof(uint32_t) == 4);
assert_compile(sizeof(uint16_t) == 2);
assert_compile(sizeof(uint8_t)  == 1);

#endif /* STDAFX_H */