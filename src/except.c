#include <string.h>
#include <malloc.h>

#include "objects.h"

#include "except.h"


void jnikit_throw_out_of_memory(JNIEnv* env, const char* message) {
    jclass cls = (*env)->FindClass(env, "java/lang/OutOfMemoryError");
    if (NULL == cls) {
        (*env)->FatalError(env, "java/lang/OutOfMemoryError not found");
        return;
    }

    (*env)->ThrowNew(env, cls, message);
    // TODO: returns an error
}

void jnikit_throw_unsupported(JNIEnv* env, const char* message) {
    jclass cls = (*env)->FindClass(env, "java/lang/UnsupportedOperationException");
    if (NULL == cls) {
        (*env)->FatalError(env, "java/lang/UnsupportedOperationException not found");
        return;
    }

    (*env)->ThrowNew(env, cls, message);
    // TODO: returns an error
}

void jnikit_throw_class_not_found(JNIEnv* env, const char* name) {
    jclass cls = (*env)->FindClass(env, "java/lang/NoClassDefFoundError");
    if (NULL == cls) {
        (*env)->FatalError(env, "java/lang/NoClassDefFoundError not found");
        return;
    }

    (*env)->ThrowNew(env, cls, name);
    // TODO: returns an error
}

void jnikit_throw_method_not_found(JNIEnv* env, const char* name, const char* signature) {
    jclass cls = jnikit_get_class(env, "java/lang/NoSuchMethodError");
    if (NULL == cls) {
        return;
    }

    size_t messageSize = strlen(name) + strlen(signature) + 1;
    char* messageBuffer = (char*) malloc(messageSize);
    if (NULL == messageBuffer) {
        jnikit_throw_out_of_memory(env, "throw_method_not_found");
        return;
    }

    sprintf(messageBuffer, "%s.%s", name, signature);

    (*env)->ThrowNew(env, cls, messageBuffer);
    free(messageBuffer);
}

void jnikit_throw_field_not_found(JNIEnv* env, const char* name, const char* signature) {
    jclass cls = jnikit_get_class(env, "java/lang/NoSuchFieldError");
    if (NULL == cls) {
        return;
    }

    size_t messageSize = strlen(name) + strlen(signature) + 1;
    char* messageBuffer = (char*) malloc(messageSize);
    if (NULL == messageBuffer) {
        jnikit_throw_out_of_memory(env, "throw_field_not_found");
        return;
    }

    sprintf(messageBuffer, "%s.%s", name, signature);

    (*env)->ThrowNew(env, cls, messageBuffer);
    free(messageBuffer);
}
