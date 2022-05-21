/*******************************************************************************
* Copyright (C) 2013, Louis Zuckerman.
*******************************************************************************/
#include "libgfapi-jni.h"
#include "hawtjni.h"
#include "libgfapi-jni_structs.h"
#include "libgfapi-jni_stats.h"

#define GLFS_NATIVE(func) Java_com_peircean_libgfapi_1jni_internal_GLFS_##func

JNIEXPORT jint JNICALL GLFS_NATIVE(glfs_1access)
	(JNIEnv *env, jclass that, jlong arg0, jstring arg1, jint arg2)
{
	const char *lparg1= NULL;
	jint rc = 0;
	GLFS_NATIVE_ENTER(env, that, GLFS_glfs_1access_FUNC);
	if (arg1) if ((lparg1 = (*env)->GetStringUTFChars(env, arg1, NULL)) == NULL) goto fail;
	rc = (jint)glfs_access((glfs_t *)(intptr_t)arg0, (const char *)lparg1, arg2);
fail:
	if (arg1 && lparg1) (*env)->ReleaseStringUTFChars(env, arg1, lparg1);
	GLFS_NATIVE_EXIT(env, that, GLFS_glfs_1access_FUNC);
	return rc;
}

JNIEXPORT jint JNICALL GLFS_NATIVE(glfs_1chmod)
	(JNIEnv *env, jclass that, jlong arg0, jstring arg1, jint arg2)
{
	const char *lparg1= NULL;
	jint rc = 0;
	GLFS_NATIVE_ENTER(env, that, GLFS_glfs_1chmod_FUNC);
	if (arg1) if ((lparg1 = (*env)->GetStringUTFChars(env, arg1, NULL)) == NULL) goto fail;
	rc = (jint)glfs_chmod((glfs_t *)(intptr_t)arg0, (const char *)lparg1, arg2);
fail:
	if (arg1 && lparg1) (*env)->ReleaseStringUTFChars(env, arg1, lparg1);
	GLFS_NATIVE_EXIT(env, that, GLFS_glfs_1chmod_FUNC);
	return rc;
}

JNIEXPORT jint JNICALL GLFS_NATIVE(glfs_1close)
	(JNIEnv *env, jclass that, jlong arg0)
{
	jint rc = 0;
	GLFS_NATIVE_ENTER(env, that, GLFS_glfs_1close_FUNC);
	rc = (jint)glfs_close((glfs_fd_t *)(intptr_t)arg0);
	GLFS_NATIVE_EXIT(env, that, GLFS_glfs_1close_FUNC);
	return rc;
}

JNIEXPORT jint JNICALL GLFS_NATIVE(glfs_1closedir)
	(JNIEnv *env, jclass that, jlong arg0)
{
	jint rc = 0;
	GLFS_NATIVE_ENTER(env, that, GLFS_glfs_1closedir_FUNC);
	rc = (jint)glfs_closedir((glfs_fd_t *)(intptr_t)arg0);
	GLFS_NATIVE_EXIT(env, that, GLFS_glfs_1closedir_FUNC);
	return rc;
}

JNIEXPORT jlong JNICALL GLFS_NATIVE(glfs_1creat)
	(JNIEnv *env, jclass that, jlong arg0, jstring arg1, jint arg2, jint arg3)
{
	const char *lparg1= NULL;
	jlong rc = 0;
	GLFS_NATIVE_ENTER(env, that, GLFS_glfs_1creat_FUNC);
	if (arg1) if ((lparg1 = (*env)->GetStringUTFChars(env, arg1, NULL)) == NULL) goto fail;
	rc = (intptr_t)(glfs_fd_t *)glfs_creat((glfs_t *)(intptr_t)arg0, (const char*)lparg1, arg2, arg3);
fail:
	if (arg1 && lparg1) (*env)->ReleaseStringUTFChars(env, arg1, lparg1);
	GLFS_NATIVE_EXIT(env, that, GLFS_glfs_1creat_FUNC);
	return rc;
}

