/*
 * Copyright (c) 2003, 2007-14 Matteo Frigo
 * Copyright (c) 2003, 2007-14 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Thu Dec 10 07:04:24 EST 2020 */

#include "codelet-dft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_twidsq.native -fma -compact -variables 4 -pipeline-latency 4 -reload-twiddle -dif -n 2 -name q1_2 -include dft/scalar/q.h */

/*
 * This function contains 12 FP additions, 8 FP multiplications,
 * (or, 8 additions, 4 multiplications, 4 fused multiply/add),
 * 17 stack variables, 0 constants, and 16 memory accesses
 */
#include "q.h"

static void q1_2(R *rio, R *iio, const R *W, stride rs, stride vs, INT mb, INT me, INT ms)
{
     {
	  INT m;
	  for (m = mb, W = W + (mb * 2); m < me; m = m + 1, rio = rio + ms, iio = iio + ms, W = W + 2, MAKE_VOLATILE_STRIDE(4, rs), MAKE_VOLATILE_STRIDE(0, vs)) {
	       E T1, T2, T4, T7, T8, T9, Tb, Tc, Te, Th, Ti, Tj;
	       T1 = rio[0];
	       T2 = rio[WS(rs, 1)];
	       T4 = T1 - T2;
	       T7 = iio[0];
	       T8 = iio[WS(rs, 1)];
	       T9 = T7 - T8;
	       Tb = rio[WS(vs, 1)];
	       Tc = rio[WS(vs, 1) + WS(rs, 1)];
	       Te = Tb - Tc;
	       Th = iio[WS(vs, 1)];
	       Ti = iio[WS(vs, 1) + WS(rs, 1)];
	       Tj = Th - Ti;
	       rio[0] = T1 + T2;
	       iio[0] = T7 + T8;
	       rio[WS(rs, 1)] = Tb + Tc;
	       iio[WS(rs, 1)] = Th + Ti;
	       {
		    E Tf, Tk, Td, Tg;
		    Td = W[0];
		    Tf = Td * Te;
		    Tk = Td * Tj;
		    Tg = W[1];
		    rio[WS(vs, 1) + WS(rs, 1)] = FMA(Tg, Tj, Tf);
		    iio[WS(vs, 1) + WS(rs, 1)] = FNMS(Tg, Te, Tk);
	       }
	       {
		    E T5, Ta, T3, T6;
		    T3 = W[0];
		    T5 = T3 * T4;
		    Ta = T3 * T9;
		    T6 = W[1];
		    rio[WS(vs, 1)] = FMA(T6, T9, T5);
		    iio[WS(vs, 1)] = FNMS(T6, T4, Ta);
	       }
	  }
     }
}

static const tw_instr twinstr[] = {
     { TW_FULL, 0, 2 },
     { TW_NEXT, 1, 0 }
};

static const ct_desc desc = { 2, "q1_2", twinstr, &GENUS, { 8, 4, 4, 0 }, 0, 0, 0 };

void X(codelet_q1_2) (planner *p) {
     X(kdft_difsq_register) (p, q1_2, &desc);
}
#else

/* Generated by: ../../../genfft/gen_twidsq.native -compact -variables 4 -pipeline-latency 4 -reload-twiddle -dif -n 2 -name q1_2 -include dft/scalar/q.h */

/*
 * This function contains 12 FP additions, 8 FP multiplications,
 * (or, 8 additions, 4 multiplications, 4 fused multiply/add),
 * 17 stack variables, 0 constants, and 16 memory accesses
 */
#include "q.h"

static void q1_2(R *rio, R *iio, const R *W, stride rs, stride vs, INT mb, INT me, INT ms)
{
     {
	  INT m;
	  for (m = mb, W = W + (mb * 2); m < me; m = m + 1, rio = rio + ms, iio = iio + ms, W = W + 2, MAKE_VOLATILE_STRIDE(4, rs), MAKE_VOLATILE_STRIDE(0, vs)) {
	       E T1, T2, T4, T6, T7, T8, T9, Ta, Tc, Te, Tf, Tg;
	       T1 = rio[0];
	       T2 = rio[WS(rs, 1)];
	       T4 = T1 - T2;
	       T6 = iio[0];
	       T7 = iio[WS(rs, 1)];
	       T8 = T6 - T7;
	       T9 = rio[WS(vs, 1)];
	       Ta = rio[WS(vs, 1) + WS(rs, 1)];
	       Tc = T9 - Ta;
	       Te = iio[WS(vs, 1)];
	       Tf = iio[WS(vs, 1) + WS(rs, 1)];
	       Tg = Te - Tf;
	       rio[0] = T1 + T2;
	       iio[0] = T6 + T7;
	       rio[WS(rs, 1)] = T9 + Ta;
	       iio[WS(rs, 1)] = Te + Tf;
	       {
		    E Tb, Td, T3, T5;
		    Tb = W[0];
		    Td = W[1];
		    rio[WS(vs, 1) + WS(rs, 1)] = FMA(Tb, Tc, Td * Tg);
		    iio[WS(vs, 1) + WS(rs, 1)] = FNMS(Td, Tc, Tb * Tg);
		    T3 = W[0];
		    T5 = W[1];
		    rio[WS(vs, 1)] = FMA(T3, T4, T5 * T8);
		    iio[WS(vs, 1)] = FNMS(T5, T4, T3 * T8);
	       }
	  }
     }
}

static const tw_instr twinstr[] = {
     { TW_FULL, 0, 2 },
     { TW_NEXT, 1, 0 }
};

static const ct_desc desc = { 2, "q1_2", twinstr, &GENUS, { 8, 4, 4, 0 }, 0, 0, 0 };

void X(codelet_q1_2) (planner *p) {
     X(kdft_difsq_register) (p, q1_2, &desc);
}
#endif
