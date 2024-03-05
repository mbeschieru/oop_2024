cmake_minimum_required(VERSION 3.27)
project(lab2_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab2_1 main.cpp
        Movie.cpp
        Movie.h
        global.h
        global.cpp
        MovieSeries.cpp
        MovieSeries.h)
