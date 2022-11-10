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

    Env(Env& other) = delete;
    Env(Env&& other) = delete;

    Env& operator=(Env& other) = delete;
    Env& operator=(Env&& other) = delete;

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

    void throwException(jthrowable ex) {
        m_env->Throw(ex);
        throwIfPendingException(m_env);
    }

    template<class T>
    void throwException(const char* msg) {
        auto cls = getClass<T>();
        m_env->ThrowNew(cls.classObj(), msg);
        throwIfPendingException(m_env);
    }

    template<class T, class... Args>
    void throwException(typename Args::CType... args) {
        auto cls = getClass<T>();
        auto instance = cls.template newInstance<Args...>(args...);
        throwException(reinterpret_cast<jthrowable>(instance));
    }

private:
    JNIEnv* m_env;
};

}
