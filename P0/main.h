//
// Created by Lucas Núñez González on 18/9/23.
//

#ifndef LABAS1_MAIN_H
#define LABAS1_MAIN_H

/* -- LIBRARIES -- */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

/* -- COLORS --*/
#define RED     "\x1b[31m"
#define RESET   "\x1b[0m"
#define YELLOW  "\x1b[33m"

/* -- HEADERS -- */
int sumaSubMaxCuad(int[], int);
int sumaSubMaxLineal(int[], int);
void test1();
void test2();
void test3();
void test4();

/* -- UTILITIES -- */
void inicializar_semilla();
void aleatorio(int[], int);
void listar_vector(int[], int);
double microsegundos();

/* -- TIMES -- */
float subMaxCuadTime(int v[], int n, int k);
float subMaxLinealTime(int v[], int n, int k);

#endif //LABAS1_MAIN_H
