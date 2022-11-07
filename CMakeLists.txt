cmake_minimum_required(VERSION 3.16)
project(jnikit CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(JNI REQUIRED)

add_library(jnikit STATIC
        src/empty.cpp
        src/except.cpp

        # for better IDE rendering
        include/except.h
        include/types.h
        include/meta.h
        include/signatures.h
        include/env.h
        include/class.h
        include/functions.h
        include/exceptions.h include/objects.h)

target_include_directories(jnikit PUBLIC
        ${JNI_INCLUDE_DIRS}
        ${CMAKE_CURRENT_SOURCE_DIR}/include)

set_property(TARGET jnikit PROPERTY POSITION_INDEPENDENT_CODE ON)
