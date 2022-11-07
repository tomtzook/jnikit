#pragma once

#include <jni.h>

#include "types.h"
#include "signatures.h"


namespace jnikit {

template<class _type>
jmethodID getMethodId(JNIEnv* env, jclass cls, const char* name) {
    jmethodID methodId = env->GetMethodID(cls, name, jnikit::types::Signature<_type>()());
    if (nullptr == methodId) {

    }

    return methodId;
}




}