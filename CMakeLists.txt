cmake_minimum_required(VERSION 3.3)
project(DS)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        "merge sort.c")

add_executable(DS ${SOURCE_FILES})