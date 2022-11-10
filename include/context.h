#pragma once

#include <utility>
#include <jni.h>
#include <functional>

#include "env.h"
#include "except.h"


namespace jnikit {

namespace meta {
template <class...> constexpr std::false_type always_false{};
}

template<typename R>
R context(JNIEnv* env, std::function<R(Env&)> func) {
    try {
        Env jnikitEnv(env);
        return func(jnikitEnv);
    } catch (const PendingJavaException&) {
        if constexpr (std::is_integral_v<R>) {
            return 0;
        } else if constexpr (std::is_pointer_v<R>) {
            return nullptr;
        } else {
            static_assert(meta::always_false<R>);
        }
    }
}

template<>
void context(JNIEnv* env, std::function<void(Env&)> func) {
    try {
        Env jnikitEnv(env);
        func(jnikitEnv);
    } catch (const PendingJavaException&) {
        return;
    }
}

}
