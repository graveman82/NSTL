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
#ifndef NSTLSTATICARRAY_H
#define NSTLSTATICARRAY_H

#include "nstl/nstldef.h"

namespace nstd
{
template <typename T, size_t N>
class static_array
{
public:
	typedef T value_type;
	typedef size_t size_type;
	typedef int32_t error_type;

	typedef T* pointer;
	typedef const T* const_pointer;
	typedef T& reference;
	typedef const T& const_reference;

	static_array() : m_nCount(0)
	{

	}

	const size_type() const { return m_nCount; }
private:
	byte m_data[N * sizeof(T)];
	size_type m_nCount;

};

} // eof nstd

#endif // NSTLSTATICARRAY_H