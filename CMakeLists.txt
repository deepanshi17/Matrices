cmake_minimum_required(VERSION 3.14)
project(project2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Project2_starter_files)

add_executable(project2
        cmake-build-debug/cmake_install.cmake
        cmake-build-debug/CMakeCache.txt
        cmake-build-debug/Makefile
        cmake-build-debug/project2.cbp
        Project2_starter_files/header.txt
        Project2_starter_files/main.cpp
        Project2_starter_files/Makefile
        Project2_starter_files/MatrixMultiply.h
        Project2_starter_files/Project2.cpp
        CMakeLists.txt
        Matrix_multiplication.pdf
        Project2_starter_files.zip)
