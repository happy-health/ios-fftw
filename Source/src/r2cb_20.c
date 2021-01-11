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
/* Generated on Thu Dec 10 07:06:26 EST 2020 */

#include "codelet-rdft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_r2cb.native -fma -compact -variables 4 -pipeline-latency 4 -sign 1 -n 20 -name r2cb_20 -include rdft/scalar/r2cb.h */

/*
 * This function contains 86 FP additions, 44 FP multiplications,
 * (or, 42 additions, 0 multiplications, 44 fused multiply/add),
 * 50 stack variables, 5 constants, and 40 memory accesses
 */
#include "r2cb.h"

static void r2cb_20(R *R0, R *R1, R *Cr, R *Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
     DK(KP1_902113032, +1.902113032590307144232878666758764286811397268);
     DK(KP1_118033988, +1.118033988749894848204586834365638117720309180);
     DK(KP500000000, +0.500000000000000000000000000000000000000000000);
     DK(KP618033988, +0.618033988749894848204586834365638117720309180);
     DK(KP2_000000000, +2.000000000000000000000000000000000000000000000);
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, R0 = R0 + ovs, R1 = R1 + ovs, Cr = Cr + ivs, Ci = Ci + ivs, MAKE_VOLATILE_STRIDE(80, rs), MAKE_VOLATILE_STRIDE(80, csr), MAKE_VOLATILE_STRIDE(80, csi)) {
	       E T5, TD, Tl, Tr, TO, T1l, T1d, T10, T1k, TT, T11, T1a, Tc, Tj, Tk;
	       E Tw, TB, TC, Tm, Tn, To, TE, TF, TG;
	       {
		    E T4, Tq, T3, Tp, T1, T2;
		    T4 = Cr[WS(csr, 5)];
		    Tq = Ci[WS(csi, 5)];
		    T1 = Cr[0];
		    T2 = Cr[WS(csr, 10)];
		    T3 = T1 + T2;
		    Tp = T1 - T2;
		    T5 = FNMS(KP2_000000000, T4, T3);
		    TD = FNMS(KP2_000000000, Tq, Tp);
		    Tl = FMA(KP2_000000000, T4, T3);
		    Tr = FMA(KP2_000000000, Tq, Tp);
	       }
	       {
		    E T8, Ts, TR, T19, Tb, T18, Tv, TS, Tf, Tx, TM, T1c, Ti, T1b, TA;
		    E TN;
		    {
			 E T6, T7, TP, TQ;
			 T6 = Cr[WS(csr, 4)];
			 T7 = Cr[WS(csr, 6)];
			 T8 = T6 + T7;
			 Ts = T6 - T7;
			 TP = Ci[WS(csi, 4)];
			 TQ = Ci[WS(csi, 6)];
			 TR = TP - TQ;
			 T19 = TP + TQ;
		    }
		    {
			 E T9, Ta, Tt, Tu;
			 T9 = Cr[WS(csr, 9)];
			 Ta = Cr[WS(csr, 1)];
			 Tb = T9 + Ta;
			 T18 = T9 - Ta;
			 Tt = Ci[WS(csi, 9)];
			 Tu = Ci[WS(csi, 1)];
			 Tv = Tt + Tu;
			 TS = Tt - Tu;
		    }
		    {
			 E Td, Te, TK, TL;
			 Td = Cr[WS(csr, 8)];
			 Te = Cr[WS(csr, 2)];
			 Tf = Td + Te;
			 Tx = Td - Te;
			 TK = Ci[WS(csi, 8)];
			 TL = Ci[WS(csi, 2)];
			 TM = TK - TL;
			 T1c = TK + TL;
		    }
		    {
			 E Tg, Th, Ty, Tz;
			 Tg = Cr[WS(csr, 7)];
			 Th = Cr[WS(csr, 3)];
			 Ti = Tg + Th;
			 T1b = Tg - Th;
			 Ty = Ci[WS(csi, 7)];
			 Tz = Ci[WS(csi, 3)];
			 TA = Ty + Tz;
			 TN = Tz - Ty;
		    }
		    TO = TM - TN;
		    T1l = T19 - T18;
		    T1d = T1b + T1c;
		    T10 = TS + TR;
		    T1k = T1c - T1b;
		    TT = TR - TS;
		    T11 = TN + TM;
		    T1a = T18 + T19;
		    Tc = T8 - Tb;
		    Tj = Tf - Ti;
		    Tk = Tc + Tj;
		    Tw = Ts + Tv;
		    TB = Tx - TA;
		    TC = Tw + TB;
		    Tm = T8 + Tb;
		    Tn = Tf + Ti;
		    To = Tm + Tn;
		    TE = Ts - Tv;
		    TF = Tx + TA;
		    TG = TE + TF;
	       }
	       R0[WS(rs, 5)] = FMA(KP2_000000000, Tk, T5);
	       R1[WS(rs, 7)] = FMA(KP2_000000000, TC, Tr);
	       R1[WS(rs, 2)] = FMA(KP2_000000000, TG, TD);
	       R0[0] = FMA(KP2_000000000, To, Tl);
	       {
		    E TU, TW, TJ, TV, TH, TI;
		    TU = FNMS(KP618033988, TT, TO);
		    TW = FMA(KP618033988, TO, TT);
		    TH = FNMS(KP500000000, Tk, T5);
		    TI = Tc - Tj;
		    TJ = FNMS(KP1_118033988, TI, TH);
		    TV = FMA(KP1_118033988, TI, TH);
		    R0[WS(rs, 9)] = FNMS(KP1_902113032, TU, TJ);
		    R0[WS(rs, 7)] = FMA(KP1_902113032, TW, TV);
		    R0[WS(rs, 1)] = FMA(KP1_902113032, TU, TJ);
		    R0[WS(rs, 3)] = FNMS(KP1_902113032, TW, TV);
	       }
	       {
		    E T1e, T1g, T17, T1f, T15, T16;
		    T1e = FMA(KP618033988, T1d, T1a);
		    T1g = FNMS(KP618033988, T1a, T1d);
		    T15 = FNMS(KP500000000, TG, TD);
		    T16 = TE - TF;
		    T17 = FMA(KP1_118033988, T16, T15);
		    T1f = FNMS(KP1_118033988, T16, T15);
		    R1[0] = FNMS(KP1_902113032, T1e, T17);
		    R1[WS(rs, 8)] = FMA(KP1_902113032, T1g, T1f);
		    R1[WS(rs, 4)] = FMA(KP1_902113032, T1e, T17);
		    R1[WS(rs, 6)] = FNMS(KP1_902113032, T1g, T1f);
	       }
	       {
		    E T1m, T1o, T1j, T1n, T1h, T1i;
		    T1m = FNMS(KP618033988, T1l, T1k);
		    T1o = FMA(KP618033988, T1k, T1l);
		    T1h = FNMS(KP500000000, TC, Tr);
		    T1i = Tw - TB;
		    T1j = FNMS(KP1_118033988, T1i, T1h);
		    T1n = FMA(KP1_118033988, T1i, T1h);
		    R1[WS(rs, 1)] = FNMS(KP1_902113032, T1m, T1j);
		    R1[WS(rs, 9)] = FMA(KP1_902113032, T1o, T1n);
		    R1[WS(rs, 3)] = FMA(KP1_902113032, T1m, T1j);
		    R1[WS(rs, 5)] = FNMS(KP1_902113032, T1o, T1n);
	       }
	       {
		    E T12, T14, TZ, T13, TX, TY;
		    T12 = FMA(KP618033988, T11, T10);
		    T14 = FNMS(KP618033988, T10, T11);
		    TX = FNMS(KP500000000, To, Tl);
		    TY = Tm - Tn;
		    TZ = FMA(KP1_118033988, TY, TX);
		    T13 = FNMS(KP1_118033988, TY, TX);
		    R0[WS(rs, 8)] = FNMS(KP1_902113032, T12, TZ);
		    R0[WS(rs, 6)] = FMA(KP1_902113032, T14, T13);
		    R0[WS(rs, 2)] = FMA(KP1_902113032, T12, TZ);
		    R0[WS(rs, 4)] = FNMS(KP1_902113032, T14, T13);
	       }
	  }
     }
}

