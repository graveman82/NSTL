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
#ifndef NSTLSTREAM_H
#define NSTLSTREAM_H

#include "nstl/nstldef.h"

namespace nstd
{
template <typename Handle>
class stream
{
public:
	typedef size_t size_type;
	typedef int64_t pos_type;
	typedef int32_t error_type;

	stream() {}

	virtual ~stream()
	{
		close();
	}

	virtual error_type init(Handle handle) = 0;

	virtual error_type close() = 0;

	virtual bool is_inited() const = 0;

	virtual size_t size() const = 0;

	virtual pos_type get_pos(error_type* p_error_code = NSTD_NULLPTR(error_type)) = 0;

	virtual error_type set_pos(pos_type pos) = 0;

	virtual size_type read(
		void* buf_read_to, 
		size_type n_bytes, 
		error_type* p_error_code = NSTD_NULLPTR(error_type)) = 0;

	virtual size_type write(
		const void* buf_read_from, 
		size_type n_bytes,
		error_type* p_error_code = NSTD_NULLPTR(error_type)) = 0;
};

} // eof nstd

#endif // NSTLSTREAM_H