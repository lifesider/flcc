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
#include "flcc.h"
#include "coefficients.h"

FLCC_API const char* flcc_version()
{
	return FLCC_VERSION;
}

FLCC_API int flcc_register()
{
	__m128 c14 = _mm_set1_ps(16384.f);
	__m128i comp = _mm_set_epi16(257, 0, 0, 0, 1, 0, 0, 0);

	// RGB to YUV for standard definition
	__m128i y = _mm_cvtps_epi32(_mm_mul_ps(c14, matRGBA2YUVA_SD[0]));
	__m128i u = _mm_cvtps_epi32(_mm_mul_ps(c14, matRGBA2YUVA_SD[1]));
	__m128i v = _mm_cvtps_epi32(_mm_mul_ps(c14, matRGBA2YUVA_SD[2]));
	coefYU_RGBA_SD = _mm_or_si128(_mm_packs_epi32(y, u), comp);
	coefYU_BGRA_SD = _mm_shufflehi_epi16(_mm_shufflelo_epi16(coefYU_RGBA_SD, 0xc6), 0xc6);
	coefYV_RGBA_SD = _mm_or_si128(_mm_packs_epi32(y, v), comp);
	coefYV_BGRA_SD = _mm_shufflehi_epi16(_mm_shufflelo_epi16(coefYV_RGBA_SD, 0xc6), 0xc6);
	
	return 0;
}

FLCC_API int flcc_rgb2yuv(void* yuv, intptr_t stride_yuv, void* rgb, intptr_t stride_rgb, int width, int height, bool isbgr, bool flip)
{
	return 0;
}
