cmake_minimum_required(VERSION 3.27)
project(Lab4_2___MyLibrary_)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lab4_2___MyLibrary_
        main.cpp
        MyLibrary.cpp
        MyLibrary.h)
