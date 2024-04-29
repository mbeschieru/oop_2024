cmake_minimum_required(VERSION 3.27)
project(Biblieoteca)

set(CMAKE_CXX_STANDARD 17)

add_executable(Biblieoteca main.cpp
        Carte.h
        Roman.cpp
        Roman.h
        Revista.cpp
        Revista.h
        Biblioteca.cpp
        Biblioteca.h)
