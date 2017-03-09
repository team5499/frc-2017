package com.team1538.lib;

public class CowAlphaNum {
	static {
		CowAlphaNum.init();
	}
	
	private static native void init();
	
	public static native void SetBanner(String text);
	public static native void SetBannerPosition(int position);
	public static native void DisplayBanner();
	
	
}
