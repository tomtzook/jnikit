#pragma once

#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif

jclass jnikit_get_class(JNIEnv* env, const char* name);

jmethodID jnikit_get_static_method(JNIEnv* env, jclass cls, const char* name, const char* signature);

jmethodID jnikit_get_method(JNIEnv* env, jclass cls, const char* name, const char* signature);

jmethodID jnikit_get_constructor(JNIEnv* env, jclass cls, const char* signature);

jfieldID jnikit_get_static_field(JNIEnv* env, jclass cls, const char* name, const char* signature);

jfieldID jnikit_get_field(JNIEnv* env, jclass cls, const char* name, const char* signature);

jint jnikit_get_enum_ordinal(JNIEnv* env, jclass cls, jobject enum_constant);

jobject jnikit_new_object(JNIEnv* env, const char* cls, const char* ctor_signature, ...);
jobject jnikit_new_object_a(JNIEnv* env, const char* cls, const char* ctor_signature, const jvalue* args);
jobject jnikit_new_object_v(JNIEnv* env, const char* cls, const char* ctor_signature, va_list args);

#ifdef __cplusplus
}
#endif
