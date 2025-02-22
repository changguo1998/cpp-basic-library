/**********************************************************************************
 * MIT License                                                                    *
 *                                                                                *
 * Copyright (c) 2024 Chang Guo                                                   *
 *                                                                                *
 * Permission is hereby granted, free of charge, to any person obtaining a copy   *
 * of this software and associated documentation files (the "Software"), to deal  *
 * in the Software without restriction, including without limitation the rights   *
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell      *
 * copies of the Software, and to permit persons to whom the Software is          *
 * furnished to do so, subject to the following conditions:                       *
 *                                                                                *
 * The above copyright notice and this permission notice shall be included in all *
 * copies or substantial portions of the Software.                                *
 *                                                                                *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR     *
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,       *
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE    *
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER         *
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  *
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  *
 * SOFTWARE.                                                                      *
 *                                                                                *
 **********************************************************************************/

#ifndef _TYPE_COMPLEX_H_
#define _TYPE_COMPLEX_H_

#include <math.h>

#define DEFINE_COMPLEX(R, C, BIT) \
typedef struct { R re, im; } C; \
static inline C cmplx_##BIT(R re, R im){\
    C t;\
    t.re = re;\
    t.im = im;\
    return t;\
}\
static inline R cmplx_real##BIT(C z){ return z.re; }\
static inline R cmplx_imag##BIT(C z){ return z.im; }\
static inline R cmplx_abs2##BIT(C z){ return z.re*z.re+z.im*z.im;}\
static inline R cmplx_abs##BIT(C z){ return sqrtl(z.re*z.re+z.im*z.im);}\
static inline R cmplx_angle##BIT(C z){ return atan2l(z.im, z.re);}\
static inline C cmplx_sqrt##BIT(C z){\
    long double r0, t0, r1, t1;\
    C t;\
    r0 = cmplx_abs##BIT(z);\
    t0 = cmplx_angle##BIT(z);\
    r1 = sqrtl(r0);\
    t1 = t0 / 2.0;\
    t.re = r1 * cosl(t1);\
    t.im = r1 * sinl(t1);\
    return t;\
}\
static inline C cmplx_conj##BIT(C z){\
    C t;\
    t.re = z.re;\
    t.im = -z.im;\
    return t;\
}\
static inline C cmplx_add##BIT(C z1, C z2){\
    C t;\
    t.re = z1.re + z2.re;\
    t.im = z1.im + z2.im;\
    return t;\
}\
static inline C cmplx_sub##BIT(C z1, C z2){\
    C t;\
    t.re = z1.re - z2.re;\
    t.im = z1.im - z2.im;\
    return t;\
}\
static inline C cmplx_mul##BIT(C z1, C z2){\
    C t;\
    t.re = z1.re * z2.re - z1.im * z2.im;\
    t.im = z1.im * z2.re + z1.re * z2.im;\
    return t;\
}\
static inline C cmplx_div##BIT(C z1, C z2){\
    C t;\
    R n;\
    n = cmplx_abs2##BIT(z2);\
    t = cmplx_mul##BIT(z1, cmplx_conj##BIT(z2));\
    t.re /= n;\
    t.im /= n;\
    return t;\
}

DEFINE_COMPLEX(float, Complex32, 32)
DEFINE_COMPLEX(double, Complex64, 64)
DEFINE_COMPLEX(long double, Complex128, 128)


#endif // _TYPE_COMPLEX_H_
