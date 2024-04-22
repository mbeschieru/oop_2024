cmake_minimum_required(VERSION 3.27)
project(Expression)

set(CMAKE_CXX_STANDARD 17)

add_executable(Expression main.cpp
        Expression.h
        Value.cpp
        Value.h
        Add.cpp
        Add.h
        Sub.cpp
        Sub.h
        Neg.cpp
        Neg.h)
