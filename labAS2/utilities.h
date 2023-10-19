/*
 * Rodrigo Meijome Quintana - rodrigo.meijome
 * Lucas Nuñez - l.nunez
 */

#ifndef LABAS2_UTILITIES_H
#define LABAS2_UTILITIES_H


#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>


/* -- UTILITIES -- */
void inicializar_semilla();
void aleatorio(int[], int);
void listar_vector(int[], int);
int isSorted(int v[], int n);
void revert(int v[], int n);

/* -- TIMES -- */
double microsegundos();
float exTime(int v[], int n, int k, int sorted);
float calcTime(void (*func)(int v[], int n), int v[], int n, int k, int sorted);
void printRes(float time[], char *method, char *type, double under, double est, double over);

#endif //LABAS2_UTILITIES_H
