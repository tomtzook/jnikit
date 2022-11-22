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

template<typename IT>
struct ToArrayType {};
template<> struct ToArrayType<Boolean> { using Type = BooleanArray; };
template<> struct ToArrayType<Char> { using Type = CharArray; };
template<> struct ToArrayType<Byte> { using Type = ByteArray; };
template<> struct ToArrayType<Short> { using Type = ShortArray; };
template<> struct ToArrayType<Int> { using Type = IntArray; };
template<> struct ToArrayType<Long> { using Type = LongArray; };
template<> struct ToArrayType<Float> { using Type = FloatArray; };
template<> struct ToArrayType<Double> { using Type = DoubleArray; };

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
template<typename CT, typename IT>
struct IsObject<ArrayType<CT, IT>> : public std::true_type {};

template<class T>
struct IsArray : public std::false_type {};
template<> struct IsArray<BooleanArray> : public std::true_type {};
template<> struct IsArray<CharArray> : public std::true_type {};
template<> struct IsArray<ByteArray> : public std::true_type {};
template<> struct IsArray<ShortArray> : public std::true_type {};
template<> struct IsArray<IntArray> : public std::true_type {};
template<> struct IsArray<LongArray> : public std::true_type {};
template<> struct IsArray<FloatArray> : public std::true_type {};
template<> struct IsArray<DoubleArray> : public std::true_type {};
template<class T>
struct IsArray<ObjectArray<T>> : public std::true_type {};

}
