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
/* Generated on Thu Dec 10 07:05:49 EST 2020 */

#include "codelet-rdft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_r2cf.native -fma -compact -variables 4 -pipeline-latency 4 -n 6 -name r2cf_6 -include rdft/scalar/r2cf.h */

/*
 * This function contains 14 FP additions, 4 FP multiplications,
 * (or, 12 additions, 2 multiplications, 2 fused multiply/add),
 * 17 stack variables, 2 constants, and 12 memory accesses
 */
#include "r2cf.h"

static void r2cf_6(R *R0, R *R1, R *Cr, R *Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
     DK(KP500000000, +0.500000000000000000000000000000000000000000000);
     DK(KP866025403, +0.866025403784438646763723170752936183471402627);
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, R0 = R0 + ivs, R1 = R1 + ivs, Cr = Cr + ovs, Ci = Ci + ovs, MAKE_VOLATILE_STRIDE(24, rs), MAKE_VOLATILE_STRIDE(24, csr), MAKE_VOLATILE_STRIDE(24, csi)) {
	       E T3, Td, T9, Tc, T6, Tb, T1, T2, Ta, Te;
	       T1 = R0[0];
	       T2 = R1[WS(rs, 1)];
	       T3 = T1 - T2;
	       Td = T1 + T2;
	       {
		    E T7, T8, T4, T5;
		    T7 = R0[WS(rs, 2)];
		    T8 = R1[0];
		    T9 = T7 - T8;
		    Tc = T7 + T8;
		    T4 = R0[WS(rs, 1)];
		    T5 = R1[WS(rs, 2)];
		    T6 = T4 - T5;
		    Tb = T4 + T5;
	       }
	       Ci[WS(csi, 1)] = KP866025403 * (T9 - T6);
	       Ta = T6 + T9;
	       Cr[WS(csr, 1)] = FNMS(KP500000000, Ta, T3);
	       Cr[WS(csr, 3)] = T3 + Ta;
	       Ci[WS(csi, 2)] = KP866025403 * (Tb - Tc);
	       Te = Tb + Tc;
	       Cr[WS(csr, 2)] = FNMS(KP500000000, Te, Td);
	       Cr[0] = Td + Te;
	  }
     }
}

static const kr2c_desc desc = { 6, "r2cf_6", { 12, 2, 2, 0 }, &GENUS };

void X(codelet_r2cf_6) (planner *p) { X(kr2c_register) (p, r2cf_6, &desc);
}

#else

/* Generated by: ../../../genfft/gen_r2cf.native -compact -variables 4 -pipeline-latency 4 -n 6 -name r2cf_6 -include rdft/scalar/r2cf.h */

/*
 * This function contains 14 FP additions, 4 FP multiplications,
 * (or, 12 additions, 2 multiplications, 2 fused multiply/add),
 * 17 stack variables, 2 constants, and 12 memory accesses
 */
#include "r2cf.h"

static void r2cf_6(R *R0, R *R1, R *Cr, R *Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
     DK(KP500000000, +0.500000000000000000000000000000000000000000000);
     DK(KP866025403, +0.866025403784438646763723170752936183471402627);
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, R0 = R0 + ivs, R1 = R1 + ivs, Cr = Cr + ovs, Ci = Ci + ovs, MAKE_VOLATILE_STRIDE(24, rs), MAKE_VOLATILE_STRIDE(24, csr), MAKE_VOLATILE_STRIDE(24, csi)) {
	       E T3, Td, T9, Tc, T6, Tb, T1, T2, Ta, Te;
	       T1 = R0[0];
	       T2 = R1[WS(rs, 1)];
	       T3 = T1 - T2;
	       Td = T1 + T2;
	       {
		    E T7, T8, T4, T5;
		    T7 = R0[WS(rs, 2)];
		    T8 = R1[0];
		    T9 = T7 - T8;
		    Tc = T7 + T8;
		    T4 = R0[WS(rs, 1)];
		    T5 = R1[WS(rs, 2)];
		    T6 = T4 - T5;
		    Tb = T4 + T5;
	       }
	       Ci[WS(csi, 1)] = KP866025403 * (T9 - T6);
	       Ta = T6 + T9;
	       Cr[WS(csr, 1)] = FNMS(KP500000000, Ta, T3);
	       Cr[WS(csr, 3)] = T3 + Ta;
	       Ci[WS(csi, 2)] = KP866025403 * (Tb - Tc);
	       Te = Tb + Tc;
	       Cr[WS(csr, 2)] = FNMS(KP500000000, Te, Td);
	       Cr[0] = Td + Te;
	  }
     }
}

static const kr2c_desc desc = { 6, "r2cf_6", { 12, 2, 2, 0 }, &GENUS };

void X(codelet_r2cf_6) (planner *p) { X(kr2c_register) (p, r2cf_6, &desc);
}

#endif