JNIEXPORT jint JNICALL GLFS_NATIVE(glfs_1fini)
	(JNIEnv *env, jclass that, jlong arg0)
{
	jint rc = 0;
	GLFS_NATIVE_ENTER(env, that, GLFS_glfs_1fini_FUNC);
	rc = (jint)glfs_fini((glfs_t *)(intptr_t)arg0);
	GLFS_NATIVE_EXIT(env, that, GLFS_glfs_1fini_FUNC);
	return rc;
}

JNIEXPORT jlong JNICALL GLFS_NATIVE(glfs_1from_1glfd)
	(JNIEnv *env, jclass that, jlong arg0)
{
	jlong rc = 0;
	GLFS_NATIVE_ENTER(env, that, GLFS_glfs_1from_1glfd_FUNC);
	rc = (intptr_t)(glfs_t *)glfs_from_glfd((glfs_fd_t *)(intptr_t)arg0);
	GLFS_NATIVE_EXIT(env, that, GLFS_glfs_1from_1glfd_FUNC);
	return rc;
}

JNIEXPORT jint JNICALL GLFS_NATIVE(glfs_1fstat)
	(JNIEnv *env, jclass that, jlong arg0, jobject arg1)
{
	struct stat _arg1, *lparg1=NULL;
	jint rc = 0;
	GLFS_NATIVE_ENTER(env, that, GLFS_glfs_1fstat_FUNC);
	if (arg1) if ((lparg1 = &_arg1) == NULL) goto fail;
	rc = (jint)glfs_fstat((glfs_fd_t *)(intptr_t)arg0, lparg1);
fail:
	if (arg1 && lparg1) setstatFields(env, arg1, lparg1);
	GLFS_NATIVE_EXIT(env, that, GLFS_glfs_1fstat_FUNC);
	return rc;
}

JNIEXPORT jint JNICALL GLFS_NATIVE(glfs_1fsync)
	(JNIEnv *env, jclass that, jlong arg0, jobject arg1, jobject arg2)
{
	jint rc = 0;
	GLFS_NATIVE_ENTER(env, that, GLFS_glfs_1fsync_FUNC);
	rc = (jint)glfs_fsync((glfs_fd_t *)(intptr_t)arg0, (struct glfs_stat *)arg1, (struct glfs_stat *)arg2);
	GLFS_NATIVE_EXIT(env, that, GLFS_glfs_1fsync_FUNC);
	return rc;
}

JNIEXPORT jint JNICALL GLFS_NATIVE(glfs_1init)
	(JNIEnv *env, jclass that, jlong arg0)
{
	jint rc = 0;
	GLFS_NATIVE_ENTER(env, that, GLFS_glfs_1init_FUNC);
	rc = (jint)glfs_init((glfs_t *)(intptr_t)arg0);
	GLFS_NATIVE_EXIT(env, that, GLFS_glfs_1init_FUNC);
	return rc;
}

JNIEXPORT jint JNICALL GLFS_NATIVE(glfs_1lseek)
	(JNIEnv *env, jclass that, jlong arg0, jlong arg1, jint arg2)
{
	jint rc = 0;
	GLFS_NATIVE_ENTER(env, that, GLFS_glfs_1lseek_FUNC);
	rc = (off_t)glfs_lseek((glfs_fd_t *)(intptr_t)arg0, (off_t)arg1, arg2);
	GLFS_NATIVE_EXIT(env, that, GLFS_glfs_1lseek_FUNC);
	return rc;
}

JNIEXPORT jint JNICALL GLFS_NATIVE(glfs_1lstat)
	(JNIEnv *env, jclass that, jlong arg0, jstring arg1, jobject arg2)
{
	const char *lparg1= NULL;
	struct stat _arg2, *lparg2=NULL;
	jint rc = 0;
	GLFS_NATIVE_ENTER(env, that, GLFS_glfs_1lstat_FUNC);
	if (arg1) if ((lparg1 = (*env)->GetStringUTFChars(env, arg1, NULL)) == NULL) goto fail;
	if (arg2) if ((lparg2 = &_arg2) == NULL) goto fail;
	rc = (jint)glfs_lstat((glfs_t *)(intptr_t)arg0, (const char *)lparg1, lparg2);
fail:
	if (arg2 && lparg2) setstatFields(env, arg2, lparg2);
	if (arg1 && lparg1) (*env)->ReleaseStringUTFChars(env, arg1, lparg1);
	GLFS_NATIVE_EXIT(env, that, GLFS_glfs_1lstat_FUNC);
	return rc;
}

