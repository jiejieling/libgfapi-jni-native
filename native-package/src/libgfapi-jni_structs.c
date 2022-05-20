/*******************************************************************************
* Copyright (C) 2013, Louis Zuckerman.
*******************************************************************************/
#include "libgfapi-jni.h"
#include "hawtjni.h"
#include "libgfapi-jni_structs.h"

typedef struct dirent_FID_CACHE {
	int cached;
	jclass clazz;
	jfieldID d_ino, d_off, d_reclen, d_type, d_name;
} dirent_FID_CACHE;

dirent_FID_CACHE direntFc;

void cachedirentFields(JNIEnv *env, jobject lpObject)
{
	if (direntFc.cached) return;
	direntFc.clazz = (*env)->GetObjectClass(env, lpObject);
	direntFc.d_ino = (*env)->GetFieldID(env, direntFc.clazz, "d_ino", "J");
	direntFc.d_off = (*env)->GetFieldID(env, direntFc.clazz, "d_off", "J");
	direntFc.d_reclen = (*env)->GetFieldID(env, direntFc.clazz, "d_reclen", "I");
	direntFc.d_type = (*env)->GetFieldID(env, direntFc.clazz, "d_type", "B");
	direntFc.d_name = (*env)->GetFieldID(env, direntFc.clazz, "d_name", "[B");
	hawtjni_w_barrier();
	direntFc.cached = 1;
}

struct dirent *getdirentFields(JNIEnv *env, jobject lpObject, struct dirent *lpStruct)
{
	if (!direntFc.cached) cachedirentFields(env, lpObject);
	lpStruct->d_ino = (uint32_t)(*env)->GetLongField(env, lpObject, direntFc.d_ino);
#if defined(__APPLE__)
    lpStruct->d_seekoff = (uint32_t)(*env)->GetLongField(env, lpObject, direntFc.d_off);
#else
	lpStruct->d_off = (uint32_t)(*env)->GetLongField(env, lpObject, direntFc.d_off);
#endif
	lpStruct->d_reclen = (*env)->GetIntField(env, lpObject, direntFc.d_reclen);
	lpStruct->d_type = (*env)->GetByteField(env, lpObject, direntFc.d_type);
	{
	jbyteArray lpObject1 = (jbyteArray)(*env)->GetObjectField(env, lpObject, direntFc.d_name);
	(*env)->GetByteArrayRegion(env, lpObject1, 0, sizeof(lpStruct->d_name), (jbyte *)lpStruct->d_name);
	}
	return lpStruct;
}

void setdirentFields(JNIEnv *env, jobject lpObject, struct dirent *lpStruct)
{
	if (!direntFc.cached) cachedirentFields(env, lpObject);
	(*env)->SetLongField(env, lpObject, direntFc.d_ino, (jlong)lpStruct->d_ino);
#if defined(__APPLE__)
	(*env)->SetLongField(env, lpObject, direntFc.d_off, (jlong)lpStruct->d_seekoff);
#else
    (*env)->SetLongField(env, lpObject, direntFc.d_off, (jlong)lpStruct->d_off);
#endif
	(*env)->SetIntField(env, lpObject, direntFc.d_reclen, (jint)lpStruct->d_reclen);
	(*env)->SetByteField(env, lpObject, direntFc.d_type, (jbyte)lpStruct->d_type);
	{
	jbyteArray lpObject1 = (jbyteArray)(*env)->GetObjectField(env, lpObject, direntFc.d_name);
	(*env)->SetByteArrayRegion(env, lpObject1, 0, sizeof(lpStruct->d_name), (jbyte *)lpStruct->d_name);
	}
}

typedef struct stat_FID_CACHE {
	int cached;
	jclass clazz;
	jfieldID st_dev, st_ino, st_mode, st_nlink, st_uid, st_gid, st_rdev, st_size, st_blksize, st_blocks, atime, mtime, ctime;
} stat_FID_CACHE;

stat_FID_CACHE statFc;

void cachestatFields(JNIEnv *env, jobject lpObject)
{
	if (statFc.cached) return;
	statFc.clazz = (*env)->GetObjectClass(env, lpObject);
	statFc.st_dev = (*env)->GetFieldID(env, statFc.clazz, "st_dev", "J");
	statFc.st_ino = (*env)->GetFieldID(env, statFc.clazz, "st_ino", "J");
	statFc.st_mode = (*env)->GetFieldID(env, statFc.clazz, "st_mode", "I");
	statFc.st_nlink = (*env)->GetFieldID(env, statFc.clazz, "st_nlink", "I");
	statFc.st_uid = (*env)->GetFieldID(env, statFc.clazz, "st_uid", "I");
	statFc.st_gid = (*env)->GetFieldID(env, statFc.clazz, "st_gid", "I");
	statFc.st_rdev = (*env)->GetFieldID(env, statFc.clazz, "st_rdev", "J");
	statFc.st_size = (*env)->GetFieldID(env, statFc.clazz, "st_size", "J");
	statFc.st_blksize = (*env)->GetFieldID(env, statFc.clazz, "st_blksize", "I");
	statFc.st_blocks = (*env)->GetFieldID(env, statFc.clazz, "st_blocks", "J");
	statFc.atime = (*env)->GetFieldID(env, statFc.clazz, "atime", "J");
	statFc.mtime = (*env)->GetFieldID(env, statFc.clazz, "mtime", "J");
	statFc.ctime = (*env)->GetFieldID(env, statFc.clazz, "ctime", "J");
	hawtjni_w_barrier();
	statFc.cached = 1;
}

