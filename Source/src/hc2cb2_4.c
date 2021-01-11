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
/* Generated on Thu Dec 10 07:06:45 EST 2020 */

#include "codelet-rdft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_hc2c.native -fma -compact -variables 4 -pipeline-latency 4 -sign 1 -twiddle-log3 -precompute-twiddles -n 4 -dif -name hc2cb2_4 -include rdft/scalar/hc2cb.h */

/*
 * This function contains 24 FP additions, 16 FP multiplications,
 * (or, 16 additions, 8 multiplications, 8 fused multiply/add),
 * 33 stack variables, 0 constants, and 16 memory accesses
 */
#include "hc2cb.h"

static void hc2cb2_4(R *Rp, R *Ip, R *Rm, R *Im, const R *W, stride rs, INT mb, INT me, INT ms)
{
     {
	  INT m;
	  for (m = mb, W = W + ((mb - 1) * 4); m < me; m = m + 1, Rp = Rp + ms, Ip = Ip + ms, Rm = Rm - ms, Im = Im - ms, W = W + 4, MAKE_VOLATILE_STRIDE(16, rs)) {
	       E T7, Tb, T8, Ta, Tc, Tg, T9, Tf;
	       T7 = W[0];
	       Tb = W[3];
	       T8 = W[2];
	       T9 = T7 * T8;
	       Tf = T7 * Tb;
	       Ta = W[1];
	       Tc = FMA(Ta, Tb, T9);
	       Tg = FNMS(Ta, T8, Tf);
	       {
		    E T3, T6, Td, Tj, Tz, Tx, Tr, Tm, Tv, Ts, Tw, TA;
		    {
			 E Th, Ti, Tu, Tp, Tk, Tl, Tq, Tt;
			 {
			      E T1, T2, T4, T5;
			      Th = Ip[0];
			      Ti = Im[WS(rs, 1)];
			      Tu = Th + Ti;
			      T1 = Rp[0];
			      T2 = Rm[WS(rs, 1)];
			      T3 = T1 + T2;
			      Tp = T1 - T2;
			      Tk = Ip[WS(rs, 1)];
			      Tl = Im[0];
			      Tq = Tk + Tl;
			      T4 = Rp[WS(rs, 1)];
			      T5 = Rm[0];
			      T6 = T4 + T5;
			      Tt = T4 - T5;
			 }
			 Td = T3 - T6;
			 Tj = Th - Ti;
			 Tz = Tu - Tt;
			 Tx = Tp + Tq;
			 Tr = Tp - Tq;
			 Tm = Tk - Tl;
			 Tv = Tt + Tu;
		    }
		    Rp[0] = T3 + T6;
		    Rm[0] = Tj + Tm;
		    Ts = T7 * Tr;
		    Ip[0] = FNMS(Ta, Tv, Ts);
		    Tw = T7 * Tv;
		    Im[0] = FMA(Ta, Tr, Tw);
		    TA = T8 * Tz;
		    Im[WS(rs, 1)] = FMA(Tb, Tx, TA);
		    {
			 E Ty, Te, To, Tn;
			 Ty = T8 * Tx;
			 Ip[WS(rs, 1)] = FNMS(Tb, Tz, Ty);
			 Te = Tc * Td;
			 To = Tg * Td;
			 Tn = Tj - Tm;
			 Rp[WS(rs, 1)] = FNMS(Tg, Tn, Te);
			 Rm[WS(rs, 1)] = FMA(Tc, Tn, To);
		    }
	       }
	  }
     }
}

static const tw_instr twinstr[] = {
     { TW_CEXP, 1, 1 },
     { TW_CEXP, 1, 3 },
     { TW_NEXT, 1, 0 }
};

static const hc2c_desc desc = { 4, "hc2cb2_4", twinstr, &GENUS, { 16, 8, 8, 0 } };

void X(codelet_hc2cb2_4) (planner *p) {
     X(khc2c_register) (p, hc2cb2_4, &desc, HC2C_VIA_RDFT);
}
#else

/* Generated by: ../../../genfft/gen_hc2c.native -compact -variables 4 -pipeline-latency 4 -sign 1 -twiddle-log3 -precompute-twiddles -n 4 -dif -name hc2cb2_4 -include rdft/scalar/hc2cb.h */

/*
 * This function contains 24 FP additions, 16 FP multiplications,
 * (or, 16 additions, 8 multiplications, 8 fused multiply/add),
 * 21 stack variables, 0 constants, and 16 memory accesses
 */
#include "hc2cb.h"

static void hc2cb2_4(R *Rp, R *Ip, R *Rm, R *Im, const R *W, stride rs, INT mb, INT me, INT ms)
{
     {
	  INT m;
	  for (m = mb, W = W + ((mb - 1) * 4); m < me; m = m + 1, Rp = Rp + ms, Ip = Ip + ms, Rm = Rm - ms, Im = Im - ms, W = W + 4, MAKE_VOLATILE_STRIDE(16, rs)) {
	       E T7, T9, T8, Ta, Tb, Td;
	       T7 = W[0];
	       T9 = W[1];
	       T8 = W[2];
	       Ta = W[3];
	       Tb = FMA(T7, T8, T9 * Ta);
	       Td = FNMS(T9, T8, T7 * Ta);
	       {
		    E T3, Tl, Tg, Tp, T6, To, Tj, Tm, Tc, Tk;
		    {
			 E T1, T2, Te, Tf;
			 T1 = Rp[0];
			 T2 = Rm[WS(rs, 1)];
			 T3 = T1 + T2;
			 Tl = T1 - T2;
			 Te = Ip[0];
			 Tf = Im[WS(rs, 1)];
			 Tg = Te - Tf;
			 Tp = Te + Tf;
		    }
		    {
			 E T4, T5, Th, Ti;
			 T4 = Rp[WS(rs, 1)];
			 T5 = Rm[0];
			 T6 = T4 + T5;
			 To = T4 - T5;
			 Th = Ip[WS(rs, 1)];
			 Ti = Im[0];
			 Tj = Th - Ti;
			 Tm = Th + Ti;
		    }
		    Rp[0] = T3 + T6;
		    Rm[0] = Tg + Tj;
		    Tc = T3 - T6;
		    Tk = Tg - Tj;
		    Rp[WS(rs, 1)] = FNMS(Td, Tk, Tb * Tc);
		    Rm[WS(rs, 1)] = FMA(Td, Tc, Tb * Tk);
		    {
			 E Tn, Tq, Tr, Ts;
			 Tn = Tl - Tm;
			 Tq = To + Tp;
			 Ip[0] = FNMS(T9, Tq, T7 * Tn);
			 Im[0] = FMA(T7, Tq, T9 * Tn);
			 Tr = Tl + Tm;
			 Ts = Tp - To;
			 Ip[WS(rs, 1)] = FNMS(Ta, Ts, T8 * Tr);
			 Im[WS(rs, 1)] = FMA(T8, Ts, Ta * Tr);
		    }
	       }
	  }
     }
}

static const tw_instr twinstr[] = {
     { TW_CEXP, 1, 1 },
     { TW_CEXP, 1, 3 },
     { TW_NEXT, 1, 0 }
};

static const hc2c_desc desc = { 4, "hc2cb2_4", twinstr, &GENUS, { 16, 8, 8, 0 } };

void X(codelet_hc2cb2_4) (planner *p) {
     X(khc2c_register) (p, hc2cb2_4, &desc, HC2C_VIA_RDFT);
}
#endif
