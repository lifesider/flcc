/***********************************************************************
* Software License Agreement (BSD License)
*
* Copyright (C) 2016  Lifesider Lai (lifesider@qq.com). All rights reserved.
*
* THE BSD LICENSE
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions
* are met:
*
* 1. Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
* 2. Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the
*    documentation and/or other materials provided with the distribution.
*
* THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
* NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
* THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
* THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*************************************************************************/
#ifndef FLCC_COEFFICIENTS_H
#define FLCC_COEFFICIENTS_H
#include "flcc.h"
#include <emmintrin.h>

#ifdef __cplusplus
extern "C" {
#endif

extern __m128 matYUVA2RGBA_SD[4];
extern __m128 matRGBA2YUVA_SD[4];

// integer optimization, 14 bits magnified
extern __m128i coefYU_RGBA_SD;
extern __m128i coefYU_BGRA_SD;
extern __m128i coefYV_RGBA_SD;
extern __m128i coefYV_BGRA_SD;

#ifdef __cplusplus
}
#endif

#endif	// FLCC_COEFFICIENTS_H
