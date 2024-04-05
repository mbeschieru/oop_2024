cmake_minimum_required(VERSION 3.27)
project(Propozitie)

set(CMAKE_CXX_STANDARD 17)

add_executable(Propozitie main.cpp
        Utils.cpp
        Utils.h
        Propozitie.cpp
        Propozitie.h)
