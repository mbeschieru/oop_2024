cmake_minimum_required(VERSION 3.27)
project(test1)

set(CMAKE_CXX_STANDARD 17)

add_executable(test1 main.cpp
        Phrase.cpp
        Phrase.h)
