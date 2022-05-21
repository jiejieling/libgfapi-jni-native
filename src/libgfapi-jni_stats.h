/*******************************************************************************
* Copyright (C) 2013, Louis Zuckerman.
*******************************************************************************/
#ifdef NATIVE_STATS
extern int GLFS_nativeFunctionCount;
extern int GLFS_nativeFunctionCallCount[];
extern char* GLFS_nativeFunctionNames[];
#define GLFS_NATIVE_ENTER(env, that, func) GLFS_nativeFunctionCallCount[func]++;
#define GLFS_NATIVE_EXIT(env, that, func) 
#else
#ifndef GLFS_NATIVE_ENTER
#define GLFS_NATIVE_ENTER(env, that, func) 
#endif
#ifndef GLFS_NATIVE_EXIT
#define GLFS_NATIVE_EXIT(env, that, func) 
#endif
#endif

typedef enum {
	GLFS_glfs_1access_FUNC,
	GLFS_glfs_1chmod_FUNC,
	GLFS_glfs_1close_FUNC,
	GLFS_glfs_1closedir_FUNC,
	GLFS_glfs_1creat_FUNC,
	GLFS_glfs_1fini_FUNC,
	GLFS_glfs_1from_1glfd_FUNC,
	GLFS_glfs_1fstat_FUNC,
	GLFS_glfs_1fsync_FUNC,
	GLFS_glfs_1init_FUNC,
	GLFS_glfs_1lseek_FUNC,
	GLFS_glfs_1lstat_FUNC,
	GLFS_glfs_1mkdir_FUNC,
	GLFS_glfs_1new_FUNC,
	GLFS_glfs_1open_FUNC,
	GLFS_glfs_1opendir_FUNC,
	GLFS_glfs_1read_FUNC,
	GLFS_glfs_1readdir_1r_FUNC,
	GLFS_glfs_1readlink_FUNC,
	GLFS_glfs_1rename_FUNC,
	GLFS_glfs_1rmdir_FUNC,
	GLFS_glfs_1seekdir_FUNC,
	GLFS_glfs_1set_1logging_FUNC,
	GLFS_glfs_1set_1volfile_1server_FUNC,
	GLFS_glfs_1stat_FUNC,
	GLFS_glfs_1statvfs_FUNC,
	GLFS_glfs_1symlink_FUNC,
	GLFS_glfs_1telldir_FUNC,
	GLFS_glfs_1unlink_FUNC,
	GLFS_glfs_1write_FUNC,
} GLFS_FUNCS;
#ifdef NATIVE_STATS
extern int GlusterOpenOption_nativeFunctionCount;
extern int GlusterOpenOption_nativeFunctionCallCount[];
extern char* GlusterOpenOption_nativeFunctionNames[];
#define GlusterOpenOption_NATIVE_ENTER(env, that, func) GlusterOpenOption_nativeFunctionCallCount[func]++;
#define GlusterOpenOption_NATIVE_EXIT(env, that, func) 
#else
#ifndef GlusterOpenOption_NATIVE_ENTER
#define GlusterOpenOption_NATIVE_ENTER(env, that, func) 
#endif
#ifndef GlusterOpenOption_NATIVE_EXIT
#define GlusterOpenOption_NATIVE_EXIT(env, that, func) 
#endif
#endif

typedef enum {
	GlusterOpenOption_init_FUNC,
} GlusterOpenOption_FUNCS;
#ifdef NATIVE_STATS
extern int UtilJNI_nativeFunctionCount;
extern int UtilJNI_nativeFunctionCallCount[];
extern char* UtilJNI_nativeFunctionNames[];
#define UtilJNI_NATIVE_ENTER(env, that, func) UtilJNI_nativeFunctionCallCount[func]++;
#define UtilJNI_NATIVE_EXIT(env, that, func) 
#else
#ifndef UtilJNI_NATIVE_ENTER
#define UtilJNI_NATIVE_ENTER(env, that, func) 
#endif
#ifndef UtilJNI_NATIVE_EXIT
#define UtilJNI_NATIVE_EXIT(env, that, func) 
#endif
#endif

typedef enum {
	UtilJNI_errno_FUNC,
	UtilJNI_memmove_FUNC,
	UtilJNI_strerror_1jni_FUNC,
	UtilJNI_strlen_FUNC,
} UtilJNI_FUNCS;
#ifdef NATIVE_STATS
extern int dirent_nativeFunctionCount;
extern int dirent_nativeFunctionCallCount[];
extern char* dirent_nativeFunctionNames[];
#define dirent_NATIVE_ENTER(env, that, func) dirent_nativeFunctionCallCount[func]++;
#define dirent_NATIVE_EXIT(env, that, func) 
#else
#ifndef dirent_NATIVE_ENTER
#define dirent_NATIVE_ENTER(env, that, func) 
#endif
#ifndef dirent_NATIVE_EXIT
#define dirent_NATIVE_EXIT(env, that, func) 
#endif
#endif

typedef enum {
	dirent_free_FUNC,
	dirent_init_FUNC,
	dirent_malloc_FUNC,
	dirent_memmove__JLcom_peircean_libgfapi_1jni_internal_structs_dirent_2J_FUNC,
	dirent_memmove__Lcom_peircean_libgfapi_1jni_internal_structs_dirent_2JJ_FUNC,
} dirent_FUNCS;
