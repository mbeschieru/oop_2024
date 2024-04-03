cmake_minimum_required(VERSION 3.27)
project(lab6)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab6 main.cpp
        Car.cpp
        Car.h
        Volvo.cpp
        Volvo.h
        BMW.cpp
        BMW.h
        Seat.cpp
        Seat.h
        RangeRover.cpp
        RangeRover.h
        Circuit.cpp
        Circuit.h)