JNIEXPORT jint JNICALL GLFS_NATIVE(glfs_1mkdir)
	(JNIEnv *env, jclass that, jlong arg0, jstring arg1, jint arg2)
{
	const char *lparg1= NULL;
	jint rc = 0;
	GLFS_NATIVE_ENTER(env, that, GLFS_glfs_1mkdir_FUNC);
	if (arg1) if ((lparg1 = (*env)->GetStringUTFChars(env, arg1, NULL)) == NULL) goto fail;
	rc = (jint)glfs_mkdir((glfs_t *)(intptr_t)arg0, (const char *)lparg1, arg2);
fail:
	if (arg1 && lparg1) (*env)->ReleaseStringUTFChars(env, arg1, lparg1);
	GLFS_NATIVE_EXIT(env, that, GLFS_glfs_1mkdir_FUNC);
	return rc;
}

JNIEXPORT jlong JNICALL GLFS_NATIVE(glfs_1new)
	(JNIEnv *env, jclass that, jstring arg0)
{
	const char *lparg0= NULL;
	jlong rc = 0;
	GLFS_NATIVE_ENTER(env, that, GLFS_glfs_1new_FUNC);
	if (arg0) if ((lparg0 = (*env)->GetStringUTFChars(env, arg0, NULL)) == NULL) goto fail;
	rc = (intptr_t)(glfs_t *)glfs_new((const char*)lparg0);
fail:
	if (arg0 && lparg0) (*env)->ReleaseStringUTFChars(env, arg0, lparg0);
	GLFS_NATIVE_EXIT(env, that, GLFS_glfs_1new_FUNC);
	return rc;
}

JNIEXPORT jlong JNICALL GLFS_NATIVE(glfs_1open)
	(JNIEnv *env, jclass that, jlong arg0, jstring arg1, jint arg2)
{
	const char *lparg1= NULL;
	jlong rc = 0;
	GLFS_NATIVE_ENTER(env, that, GLFS_glfs_1open_FUNC);
	if (arg1) if ((lparg1 = (*env)->GetStringUTFChars(env, arg1, NULL)) == NULL) goto fail;
	rc = (intptr_t)(glfs_fd_t *)glfs_open((glfs_t *)(intptr_t)arg0, (const char*)lparg1, arg2);
fail:
	if (arg1 && lparg1) (*env)->ReleaseStringUTFChars(env, arg1, lparg1);
	GLFS_NATIVE_EXIT(env, that, GLFS_glfs_1open_FUNC);
	return rc;
}

JNIEXPORT jlong JNICALL GLFS_NATIVE(glfs_1opendir)
	(JNIEnv *env, jclass that, jlong arg0, jstring arg1)
{
	const char *lparg1= NULL;
	jlong rc = 0;
	GLFS_NATIVE_ENTER(env, that, GLFS_glfs_1opendir_FUNC);
	if (arg1) if ((lparg1 = (*env)->GetStringUTFChars(env, arg1, NULL)) == NULL) goto fail;
	rc = (intptr_t)(glfs_fd_t *)glfs_opendir((glfs_t *)(intptr_t)arg0, (const char *)lparg1);
fail:
	if (arg1 && lparg1) (*env)->ReleaseStringUTFChars(env, arg1, lparg1);
	GLFS_NATIVE_EXIT(env, that, GLFS_glfs_1opendir_FUNC);
	return rc;
}

