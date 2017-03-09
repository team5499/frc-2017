#include <jni.h>
#include "CowAlphaNumJNI.h"
#include "CowAlphaNum.h"

CowLib::CowAlphaNum *g_Instance = NULL;

JNIEXPORT void JNICALL Java_com_team1538_lib_CowAlphaNum_init(JNIEnv *env, jclass cls)
{
	HALInitialize();
	if(g_Instance == NULL) {
		g_Instance = new CowLib::CowAlphaNum(0x70);
	}
}

JNIEXPORT void JNICALL Java_com_team1538_lib_CowAlphaNum_SetBanner(JNIEnv *env, jclass cls, jstring text)
{
	const char* nativeText = env->GetStringUTFChars(text, FALSE);
	g_Instance->SetBanner(nativeText);
	env->ReleaseStringUTFChars(text, nativeText);
}

JNIEXPORT void JNICALL Java_com_team1538_lib_CowAlphaNum_SetBannerPosition(JNIEnv *env, jclass cls, jint position)
{
	g_Instance->SetBannerPosition((uint32_t) position);
}

JNIEXPORT void JNICALL Java_com_team1538_lib_CowAlphaNum_DisplayBanner(JNIEnv *env, jclass cls)
{
	g_Instance->DisplayBanner();
}
