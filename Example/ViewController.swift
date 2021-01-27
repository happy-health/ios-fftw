//
//  ViewController.swift
//  Example
//
//  Created by Haris Ali on 3/12/20.
//  Copyright © 2020 Happy Health, Inc. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        
        // Simple example of using FFTW. We're briding to obj-c until we
        // do a direct swift implementation.
        FFT.performForward()
    }

}
