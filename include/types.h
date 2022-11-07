#pragma once

#include <jni.h>

#include "meta.h"


namespace jnikit::types {

template<typename T>
struct Type {
    using CType = T;
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


template<typename NT>
struct ObjectType : public Type<jobject> {
    using NameType = NT;
};

template<typename CT, typename IT>
struct ArrayType : public Type<CT> {
    using InnerType = IT;
};

using BooleanArray = ArrayType<jbooleanArray, Boolean>;
using CharArray = ArrayType<jcharArray, Char>;
using ByteArray = ArrayType<jbyteArray, Byte>;
using ShortArray = ArrayType<jshortArray, Short>;
using IntArray = ArrayType<jintArray, Int>;
using LongArray = ArrayType<jlongArray, Long>;
using FloatArray = ArrayType<jfloatArray, Float>;
using DoubleArray = ArrayType<jdoubleArray, Double>;
template<typename InnerType>
using ObjectArray = ArrayType<jobjectArray, InnerType>;

template<typename R, typename... Args>
struct MethodType;

template<typename R, typename... Args>
struct MethodType<R(Args...)> {
    using ReturnType = R;
};

#define DEFINE_OBJECT_TYPE(name, java_class_full_name) \
    struct name##_nameholder { static constexpr auto Name() { return java_class_full_name; } }; \
    using name = jnikit::types::ObjectType<name##_nameholder>;


template<class T>
struct IsPrimitive : public std::false_type {};
template<> struct IsPrimitive<Boolean> : public std::true_type {};
template<> struct IsPrimitive<Char> : public std::true_type {};
template<> struct IsPrimitive<Byte> : public std::true_type {};
template<> struct IsPrimitive<Short> : public std::true_type {};
template<> struct IsPrimitive<Int> : public std::true_type {};
template<> struct IsPrimitive<Long> : public std::true_type {};
template<> struct IsPrimitive<Float> : public std::true_type {};
template<> struct IsPrimitive<Double> : public std::true_type {};

template<class T>
struct IsObject : public std::false_type {};
template<class NameType>
struct IsObject<ObjectType<NameType>> : public std::true_type {};

}
