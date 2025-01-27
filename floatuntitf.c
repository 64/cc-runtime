//===-- lib/floatuntitf.c - uint128 -> quad-precision conversion --*- C -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file implements tu_int to quad-precision conversion for the
// compiler-rt library in the IEEE-754 default round-to-nearest, ties-to-even
// mode.
//
//===----------------------------------------------------------------------===//

#ifndef CC_RUNTIME_NO_FLOAT

#define QUAD_PRECISION
#include "fp_lib.h"
#include "int_lib.h"

#if defined(CRT_HAS_TF_MODE)
#define SRC_U128
#define DST_QUAD
#include "int_to_fp_impl.inc"

// Returns: convert a tu_int to a fp_t, rounding toward even.

// Assumption: fp_t is a IEEE 128 bit floating point type
//             tu_int is a 128 bit integral type

// seee eeee eeee eeee mmmm mmmm mmmm mmmm | mmmm mmmm mmmm mmmm mmmm mmmm mmmm
// mmmm | mmmm mmmm mmmm mmmm mmmm mmmm mmmm mmmm | mmmm mmmm mmmm mmmm mmmm
// mmmm mmmm mmmm

COMPILER_RT_ABI fp_t __floatuntitf(tu_int a) { return __floatXiYf__(a); }

#endif

#endif
