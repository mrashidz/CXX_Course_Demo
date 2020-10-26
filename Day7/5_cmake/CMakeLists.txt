cmake_minimum_required(VERSION 3.5.1)
project(foo)
include_directories(include)
add_executable(foo src/foo.cpp
                   src/main.cpp)
