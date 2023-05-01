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
        if constexpr (std::is_void_v<R>) {
            func(jnikitEnv);
        } else {
            return func(jnikitEnv);
        }
    } catch (const PendingJavaException&) {
        if constexpr (std::is_void_v<R>) {
            return;
        } else if constexpr (std::is_integral_v<R> || std::is_floating_point_v<R>) {
            return 0;
        } else if constexpr (std::is_pointer_v<R>) {
            return nullptr;
        } else {
            static_assert(meta::always_false<R>);
        }
    }
}

}
