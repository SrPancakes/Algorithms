cmake_minimum_required(VERSION 3.26)
project(labAS1 C)

set(CMAKE_C_STANDARD 11)

add_executable(labAS1 main.c
        sumaSubMaxCuad.c
        sumaSubMaxLineal.c
        main.h
        test02.c
        utilities.c
        test01.c
        testTiempos.c)
