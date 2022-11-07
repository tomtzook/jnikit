#pragma once

#include <jni.h>
#include "meta.h"
#include "types.h"


namespace jnikit::types {

#define MAKE_SIGNATURE_CHAR(type, signature_char) \
    template<> \
    struct Signature<type> { \
        constexpr auto operator()() const { \
            return jnikit::meta::StringLiteral<signature_char>(); \
        }\
    };

template<typename _type>
struct Signature {};

MAKE_SIGNATURE_CHAR(Boolean, 'Z')
MAKE_SIGNATURE_CHAR(Char, 'C')
MAKE_SIGNATURE_CHAR(Byte, 'B')
MAKE_SIGNATURE_CHAR(Short, 'S')
MAKE_SIGNATURE_CHAR(Int, 'I')
MAKE_SIGNATURE_CHAR(Long, 'J')
MAKE_SIGNATURE_CHAR(Float, 'F')
MAKE_SIGNATURE_CHAR(Double, 'D')
MAKE_SIGNATURE_CHAR(Void, 'V')


template<class _name_type>
struct Signature<ObjectType<_name_type>> {
    constexpr auto operator()() const {
        return meta::concat(meta::StringLiteral<'L'>(), meta::StringLiteralSignature<_name_type>(), meta::StringLiteral<';'>());
    }
};

template<typename _c_type, typename _inner_type>
struct Signature<ArrayType<_c_type, _inner_type>> {
    constexpr auto operator()() const {
        return meta::concat(meta::StringLiteral<'['>(), Signature<_inner_type>()());
    }
};

template<typename R, typename... Args>
struct Signature<MethodType<R(Args...)>> {
    constexpr auto operator()() const {
        return meta::concat(meta::StringLiteral<'('>(), Signature<Args>()()..., meta::StringLiteral<')'>(),
                Signature<R>()());
    }
};

}
