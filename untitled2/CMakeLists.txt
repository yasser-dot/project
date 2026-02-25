cmake_minimum_required(VERSION 4.0)
project(untitled2)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled2 main.cpp
        headerfiles/student.h
        headerfiles/functions.cpp
        headerfiles/course.h)
