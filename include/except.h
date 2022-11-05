#pragma once

#include <jni.h>


#ifdef __cplusplus
extern "C" {
#endif

void jnikit_throw_out_of_memory(JNIEnv* env, const char* message);

void jnikit_throw_unsupported(JNIEnv* env, const char* message);

void jnikit_throw_class_not_found(JNIEnv* env, const char* name);

void jnikit_throw_method_not_found(JNIEnv* env, const char* name, const char* signature);

void jnikit_throw_field_not_found(JNIEnv* env, const char* name, const char* signature);

#ifdef __cplusplus
}
#endif
