//
// Created by Lucas Núñez González on 18/9/23.
//

#ifndef LABAS1_MAIN_H
#define LABAS1_MAIN_H

/* -- LIBRARIES -- */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

/* -- HEADERS -- */
int sumaSubMaxCuad(int[], int);
int sumaSubMaxLineal(int[], int);
void test1();
void test2();
void testTiempos();

/* -- UTILITIES -- */
void inicializar_semilla();
void aleatorio(int[], int);
void listar_vector(int[], int);
double microsegundos();
double estimar_tiempo(int*, int, int, int (*f)(int*, int));

#endif //LABAS1_MAIN_H
