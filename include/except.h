#pragma once

#include <exception>
#include <jni.h>


namespace jnikit {

class PendingJavaException : std::exception {
public:
    explicit PendingJavaException(jthrowable throwable)
        : m_throwable(throwable)
    {}

    virtual const char* what() const noexcept override {
        return "Pending Exception from Java";
    }

    [[nodiscard]] jthrowable throwable() const {
        return m_throwable;
    }

private:
    jthrowable m_throwable;
};

void throwIfPendingException(JNIEnv* env);

}