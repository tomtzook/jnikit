#pragma once

#include <jni.h>

#include "meta.h"


namespace jnikit::types {

template<typename _c_type>
struct Type {
    using CType = _c_type;
};

using Boolean = Type<jboolean>;
using Char = Type<jchar>;
using Byte = Type<jbyte>;
using Short = Type<jshort>;
using Int = Type<jint>;
using Long = Type<jlong>;
using Float = Type<jfloat>;
using Double = Type<jdouble>;
using Void = Type<void>;


template<typename _name_type>
struct ObjectType : public Type<jobject> {
    using NameType = _name_type;
};

template<typename _c_type, typename _inner_type>
struct ArrayType : public Type<_c_type> {
    using InnerType = _inner_type;
};

using BooleanArray = ArrayType<jbooleanArray, Boolean>;
using CharArray = ArrayType<jcharArray, Char>;
using ByteArray = ArrayType<jbyteArray, Byte>;
using ShortArray = ArrayType<jshortArray, Short>;
using IntArray = ArrayType<jintArray, Int>;
using LongArray = ArrayType<jlongArray, Long>;
using FloatArray = ArrayType<jfloatArray, Float>;
using DoubleArray = ArrayType<jdoubleArray, Double>;
template<typename _inner_type>
using ObjectArray = ArrayType<jobjectArray, _inner_type>;


template<typename R, typename... Args>
struct MethodType;

template<typename R, typename... Args>
struct MethodType<R(Args...)> {
    using ReturnType = R;
};

#define DEFINE_OBJECT_TYPE(name, java_class_full_name) \
    struct name##_nameholder { static constexpr auto Name() { return java_class_full_name; } }; \
    using name = jnikit::types::ObjectType<name##_nameholder>;


DEFINE_OBJECT_TYPE(Object, "java/lang/Object")
DEFINE_OBJECT_TYPE(String, "java/lang/String")


/*

template<class _name_type>
struct ObjectType : Type<jobject> {
    constexpr auto operator()() const {
        return meta::concat(meta::StringLiteral<'L'>(), _name_type::Name()(), meta::StringLiteral<';'>());
    }
};

template<class _ctype, class _inner_type>
struct ArrayType : Type<_ctype> {
    constexpr auto operator()() const {
        return meta::concat(meta::StringLiteral<'['>(), _inner_type()());
    }
};

using BooleanArray = ArrayType<jbooleanArray, Boolean>;
using CharArray = ArrayType<jcharArray, Char>;
using ByteArray = ArrayType<jbyteArray, Byte>;
using ShortArray = ArrayType<jshortArray, Short>;
using IntArray = ArrayType<jintArray, Int>;
using LongArray = ArrayType<jlongArray, Long>;
using FloatArray = ArrayType<jfloatArray, Float>;
using DoubleArray = ArrayType<jdoubleArray, Double>;

template<class _inner_type>
struct ArrayType<jobjectArray, _inner_type> {
    constexpr auto operator()() const {
        return meta::concat(meta::StringLiteral<'['>(), _inner_type()());
    }
};

template<class>
struct MethodSignature;

template<class R, class... Args>
struct MethodSignature<R(Args...)> {
    constexpr auto operator()() const {
        return meta::concat(meta::StringLiteral<'('>(), Args()()..., meta::StringLiteral<')'>(), R()());
    }
};*/

}
