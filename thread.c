/* SPDX-License-Identifier: MIT */
/*
 * Copyright (C) 2004-2007 Koichi Sasada
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */
/* ruby_fill_thread_id_string() is copied from Ruby's thread.c */

#include "ruby/config.h"
#include "ruby/thread_native.h"
#include "vm_core.h"


# ifdef NON_SCALAR_THREAD_ID
const char *
ruby_fill_thread_id_string(rb_nativethread_id_t thid, rb_thread_id_string_t buf)
{
    extern const char ruby_digitmap[];
    size_t i;

    buf[0] = '0';
    buf[1] = 'x';
    for (i = 0; i < sizeof(thid); i++) {
# ifdef LITTLE_ENDIAN
	size_t j = sizeof(thid) - i - 1;
# else
	size_t j = i;
# endif
	unsigned char c = (unsigned char)((char *)&thid)[j];
	buf[2 + i * 2] = ruby_digitmap[(c >> 4) & 0xf];
	buf[3 + i * 2] = ruby_digitmap[c & 0xf];
    }
    buf[sizeof(rb_thread_id_string_t)-1] = '\0';
    return buf;
}
#endif
