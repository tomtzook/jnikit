#pragma once

#include <utility>
#include <jni.h>

#include "types.h"
#include "signatures.h"
#include "functions.h"
#include "except.h"


namespace jnikit {

template<class T, class... Args>
class Constructor;
template<class T>
class Method;
template<class T>
class StaticMethod;
template<class T>
class Field;
template<class T>
class StaticField;


template<class T, class... Args>
class Constructor {
public:
    using MethodType = jnikit::types::MethodType<types::Void(Args...)>;

    Constructor(JNIEnv* env, jclass cls, jmethodID methodId)
        : m_env(env)
        , m_cls(cls)
        , m_methodId(methodId)
    {}

    Constructor(JNIEnv* env, jclass cls)
        : m_env(env)
        , m_cls(cls)
        , m_methodId(m_env->GetMethodID(cls, NAME, types::Signature<MethodType>()()))
    {
        throwIfPendingException(env);
    }

    jobject call(typename Args::CType... args) {
        jobject instance = m_env->NewObject(m_cls, m_methodId, args...);
        throwIfPendingException(m_env);
        return instance;
    }

private:
    static constexpr char NAME[] = "<init>";

    JNIEnv* m_env;
    jclass m_cls;
    jmethodID m_methodId;
};

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
        throwIfPendingException(env);
    }

    ReturnType call(jobject instance, typename Args::CType... args) {
        if constexpr (std::is_void_v<ReturnType>) {
            m_env->CallVoidMethod(instance, m_methodId, args...);
            throwIfPendingException(m_env);
        } else {
            ReturnType result = (m_env->*(env::EnvFunctions<ReturnType>::CallMethod))(instance, m_methodId, args...);
            throwIfPendingException(m_env);
            return result;
        }
    }

    ReturnType callNonVirtual(jobject instance, typename Args::CType... args) {
        if constexpr (std::is_void_v<ReturnType>) {
            m_env->CallNonvirtualVoidMethod(instance, m_methodId, args...);
            throwIfPendingException(m_env);
        } else {
            ReturnType result = (m_env->*(env::EnvFunctions<ReturnType>::CallNonVirtualMethod))(instance, m_methodId, args...);
            throwIfPendingException(m_env);
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
        throwIfPendingException(env);
    }

    ReturnType call(typename Args::CType... args) {
        if constexpr (std::is_void_v<ReturnType>) {
            m_env->CallStaticVoidMethod(m_cls, m_methodId, args...);
            throwIfPendingException(m_env);
        } else {
            ReturnType result = (m_env->*(env::EnvFunctions<ReturnType>::CallStaticMethod))(m_cls, m_methodId, args...);
            throwIfPendingException(m_env);
            return result;
        }
    }

private:
    JNIEnv* m_env;
    jclass m_cls;
    jmethodID m_methodId;
};


template<class T>
class Field {
public:
    using Type = typename T::CType;

    Field(JNIEnv* env, jfieldID fieldId)
        : m_env(env)
        , m_fieldId(fieldId)
    {}

    Field(JNIEnv* env, jclass cls, const char* name)
        : m_env(env)
        , m_fieldId(env->GetFieldID(cls, name, types::Signature<T>()()))
    {
        throwIfPendingException(env);
    }

    Type get(jobject instance) {
        Type result = (m_env->*(env::EnvFunctions<Type>::GetField))(instance, m_fieldId);
        throwIfPendingException(m_env);
        return result;
    }

    void set(jobject instance, Type value) {
        (m_env->*(env::EnvFunctions<Type>::SetField))(instance, m_fieldId, value);
        throwIfPendingException(m_env);
    }

private:
    JNIEnv* m_env;
    jfieldID m_fieldId;
};

template<class T>
class StaticField {
public:
    using Type = typename T::CType;

    StaticField(JNIEnv* env, jclass cls, jfieldID fieldId)
        : m_env(env)
        , m_cls(cls)
        , m_fieldId(fieldId)
    {}

    StaticField(JNIEnv* env, jclass cls, const char* name)
        : m_env(env)
        , m_cls(cls)
        , m_fieldId(env->GetStaticFieldID(cls, name, types::Signature<T>()()))
    {}

    Type get() {
        Type result = (m_env->*(env::EnvFunctions<Type>::GetStaticField))(m_cls, m_fieldId);
        throwIfPendingException(m_env);
        return result;
    }

    void set(Type value) {
        (m_env->*(env::EnvFunctions<Type>::SetStaticField))(m_cls, m_fieldId, value);
        throwIfPendingException(m_env);
    }

private:
    JNIEnv* m_env;
    jclass m_cls;
    jfieldID m_fieldId;
};

template<class CT>
class Class {
public:
    using Type = CT;

    Class(JNIEnv* env, jclass cls)
        : m_env(env)
        , m_cls(cls)
    {}

    template<class... Args>
    Constructor<CT, Args...> constructor() {
        return Constructor<CT, Args...>{m_env, m_cls};
    }

    template<class T>
    Method<T> method(const char* name) {
        return Method<T>{m_env, m_cls, name};
    }

    template<class T>
    StaticMethod<T> staticMethod(const char* name) {
        return StaticMethod<T>{m_env, m_cls, name};
    }

    template<class T>
    Field<T> field(const char* name) {
        return Field<T>{m_env, m_cls, name};
    }

    template<class T>
    StaticField<T> staticField(const char* name) {
        return StaticField<T>{m_env, m_cls, name};
    }

    template<class FT>
    typename FT::CType getStaticField(const char* name) {
        auto field = staticField<FT>(name);
        return field.get();
    }

    template<class FT>
    void setStaticField(const char* name, typename FT::CType value) {
        auto field = staticField<FT>(name);
        return field.set(value);
    }

    template<class R, class... Args>
    typename R::CType callStaticMethod(const char* name, typename Args::CType... args) {
        using t = R(Args...);
        auto method = staticMethod<t>(name);
        return method.call(args...);
    }

    template<class... Args>
    jobject newInstance(typename Args::CType... args) {
        auto ctor = constructor<Args...>();
        return ctor.call(args...);
    }

private:
    JNIEnv* m_env;
    jclass m_cls;
};


}
