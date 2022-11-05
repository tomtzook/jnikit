#include "except.h"

#include "objects.h"


jclass jnikit_get_class(JNIEnv* env, const char* name) {
    jclass cls = (*env)->FindClass(env, name);
    if (NULL == cls) {
        jnikit_throw_class_not_found(env, name);
        return NULL;
    }

    return cls;
}

jmethodID jnikit_get_static_method(JNIEnv* env, jclass cls, const char* name, const char* signature) {
    jmethodID method = (*env)->GetStaticMethodID(env, cls, name, signature);
    if (NULL == method) {
        jnikit_throw_method_not_found(env, name, signature);
        return NULL;
    }

    return method;
}

jmethodID jnikit_get_method(JNIEnv* env, jclass cls, const char* name, const char* signature) {
    jmethodID method = (*env)->GetMethodID(env, cls, name, signature);
    if (NULL == method) {
        jnikit_throw_method_not_found(env, name, signature);
        return NULL;
    }

    return method;
}

jmethodID jnikit_get_constructor(JNIEnv* env, jclass cls, const char* signature) {
    return jnikit_get_method(env, cls, "<init>", signature);
}

jfieldID jnikit_get_static_field(JNIEnv* env, jclass cls, const char* name, const char* signature) {
    jfieldID field = (*env)->GetStaticFieldID(env, cls, name, signature);
    if (NULL == field) {
        jnikit_throw_field_not_found(env, name, signature);
        return NULL;
    }

    return field;
}

jfieldID jnikit_get_field(JNIEnv* env, jclass cls, const char* name, const char* signature) {
    jfieldID field = (*env)->GetFieldID(env, cls, name, signature);
    if (NULL == field) {
        jnikit_throw_field_not_found(env, name, signature);
        return NULL;
    }

    return field;
}

jint jnikit_get_enum_ordinal(JNIEnv* env, jclass cls, jobject enum_constant) {
    jmethodID method = jnikit_get_method(env, cls, "ordinal", "()I");
    if (NULL == method) {
        return -1;
    }

    return (*env)->CallIntMethod(env, enum_constant, method);
}

jobject jnikit_new_object(JNIEnv* env, const char* cls, const char* ctor_signature, ...) {
    jclass cls_obj = jnikit_get_class(env, cls);
    if (NULL == cls_obj) {
        return NULL;
    }

    jmethodID ctor = jnikit_get_constructor(env, cls_obj, ctor_signature);
    if (NULL == ctor) {
        return NULL;
    }

    va_list argp;
    va_start(argp, ctor_signature);
    jobject obj = (*env)->NewObjectV(env, cls_obj, ctor, argp);
    va_end(argp);

    return obj;
}

jobject jnikit_new_object_a(JNIEnv* env, const char* cls, const char* ctor_signature, const jvalue* args) {
    jclass cls_obj = jnikit_get_class(env, cls);
    if (NULL == cls_obj) {
        return NULL;
    }

    jmethodID ctor = jnikit_get_constructor(env, cls_obj, ctor_signature);
    if (NULL == ctor) {
        return NULL;
    }

    return (*env)->NewObjectA(env, cls_obj, ctor, args);
}

jobject new_object_v(JNIEnv* env, const char* cls, const char* ctor_signature, va_list args) {
    jclass cls_obj = jnikit_get_class(env, cls);
    if (NULL == cls_obj) {
        return NULL;
    }

    jmethodID ctor = jnikit_get_constructor(env, cls_obj, ctor_signature);
    if (NULL == ctor) {
        return NULL;
    }

    return (*env)->NewObjectV(env, cls_obj, ctor, args);
}
