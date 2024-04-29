cmake_minimum_required(VERSION 3.27)
project(Database)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Database
        main.cpp
        Entry.cpp
        Entry.h
        StringData.cpp
        StringData.h
        IntegerData.cpp
        IntegerData.h
        Database.cpp
        Database.h)
