//
//  ViewController.swift
//  TuyaEmbedded
//
//  Created by 18828025 on 28.09.2021.
//

import UIKit
import TuyaSmartBaseKit

class ViewController: UIViewController {

	private let tuyaSmartSDK: TuyaSmartSDK = TuyaSmartSDK.sharedInstance()

	override func viewDidLoad() {
		super.viewDidLoad()
		// Do any additional setup after loading the view.
	}


	override func viewDidAppear(_ animated: Bool) {
		super.viewDidAppear(animated)
		
		tuyaSmartSDK.start(
			withAppKey: "12312",
			secretKey: "3123123"
		)
	}
}