JNIEXPORT jlong JNICALL GLFS_NATIVE(glfs_1read)
	(JNIEnv *env, jclass that, jlong arg0, jbyteArray arg1, jlong arg2, jint arg3)
{
	jbyte *lparg1=NULL;
	jlong rc = 0;
	GLFS_NATIVE_ENTER(env, that, GLFS_glfs_1read_FUNC);
	if (arg1) if ((lparg1 = (*env)->GetByteArrayElements(env, arg1, NULL)) == NULL) goto fail;
	rc = (ssize_t)glfs_read((glfs_fd_t *)(intptr_t)arg0, (void *)lparg1, (size_t)arg2, arg3);
fail:
	if (arg1 && lparg1) (*env)->ReleaseByteArrayElements(env, arg1, lparg1, 0);
	GLFS_NATIVE_EXIT(env, that, GLFS_glfs_1read_FUNC);
	return rc;
}

JNIEXPORT jint JNICALL GLFS_NATIVE(glfs_1readdir_1r)
	(JNIEnv *env, jclass that, jlong arg0, jobject arg1, jlong arg2)
{
	struct dirent _arg1, *lparg1=NULL;
	jint rc = 0;
	GLFS_NATIVE_ENTER(env, that, GLFS_glfs_1readdir_1r_FUNC);
	if (arg1) if ((lparg1 = &_arg1) == NULL) goto fail;
	rc = (jint)glfs_readdir_r((glfs_fd_t *)(intptr_t)arg0, lparg1, (struct dirent **)(intptr_t)arg2);
fail:
	if (arg1 && lparg1) setdirentFields(env, arg1, lparg1);
	GLFS_NATIVE_EXIT(env, that, GLFS_glfs_1readdir_1r_FUNC);
	return rc;
}

JNIEXPORT jint JNICALL GLFS_NATIVE(glfs_1readlink)
	(JNIEnv *env, jclass that, jlong arg0, jstring arg1, jbyteArray arg2, jlong arg3)
{
	const char *lparg1= NULL;
	jbyte *lparg2=NULL;
	jint rc = 0;
	GLFS_NATIVE_ENTER(env, that, GLFS_glfs_1readlink_FUNC);
	if (arg1) if ((lparg1 = (*env)->GetStringUTFChars(env, arg1, NULL)) == NULL) goto fail;
	if (arg2) if ((lparg2 = (*env)->GetByteArrayElements(env, arg2, NULL)) == NULL) goto fail;
	rc = (jint)glfs_readlink((glfs_t *)(intptr_t)arg0, (const char *)lparg1, (char *)lparg2, (size_t)arg3);
fail:
	if (arg2 && lparg2) (*env)->ReleaseByteArrayElements(env, arg2, lparg2, 0);
	if (arg1 && lparg1) (*env)->ReleaseStringUTFChars(env, arg1, lparg1);
	GLFS_NATIVE_EXIT(env, that, GLFS_glfs_1readlink_FUNC);
	return rc;
}

JNIEXPORT jint JNICALL GLFS_NATIVE(glfs_1rename)
	(JNIEnv *env, jclass that, jlong arg0, jstring arg1, jstring arg2)
{
	const char *lparg1= NULL;
	const char *lparg2= NULL;
	jint rc = 0;
	GLFS_NATIVE_ENTER(env, that, GLFS_glfs_1rename_FUNC);
	if (arg1) if ((lparg1 = (*env)->GetStringUTFChars(env, arg1, NULL)) == NULL) goto fail;
	if (arg2) if ((lparg2 = (*env)->GetStringUTFChars(env, arg2, NULL)) == NULL) goto fail;
	rc = (jint)glfs_rename((glfs_t *)(intptr_t)arg0, (const char *)lparg1, (const char *)lparg2);
fail:
	if (arg2 && lparg2) (*env)->ReleaseStringUTFChars(env, arg2, lparg2);
	if (arg1 && lparg1) (*env)->ReleaseStringUTFChars(env, arg1, lparg1);
	GLFS_NATIVE_EXIT(env, that, GLFS_glfs_1rename_FUNC);
	return rc;
}

