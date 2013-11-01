/*

   BLIS    
   An object-based framework for developing high-performance BLAS-like
   libraries.

   Copyright (C) 2013, The University of Texas

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    - Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    - Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    - Neither the name of The University of Texas nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
   HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#ifndef BLIS_INVERTS_H
#define BLIS_INVERTS_H

// inverts

// Notes:
// - The first char encodes the type of x.


#define bli_sinverts( x ) \
{ \
	(x) = 1.0F / (x); \
}

#define bli_dinverts( x ) \
{ \
	(x) = 1.0  / (x); \
}


#ifndef BLIS_ENABLE_C99_COMPLEX


#define bli_cinverts( x ) \
{ \
	float  s     = bli_fmaxabs( bli_creal(x), bli_cimag(x) ); \
	float  xr_s  = bli_creal(x) / s; \
	float  xi_s  = bli_cimag(x) / s; \
	float  temp  = ( xr_s * bli_creal(x) + xi_s * bli_cimag(x) ); \
	bli_creal(x) =   xr_s / temp; \
	bli_cimag(x) =  -xi_s / temp; \
}

#define bli_zinverts( x ) \
{ \
	double s     = bli_fmaxabs( bli_zreal(x), bli_zimag(x) ); \
	double xr_s  = bli_zreal(x) / s; \
	double xi_s  = bli_zimag(x) / s; \
	double temp  = ( xr_s * bli_zreal(x) + xi_s * bli_zimag(x) ); \
	bli_zreal(x) =   xr_s / temp; \
	bli_zimag(x) =  -xi_s / temp; \
}


#else // ifdef BLIS_ENABLE_C99_COMPLEX


#define bli_cinverts( x )  { (x) = 1.0F / (x); }
#define bli_zinverts( x )  { (x) = 1.0  / (x); }


#endif


#endif
