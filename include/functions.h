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
    static constexpr auto GetArrayRegion = &JNIEnv::GetBooleanArrayRegion;
    static constexpr auto SetArrayRegion = &JNIEnv::SetBooleanArrayRegion;
    static constexpr auto GetArrayElements = &JNIEnv::GetBooleanArrayElements;
    static constexpr auto ReleaseArrayElements = &JNIEnv::ReleaseBooleanArrayElements;
    static constexpr auto NewArray = &JNIEnv::NewBooleanArray;
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
    static constexpr auto GetArrayRegion = &JNIEnv::GetCharArrayRegion;
    static constexpr auto SetArrayRegion = &JNIEnv::SetCharArrayRegion;
    static constexpr auto GetArrayElements = &JNIEnv::GetCharArrayElements;
    static constexpr auto ReleaseArrayElements = &JNIEnv::ReleaseCharArrayElements;
    static constexpr auto NewArray = &JNIEnv::NewCharArray;
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
    static constexpr auto GetArrayRegion = &JNIEnv::GetByteArrayRegion;
    static constexpr auto SetArrayRegion = &JNIEnv::SetByteArrayRegion;
    static constexpr auto GetArrayElements = &JNIEnv::GetByteArrayElements;
    static constexpr auto ReleaseArrayElements = &JNIEnv::ReleaseByteArrayElements;
    static constexpr auto NewArray = &JNIEnv::NewByteArray;
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
    static constexpr auto GetArrayRegion = &JNIEnv::GetShortArrayRegion;
    static constexpr auto SetArrayRegion = &JNIEnv::SetShortArrayRegion;
    static constexpr auto GetArrayElements = &JNIEnv::GetShortArrayElements;
    static constexpr auto ReleaseArrayElements = &JNIEnv::ReleaseShortArrayElements;
    static constexpr auto NewArray = &JNIEnv::NewShortArray;
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
    static constexpr auto GetArrayRegion = &JNIEnv::GetIntArrayRegion;
    static constexpr auto SetArrayRegion = &JNIEnv::SetIntArrayRegion;
    static constexpr auto GetArrayElements = &JNIEnv::GetIntArrayElements;
    static constexpr auto ReleaseArrayElements = &JNIEnv::ReleaseIntArrayElements;
    static constexpr auto NewArray = &JNIEnv::NewIntArray;
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
    static constexpr auto GetArrayRegion = &JNIEnv::GetLongArrayRegion;
    static constexpr auto SetArrayRegion = &JNIEnv::SetLongArrayRegion;
    static constexpr auto GetArrayElements = &JNIEnv::GetLongArrayElements;
    static constexpr auto ReleaseArrayElements = &JNIEnv::ReleaseLongArrayElements;
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
    static constexpr auto GetArrayRegion = &JNIEnv::GetFloatArrayRegion;
    static constexpr auto SetArrayRegion = &JNIEnv::SetFloatArrayRegion;
    static constexpr auto GetArrayElements = &JNIEnv::GetFloatArrayElements;
    static constexpr auto ReleaseArrayElements = &JNIEnv::ReleaseFloatArrayElements;
    static constexpr auto NewArray = &JNIEnv::NewFloatArray;
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
    static constexpr auto GetArrayRegion = &JNIEnv::GetDoubleArrayRegion;
    static constexpr auto SetArrayRegion = &JNIEnv::SetDoubleArrayRegion;
    static constexpr auto GetArrayElements = &JNIEnv::GetDoubleArrayElements;
    static constexpr auto ReleaseArrayElements = &JNIEnv::ReleaseDoubleArrayElements;
    static constexpr auto NewArray = &JNIEnv::NewDoubleArray;
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
    static constexpr auto GetArrayElement = &JNIEnv::GetObjectArrayElement;
    static constexpr auto SetArrayElement = &JNIEnv::SetObjectArrayElement;
    static constexpr auto NewArray = &JNIEnv::NewObjectArray;
};

}