JNIEXPORT jint JNICALL GLFS_NATIVE(glfs_1rmdir)
	(JNIEnv *env, jclass that, jlong arg0, jstring arg1)
{
	const char *lparg1= NULL;
	jint rc = 0;
	GLFS_NATIVE_ENTER(env, that, GLFS_glfs_1rmdir_FUNC);
	if (arg1) if ((lparg1 = (*env)->GetStringUTFChars(env, arg1, NULL)) == NULL) goto fail;
	rc = (jint)glfs_rmdir((glfs_t *)(intptr_t)arg0, (const char *)lparg1);
fail:
	if (arg1 && lparg1) (*env)->ReleaseStringUTFChars(env, arg1, lparg1);
	GLFS_NATIVE_EXIT(env, that, GLFS_glfs_1rmdir_FUNC);
	return rc;
}

JNIEXPORT void JNICALL GLFS_NATIVE(glfs_1seekdir)
	(JNIEnv *env, jclass that, jlong arg0, jlong arg1)
{
	GLFS_NATIVE_ENTER(env, that, GLFS_glfs_1seekdir_FUNC);
	glfs_seekdir((glfs_fd_t *)(intptr_t)arg0, arg1);
	GLFS_NATIVE_EXIT(env, that, GLFS_glfs_1seekdir_FUNC);
}

JNIEXPORT jint JNICALL GLFS_NATIVE(glfs_1set_1logging)
	(JNIEnv *env, jclass that, jlong arg0, jstring arg1, jint arg2)
{
	const char *lparg1= NULL;
	jint rc = 0;
	GLFS_NATIVE_ENTER(env, that, GLFS_glfs_1set_1logging_FUNC);
	if (arg1) if ((lparg1 = (*env)->GetStringUTFChars(env, arg1, NULL)) == NULL) goto fail;
	rc = (jint)glfs_set_logging((glfs_t *)(intptr_t)arg0, (const char*)lparg1, arg2);
fail:
	if (arg1 && lparg1) (*env)->ReleaseStringUTFChars(env, arg1, lparg1);
	GLFS_NATIVE_EXIT(env, that, GLFS_glfs_1set_1logging_FUNC);
	return rc;
}

JNIEXPORT jint JNICALL GLFS_NATIVE(glfs_1set_1volfile_1server)
	(JNIEnv *env, jclass that, jlong arg0, jstring arg1, jstring arg2, jint arg3)
{
	const char *lparg1= NULL;
	const char *lparg2= NULL;
	jint rc = 0;
	GLFS_NATIVE_ENTER(env, that, GLFS_glfs_1set_1volfile_1server_FUNC);
	if (arg1) if ((lparg1 = (*env)->GetStringUTFChars(env, arg1, NULL)) == NULL) goto fail;
	if (arg2) if ((lparg2 = (*env)->GetStringUTFChars(env, arg2, NULL)) == NULL) goto fail;
	rc = (jint)glfs_set_volfile_server((glfs_t *)(intptr_t)arg0, (const char*)lparg1, (const char*)lparg2, arg3);
fail:
	if (arg2 && lparg2) (*env)->ReleaseStringUTFChars(env, arg2, lparg2);
	if (arg1 && lparg1) (*env)->ReleaseStringUTFChars(env, arg1, lparg1);
	GLFS_NATIVE_EXIT(env, that, GLFS_glfs_1set_1volfile_1server_FUNC);
	return rc;
}

JNIEXPORT jint JNICALL GLFS_NATIVE(glfs_1stat)
	(JNIEnv *env, jclass that, jlong arg0, jstring arg1, jobject arg2)
{
	const char *lparg1= NULL;
	struct stat _arg2, *lparg2=NULL;
	jint rc = 0;
	GLFS_NATIVE_ENTER(env, that, GLFS_glfs_1stat_FUNC);
	if (arg1) if ((lparg1 = (*env)->GetStringUTFChars(env, arg1, NULL)) == NULL) goto fail;
	if (arg2) if ((lparg2 = &_arg2) == NULL) goto fail;
	rc = (jint)glfs_stat((glfs_t *)(intptr_t)arg0, (const char *)lparg1, lparg2);
fail:
	if (arg2 && lparg2) setstatFields(env, arg2, lparg2);
	if (arg1 && lparg1) (*env)->ReleaseStringUTFChars(env, arg1, lparg1);
	GLFS_NATIVE_EXIT(env, that, GLFS_glfs_1stat_FUNC);
	return rc;
}

