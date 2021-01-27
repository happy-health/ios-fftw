//
//  FFT.m
//  Example
//
//  Created by Haris Ali on 1/27/21.
//  Copyright © 2021 Happy Health, Inc. All rights reserved.
//

#import "FFT.h"

@implementation FFT

+ (void)performForward {
    int N = 200;
    fftw_complex *in, *out;
    fftw_plan p;
    in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
    out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
    p = fftw_plan_dft_1d(N, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
    fftw_execute(p);
    fftw_destroy_plan(p);
    fftw_free(in);
    fftw_free(out);
}

@end
