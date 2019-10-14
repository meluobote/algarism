cmake_minimum_required(VERSION 3.15)
project(algarism)

set(CMAKE_CXX_STANDARD 11)

add_executable(algarism main.cpp cmake-build-debug/Sort.cpp cmake-build-debug/Sort.h)