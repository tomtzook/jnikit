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
    static constexpr auto GetField = &JNIEnv::GetBooleanField;
    static constexpr auto SetField = &JNIEnv::SetBooleanField;
    static constexpr auto GetStaticField = &JNIEnv::GetStaticBooleanField;
    static constexpr auto SetStaticField = &JNIEnv::SetStaticBooleanField;
};

template<>
struct EnvFunctions<jchar> {
    static constexpr auto CallMethod = &JNIEnv::CallCharMethod;
    static constexpr auto CallNonVirtualMethod = &JNIEnv::CallNonvirtualCharMethod;
    static constexpr auto CallStaticMethod = &JNIEnv::CallStaticCharMethod;
    static constexpr auto GetField = &JNIEnv::GetCharField;
    static constexpr auto SetField = &JNIEnv::SetCharField;
    static constexpr auto GetStaticField = &JNIEnv::GetStaticCharField;
    static constexpr auto SetStaticField = &JNIEnv::SetStaticCharField;
};

template<>
struct EnvFunctions<jbyte> {
    static constexpr auto CallMethod = &JNIEnv::CallByteMethod;
    static constexpr auto CallNonVirtualMethod = &JNIEnv::CallNonvirtualByteMethod;
    static constexpr auto CallStaticMethod = &JNIEnv::CallStaticByteMethod;
    static constexpr auto GetField = &JNIEnv::GetByteField;
    static constexpr auto SetField = &JNIEnv::SetByteField;
    static constexpr auto GetStaticField = &JNIEnv::GetStaticByteField;
    static constexpr auto SetStaticField = &JNIEnv::SetStaticByteField;
};

template<>
struct EnvFunctions<jshort> {
    static constexpr auto CallMethod = &JNIEnv::CallShortMethod;
    static constexpr auto CallNonVirtualMethod = &JNIEnv::CallNonvirtualShortMethod;
    static constexpr auto CallStaticMethod = &JNIEnv::CallStaticShortMethod;
    static constexpr auto GetField = &JNIEnv::GetShortField;
    static constexpr auto SetField = &JNIEnv::SetShortField;
    static constexpr auto GetStaticField = &JNIEnv::GetStaticShortField;
    static constexpr auto SetStaticField = &JNIEnv::SetStaticShortField;
};

template<>
struct EnvFunctions<jint> {
    static constexpr auto CallMethod = &JNIEnv::CallIntMethod;
    static constexpr auto CallNonVirtualMethod = &JNIEnv::CallNonvirtualIntMethod;
    static constexpr auto CallStaticMethod = &JNIEnv::CallStaticIntMethod;
    static constexpr auto GetField = &JNIEnv::GetIntField;
    static constexpr auto SetField = &JNIEnv::SetIntField;
    static constexpr auto GetStaticField = &JNIEnv::GetStaticIntField;
    static constexpr auto SetStaticField = &JNIEnv::SetStaticIntField;
};

template<>
struct EnvFunctions<jlong> {
    static constexpr auto CallMethod = &JNIEnv::CallLongMethod;
    static constexpr auto CallNonVirtualMethod = &JNIEnv::CallNonvirtualLongMethod;
    static constexpr auto CallStaticMethod = &JNIEnv::CallStaticLongMethod;
    static constexpr auto GetField = &JNIEnv::GetLongField;
    static constexpr auto SetField = &JNIEnv::SetLongField;
    static constexpr auto GetStaticField = &JNIEnv::GetStaticLongField;
    static constexpr auto SetStaticField = &JNIEnv::SetStaticLongField;
};

template<>
struct EnvFunctions<jfloat> {
    static constexpr auto CallMethod = &JNIEnv::CallFloatMethod;
    static constexpr auto CallNonVirtualMethod = &JNIEnv::CallNonvirtualFloatMethod;
    static constexpr auto CallStaticMethod = &JNIEnv::CallStaticFloatMethod;
    static constexpr auto GetField = &JNIEnv::GetFloatField;
    static constexpr auto SetField = &JNIEnv::SetFloatField;
    static constexpr auto GetStaticField = &JNIEnv::GetStaticFloatField;
    static constexpr auto SetStaticField = &JNIEnv::SetStaticFloatField;
};

template<>
struct EnvFunctions<jdouble> {
    static constexpr auto CallMethod = &JNIEnv::CallDoubleMethod;
    static constexpr auto CallNonVirtualMethod = &JNIEnv::CallNonvirtualDoubleMethod;
    static constexpr auto CallStaticMethod = &JNIEnv::CallStaticDoubleMethod;
    static constexpr auto GetField = &JNIEnv::GetDoubleField;
    static constexpr auto SetField = &JNIEnv::SetDoubleField;
    static constexpr auto GetStaticField = &JNIEnv::GetStaticDoubleField;
    static constexpr auto SetStaticField = &JNIEnv::SetStaticDoubleField;
};

template<>
struct EnvFunctions<jobject> {
    static constexpr auto CallMethod = &JNIEnv::CallObjectMethod;
    static constexpr auto CallNonVirtualMethod = &JNIEnv::CallNonvirtualObjectMethod;
    static constexpr auto CallStaticMethod = &JNIEnv::CallStaticObjectMethod;
    static constexpr auto GetField = &JNIEnv::GetObjectField;
    static constexpr auto SetField = &JNIEnv::SetObjectField;
    static constexpr auto GetStaticField = &JNIEnv::GetStaticObjectField;
    static constexpr auto SetStaticField = &JNIEnv::SetStaticObjectField;
};

}
