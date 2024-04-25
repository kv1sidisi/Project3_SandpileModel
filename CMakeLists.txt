cmake_minimum_required(VERSION 3.26)
project(labwork3_kv1sidisi)

set(CMAKE_CXX_STANDARD 14)

add_executable(labwork3_kv1sidisi
        bin/main.cpp
        bin/parsing.cpp
        lib/parsing.h
        lib/create_grid.h
        bin/create_grid.cpp
        lib/create_bmp.h
        bin/create_bmp.cpp)
