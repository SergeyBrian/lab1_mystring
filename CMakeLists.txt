cmake_minimum_required(VERSION 3.27)
project(lab1_mystring)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab1_mystring
        main.cpp
        MyString.cpp
        MyString.h
        tests/test_all.h
        tests/test_ctor.h
        tests/test_insert.h
        tests/test_logger.cpp
        tests/test_logger.h
        MyStringException.cpp
        MyStringException.h
)
