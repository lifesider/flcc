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
#include "coefficients.h"

// YUV to RGB for standard definition
__m128 matYUVA2RGBA_SD[4] = {
	{ 1.f,  	0.f,		    1.401978f,	    0.f },
	{ 1.f,  	-0.344116f,	    -0.714111f, 	0.f },
	{ 1.f,  	1.771973f,  	0.f,		    0.f },
	{ 0.f,  	0.f,		    0.f,		    1.f }
};

// RGB to YUV for standard definition
__m128 matRGBA2YUVA_SD[4] = {
	{ 0.29895f, 	0.587036f,	    0.114014f,  	0.f },
	{ -0.168701f,	-0.331299f,     0.5f,		    0.f },
	{ 0.5f,	    	-0.418701f,	    -0.081299f, 	0.f },
	{ 0.f,	    	0.f,		    0.f,		    1.f }
};

// integer optimization, 14 bits magnified
__m128i coefYU_RGBA_SD;
__m128i coefYU_BGRA_SD;
__m128i coefYV_RGBA_SD;
__m128i coefYV_BGRA_SD;
