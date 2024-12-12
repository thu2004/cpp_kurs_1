cmake_minimum_required(VERSION 3.29)
project(Hemtentamen_Uppgift_4_VG)

set(CMAKE_CXX_STANDARD 11)

# Includes
include_directories(.)

# Testing
add_subdirectory(test)

add_executable(Hemtentamen_Uppgift_4_VG main.cpp
        PriorityQueue.h)
