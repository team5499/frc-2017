#include <jni.h>
#include "CowGyroJNI.h"
#include "CowGyro.h"

JNIEXPORT void JNICALL Java_com_team1538_lib_CowGyro_init(JNIEnv *env, jclass cls)
{
	HALInitialize();
}


JNIEXPORT jfloat JNICALL Java_com_team1538_lib_CowGyro_GetAngle(JNIEnv *env, jclass cls)
{
  return (jfloat) CowLib::CowGyro::GetInstance()->GetAngle();
}

JNIEXPORT jdouble JNICALL Java_com_team1538_lib_CowGyro_GetRate(JNIEnv *env, jclass cls)
{
  return (jdouble) CowLib::CowGyro::GetInstance()->GetRate();
}

JNIEXPORT void JNICALL Java_com_team1538_lib_CowGyro_BeginCalibration(JNIEnv *env, jclass cls)
{
  CowLib::CowGyro::GetInstance()->BeginCalibration();
}

JNIEXPORT void JNICALL Java_com_team1538_lib_CowGyro_FinalizeCalibration(JNIEnv *env, jclass cls)
{
  CowLib::CowGyro::GetInstance()->FinalizeCalibration();
}
