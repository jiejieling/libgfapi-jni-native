/*******************************************************************************
* Copyright (C) 2013, Louis Zuckerman.
*******************************************************************************/
#include "hawtjni.h"
#include "libgfapi-jni_stats.h"

#ifdef NATIVE_STATS

int GLFS_nativeFunctionCount = 30;
int GLFS_nativeFunctionCallCount[30];
char * GLFS_nativeFunctionNames[] = {
	"glfs_1access",
	"glfs_1chmod",
	"glfs_1close",
	"glfs_1closedir",
	"glfs_1creat",
	"glfs_1fini",
	"glfs_1from_1glfd",
	"glfs_1fstat",
	"glfs_1fsync",
	"glfs_1init",
	"glfs_1lseek",
	"glfs_1lstat",
	"glfs_1mkdir",
	"glfs_1new",
	"glfs_1open",
	"glfs_1opendir",
	"glfs_1read",
	"glfs_1readdir_1r",
	"glfs_1readlink",
	"glfs_1rename",
	"glfs_1rmdir",
	"glfs_1seekdir",
	"glfs_1set_1logging",
	"glfs_1set_1volfile_1server",
	"glfs_1stat",
	"glfs_1statvfs",
	"glfs_1symlink",
	"glfs_1telldir",
	"glfs_1unlink",
	"glfs_1write",
};

#define STATS_NATIVE(func) Java_org_fusesource_hawtjni_runtime_NativeStats_##func

JNIEXPORT jint JNICALL STATS_NATIVE(GLFS_1GetFunctionCount)
	(JNIEnv *env, jclass that)
{
	return GLFS_nativeFunctionCount;
}

JNIEXPORT jstring JNICALL STATS_NATIVE(GLFS_1GetFunctionName)
	(JNIEnv *env, jclass that, jint index)
{
	return (*env)->NewStringUTF(env, GLFS_nativeFunctionNames[index]);
}

JNIEXPORT jint JNICALL STATS_NATIVE(GLFS_1GetFunctionCallCount)
	(JNIEnv *env, jclass that, jint index)
{
	return GLFS_nativeFunctionCallCount[index];
}

#endif
#ifdef NATIVE_STATS

int GlusterOpenOption_nativeFunctionCount = 1;
int GlusterOpenOption_nativeFunctionCallCount[1];
char * GlusterOpenOption_nativeFunctionNames[] = {
	"init",
};

#define STATS_NATIVE(func) Java_org_fusesource_hawtjni_runtime_NativeStats_##func

JNIEXPORT jint JNICALL STATS_NATIVE(GlusterOpenOption_1GetFunctionCount)
	(JNIEnv *env, jclass that)
{
	return GlusterOpenOption_nativeFunctionCount;
}

JNIEXPORT jstring JNICALL STATS_NATIVE(GlusterOpenOption_1GetFunctionName)
	(JNIEnv *env, jclass that, jint index)
{
	return (*env)->NewStringUTF(env, GlusterOpenOption_nativeFunctionNames[index]);
}

JNIEXPORT jint JNICALL STATS_NATIVE(GlusterOpenOption_1GetFunctionCallCount)
	(JNIEnv *env, jclass that, jint index)
{
	return GlusterOpenOption_nativeFunctionCallCount[index];
}

#endif
#ifdef NATIVE_STATS

int UtilJNI_nativeFunctionCount = 4;
int UtilJNI_nativeFunctionCallCount[4];
char * UtilJNI_nativeFunctionNames[] = {
	"errno",
	"memmove",
	"strerror_1jni",
	"strlen",
};

#define STATS_NATIVE(func) Java_org_fusesource_hawtjni_runtime_NativeStats_##func

JNIEXPORT jint JNICALL STATS_NATIVE(UtilJNI_1GetFunctionCount)
	(JNIEnv *env, jclass that)
{
	return UtilJNI_nativeFunctionCount;
}

JNIEXPORT jstring JNICALL STATS_NATIVE(UtilJNI_1GetFunctionName)
	(JNIEnv *env, jclass that, jint index)
{
	return (*env)->NewStringUTF(env, UtilJNI_nativeFunctionNames[index]);
}

JNIEXPORT jint JNICALL STATS_NATIVE(UtilJNI_1GetFunctionCallCount)
	(JNIEnv *env, jclass that, jint index)
{
	return UtilJNI_nativeFunctionCallCount[index];
}

#endif
#ifdef NATIVE_STATS

int dirent_nativeFunctionCount = 5;
int dirent_nativeFunctionCallCount[5];
char * dirent_nativeFunctionNames[] = {
	"free",
	"init",
	"malloc",
	"memmove__JLcom_peircean_libgfapi_1jni_internal_structs_dirent_2J",
	"memmove__Lcom_peircean_libgfapi_1jni_internal_structs_dirent_2JJ",
};

#define STATS_NATIVE(func) Java_org_fusesource_hawtjni_runtime_NativeStats_##func

JNIEXPORT jint JNICALL STATS_NATIVE(dirent_1GetFunctionCount)
	(JNIEnv *env, jclass that)
{
	return dirent_nativeFunctionCount;
}

JNIEXPORT jstring JNICALL STATS_NATIVE(dirent_1GetFunctionName)
	(JNIEnv *env, jclass that, jint index)
{
	return (*env)->NewStringUTF(env, dirent_nativeFunctionNames[index]);
}

JNIEXPORT jint JNICALL STATS_NATIVE(dirent_1GetFunctionCallCount)
	(JNIEnv *env, jclass that, jint index)
{
	return dirent_nativeFunctionCallCount[index];
}

#endif
