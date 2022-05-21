/*******************************************************************************
* Copyright (C) 2013, Louis Zuckerman.
*******************************************************************************/
#include "libgfapi-jni.h"

void cachedirentFields(JNIEnv *env, jobject lpObject);
struct dirent *getdirentFields(JNIEnv *env, jobject lpObject, struct dirent *lpStruct);
void setdirentFields(JNIEnv *env, jobject lpObject, struct dirent *lpStruct);

void cachestatFields(JNIEnv *env, jobject lpObject);
struct stat *getstatFields(JNIEnv *env, jobject lpObject, struct stat *lpStruct);
void setstatFields(JNIEnv *env, jobject lpObject, struct stat *lpStruct);

void cachestatvfsFields(JNIEnv *env, jobject lpObject);
struct statvfs *getstatvfsFields(JNIEnv *env, jobject lpObject, struct statvfs *lpStruct);
void setstatvfsFields(JNIEnv *env, jobject lpObject, struct statvfs *lpStruct);

