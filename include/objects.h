#pragma once

#include <jni.h>

#include "class.h"


namespace jnikit {

template<class T>
class Object {
public:
    Object(JNIEnv* env, jclass cls, jobject instance)
        : m_cls(env, cls)
        , m_instance(instance)
    {}

    Class<T>& getClass() {
        return m_cls;
    }

    template<class FT>
    typename FT::CType getField(const char* name) {
        auto field = m_cls.template field<FT>(name);
        return field.get(m_instance);
    }

    template<class FT>
    void setField(const char* name, typename FT::CType value) {
        auto field = m_cls.template field<FT>(name);
        return field.set(m_instance, value);
    }

    template<class R, class... Args>
    typename R::CType callMethod(const char* name, typename Args::CType... args) {
        using t = R(Args...);
        auto method = m_cls.template method<t>(name);
        return method.call(m_instance, args...);
    }

private:
    Class<T> m_cls;
    jobject m_instance;
};

}
