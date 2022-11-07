#pragma once

#include <jni.h>

#include "signatures.h"
#include "class.h"
#include "except.h"
#include "array.h"
#include "types.h"


namespace jnikit {

class Env {
public:
    explicit Env(JNIEnv* env)
        : m_env(env)
    {}

    template<class T,
            typename = typename std::enable_if<types::IsArray<T>::value>::type>
    Array<T> newArray(jsize size) {
        return Array<T>::newInstance(m_env, size);
    }

    template<class T,
            typename = typename std::enable_if<types::IsObject<T>::value>::type>
    ObjectArray<T> newObjectArray(jsize size) {
        auto cls = getClass<T>();
        return cls.newArray(size);
    }

    template<class T,
            typename = typename std::enable_if<types::IsObject<T>::value>::type>
    Class<T> getClass() {
        jclass cls = m_env->FindClass(types::Signature<T>()());
        throwIfPendingException(m_env);
        return {m_env, cls};
    }

private:
    JNIEnv* m_env;
};

}
