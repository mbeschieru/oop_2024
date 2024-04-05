cmake_minimum_required(VERSION 3.27)
project(test4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(test4
        Student.cpp
        Student.h
        Catalog.cpp
        Catalog.h
        main.cpp)
