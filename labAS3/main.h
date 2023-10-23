//
// Created by Lucas Núñez González on 23/10/23.
//

#ifndef LABAS3_MAIN_H
#define LABAS3_MAIN_H

/* -- LIBRARIES -- */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

#define TAM 256000


struct monticulo {
    int ultimo;
    int vector[TAM];
};

typedef struct monticulo *pmonticulo;

/* -- HEADERS -- */
void inicializar_semilla();
void aleatorio(int[], int);
void listar_monticulo(pmonticulo, int);

void crearMonticulo(const int[], int, pmonticulo);
int quitarMenor(pmonticulo);


#endif //LABAS3_MAIN_H
