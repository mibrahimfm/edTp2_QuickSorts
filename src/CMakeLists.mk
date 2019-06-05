cmake_minimum_required(VERSION 3.14)
project(untitled C)

set(CMAKE_C_STANDARD 99)

add_library(untitled library.h)

MATH(EXPR stack_size 48 1024 1024) # 16 Mb
set(CMAKE_EXE_LINKER_FLAGS "-WI,--stack,${stack_size}")