static const kr2c_desc desc = { 20, "r2cb_20", { 42, 0, 44, 0 }, &GENUS };

void X(codelet_r2cb_20) (planner *p) { X(kr2c_register) (p, r2cb_20, &desc);
}

#else

/* Generated by: ../../../genfft/gen_r2cb.native -compact -variables 4 -pipeline-latency 4 -sign 1 -n 20 -name r2cb_20 -include rdft/scalar/r2cb.h */

/*
 * This function contains 86 FP additions, 30 FP multiplications,
 * (or, 70 additions, 14 multiplications, 16 fused multiply/add),
 * 50 stack variables, 5 constants, and 40 memory accesses
 */
#include "r2cb.h"

static void r2cb_20(R *R0, R *R1, R *Cr, R *Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
     DK(KP1_118033988, +1.118033988749894848204586834365638117720309180);
     DK(KP500000000, +0.500000000000000000000000000000000000000000000);
     DK(KP1_902113032, +1.902113032590307144232878666758764286811397268);
     DK(KP1_175570504, +1.175570504584946258337411909278145537195304875);
     DK(KP2_000000000, +2.000000000000000000000000000000000000000000000);
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, R0 = R0 + ovs, R1 = R1 + ovs, Cr = Cr + ivs, Ci = Ci + ivs, MAKE_VOLATILE_STRIDE(80, rs), MAKE_VOLATILE_STRIDE(80, csr), MAKE_VOLATILE_STRIDE(80, csi)) {
	       E T6, TF, Tm, Tt, TQ, T1n, T1f, T12, T1m, TV, T13, T1c, Td, Tk, Tl;
	       E Ty, TD, TE, Tn, To, Tp, TG, TH, TI;
	       {
		    E T5, Ts, T3, Tq;
		    {
			 E T4, Tr, T1, T2;
			 T4 = Cr[WS(csr, 5)];
			 T5 = KP2_000000000 * T4;
			 Tr = Ci[WS(csi, 5)];
			 Ts = KP2_000000000 * Tr;
			 T1 = Cr[0];
			 T2 = Cr[WS(csr, 10)];
			 T3 = T1 + T2;
			 Tq = T1 - T2;
		    }
		    T6 = T3 - T5;
		    TF = Tq - Ts;
		    Tm = T3 + T5;
		    Tt = Tq + Ts;
	       }
	       {
		    E T9, Tu, TO, T1b, Tc, T1a, Tx, TP, Tg, Tz, TT, T1e, Tj, T1d, TC;
		    E TU;
		    {
			 E T7, T8, TM, TN;
			 T7 = Cr[WS(csr, 4)];
			 T8 = Cr[WS(csr, 6)];
			 T9 = T7 + T8;
			 Tu = T7 - T8;
			 TM = Ci[WS(csi, 4)];
			 TN = Ci[WS(csi, 6)];
			 TO = TM - TN;
			 T1b = TM + TN;
		    }
		    {
			 E Ta, Tb, Tv, Tw;
			 Ta = Cr[WS(csr, 9)];
			 Tb = Cr[WS(csr, 1)];
			 Tc = Ta + Tb;
			 T1a = Ta - Tb;
			 Tv = Ci[WS(csi, 9)];
			 Tw = Ci[WS(csi, 1)];
			 Tx = Tv + Tw;
			 TP = Tv - Tw;
		    }
		    {
			 E Te, Tf, TR, TS;
			 Te = Cr[WS(csr, 8)];
			 Tf = Cr[WS(csr, 2)];
			 Tg = Te + Tf;
			 Tz = Te - Tf;
			 TR = Ci[WS(csi, 8)];
			 TS = Ci[WS(csi, 2)];
			 TT = TR - TS;
			 T1e = TR + TS;
		    }
		    {
			 E Th, Ti, TA, TB;
			 Th = Cr[WS(csr, 7)];
			 Ti = Cr[WS(csr, 3)];
			 Tj = Th + Ti;
			 T1d = Th - Ti;
			 TA = Ci[WS(csi, 7)];
			 TB = Ci[WS(csi, 3)];
			 TC = TA + TB;
			 TU = TB - TA;
		    }
		    TQ = TO - TP;
		    T1n = T1e - T1d;
		    T1f = T1d + T1e;
		    T12 = TP + TO;
		    T1m = T1b - T1a;
		    TV = TT - TU;
		    T13 = TU + TT;
		    T1c = T1a + T1b;
		    Td = T9 - Tc;
		    Tk = Tg - Tj;
		    Tl = Td + Tk;
		    Ty = Tu + Tx;
		    TD = Tz - TC;
		    TE = Ty + TD;
		    Tn = T9 + Tc;
		    To = Tg + Tj;
		    Tp = Tn + To;
		    TG = Tu - Tx;
		    TH = Tz + TC;
		    TI = TG + TH;
	       }
	       R0[WS(rs, 5)] = FMA(KP2_000000000, Tl, T6);
	       R1[WS(rs, 7)] = FMA(KP2_000000000, TE, Tt);
	       R1[WS(rs, 2)] = FMA(KP2_000000000, TI, TF);
	       R0[0] = FMA(KP2_000000000, Tp, Tm);
	       {
		    E TW, TY, TL, TX, TJ, TK;
		    TW = FNMS(KP1_902113032, TV, KP1_175570504 * TQ);
		    TY = FMA(KP1_902113032, TQ, KP1_175570504 * TV);
		    TJ = FNMS(KP500000000, Tl, T6);
		    TK = KP1_118033988 * (Td - Tk);
		    TL = TJ - TK;
		    TX = TK + TJ;
		    R0[WS(rs, 1)] = TL - TW;
		    R0[WS(rs, 7)] = TX + TY;
		    R0[WS(rs, 9)] = TL + TW;
		    R0[WS(rs, 3)] = TX - TY;
	       }
	       {
		    E T1g, T1i, T19, T1h, T17, T18;
		    T1g = FNMS(KP1_902113032, T1f, KP1_175570504 * T1c);
		    T1i = FMA(KP1_902113032, T1c, KP1_175570504 * T1f);
		    T17 = FNMS(KP500000000, TI, TF);
		    T18 = KP1_118033988 * (TG - TH);
		    T19 = T17 - T18;
		    T1h = T18 + T17;
		    R1[WS(rs, 8)] = T19 - T1g;
		    R1[WS(rs, 4)] = T1h + T1i;
		    R1[WS(rs, 6)] = T19 + T1g;
		    R1[0] = T1h - T1i;
	       }
	       {
		    E T1o, T1q, T1l, T1p, T1j, T1k;
		    T1o = FNMS(KP1_902113032, T1n, KP1_175570504 * T1m);
		    T1q = FMA(KP1_902113032, T1m, KP1_175570504 * T1n);
		    T1j = FNMS(KP500000000, TE, Tt);
		    T1k = KP1_118033988 * (Ty - TD);
		    T1l = T1j - T1k;
		    T1p = T1k + T1j;
		    R1[WS(rs, 3)] = T1l - T1o;
		    R1[WS(rs, 9)] = T1p + T1q;
		    R1[WS(rs, 1)] = T1l + T1o;
		    R1[WS(rs, 5)] = T1p - T1q;
	       }
	       {
		    E T14, T16, T11, T15, TZ, T10;
		    T14 = FNMS(KP1_902113032, T13, KP1_175570504 * T12);
		    T16 = FMA(KP1_902113032, T12, KP1_175570504 * T13);
		    TZ = FNMS(KP500000000, Tp, Tm);
		    T10 = KP1_118033988 * (Tn - To);
		    T11 = TZ - T10;
		    T15 = T10 + TZ;
		    R0[WS(rs, 6)] = T11 - T14;
		    R0[WS(rs, 2)] = T15 + T16;
		    R0[WS(rs, 4)] = T11 + T14;
		    R0[WS(rs, 8)] = T15 - T16;
	       }
	  }
     }
}

static const kr2c_desc desc = { 20, "r2cb_20", { 70, 14, 16, 0 }, &GENUS };

void X(codelet_r2cb_20) (planner *p) { X(kr2c_register) (p, r2cb_20, &desc);
}

#endif
