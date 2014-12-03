
#include <string>
#include <sstream>
#include <jni.h>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>
#include <android/log.h>

#define  LOG_TAG    "JNIGlue"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)

void DisplayDebugHeader();

std::string rawStream = "this is raw asset stream to be replaced";

extern "C" 
{
    
    JNIEXPORT jstring JNICALL Java_com_fakhir_FileLoad_FileLoadActivity_stringFromJNI( JNIEnv* env, jobject thiz);
    JNIEXPORT void JNICALL Java_com_fakhir_FileLoad_FileLoadActivity_loadFileFromJNI( JNIEnv* env, jobject thiz, jobject assetManager);
}


JNIEXPORT jstring JNICALL Java_com_fakhir_FileLoad_FileLoadActivity_stringFromJNI( JNIEnv* env, jobject thiz)
{
    return env->NewStringUTF("Hello from JNI !");
}

JNIEXPORT void JNICALL Java_com_fakhir_FileLoad_FileLoadActivity_loadFileFromJNI( JNIEnv* env, jobject thiz, jobject assetManager)
{
    
    LOGI("JNIGlue.cpp : Calling loadFileFromJNI()...");
    

    DisplayDebugHeader();


    char * pdata;
    
 
    AAssetManager *mgr = AAssetManager_fromJava(env, assetManager);
    if (mgr == NULL)
    {
        __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "error loading asset maanger");
        return;
    } 
    else 
    {
        __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, "loaded asset  manager");
    }


    AAsset * asset = AAssetManager_open(mgr,"Candy_Person.png",AASSET_MODE_BUFFER);
    if(!asset)
    {
        LOGI("_ASSET_NOT_FOUND_");
        return;
    }
    
    int size = AAsset_getLength(asset);
    
    LOGI("Asset size: %d", size);
   
    char* buffer = (char*) malloc (sizeof(char)*size);
    AAsset_read (asset,buffer,size);
    //LOGI("%s", buffer);

    AAsset_close(asset);
    
}


void DisplayDebugHeader()
{
    LOGI("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
    LOGI("............................................................");
    LOGI("............................................................");
    LOGI("............................................................");
    LOGI("............................................................");
    LOGI("............................................................");
    LOGI("............................................................");
    LOGI("............................................................");
    LOGI("............................................................");
    LOGI("............................................................");
    LOGI("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
    
}



