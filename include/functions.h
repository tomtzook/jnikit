#pragma once

#include <jni.h>


namespace jnikit::env {

template<class>
struct EnvFunctions{};

template<>
struct EnvFunctions<jboolean> {
    static constexpr auto CallMethod = &JNIEnv::CallBooleanMethod;
    static constexpr auto CallNonVirtualMethod = &JNIEnv::CallNonvirtualBooleanMethod;
    static constexpr auto CallStaticMethod = &JNIEnv::CallStaticBooleanMethod;
};

template<>
struct EnvFunctions<jchar> {
    static constexpr auto CallMethod = &JNIEnv::CallCharMethod;
    static constexpr auto CallNonVirtualMethod = &JNIEnv::CallNonvirtualCharMethod;
    static constexpr auto CallStaticMethod = &JNIEnv::CallStaticCharMethod;
};

template<>
struct EnvFunctions<jbyte> {
    static constexpr auto CallMethod = &JNIEnv::CallByteMethod;
    static constexpr auto CallNonVirtualMethod = &JNIEnv::CallNonvirtualByteMethod;
    static constexpr auto CallStaticMethod = &JNIEnv::CallStaticByteMethod;
};

template<>
struct EnvFunctions<jshort> {
    static constexpr auto CallMethod = &JNIEnv::CallShortMethod;
    static constexpr auto CallNonVirtualMethod = &JNIEnv::CallNonvirtualShortMethod;
    static constexpr auto CallStaticMethod = &JNIEnv::CallStaticShortMethod;
};

template<>
struct EnvFunctions<jint> {
    static constexpr auto CallMethod = &JNIEnv::CallIntMethod;
    static constexpr auto CallNonVirtualMethod = &JNIEnv::CallNonvirtualIntMethod;
    static constexpr auto CallStaticMethod = &JNIEnv::CallStaticIntMethod;
};

template<>
struct EnvFunctions<jlong> {
    static constexpr auto CallMethod = &JNIEnv::CallLongMethod;
    static constexpr auto CallNonVirtualMethod = &JNIEnv::CallNonvirtualLongMethod;
    static constexpr auto CallStaticMethod = &JNIEnv::CallStaticLongMethod;
};

template<>
struct EnvFunctions<jfloat> {
    static constexpr auto CallMethod = &JNIEnv::CallFloatMethod;
    static constexpr auto CallNonVirtualMethod = &JNIEnv::CallNonvirtualFloatMethod;
    static constexpr auto CallStaticMethod = &JNIEnv::CallStaticFloatMethod;
};

template<>
struct EnvFunctions<jdouble> {
    static constexpr auto CallMethod = &JNIEnv::CallDoubleMethod;
    static constexpr auto CallNonVirtualMethod = &JNIEnv::CallNonvirtualDoubleMethod;
    static constexpr auto CallStaticMethod = &JNIEnv::CallStaticDoubleMethod;
};

template<>
struct EnvFunctions<jobject> {
    static constexpr auto CallMethod = &JNIEnv::CallObjectMethod;
    static constexpr auto CallNonVirtualMethod = &JNIEnv::CallNonvirtualObjectMethod;
    static constexpr auto CallStaticMethod = &JNIEnv::CallStaticObjectMethod;
};

}
