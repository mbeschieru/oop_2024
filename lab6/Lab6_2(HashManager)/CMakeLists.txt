cmake_minimum_required(VERSION 3.27)
project(Lab6_2_HashManager_)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab6_2_HashManager_ main.cpp
        Hash.h
        CountVowelsHash.cpp
        CountVowelsHash.h
        utils.cpp
        utils.h
        CountConsonantHash.cpp
        CountConsonantHash.h
        CountAsciiHash.cpp
        CountAsciiHash.h
        EasyHash.cpp
        EasyHash.h
        HashManager.cpp
        HashManager.h)
