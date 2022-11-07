#pragma once


#include <cstddef>
#include <utility>

namespace jnikit::meta {

template<char... _chars>
struct StringLiteral {
    operator const char*() const {
        static const char result[] = {_chars..., 0};
        return result;
    }
};

constexpr std::size_t StringLiteralLength(const char * str, std::size_t len = 0) {
    return str[0] ? StringLiteralLength(str + 1, len + 1) : len;
}

template<class, class>
struct StringLiteralSignatureImpl;

template<class _name_holder, std::size_t... Is>
struct StringLiteralSignatureImpl<_name_holder, std::index_sequence<Is...>>
{
    using Value = StringLiteral< _name_holder::Name()[Is]...>;
};

template<class _name_holder>
using StringLiteralSignature = typename StringLiteralSignatureImpl<_name_holder, std::make_index_sequence<StringLiteralLength(_name_holder::Name())> >::Value;

template<char... As, char... Bs>
constexpr auto concat(const StringLiteral<As...>&, const StringLiteral<Bs...>&) {
    return StringLiteral<As..., Bs...>();
}

template<class A, class B, class... Rest>
constexpr auto concat(const A& a, const B& b, const Rest&... rest) {
    return concat(concat(a, b), rest...);
}

}