struct stat *getstatFields(JNIEnv *env, jobject lpObject, struct stat *lpStruct)
{
	if (!statFc.cached) cachestatFields(env, lpObject);
	lpStruct->st_dev = (*env)->GetLongField(env, lpObject, statFc.st_dev);
	lpStruct->st_ino = (*env)->GetLongField(env, lpObject, statFc.st_ino);
	lpStruct->st_mode = (*env)->GetIntField(env, lpObject, statFc.st_mode);
	lpStruct->st_nlink = (*env)->GetIntField(env, lpObject, statFc.st_nlink);
	lpStruct->st_uid = (*env)->GetIntField(env, lpObject, statFc.st_uid);
	lpStruct->st_gid = (*env)->GetIntField(env, lpObject, statFc.st_gid);
	lpStruct->st_rdev = (*env)->GetLongField(env, lpObject, statFc.st_rdev);
	lpStruct->st_size = (*env)->GetLongField(env, lpObject, statFc.st_size);
	lpStruct->st_blksize = (*env)->GetIntField(env, lpObject, statFc.st_blksize);
	lpStruct->st_blocks = (*env)->GetLongField(env, lpObject, statFc.st_blocks);
	lpStruct->st_atime = (*env)->GetLongField(env, lpObject, statFc.atime);
	lpStruct->st_mtime = (*env)->GetLongField(env, lpObject, statFc.mtime);
	lpStruct->st_ctime = (*env)->GetLongField(env, lpObject, statFc.ctime);
	return lpStruct;
}

void setstatFields(JNIEnv *env, jobject lpObject, struct stat *lpStruct)
{
	if (!statFc.cached) cachestatFields(env, lpObject);
	(*env)->SetLongField(env, lpObject, statFc.st_dev, (jlong)lpStruct->st_dev);
	(*env)->SetLongField(env, lpObject, statFc.st_ino, (jlong)lpStruct->st_ino);
	(*env)->SetIntField(env, lpObject, statFc.st_mode, (jint)lpStruct->st_mode);
	(*env)->SetIntField(env, lpObject, statFc.st_nlink, (jint)lpStruct->st_nlink);
	(*env)->SetIntField(env, lpObject, statFc.st_uid, (jint)lpStruct->st_uid);
	(*env)->SetIntField(env, lpObject, statFc.st_gid, (jint)lpStruct->st_gid);
	(*env)->SetLongField(env, lpObject, statFc.st_rdev, (jlong)lpStruct->st_rdev);
	(*env)->SetLongField(env, lpObject, statFc.st_size, (jlong)lpStruct->st_size);
	(*env)->SetIntField(env, lpObject, statFc.st_blksize, (jint)lpStruct->st_blksize);
	(*env)->SetLongField(env, lpObject, statFc.st_blocks, (jlong)lpStruct->st_blocks);
	(*env)->SetLongField(env, lpObject, statFc.atime, (jlong)lpStruct->st_atime);
	(*env)->SetLongField(env, lpObject, statFc.mtime, (jlong)lpStruct->st_mtime);
	(*env)->SetLongField(env, lpObject, statFc.ctime, (jlong)lpStruct->st_ctime);
}

typedef struct statvfs_FID_CACHE {
	int cached;
	jclass clazz;
	jfieldID f_bsize, f_frsize, f_blocks, f_bfree, f_bavail, f_files, f_ffree, f_favail, f_fsid, f_flag, f_namemax, __f_spare;
} statvfs_FID_CACHE;

statvfs_FID_CACHE statvfsFc;

