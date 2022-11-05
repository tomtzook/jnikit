#pragma once

#include <jni.h>


#ifdef __cplusplus
extern "C" {
#endif

typedef enum jnikit_primitive_type {
    JNIKIT_PRIMITIVE_TYPE_BOOLEAN,
    JNIKIT_PRIMITIVE_TYPE_CHAR,
    JNIKIT_PRIMITIVE_TYPE_BYTE,
    JNIKIT_PRIMITIVE_TYPE_SHORT,
    JNIKIT_PRIMITIVE_TYPE_INT,
    JNIKIT_PRIMITIVE_TYPE_LONG,
    JNIKIT_PRIMITIVE_TYPE_FLOAT,
    JNIKIT_PRIMITIVE_TYPE_DOUBLE,
} jnikit_primitive_type_t;


#ifdef __cplusplus
}
#endif
