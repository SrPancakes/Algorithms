//
// Created by Lucas Núñez González on 11/11/23.
//

#ifndef PRUEBA_MAIN_H
#define PRUEBA_MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <sys/time.h>

#define TAM 256000

struct monticulo {
    int vector[TAM];
    int ultimo;
};
typedef struct monticulo * pmonticulo;

void inicializar_semilla();
double microsegundos();
void insertar_array(pmonticulo, const int*, int);
void mostrar_vector(int[], int);
void aleatorio(int*, int, int);
void ascendente(int*, int, int);
void descendente(int*, int, int);
void intercambiar(pmonticulo, int, int);
int monticulo_vacio(pmonticulo);
void hundir(pmonticulo, int);
void crear_monticulo(int*, pmonticulo, int);
int quitar_menor(pmonticulo);
void ord_monticulo(int[], int);
void medicion_heapsort(void (*)(int*, int, int), double, double, double);
void medicion_crear_monticulo();
void test();
void calentar();
void print_res();

#endif //PRUEBA_MAIN_H
