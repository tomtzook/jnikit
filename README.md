# jnikit

A C++ toolkit for nicer work with JNI.


```c++
#include <jnikit.h>

DEFINE_OBJECT_TYPE(MyClass, "fully/qualified/name/MyClass");

jobject create(jnikit::Env& env, jint arg1, jint arg2) {
  auto cls = env.getClass<MyClass>();
  return cls.newInstance<jnikit::types::Int, jnikit::types::Int>(arg1, arg2);
}
```

```c++
#include <jnikit.h>

DEFINE_OBJECT_TYPE(MyClass, "package/MyClass");

extern "C"
JNIEXPORT jobjectArray JNICALL Java_package_MyClass_createArray
        (JNIEnv *env, jclass obj){
    return jnikit::context<jobjectArray>(env, [](jnikit::Env& env)->jobjectArray {
        auto cls = env.getClass<MyClass>();
        auto arr = cls.newArray(3);
        
        arr.setElement(0, cls.newInstance<>());
        
        return arr.array();
    });
}
```
