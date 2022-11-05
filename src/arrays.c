#include "objects.h"

#include "arrays.h"


jarray jnikit_new_primitivearray(JNIEnv* env, jnikit_primitive_type_t type, jsize size) {
    switch (type) {
        case JNIKIT_PRIMITIVE_TYPE_BOOLEAN:
            return (*env)->NewBooleanArray(env, size);
        case JNIKIT_PRIMITIVE_TYPE_CHAR:
            return (*env)->NewCharArray(env, size);
        case JNIKIT_PRIMITIVE_TYPE_BYTE:
            return (*env)->NewByteArray(env, size);
        case JNIKIT_PRIMITIVE_TYPE_SHORT:
            return (*env)->NewShortArray(env, size);
        case JNIKIT_PRIMITIVE_TYPE_INT:
            return (*env)->NewIntArray(env, size);
        case JNIKIT_PRIMITIVE_TYPE_LONG:
            return (*env)->NewLongArray(env, size);
        case JNIKIT_PRIMITIVE_TYPE_FLOAT:
            return (*env)->NewFloatArray(env, size);
        case JNIKIT_PRIMITIVE_TYPE_DOUBLE:
            return (*env)->NewDoubleArray(env, size);
        default:
            return NULL;
    }
}

jarray jnikit_new_objectarray(JNIEnv* env, const char* type_name, jsize size, jobject initial_value) {
    jclass cls = jnikit_get_class(env, type_name);
    if (NULL == cls) {
        return NULL;
    }

    return (*env)->NewObjectArray(env, size, cls, initial_value);
}

