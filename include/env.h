#pragma once

#include <jni.h>

#include "signatures.h"
#include "class.h"
#include "except.h"


namespace jnikit {

class Env {
public:
    Env(JNIEnv* env)
        : m_env(env)
    {}

    template<class T>
    Class<T> getClass() {
        jclass cls = m_env->FindClass(types::Signature<T>()());
        throwIfPendingException(m_env);
        return {m_env, cls};
    }

private:
    JNIEnv* m_env;
};

}