JNIEXPORT jint JNICALL GLFS_NATIVE(glfs_1statvfs)
	(JNIEnv *env, jclass that, jlong arg0, jstring arg1, jobject arg2)
{
	const char *lparg1= NULL;
	struct statvfs _arg2, *lparg2=NULL;
	jint rc = 0;
	GLFS_NATIVE_ENTER(env, that, GLFS_glfs_1statvfs_FUNC);
	if (arg1) if ((lparg1 = (*env)->GetStringUTFChars(env, arg1, NULL)) == NULL) goto fail;
	if (arg2) if ((lparg2 = &_arg2) == NULL) goto fail;
	rc = (jint)glfs_statvfs((glfs_t *)(intptr_t)arg0, (const char *)lparg1, lparg2);
fail:
	if (arg2 && lparg2) setstatvfsFields(env, arg2, lparg2);
	if (arg1 && lparg1) (*env)->ReleaseStringUTFChars(env, arg1, lparg1);
	GLFS_NATIVE_EXIT(env, that, GLFS_glfs_1statvfs_FUNC);
	return rc;
}

JNIEXPORT jint JNICALL GLFS_NATIVE(glfs_1symlink)
	(JNIEnv *env, jclass that, jlong arg0, jstring arg1, jstring arg2)
{
	const char *lparg1= NULL;
	const char *lparg2= NULL;
	jint rc = 0;
	GLFS_NATIVE_ENTER(env, that, GLFS_glfs_1symlink_FUNC);
	if (arg1) if ((lparg1 = (*env)->GetStringUTFChars(env, arg1, NULL)) == NULL) goto fail;
	if (arg2) if ((lparg2 = (*env)->GetStringUTFChars(env, arg2, NULL)) == NULL) goto fail;
	rc = (jint)glfs_symlink((glfs_t *)(intptr_t)arg0, (const char *)lparg1, (const char *)lparg2);
fail:
	if (arg2 && lparg2) (*env)->ReleaseStringUTFChars(env, arg2, lparg2);
	if (arg1 && lparg1) (*env)->ReleaseStringUTFChars(env, arg1, lparg1);
	GLFS_NATIVE_EXIT(env, that, GLFS_glfs_1symlink_FUNC);
	return rc;
}

JNIEXPORT jlong JNICALL GLFS_NATIVE(glfs_1telldir)
	(JNIEnv *env, jclass that, jlong arg0)
{
	jlong rc = 0;
	GLFS_NATIVE_ENTER(env, that, GLFS_glfs_1telldir_FUNC);
	rc = (jlong)glfs_telldir((glfs_fd_t *)(intptr_t)arg0);
	GLFS_NATIVE_EXIT(env, that, GLFS_glfs_1telldir_FUNC);
	return rc;
}

JNIEXPORT jint JNICALL GLFS_NATIVE(glfs_1unlink)
	(JNIEnv *env, jclass that, jlong arg0, jstring arg1)
{
	const char *lparg1= NULL;
	jint rc = 0;
	GLFS_NATIVE_ENTER(env, that, GLFS_glfs_1unlink_FUNC);
	if (arg1) if ((lparg1 = (*env)->GetStringUTFChars(env, arg1, NULL)) == NULL) goto fail;
	rc = (jint)glfs_unlink((glfs_t *)(intptr_t)arg0, (const char *)lparg1);
fail:
	if (arg1 && lparg1) (*env)->ReleaseStringUTFChars(env, arg1, lparg1);
	GLFS_NATIVE_EXIT(env, that, GLFS_glfs_1unlink_FUNC);
	return rc;
}

