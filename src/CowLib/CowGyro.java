package com.team1538.lib;

import org.usfirst.frc.team5499.robot.controllers.PIDInput;

public class CowGyro implements PIDInput {
	public CowGyro(){
		try {
			System.loadLibrary("CowGyroJNI");
		} catch (UnsatisfiedLinkError e) {
			System.err.println(e.getMessage());
		}
		CowGyro.init();
	}
	
	private static native void init();
	
	public static native float GetAngle();
	public static native double GetRate();
	public static native void BeginCalibration();
	public static native void FinalizeCalibration();
	
	@Override
	public double getInput() {
		return CowGyro.GetAngle();
	}
}
