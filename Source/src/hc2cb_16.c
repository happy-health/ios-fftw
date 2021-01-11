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
/* Generated on Thu Dec 10 07:06:44 EST 2020 */

#include "codelet-rdft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_hc2c.native -fma -compact -variables 4 -pipeline-latency 4 -sign 1 -n 16 -dif -name hc2cb_16 -include rdft/scalar/hc2cb.h */

/*
 * This function contains 174 FP additions, 100 FP multiplications,
 * (or, 104 additions, 30 multiplications, 70 fused multiply/add),
 * 63 stack variables, 3 constants, and 64 memory accesses
 */
#include "hc2cb.h"

static void hc2cb_16(R *Rp, R *Ip, R *Rm, R *Im, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DK(KP923879532, +0.923879532511286756128183189396788286822416626);
     DK(KP707106781, +0.707106781186547524400844362104849039284835938);
     DK(KP414213562, +0.414213562373095048801688724209698078569671875);
     {
	  INT m;
	  for (m = mb, W = W + ((mb - 1) * 30); m < me; m = m + 1, Rp = Rp + ms, Ip = Ip + ms, Rm = Rm - ms, Im = Im - ms, W = W + 30, MAKE_VOLATILE_STRIDE(64, rs)) {
	       E TA, T1O, T21, T1h, T2P, T2S, T3b, T3p, T3q, T3D, T1k, T1P, Tf, T3y, T2A;
	       E T36, TL, T22, T3s, T3t, T3z, T2F, T2U, T2K, T2V, Tu, T3E, TX, T1n, T1T;
	       E T24, T1W, T25, T18, T1m;
	       {
		    E T3, Tw, T1g, T2Q, T6, T1d, Tz, T2R, Ta, TB, TE, T2y, Td, TG, TJ;
		    E T2x;
		    {
			 E T1, T2, T1e, T1f;
			 T1 = Rp[0];
			 T2 = Rm[WS(rs, 7)];
			 T3 = T1 + T2;
			 Tw = T1 - T2;
			 T1e = Ip[0];
			 T1f = Im[WS(rs, 7)];
			 T1g = T1e + T1f;
			 T2Q = T1e - T1f;
		    }
		    {
			 E T4, T5, Tx, Ty;
			 T4 = Rp[WS(rs, 4)];
			 T5 = Rm[WS(rs, 3)];
			 T6 = T4 + T5;
			 T1d = T4 - T5;
			 Tx = Ip[WS(rs, 4)];
			 Ty = Im[WS(rs, 3)];
			 Tz = Tx + Ty;
			 T2R = Tx - Ty;
		    }
		    {
			 E T8, T9, TC, TD;
			 T8 = Rp[WS(rs, 2)];
			 T9 = Rm[WS(rs, 5)];
			 Ta = T8 + T9;
			 TB = T8 - T9;
			 TC = Ip[WS(rs, 2)];
			 TD = Im[WS(rs, 5)];
			 TE = TC + TD;
			 T2y = TC - TD;
		    }
		    {
			 E Tb, Tc, TH, TI;
			 Tb = Rm[WS(rs, 1)];
			 Tc = Rp[WS(rs, 6)];
			 Td = Tb + Tc;
			 TG = Tb - Tc;
			 TH = Ip[WS(rs, 6)];
			 TI = Im[WS(rs, 1)];
			 TJ = TH + TI;
			 T2x = TH - TI;
		    }
		    TA = Tw - Tz;
		    T1O = Tw + Tz;
		    T21 = T1g - T1d;
		    T1h = T1d + T1g;
		    T2P = Ta - Td;
		    T2S = T2Q - T2R;
		    T3b = T2S - T2P;
		    {
			 E T1i, T1j, T7, Te;
			 T3p = T2Q + T2R;
			 T3q = T2y + T2x;
			 T3D = T3p - T3q;
			 T1i = TB + TE;
			 T1j = TG + TJ;
			 T1k = T1i - T1j;
			 T1P = T1i + T1j;
			 T7 = T3 + T6;
			 Te = Ta + Td;
			 Tf = T7 + Te;
			 T3y = T7 - Te;
			 {
			      E T2w, T2z, TF, TK;
			      T2w = T3 - T6;
			      T2z = T2x - T2y;
			      T2A = T2w + T2z;
			      T36 = T2w - T2z;
			      TF = TB - TE;
			      TK = TG - TJ;
			      TL = TF + TK;
			      T22 = TF - TK;
			 }
		    }
	       }
	       {
		    E Ti, T13, T11, T2C, Tl, TY, T16, T2D, Tp, TS, TQ, T2H, Ts, TN, TV;
		    E T2I, T2B, T2E;
		    {
			 E Tg, Th, TZ, T10;
			 Tg = Rp[WS(rs, 1)];
			 Th = Rm[WS(rs, 6)];
			 Ti = Tg + Th;
			 T13 = Tg - Th;
			 TZ = Ip[WS(rs, 1)];
			 T10 = Im[WS(rs, 6)];
			 T11 = TZ + T10;
			 T2C = TZ - T10;
		    }
		    {
			 E Tj, Tk, T14, T15;
			 Tj = Rp[WS(rs, 5)];
			 Tk = Rm[WS(rs, 2)];
			 Tl = Tj + Tk;
			 TY = Tj - Tk;
			 T14 = Ip[WS(rs, 5)];
			 T15 = Im[WS(rs, 2)];
			 T16 = T14 + T15;
			 T2D = T14 - T15;
		    }
		    {
			 E Tn, To, TO, TP;
			 Tn = Rm[0];
			 To = Rp[WS(rs, 7)];
			 Tp = Tn + To;
			 TS = Tn - To;
			 TO = Ip[WS(rs, 7)];
			 TP = Im[0];
			 TQ = TO + TP;
			 T2H = TO - TP;
		    }
		    {
			 E Tq, Tr, TT, TU;
			 Tq = Rp[WS(rs, 3)];
			 Tr = Rm[WS(rs, 4)];
			 Ts = Tq + Tr;
			 TN = Tq - Tr;
			 TT = Ip[WS(rs, 3)];
			 TU = Im[WS(rs, 4)];
			 TV = TT + TU;
			 T2I = TT - TU;
		    }
		    T3s = T2C + T2D;
		    T3t = T2H + T2I;
		    T3z = T3t - T3s;
		    T2B = Ti - Tl;
		    T2E = T2C - T2D;
		    T2F = T2B - T2E;
		    T2U = T2B + T2E;
		    {
			 E T2G, T2J, Tm, Tt;
			 T2G = Tp - Ts;
			 T2J = T2H - T2I;
			 T2K = T2G + T2J;
			 T2V = T2J - T2G;
			 Tm = Ti + Tl;
			 Tt = Tp + Ts;
			 Tu = Tm + Tt;
			 T3E = Tm - Tt;
		    }
		    {
			 E TR, TW, T1R, T1S;
			 TR = TN - TQ;
			 TW = TS - TV;
			 TX = FNMS(KP414213562, TW, TR);
			 T1n = FMA(KP414213562, TR, TW);
			 T1R = T11 - TY;
			 T1S = T13 + T16;
			 T1T = FNMS(KP414213562, T1S, T1R);
			 T24 = FMA(KP414213562, T1R, T1S);
		    }
		    {
			 E T1U, T1V, T12, T17;
			 T1U = TN + TQ;
			 T1V = TS + TV;
			 T1W = FNMS(KP414213562, T1V, T1U);
			 T25 = FMA(KP414213562, T1U, T1V);
			 T12 = TY + T11;
			 T17 = T13 - T16;
			 T18 = FMA(KP414213562, T17, T12);
			 T1m = FNMS(KP414213562, T12, T17);
		    }
	       }
	       Rp[0] = Tf + Tu;
	       {
		    E T3r, T3u, T3v, T3l, T3n, T3o, T3w, T3m;
		    T3r = T3p + T3q;
		    T3u = T3s + T3t;
		    T3v = T3r - T3u;
		    T3m = Tf - Tu;
		    T3l = W[14];
		    T3n = T3l * T3m;
		    T3o = W[15];
		    T3w = T3o * T3m;
		    Rm[0] = T3r + T3u;
		    Rm[WS(rs, 4)] = FMA(T3l, T3v, T3w);
		    Rp[WS(rs, 4)] = FNMS(T3o, T3v, T3n);
	       }
	       {
		    E T3A, T3F, T3B, T3G, T3x, T3C;
		    T3A = T3y - T3z;
		    T3F = T3D - T3E;
		    T3x = W[22];
		    T3B = T3x * T3A;
		    T3G = T3x * T3F;
		    T3C = W[23];
		    Rp[WS(rs, 6)] = FNMS(T3C, T3F, T3B);
		    Rm[WS(rs, 6)] = FMA(T3C, T3A, T3G);
	       }
	       {
		    E T3I, T3L, T3J, T3M, T3H, T3K;
		    T3I = T3y + T3z;
		    T3L = T3E + T3D;
		    T3H = W[6];
		    T3J = T3H * T3I;
		    T3M = T3H * T3L;
		    T3K = W[7];
		    Rp[WS(rs, 2)] = FNMS(T3K, T3L, T3J);
		    Rm[WS(rs, 2)] = FMA(T3K, T3I, T3M);
	       }
	       {
		    E T38, T3g, T3d, T3j, T37, T3c;
		    T37 = T2V - T2U;
		    T38 = FNMS(KP707106781, T37, T36);
		    T3g = FMA(KP707106781, T37, T36);
		    T3c = T2F - T2K;
		    T3d = FNMS(KP707106781, T3c, T3b);
		    T3j = FMA(KP707106781, T3c, T3b);
		    {
			 E T39, T3e, T35, T3a;
			 T35 = W[26];
			 T39 = T35 * T38;
			 T3e = T35 * T3d;
			 T3a = W[27];
			 Rp[WS(rs, 7)] = FNMS(T3a, T3d, T39);
			 Rm[WS(rs, 7)] = FMA(T3a, T38, T3e);
		    }
		    {
			 E T3h, T3k, T3f, T3i;
			 T3f = W[10];
			 T3h = T3f * T3g;
			 T3k = T3f * T3j;
			 T3i = W[11];
			 Rp[WS(rs, 3)] = FNMS(T3i, T3j, T3h);
			 Rm[WS(rs, 3)] = FMA(T3i, T3g, T3k);
		    }
	       }
	       {
		    E T2M, T30, T2X, T33, T2L, T2T, T2W;
		    T2L = T2F + T2K;
		    T2M = FNMS(KP707106781, T2L, T2A);
		    T30 = FMA(KP707106781, T2L, T2A);
		    T2T = T2P + T2S;
		    T2W = T2U + T2V;
		    T2X = FNMS(KP707106781, T2W, T2T);
		    T33 = FMA(KP707106781, T2W, T2T);
		    {
			 E T2v, T2N, T2O, T2Y;
			 T2v = W[18];
			 T2N = T2v * T2M;
			 T2O = W[19];
			 T2Y = T2O * T2M;
			 Rp[WS(rs, 5)] = FNMS(T2O, T2X, T2N);
			 Rm[WS(rs, 5)] = FMA(T2v, T2X, T2Y);
		    }
		    {
			 E T2Z, T31, T32, T34;
			 T2Z = W[2];
			 T31 = T2Z * T30;
			 T32 = W[3];
			 T34 = T32 * T30;
			 Rp[WS(rs, 1)] = FNMS(T32, T33, T31);
			 Rm[WS(rs, 1)] = FMA(T2Z, T33, T34);
		    }
	       }
	       {
		    E T1Y, T2a, T27, T2d;
		    {
			 E T1Q, T1X, T23, T26;
			 T1Q = FNMS(KP707106781, T1P, T1O);
			 T1X = T1T + T1W;
			 T1Y = FMA(KP923879532, T1X, T1Q);
			 T2a = FNMS(KP923879532, T1X, T1Q);
			 T23 = FMA(KP707106781, T22, T21);
			 T26 = T24 - T25;
			 T27 = FNMS(KP923879532, T26, T23);
			 T2d = FMA(KP923879532, T26, T23);
		    }
		    {
			 E T1N, T1Z, T20, T28;
			 T1N = W[20];
			 T1Z = T1N * T1Y;
			 T20 = W[21];
			 T28 = T20 * T1Y;
			 Ip[WS(rs, 5)] = FNMS(T20, T27, T1Z);
			 Im[WS(rs, 5)] = FMA(T1N, T27, T28);
		    }
		    {
			 E T29, T2b, T2c, T2e;
			 T29 = W[4];
			 T2b = T29 * T2a;
			 T2c = W[5];
			 T2e = T2c * T2a;
			 Ip[WS(rs, 1)] = FNMS(T2c, T2d, T2b);
			 Im[WS(rs, 1)] = FMA(T29, T2d, T2e);
		    }
	       }
	       {
		    E T1a, T1s, T1p, T1v;
		    {
			 E TM, T19, T1l, T1o;
			 TM = FNMS(KP707106781, TL, TA);
			 T19 = TX - T18;
			 T1a = FNMS(KP923879532, T19, TM);
			 T1s = FMA(KP923879532, T19, TM);
			 T1l = FNMS(KP707106781, T1k, T1h);
			 T1o = T1m - T1n;
			 T1p = FNMS(KP923879532, T1o, T1l);
			 T1v = FMA(KP923879532, T1o, T1l);
		    }
		    {
			 E Tv, T1b, T1c, T1q;
			 Tv = W[24];
			 T1b = Tv * T1a;
			 T1c = W[25];
			 T1q = T1c * T1a;
			 Ip[WS(rs, 6)] = FNMS(T1c, T1p, T1b);
			 Im[WS(rs, 6)] = FMA(Tv, T1p, T1q);
		    }
		    {
			 E T1r, T1t, T1u, T1w;
			 T1r = W[8];
			 T1t = T1r * T1s;
			 T1u = W[9];
			 T1w = T1u * T1s;
			 Ip[WS(rs, 2)] = FNMS(T1u, T1v, T1t);
			 Im[WS(rs, 2)] = FMA(T1r, T1v, T1w);
		    }
	       }
	       {
		    E T2i, T2q, T2n, T2t;
		    {
			 E T2g, T2h, T2l, T2m;
			 T2g = FMA(KP707106781, T1P, T1O);
			 T2h = T24 + T25;
			 T2i = FNMS(KP923879532, T2h, T2g);
			 T2q = FMA(KP923879532, T2h, T2g);
			 T2l = FNMS(KP707106781, T22, T21);
			 T2m = T1W - T1T;
			 T2n = FMA(KP923879532, T2m, T2l);
			 T2t = FNMS(KP923879532, T2m, T2l);
		    }
		    {
			 E T2j, T2o, T2f, T2k;
			 T2f = W[12];
			 T2j = T2f * T2i;
			 T2o = T2f * T2n;
			 T2k = W[13];
			 Ip[WS(rs, 3)] = FNMS(T2k, T2n, T2j);
			 Im[WS(rs, 3)] = FMA(T2k, T2i, T2o);
		    }
		    {
			 E T2r, T2u, T2p, T2s;
			 T2p = W[28];
			 T2r = T2p * T2q;
			 T2u = T2p * T2t;
			 T2s = W[29];
			 Ip[WS(rs, 7)] = FNMS(T2s, T2t, T2r);
			 Im[WS(rs, 7)] = FMA(T2s, T2q, T2u);
		    }
	       }
	       {
		    E T1A, T1I, T1F, T1L;
		    {
			 E T1y, T1z, T1D, T1E;
			 T1y = FMA(KP707106781, TL, TA);
			 T1z = T1m + T1n;
			 T1A = FNMS(KP923879532, T1z, T1y);
			 T1I = FMA(KP923879532, T1z, T1y);
			 T1D = FMA(KP707106781, T1k, T1h);
			 T1E = T18 + TX;
			 T1F = FNMS(KP923879532, T1E, T1D);
			 T1L = FMA(KP923879532, T1E, T1D);
		    }
		    {
			 E T1B, T1G, T1x, T1C;
			 T1x = W[16];
			 T1B = T1x * T1A;
			 T1G = T1x * T1F;
			 T1C = W[17];
			 Ip[WS(rs, 4)] = FNMS(T1C, T1F, T1B);
			 Im[WS(rs, 4)] = FMA(T1C, T1A, T1G);
		    }
		    {
			 E T1J, T1M, T1H, T1K;
			 T1H = W[0];
			 T1J = T1H * T1I;
			 T1M = T1H * T1L;
			 T1K = W[1];
			 Ip[0] = FNMS(T1K, T1L, T1J);
			 Im[0] = FMA(T1K, T1I, T1M);
		    }
	       }
	  }
     }
}

