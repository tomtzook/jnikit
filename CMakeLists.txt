cmake_minimum_required(VERSION 3.16)
project(jnikit C)

set(CMAKE_C_STANDARD 11)

find_package(JNI REQUIRED)

add_library(jnikit STATIC
        src/objects.c include/objects.h include/except.h src/except.c include/collections/list.h include/arrays.h include/types.h src/arrays.c include/signatures.h)

target_include_directories(jnikit PUBLIC
        ${JNI_INCLUDE_DIRS}
        ${CMAKE_CURRENT_SOURCE_DIR}/include)
