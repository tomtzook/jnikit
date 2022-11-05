#pragma once

#include <jni.h>


#ifdef __cplusplus
extern "C" {
#endif

#define JNIKIT_LIST_TYPENAME "java/util/List"
#define JNIKIT_ARRAYLIST_TYPENAME "java/util/ArrayList"
#define JNIKIT_LINKEDLIST_TYPENAME "java/util/LinkedList"

jobject jnikit_new_arraylist(JNIEnv* env);
jobject jnikit_new_linkedlist(JNIEnv* env);


#ifdef __cplusplus
}
#endif
