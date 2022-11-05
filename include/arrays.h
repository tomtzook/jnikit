#pragma once

#include <jni.h>

#include "types.h"
#include "signatures.h"


#ifdef __cplusplus
extern "C" {
#endif

jarray jnikit_new_primitivearray(JNIEnv* env, jnikit_primitive_type_t type, jsize size);
jarray jnikit_new_objectarray(JNIEnv* env, const char* type_name, jsize size, jobject initial_value);


#ifdef __cplusplus
}
#endif
