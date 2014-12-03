package com.fakhir.FileLoad;

import android.app.Activity;
import android.os.Bundle;
import android.content.res.AssetManager;


public class FileLoadActivity extends Activity
{
	
	private AssetManager assetMgr;

    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);

		assetMgr = getResources().getAssets();

		loadFileFromJNI(assetMgr);
		        
    }
    
    
    public native void  loadFileFromJNI(AssetManager assetMgr);
    
    static {
        System.loadLibrary("JNIGlue");
    }
    
}
