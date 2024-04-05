cmake_minimum_required(VERSION 3.27)
project(Lab6_3_Extra__JSON_)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab6_3_Extra__JSON_ main.cpp
        JsonValue.h
        NullValue.cpp
        NullValue.h
        NumberValue.cpp
        NumberValue.h
        BoolValue.cpp
        BoolValue.h
        StringValue.cpp
        StringValue.h
        Utils.cpp
        Utils.h
        ArrayValue.cpp
        ArrayValue.h
        ObjectValue.cpp
        ObjectValue.h)
