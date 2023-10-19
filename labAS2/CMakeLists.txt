cmake_minimum_required(VERSION 3.26)
project(labAS2 C)

set(CMAKE_C_STANDARD 11)

add_executable(labAS2 main.c
        main.h
        utilities.c
        main.c
        utilities.h
        tests.c
        tests.h
)
