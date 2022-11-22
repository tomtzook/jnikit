#pragma once

#include <utility>
#include <jni.h>

#include "types.h"
#include "signatures.h"
#include "except.h"
#include "functions.h"


namespace jnikit {

template<class T, typename = void>
class Array;


template<class T>
class Array<T,
        typename std::enable_if<types::IsPrimitive<typename T::InnerType>::value>::type>  {
public:
    using ArrayType = T;
    using NativeArrayType = typename T::CType;
    using InnerType = typename T::InnerType::CType;

    Array(JNIEnv* env, NativeArrayType instance)
        : m_env(env)
        , m_instance(instance)
    {}

    Array(Array& other) = delete;
    Array(Array&& other) = delete;

    Array& operator=(Array& other) = delete;
    Array& operator=(Array&& other) = delete;

    NativeArrayType array() {
        return m_instance;
    }

    [[nodiscard]] jsize length() const {
        jsize size = m_env->GetArrayLength(m_instance);
        throwIfPendingException(m_env);
        return size;
    }

    InnerType getElement(jsize index) {
        InnerType t;
        (m_env->*(env::EnvFunctions<InnerType>::GetArrayRegion))(m_instance, index, 1, &t);
        throwIfPendingException(m_env);
        return t;
    }

    void setElement(jsize index, InnerType value) {
        (m_env->*(env::EnvFunctions<InnerType>::SetArrayRegion))(m_instance, index, 1, &value);
        throwIfPendingException(m_env);
    }

    void fill(InnerType* valueArr, size_t size) {
        (m_env->*(env::EnvFunctions<InnerType>::SetArrayRegion))(m_instance, 0, size, valueArr);
        throwIfPendingException(m_env);
    }

    static Array newInstance(JNIEnv* env, jsize size) {
        NativeArrayType array = (env->*(env::EnvFunctions<InnerType>::NewArray))(size);
        throwIfPendingException(env);
        return {env, array};
    }

private:
    JNIEnv* m_env;
    NativeArrayType m_instance;
};

template<class T>
class Array<T,
        typename std::enable_if<
                std::disjunction<
                        typename types::IsObject<typename T::InnerType>::value,
                        typename types::IsArray<T>::value
                >::value
        >::type>  {
public:
    using NativeArrayType = typename T::CType;
    using InnerType = typename T::InnerType::CType;

    Array(JNIEnv* env, NativeArrayType instance)
        : m_env(env)
        , m_instance(instance)
    {}

    Array(Array& other) = delete;
    Array(Array&& other) = delete;

    Array& operator=(Array& other) = delete;
    Array& operator=(Array&& other) = delete;

    NativeArrayType array() {
        return m_instance;
    }

    [[nodiscard]] jsize length() const {
        jsize size = m_env->GetArrayLength(m_instance);
        throwIfPendingException(m_env);
        return size;
    }

    InnerType getElement(jsize index) {
        InnerType t = (m_env->*(env::EnvFunctions<InnerType>::GetArrayElement))(m_instance, index);
        throwIfPendingException(m_env);
        return t;
    }

    void setElement(jsize index, InnerType& value) {
        (m_env->*(env::EnvFunctions<InnerType>::SetArrayElement))(m_instance, index, value);
        throwIfPendingException(m_env);
    }

    static Array newInstance(JNIEnv* env, jclass cls, jsize size) {
        NativeArrayType array = (env->*(env::EnvFunctions<InnerType>::NewArray))(size, cls, nullptr);
        throwIfPendingException(env);
        return {env, array};
    }

private:
    JNIEnv* m_env;
    NativeArrayType m_instance;
};

using BooleanArray = Array<types::BooleanArray>;
using CharArray = Array<types::CharArray>;
using ByteArray = Array<types::ByteArray>;
using ShortArray = Array<types::ShortArray>;
using IntArray = Array<types::IntArray>;
using LongArray = Array<types::LongArray>;
using FloatArray = Array<types::FloatArray>;
using DoubleArray = Array<types::DoubleArray>;

template<class T>
using ObjectArray = Array<types::ObjectArray<T>>;

}
