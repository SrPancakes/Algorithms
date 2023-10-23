//
// Created by Lucas Núñez González on 23/10/23.
//

#ifndef LABAS3_MAIN_H
#define LABAS3_MAIN_H

/* -- LIBRARIES -- */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>

/* -- COLORS --*/
#define RED     "\x1b[31m"
#define RESET   "\x1b[0m"
#define YELLOW  "\x1b[33m"

#define TAM 256000
struct monticulo {
    int ultimo;
    int vector[TAM];
};
typedef struct monticulo * pmonticulo;

/* -- HEADERS -- */
void inicializar_semilla();
void aleatorio(int[], int);
void listar_monticulo(pmonticulo, int);
void OrdenarPorMonticulos(int v[], int n);

void inicializar_semilla();
void aleatorio(int values[], int n);
void createAsc(int values[], int n);
void createDesc(int values[], int n);
double microsegundos();
float calcCreateTime(int v[], int n, pmonticulo m, int k);
float calcOrdenarTime(int v[], int n, int k, int sorted);
void print_res(float time[], char *type, char *method, double under, double est, double over);


#endif //LABAS3_MAIN_H
