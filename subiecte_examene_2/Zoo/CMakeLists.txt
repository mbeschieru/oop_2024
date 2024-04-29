cmake_minimum_required(VERSION 3.27)
project(Zoo)

set(CMAKE_CXX_STANDARD 14)

add_executable(Zoo
        main.cpp
        Animal.h
        Cow.h
        Cow.cpp
        Eagle.h
        Eagle.cpp
        Shark.h
        Shark.cpp
        Feline.h
        Tiger.cpp
        Tiger.h
        Lion.cpp
        Lion.h
        Zoo.cpp
        Zoo.h)
