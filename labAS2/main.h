#ifndef LABAS2_MAIN_H
#define LABAS2_MAIN_H

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
void ord_ins(int[], int);
void ord_shell(int[], int);
void test();

/* -- UTILITIES -- */
void inicializar_semilla();
void aleatorio(int[], int);
void listar_vector(int[], int);

/* -- TIMES -- */
double microsegundos();
float ord_ins_time(int v[], int n, int k);
float ord_shell_time(int v[], int n, int k);


#endif //LABAS2_MAIN_H