JNIEXPORT jint JNICALL GLFS_NATIVE(glfs_1write)
	(JNIEnv *env, jclass that, jlong arg0, jbyteArray arg1, jint arg2, jint arg3)
{
	jbyte *lparg1=NULL;
	jint rc = 0;
	GLFS_NATIVE_ENTER(env, that, GLFS_glfs_1write_FUNC);
	if (arg1) if ((lparg1 = (*env)->GetByteArrayElements(env, arg1, NULL)) == NULL) goto fail;
	rc = (jint)glfs_write((glfs_fd_t *)(intptr_t)arg0, (const char*)lparg1, arg2, arg3);
fail:
	if (arg1 && lparg1) (*env)->ReleaseByteArrayElements(env, arg1, lparg1, JNI_ABORT);
	GLFS_NATIVE_EXIT(env, that, GLFS_glfs_1write_FUNC);
	return rc;
}

#define GlusterOpenOption_NATIVE(func) Java_com_peircean_libgfapi_1jni_internal_GlusterOpenOption_##func

JNIEXPORT void JNICALL GlusterOpenOption_NATIVE(init)(JNIEnv *env, jclass that)
{
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "O_APPEND", "I"), (jint)O_APPEND);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "O_SYNC", "I"), (jint)O_SYNC);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "O_DSYNC", "I"), (jint)O_DSYNC);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "O_TRUNC", "I"), (jint)O_TRUNC);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "O_RDONLY", "I"), (jint)O_RDONLY);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "O_WRONLY", "I"), (jint)O_WRONLY);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "O_RDWR", "I"), (jint)O_RDWR);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "O_CREAT", "I"), (jint)O_CREAT);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "O_EXCL", "I"), (jint)O_EXCL);
   return;
}
#define UtilJNI_NATIVE(func) Java_com_peircean_libgfapi_1jni_internal_UtilJNI_##func

JNIEXPORT jint JNICALL UtilJNI_NATIVE(errno)
	(JNIEnv *env, jclass that)
{
	jint rc = 0;
	UtilJNI_NATIVE_ENTER(env, that, UtilJNI_errno_FUNC);
	rc = (jint)errno;
	UtilJNI_NATIVE_EXIT(env, that, UtilJNI_errno_FUNC);
	return rc;
}

JNIEXPORT void JNICALL UtilJNI_NATIVE(memmove)
	(JNIEnv *env, jclass that, jbyteArray arg0, jlong arg1, jlong arg2)
{
	jbyte *lparg0=NULL;
	UtilJNI_NATIVE_ENTER(env, that, UtilJNI_memmove_FUNC);
#ifdef JNI_VERSION_1_2
	if (IS_JNI_1_2) {
		if (arg0) if ((lparg0 = (*env)->GetPrimitiveArrayCritical(env, arg0, NULL)) == NULL) goto fail;
	} else
#endif
	{
		if (arg0) if ((lparg0 = (*env)->GetByteArrayElements(env, arg0, NULL)) == NULL) goto fail;
	}
	memmove((void *)lparg0, (const void *)(intptr_t)arg1, (size_t)arg2);
fail:
#ifdef JNI_VERSION_1_2
	if (IS_JNI_1_2) {
		if (arg0 && lparg0) (*env)->ReleasePrimitiveArrayCritical(env, arg0, lparg0, 0);
	} else
#endif
	{
		if (arg0 && lparg0) (*env)->ReleaseByteArrayElements(env, arg0, lparg0, 0);
	}
	UtilJNI_NATIVE_EXIT(env, that, UtilJNI_memmove_FUNC);
}

JNIEXPORT jlong JNICALL UtilJNI_NATIVE(strerror_1jni)
	(JNIEnv *env, jclass that, jint arg0)
{
	jlong rc = 0;
	UtilJNI_NATIVE_ENTER(env, that, UtilJNI_strerror_1jni_FUNC);
	rc = (intptr_t)(char *)strerror(arg0);
	UtilJNI_NATIVE_EXIT(env, that, UtilJNI_strerror_1jni_FUNC);
	return rc;
}

