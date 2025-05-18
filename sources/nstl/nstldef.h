/*
This file is a part of (Non-standard template library) NSTL.

MIT License

Copyright (c) 2025 graveman82

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#ifndef NSTLDEF_H
#define NSTLDEF_H


#define NSTD_CPP_VER __cplusplus
#define NSTD_HAS_CPP11 (NSTD_CPP_VER >= 11201103L)
#define NSTD_HAS_CPP17 (NSTD_CPP_VER >= 201703L)

#ifdef _MSC_VER // Microsoft visual studio compiler detection
#	define NSTD_MSC_VER _MSC_VER
	// concrete version detection
#	if (NSTD_MSC_VER==1310) 
#		define NSTD_VISUAL_STUDIO_NET_2003
#	elif (NSTD_MSC_VER==1900)
#		define NSTD_VISUAL_STUDIO_2015
#		define NSTD_HAS_STDINT_H
#	endif
#elif defined __GNUC__ // GNU C compiler detection
#	error "Not implemented for gcc now"
#else
#	error "Your compiler is not supported by NSTD! Shit happens!"
#endif // eof compiler detection

#ifdef NSTD_HAS_STDINT_H
#include <cstdint>
#endif

#include <cstddef>

namespace nstd
{
#ifdef NSTD_HAS_STDINT_H
typedef std::int8_t int8_t;
typedef std::int16_t int16_t;
typedef std::int32_t int32_t;
typedef std::int64_t int64_t;

typedef std::uint8_t uint8_t;
typedef std::uint16_t uint16_t;
typedef std::uint32_t uint32_t;
typedef std::uint64_t uint64_t;

#else // no cstdint header
#	ifdef NSTD_MSC_VER
typedef __int8 int8_t;
typedef __int16 int16_t;
typedef __int32 int32_t;
typedef __int64 int64_t;

typedef unsigned __int8 uint8_t;
typedef unsigned __int16 uint16_t;
typedef unsigned __int32 uint32_t;
typedef unsigned __int64 uint64_t;
#	else
typedef signed char int8_t;
typedef short int16_t;
typedef long int32_t;
typedef long long int64_t;

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long uint32_t;
typedef unsigned long long uint64_t;
#	endif
#endif // eof NSTD_HAS_STDINT_H

typedef std::size_t size_t;
typedef std::ptrdiff_T ptrdiff_t;

#ifdef NSTD_HAS_CPP17
typedef std::byte byte;
#else
typedef uint8_t byte;
#endif // byte
} // eof nstd


#endif // NSTLDEF_H