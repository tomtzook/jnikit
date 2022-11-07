
#include "exceptions.h"

#include "except.h"


namespace jnikit {

void throwIfPendingException(JNIEnv* env) {
    jthrowable throwable = env->ExceptionOccurred();
    if (nullptr != throwable) {
        throw PendingJavaException(throwable);
    }
}

}
