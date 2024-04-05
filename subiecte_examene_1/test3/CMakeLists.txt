cmake_minimum_required(VERSION 3.27)
project(test3)

set(CMAKE_CXX_STANDARD 17)

add_executable(test3 main.cpp
        Operatie.h
        Operatie.cpp
        Adunare.cpp
        Adunare.h
        Scadere.cpp
        Scadere.h
        Inmultire.cpp
        Inmultire.h
        Impartire.cpp
        Impartire.h
        Calculator.cpp
        Calculator.h)
