cmake_minimum_required(VERSION 3.26)
project(labAS2 C)

set(CMAKE_C_STANDARD 11)

add_executable(labAS2 main.c
        ordenacionInsercion.c
        ordenacionShell.c
        main.h
        ex2.c
        utilities.c
        main.c
)
