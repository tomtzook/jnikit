#pragma once

#include <utility>
#include <jni.h>

#include "types.h"
#include "signatures.h"
#include "functions.h"


namespace jnikit {

template<class _type>
class Method;
template<class _type>
class StaticMethod;

template<class R, class... Args>
class Method<R(Args...)> {
public:
    using MethodType = jnikit::types::MethodType<R(Args...)>;
    using ReturnType = typename R::CType;

    Method(JNIEnv* env, jmethodID methodId)
        : m_env(env)
        , m_methodId(methodId)
    {}

    Method(JNIEnv* env, jclass cls, const char* name)
        : m_env(env)
        , m_methodId(m_env->GetMethodID(cls, name, types::Signature<MethodType>()()))
    {
        // TODO: CHECK FOR ERROR
    }

    jmethodID id() const {
        return m_methodId;
    }

    ReturnType call(jobject instance, typename Args::CType... args) {
        if constexpr (std::is_void_v<ReturnType>) {
            m_env->CallVoidMethod(instance, m_methodId, args...);
            // TODO: CHECK FOR ERROR
        } else {
            ReturnType result = (m_env->*(env::EnvFunctions<ReturnType>::CallMethod))(instance, m_methodId, args...);
            // TODO: CHECK FOR ERROR
            return result;
        }
    }

    ReturnType callNonVirtual(jobject instance, typename Args::CType... args) {
        if constexpr (std::is_void_v<ReturnType>) {
            m_env->CallNonvirtualVoidMethod(instance, m_methodId, args...);
            // TODO: CHECK FOR ERROR
        } else {
            ReturnType result = (m_env->*(env::EnvFunctions<ReturnType>::CallNonVirtualMethod))(instance, m_methodId, args...);
            // TODO: CHECK FOR ERROR
            return result;
        }
    }

private:
    JNIEnv* m_env;
    jmethodID m_methodId;
};


template<class R, class... Args>
class StaticMethod<R(Args...)> {
public:
    using MethodType = jnikit::types::MethodType<R(Args...)>;
    using ReturnType = typename R::CType;

    StaticMethod(JNIEnv* env, jclass cls, jmethodID methodId)
        : m_env(env)
        , m_cls(cls)
        , m_methodId(methodId)
    {}

    StaticMethod(JNIEnv* env, jclass cls, const char* name)
        : m_env(env)
        , m_cls(cls)
        , m_methodId(m_env->GetStaticMethodID(cls, name, types::Signature<MethodType>()()))
    {
        // TODO: CHECK FOR ERROR
    }

    jmethodID id() const {
        return m_methodId;
    }

    ReturnType call(typename Args::CType... args) {
        if constexpr (std::is_void_v<ReturnType>) {
            m_env->CallStaticVoidMethod(m_cls, m_methodId, args...);
            // TODO: CHECK FOR ERROR
        } else {
            ReturnType result = (m_env->*(env::EnvFunctions<ReturnType>::CallStaticMethod))(m_cls, m_methodId, args...);
            // TODO: CHECK FOR ERROR
            return result;
        }
    }

private:
    JNIEnv* m_env;
    jclass m_cls;
    jmethodID m_methodId;
};


template<class _type>
class Class {
public:
    using Type = _type;

    Class(JNIEnv* env, jclass cls)
        : m_env(env)
        , m_cls(cls)
    {}

    jclass cls() const {
        return m_cls;
    }

    template<class T>
    Method<T> method(const char* name) {
        return Method<T>{m_env, m_cls, name};
    }

    template<class T>
    StaticMethod<T> staticMethod(const char* name) {
        return StaticMethod<T>{m_env, m_cls, name};
    }

private:
    JNIEnv* m_env;
    jclass m_cls;
};


}
