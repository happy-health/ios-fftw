//
//  FFT.h
//  Example
//
//  Created by Haris Ali on 1/27/21.
//  Copyright © 2021 Happy Health, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <HappyFFTW/fftw3.h>

NS_ASSUME_NONNULL_BEGIN

@interface FFT : NSObject

/// Dummy method to verify we're importing the FFTW library properly and
/// getting all the functions linked properly.
+ (void)performForward;

@end

NS_ASSUME_NONNULL_END
