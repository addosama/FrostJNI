cmake_minimum_required(VERSION 4.3)
project(FrostJNI)

set(CMAKE_CXX_STANDARD 20)

add_library(
        FrostJNI STATIC
        src/FrostJNI.cpp
        src/javatypes/Object.cpp
        src/javatypes/String.cpp
        src/javatypes/Class.cpp
        src/javatypes/Iterator.cpp
        src/javatypes/Iterable.cpp
)

target_include_directories(
        FrostJNI
        PRIVATE
        src
        PUBLIC
        include
        libs/jni/include
)
