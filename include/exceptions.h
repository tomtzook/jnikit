#pragma once

#include "types.h"


namespace jnikit {

DEFINE_OBJECT_TYPE(OutOfMemoryError, "java/lang/OutOfMemoryError")
DEFINE_OBJECT_TYPE(UnsupportedOperationException, "java/lang/UnsupportedOperationException")
DEFINE_OBJECT_TYPE(IllegalArgumentException, "java/lang/IllegalArgumentException")
DEFINE_OBJECT_TYPE(IllegalStateException, "java/lang/IllegalStateException")

}