static const tw_instr twinstr[] = {
     { TW_FULL, 1, 16 },
     { TW_NEXT, 1, 0 }
};

static const hc2c_desc desc = { 16, "hc2cb_16", twinstr, &GENUS, { 104, 30, 70, 0 } };

void X(codelet_hc2cb_16) (planner *p) {
     X(khc2c_register) (p, hc2cb_16, &desc, HC2C_VIA_RDFT);
}
#else

/* Generated by: ../../../genfft/gen_hc2c.native -compact -variables 4 -pipeline-latency 4 -sign 1 -n 16 -dif -name hc2cb_16 -include rdft/scalar/hc2cb.h */

/*
 * This function contains 174 FP additions, 84 FP multiplications,
 * (or, 136 additions, 46 multiplications, 38 fused multiply/add),
 * 50 stack variables, 3 constants, and 64 memory accesses
 */
#include "hc2cb.h"

static void hc2cb_16(R *Rp, R *Ip, R *Rm, R *Im, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DK(KP382683432, +0.382683432365089771728459984030398866761344562);
     DK(KP923879532, +0.923879532511286756128183189396788286822416626);
     DK(KP707106781, +0.707106781186547524400844362104849039284835938);
     {
	  INT m;
	  for (m = mb, W = W + ((mb - 1) * 30); m < me; m = m + 1, Rp = Rp + ms, Ip = Ip + ms, Rm = Rm - ms, Im = Im - ms, W = W + 30, MAKE_VOLATILE_STRIDE(64, rs)) {
	       E T7, T2K, T2W, Tw, T17, T1S, T2k, T1w, Te, TD, T1x, T10, T2n, T2L, T1Z;
	       E T2X, Tm, T1z, TN, T19, T2e, T2p, T2P, T2Z, Tt, T1A, TW, T1a, T27, T2q;
	       E T2S, T30;
	       {
		    E T3, T1Q, T13, T2j, T6, T2i, T16, T1R;
		    {
			 E T1, T2, T11, T12;
			 T1 = Rp[0];
			 T2 = Rm[WS(rs, 7)];
			 T3 = T1 + T2;
			 T1Q = T1 - T2;
			 T11 = Ip[0];
			 T12 = Im[WS(rs, 7)];
			 T13 = T11 - T12;
			 T2j = T11 + T12;
		    }
		    {
			 E T4, T5, T14, T15;
			 T4 = Rp[WS(rs, 4)];
			 T5 = Rm[WS(rs, 3)];
			 T6 = T4 + T5;
			 T2i = T4 - T5;
			 T14 = Ip[WS(rs, 4)];
			 T15 = Im[WS(rs, 3)];
			 T16 = T14 - T15;
			 T1R = T14 + T15;
		    }
		    T7 = T3 + T6;
		    T2K = T1Q + T1R;
		    T2W = T2j - T2i;
		    Tw = T3 - T6;
		    T17 = T13 - T16;
		    T1S = T1Q - T1R;
		    T2k = T2i + T2j;
		    T1w = T13 + T16;
	       }
	       {
		    E Ta, T1T, TC, T1U, Td, T1W, Tz, T1X;
		    {
			 E T8, T9, TA, TB;
			 T8 = Rp[WS(rs, 2)];
			 T9 = Rm[WS(rs, 5)];
			 Ta = T8 + T9;
			 T1T = T8 - T9;
			 TA = Ip[WS(rs, 2)];
			 TB = Im[WS(rs, 5)];
			 TC = TA - TB;
			 T1U = TA + TB;
		    }
		    {
			 E Tb, Tc, Tx, Ty;
			 Tb = Rm[WS(rs, 1)];
			 Tc = Rp[WS(rs, 6)];
			 Td = Tb + Tc;
			 T1W = Tb - Tc;
			 Tx = Ip[WS(rs, 6)];
			 Ty = Im[WS(rs, 1)];
			 Tz = Tx - Ty;
			 T1X = Tx + Ty;
		    }
		    Te = Ta + Td;
		    TD = Tz - TC;
		    T1x = TC + Tz;
		    T10 = Ta - Td;
		    {
			 E T2l, T2m, T1V, T1Y;
			 T2l = T1T + T1U;
			 T2m = T1W + T1X;
			 T2n = KP707106781 * (T2l - T2m);
			 T2L = KP707106781 * (T2l + T2m);
			 T1V = T1T - T1U;
			 T1Y = T1W - T1X;
			 T1Z = KP707106781 * (T1V + T1Y);
			 T2X = KP707106781 * (T1V - T1Y);
		    }
	       }
	       {
		    E Ti, T2b, TI, T29, Tl, T28, TL, T2c, TF, TM;
		    {
			 E Tg, Th, TG, TH;
			 Tg = Rp[WS(rs, 1)];
			 Th = Rm[WS(rs, 6)];
			 Ti = Tg + Th;
			 T2b = Tg - Th;
			 TG = Ip[WS(rs, 1)];
			 TH = Im[WS(rs, 6)];
			 TI = TG - TH;
			 T29 = TG + TH;
		    }
		    {
			 E Tj, Tk, TJ, TK;
			 Tj = Rp[WS(rs, 5)];
			 Tk = Rm[WS(rs, 2)];
			 Tl = Tj + Tk;
			 T28 = Tj - Tk;
			 TJ = Ip[WS(rs, 5)];
			 TK = Im[WS(rs, 2)];
			 TL = TJ - TK;
			 T2c = TJ + TK;
		    }
		    Tm = Ti + Tl;
		    T1z = TI + TL;
		    TF = Ti - Tl;
		    TM = TI - TL;
		    TN = TF - TM;
		    T19 = TF + TM;
		    {
			 E T2a, T2d, T2N, T2O;
			 T2a = T28 + T29;
			 T2d = T2b - T2c;
			 T2e = FMA(KP923879532, T2a, KP382683432 * T2d);
			 T2p = FNMS(KP382683432, T2a, KP923879532 * T2d);
			 T2N = T2b + T2c;
			 T2O = T29 - T28;
			 T2P = FNMS(KP923879532, T2O, KP382683432 * T2N);
			 T2Z = FMA(KP382683432, T2O, KP923879532 * T2N);
		    }
	       }
	       {
		    E Tp, T24, TR, T22, Ts, T21, TU, T25, TO, TV;
		    {
			 E Tn, To, TP, TQ;
			 Tn = Rm[0];
			 To = Rp[WS(rs, 7)];
			 Tp = Tn + To;
			 T24 = Tn - To;
			 TP = Ip[WS(rs, 7)];
			 TQ = Im[0];
			 TR = TP - TQ;
			 T22 = TP + TQ;
		    }
		    {
			 E Tq, Tr, TS, TT;
			 Tq = Rp[WS(rs, 3)];
			 Tr = Rm[WS(rs, 4)];
			 Ts = Tq + Tr;
			 T21 = Tq - Tr;
			 TS = Ip[WS(rs, 3)];
			 TT = Im[WS(rs, 4)];
			 TU = TS - TT;
			 T25 = TS + TT;
		    }
		    Tt = Tp + Ts;
		    T1A = TR + TU;
		    TO = Tp - Ts;
		    TV = TR - TU;
		    TW = TO + TV;
		    T1a = TV - TO;
		    {
			 E T23, T26, T2Q, T2R;
			 T23 = T21 - T22;
			 T26 = T24 - T25;
			 T27 = FNMS(KP382683432, T26, KP923879532 * T23);
			 T2q = FMA(KP382683432, T23, KP923879532 * T26);
			 T2Q = T24 + T25;
			 T2R = T21 + T22;
			 T2S = FNMS(KP923879532, T2R, KP382683432 * T2Q);
			 T30 = FMA(KP382683432, T2R, KP923879532 * T2Q);
		    }
	       }
	       {
		    E Tf, Tu, T1u, T1y, T1B, T1C, T1t, T1v;
		    Tf = T7 + Te;
		    Tu = Tm + Tt;
		    T1u = Tf - Tu;
		    T1y = T1w + T1x;
		    T1B = T1z + T1A;
		    T1C = T1y - T1B;
		    Rp[0] = Tf + Tu;
		    Rm[0] = T1y + T1B;
		    T1t = W[14];
		    T1v = W[15];
		    Rp[WS(rs, 4)] = FNMS(T1v, T1C, T1t * T1u);
		    Rm[WS(rs, 4)] = FMA(T1v, T1u, T1t * T1C);
	       }
	       {
		    E T2U, T34, T32, T36;
		    {
			 E T2M, T2T, T2Y, T31;
			 T2M = T2K - T2L;
			 T2T = T2P + T2S;
			 T2U = T2M - T2T;
			 T34 = T2M + T2T;
			 T2Y = T2W + T2X;
			 T31 = T2Z - T30;
			 T32 = T2Y - T31;
			 T36 = T2Y + T31;
		    }
		    {
			 E T2J, T2V, T33, T35;
			 T2J = W[20];
			 T2V = W[21];
			 Ip[WS(rs, 5)] = FNMS(T2V, T32, T2J * T2U);
			 Im[WS(rs, 5)] = FMA(T2V, T2U, T2J * T32);
			 T33 = W[4];
			 T35 = W[5];
			 Ip[WS(rs, 1)] = FNMS(T35, T36, T33 * T34);
			 Im[WS(rs, 1)] = FMA(T35, T34, T33 * T36);
		    }
	       }
	       {
		    E T3a, T3g, T3e, T3i;
		    {
			 E T38, T39, T3c, T3d;
			 T38 = T2K + T2L;
			 T39 = T2Z + T30;
			 T3a = T38 - T39;
			 T3g = T38 + T39;
			 T3c = T2W - T2X;
			 T3d = T2P - T2S;
			 T3e = T3c + T3d;
			 T3i = T3c - T3d;
		    }
		    {
			 E T37, T3b, T3f, T3h;
			 T37 = W[12];
			 T3b = W[13];
			 Ip[WS(rs, 3)] = FNMS(T3b, T3e, T37 * T3a);
			 Im[WS(rs, 3)] = FMA(T37, T3e, T3b * T3a);
			 T3f = W[28];
			 T3h = W[29];
			 Ip[WS(rs, 7)] = FNMS(T3h, T3i, T3f * T3g);
			 Im[WS(rs, 7)] = FMA(T3f, T3i, T3h * T3g);
		    }
	       }
	       {
		    E TY, T1e, T1c, T1g;
		    {
			 E TE, TX, T18, T1b;
			 TE = Tw + TD;
			 TX = KP707106781 * (TN + TW);
			 TY = TE - TX;
			 T1e = TE + TX;
			 T18 = T10 + T17;
			 T1b = KP707106781 * (T19 + T1a);
			 T1c = T18 - T1b;
			 T1g = T18 + T1b;
		    }
		    {
			 E Tv, TZ, T1d, T1f;
			 Tv = W[18];
			 TZ = W[19];
			 Rp[WS(rs, 5)] = FNMS(TZ, T1c, Tv * TY);
			 Rm[WS(rs, 5)] = FMA(TZ, TY, Tv * T1c);
			 T1d = W[2];
			 T1f = W[3];
			 Rp[WS(rs, 1)] = FNMS(T1f, T1g, T1d * T1e);
			 Rm[WS(rs, 1)] = FMA(T1f, T1e, T1d * T1g);
		    }
	       }
	       {
		    E T1k, T1q, T1o, T1s;
		    {
			 E T1i, T1j, T1m, T1n;
			 T1i = Tw - TD;
			 T1j = KP707106781 * (T1a - T19);
			 T1k = T1i - T1j;
			 T1q = T1i + T1j;
			 T1m = T17 - T10;
			 T1n = KP707106781 * (TN - TW);
			 T1o = T1m - T1n;
			 T1s = T1m + T1n;
		    }
		    {
			 E T1h, T1l, T1p, T1r;
			 T1h = W[26];
			 T1l = W[27];
			 Rp[WS(rs, 7)] = FNMS(T1l, T1o, T1h * T1k);
			 Rm[WS(rs, 7)] = FMA(T1h, T1o, T1l * T1k);
			 T1p = W[10];
			 T1r = W[11];
			 Rp[WS(rs, 3)] = FNMS(T1r, T1s, T1p * T1q);
			 Rm[WS(rs, 3)] = FMA(T1p, T1s, T1r * T1q);
		    }
	       }
	       {
		    E T2g, T2u, T2s, T2w;
		    {
			 E T20, T2f, T2o, T2r;
			 T20 = T1S - T1Z;
			 T2f = T27 - T2e;
			 T2g = T20 - T2f;
			 T2u = T20 + T2f;
			 T2o = T2k - T2n;
			 T2r = T2p - T2q;
			 T2s = T2o - T2r;
			 T2w = T2o + T2r;
		    }
		    {
			 E T1P, T2h, T2t, T2v;
			 T1P = W[24];
			 T2h = W[25];
			 Ip[WS(rs, 6)] = FNMS(T2h, T2s, T1P * T2g);
			 Im[WS(rs, 6)] = FMA(T2h, T2g, T1P * T2s);
			 T2t = W[8];
			 T2v = W[9];
			 Ip[WS(rs, 2)] = FNMS(T2v, T2w, T2t * T2u);
			 Im[WS(rs, 2)] = FMA(T2v, T2u, T2t * T2w);
		    }
	       }
	       {
		    E T2A, T2G, T2E, T2I;
		    {
			 E T2y, T2z, T2C, T2D;
			 T2y = T1S + T1Z;
			 T2z = T2p + T2q;
			 T2A = T2y - T2z;
			 T2G = T2y + T2z;
			 T2C = T2k + T2n;
			 T2D = T2e + T27;
			 T2E = T2C - T2D;
			 T2I = T2C + T2D;
		    }
		    {
			 E T2x, T2B, T2F, T2H;
			 T2x = W[16];
			 T2B = W[17];
			 Ip[WS(rs, 4)] = FNMS(T2B, T2E, T2x * T2A);
			 Im[WS(rs, 4)] = FMA(T2x, T2E, T2B * T2A);
			 T2F = W[0];
			 T2H = W[1];
			 Ip[0] = FNMS(T2H, T2I, T2F * T2G);
			 Im[0] = FMA(T2F, T2I, T2H * T2G);
		    }
	       }
	       {
		    E T1G, T1M, T1K, T1O;
		    {
			 E T1E, T1F, T1I, T1J;
			 T1E = T7 - Te;
			 T1F = T1A - T1z;
			 T1G = T1E - T1F;
			 T1M = T1E + T1F;
			 T1I = T1w - T1x;
			 T1J = Tm - Tt;
			 T1K = T1I - T1J;
			 T1O = T1J + T1I;
		    }
		    {
			 E T1D, T1H, T1L, T1N;
			 T1D = W[22];
			 T1H = W[23];
			 Rp[WS(rs, 6)] = FNMS(T1H, T1K, T1D * T1G);
			 Rm[WS(rs, 6)] = FMA(T1D, T1K, T1H * T1G);
			 T1L = W[6];
			 T1N = W[7];
			 Rp[WS(rs, 2)] = FNMS(T1N, T1O, T1L * T1M);
			 Rm[WS(rs, 2)] = FMA(T1L, T1O, T1N * T1M);
		    }
	       }
	  }
     }
}

static const tw_instr twinstr[] = {
     { TW_FULL, 1, 16 },
     { TW_NEXT, 1, 0 }
};

static const hc2c_desc desc = { 16, "hc2cb_16", twinstr, &GENUS, { 136, 46, 38, 0 } };

void X(codelet_hc2cb_16) (planner *p) {
     X(khc2c_register) (p, hc2cb_16, &desc, HC2C_VIA_RDFT);
}
#endif