void cachestatvfsFields(JNIEnv *env, jobject lpObject)
{
	if (statvfsFc.cached) return;
	statvfsFc.clazz = (*env)->GetObjectClass(env, lpObject);
	statvfsFc.f_bsize = (*env)->GetFieldID(env, statvfsFc.clazz, "f_bsize", "J");
	statvfsFc.f_frsize = (*env)->GetFieldID(env, statvfsFc.clazz, "f_frsize", "J");
	statvfsFc.f_blocks = (*env)->GetFieldID(env, statvfsFc.clazz, "f_blocks", "J");
	statvfsFc.f_bfree = (*env)->GetFieldID(env, statvfsFc.clazz, "f_bfree", "J");
	statvfsFc.f_bavail = (*env)->GetFieldID(env, statvfsFc.clazz, "f_bavail", "J");
	statvfsFc.f_files = (*env)->GetFieldID(env, statvfsFc.clazz, "f_files", "J");
	statvfsFc.f_ffree = (*env)->GetFieldID(env, statvfsFc.clazz, "f_ffree", "J");
	statvfsFc.f_favail = (*env)->GetFieldID(env, statvfsFc.clazz, "f_favail", "J");
	statvfsFc.f_fsid = (*env)->GetFieldID(env, statvfsFc.clazz, "f_fsid", "J");
	statvfsFc.f_flag = (*env)->GetFieldID(env, statvfsFc.clazz, "f_flag", "J");
	statvfsFc.f_namemax = (*env)->GetFieldID(env, statvfsFc.clazz, "f_namemax", "J");
	statvfsFc.__f_spare = (*env)->GetFieldID(env, statvfsFc.clazz, "__f_spare", "[I");
	hawtjni_w_barrier();
	statvfsFc.cached = 1;
}

struct statvfs *getstatvfsFields(JNIEnv *env, jobject lpObject, struct statvfs *lpStruct)
{
	if (!statvfsFc.cached) cachestatvfsFields(env, lpObject);
	lpStruct->f_bsize = (*env)->GetLongField(env, lpObject, statvfsFc.f_bsize);
	lpStruct->f_frsize = (*env)->GetLongField(env, lpObject, statvfsFc.f_frsize);
	lpStruct->f_blocks = (uint32_t)(*env)->GetLongField(env, lpObject, statvfsFc.f_blocks);
	lpStruct->f_bfree = (uint32_t)(*env)->GetLongField(env, lpObject, statvfsFc.f_bfree);
	lpStruct->f_bavail = (uint32_t)(*env)->GetLongField(env, lpObject, statvfsFc.f_bavail);
	lpStruct->f_files = (uint32_t)(*env)->GetLongField(env, lpObject, statvfsFc.f_files);
	lpStruct->f_ffree = (uint32_t)(*env)->GetLongField(env, lpObject, statvfsFc.f_ffree);
	lpStruct->f_favail = (uint32_t)(*env)->GetLongField(env, lpObject, statvfsFc.f_favail);
	lpStruct->f_fsid = (*env)->GetLongField(env, lpObject, statvfsFc.f_fsid);
	lpStruct->f_flag = (*env)->GetLongField(env, lpObject, statvfsFc.f_flag);
	lpStruct->f_namemax = (*env)->GetLongField(env, lpObject, statvfsFc.f_namemax);
#if ! defined(__APPLE__)
	{
	jintArray lpObject1 = (jintArray)(*env)->GetObjectField(env, lpObject, statvfsFc.__f_spare);
	(*env)->GetIntArrayRegion(env, lpObject1, 0, sizeof(lpStruct->__f_spare) / sizeof(jint), (jint *)lpStruct->__f_spare);
	}
#endif
	return lpStruct;
}

void setstatvfsFields(JNIEnv *env, jobject lpObject, struct statvfs *lpStruct)
{
	if (!statvfsFc.cached) cachestatvfsFields(env, lpObject);
	(*env)->SetLongField(env, lpObject, statvfsFc.f_bsize, (jlong)lpStruct->f_bsize);
	(*env)->SetLongField(env, lpObject, statvfsFc.f_frsize, (jlong)lpStruct->f_frsize);
	(*env)->SetLongField(env, lpObject, statvfsFc.f_blocks, (jlong)lpStruct->f_blocks);
	(*env)->SetLongField(env, lpObject, statvfsFc.f_bfree, (jlong)lpStruct->f_bfree);
	(*env)->SetLongField(env, lpObject, statvfsFc.f_bavail, (jlong)lpStruct->f_bavail);
	(*env)->SetLongField(env, lpObject, statvfsFc.f_files, (jlong)lpStruct->f_files);
	(*env)->SetLongField(env, lpObject, statvfsFc.f_ffree, (jlong)lpStruct->f_ffree);
	(*env)->SetLongField(env, lpObject, statvfsFc.f_favail, (jlong)lpStruct->f_favail);
	(*env)->SetLongField(env, lpObject, statvfsFc.f_fsid, (jlong)lpStruct->f_fsid);
	(*env)->SetLongField(env, lpObject, statvfsFc.f_flag, (jlong)lpStruct->f_flag);
	(*env)->SetLongField(env, lpObject, statvfsFc.f_namemax, (jlong)lpStruct->f_namemax);
#if ! defined(__APPLE__)
	{
	jintArray lpObject1 = (jintArray)(*env)->GetObjectField(env, lpObject, statvfsFc.__f_spare);
	(*env)->SetIntArrayRegion(env, lpObject1, 0, sizeof(lpStruct->__f_spare) / sizeof(jint), (jint *)lpStruct->__f_spare);
	}
#endif
}