JNIEXPORT jint JNICALL UtilJNI_NATIVE(strlen)
	(JNIEnv *env, jclass that, jlong arg0)
{
	jint rc = 0;
	UtilJNI_NATIVE_ENTER(env, that, UtilJNI_strlen_FUNC);
	rc = (jint)strlen((const char *)(intptr_t)arg0);
	UtilJNI_NATIVE_EXIT(env, that, UtilJNI_strlen_FUNC);
	return rc;
}

#define dirent_NATIVE(func) Java_com_peircean_libgfapi_1jni_internal_structs_dirent_##func

JNIEXPORT void JNICALL dirent_NATIVE(free)
	(JNIEnv *env, jclass that, jlong arg0)
{
	dirent_NATIVE_ENTER(env, that, dirent_free_FUNC);
	free((void *)(intptr_t)arg0);
	dirent_NATIVE_EXIT(env, that, dirent_free_FUNC);
}

JNIEXPORT void JNICALL dirent_NATIVE(init)(JNIEnv *env, jclass that)
{
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "DT_UNKNOWN", "I"), (jint)DT_UNKNOWN);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "DT_FIFO", "I"), (jint)DT_FIFO);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "DT_CHR", "I"), (jint)DT_CHR);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "DT_DIR", "I"), (jint)DT_DIR);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "DT_BLK", "I"), (jint)DT_BLK);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "DT_REG", "I"), (jint)DT_REG);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "DT_LNK", "I"), (jint)DT_LNK);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "DT_SOCK", "I"), (jint)DT_SOCK);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "DT_WHT", "I"), (jint)DT_WHT);
	(*env)->SetStaticShortField(env, that, (*env)->GetStaticFieldID(env, that, "SIZE_OF", "S"), (jshort)sizeof(struct dirent));
   return;
}
JNIEXPORT jlong JNICALL dirent_NATIVE(malloc)
	(JNIEnv *env, jclass that, jlong arg0)
{
	jlong rc = 0;
	dirent_NATIVE_ENTER(env, that, dirent_malloc_FUNC);
	rc = (intptr_t)(void *)malloc((size_t)arg0);
	dirent_NATIVE_EXIT(env, that, dirent_malloc_FUNC);
	return rc;
}

JNIEXPORT void JNICALL dirent_NATIVE(memmove__JLcom_peircean_libgfapi_1jni_internal_structs_dirent_2J)
	(JNIEnv *env, jclass that, jlong arg0, jobject arg1, jlong arg2)
{
	struct dirent _arg1, *lparg1=NULL;
	dirent_NATIVE_ENTER(env, that, dirent_memmove__JLcom_peircean_libgfapi_1jni_internal_structs_dirent_2J_FUNC);
	if (arg1) if ((lparg1 = getdirentFields(env, arg1, &_arg1)) == NULL) goto fail;
	memmove((void *)(intptr_t)arg0, (const void *)lparg1, (size_t)arg2);
fail:
	dirent_NATIVE_EXIT(env, that, dirent_memmove__JLcom_peircean_libgfapi_1jni_internal_structs_dirent_2J_FUNC);
}

JNIEXPORT void JNICALL dirent_NATIVE(memmove__Lcom_peircean_libgfapi_1jni_internal_structs_dirent_2JJ)
	(JNIEnv *env, jclass that, jobject arg0, jlong arg1, jlong arg2)
{
	struct dirent _arg0, *lparg0=NULL;
	dirent_NATIVE_ENTER(env, that, dirent_memmove__Lcom_peircean_libgfapi_1jni_internal_structs_dirent_2JJ_FUNC);
	if (arg0) if ((lparg0 = &_arg0) == NULL) goto fail;
	memmove((void *)lparg0, (const void *)(intptr_t)arg1, (size_t)arg2);
fail:
	if (arg0 && lparg0) setdirentFields(env, arg0, lparg0);
	dirent_NATIVE_EXIT(env, that, dirent_memmove__Lcom_peircean_libgfapi_1jni_internal_structs_dirent_2JJ_FUNC);
}

