//
//  ViewController.swift
//  Example
//
//  Created by Haris Ali on 3/12/20.
//  Copyright © 2020 Gideon Health, Inc. All rights reserved.
//

import fftw
import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        
        let plan = fftw_malloc(1024)
        fftw_free(plan)
    }

}
