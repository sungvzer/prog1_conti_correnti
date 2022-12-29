cmake_minimum_required(VERSION 3.14)
SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)
SET(CMAKE_C_STANDARD 23)
project(PROG1_PROJECT)
include_directories(lib)

add_compile_options(-g)

add_subdirectory(src)
