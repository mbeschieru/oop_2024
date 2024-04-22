cmake_minimum_required(VERSION 3.27)
project(Fractie)

set(CMAKE_CXX_STANDARD 17)

add_executable(Fractie main.cpp
        Fractie.cpp
        Fractie.h
        utils.cpp
        utils.h)
