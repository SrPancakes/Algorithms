#include "main.h"

// TEST INS
void test_ins(int v[], int n) {
    printf("Ordenación\n");
    ord_ins(v, n);
    listar_vector(v, n);
    printf("\nOrdenado? %d\n\n", is_sorted(v, n));
}

// TEST SHELL
void test_shell(int v[], int n) {
    printf("Ordenación\n");
    ord_shell(v, n);
    listar_vector(v, n);
    printf("\nOrdenado? %d\n\n", is_sorted(v, n));
}

// TEST TIMES
void test_times(void (*func)(int[], int), char *iniType){
    double insertion[3][7], shell[3][7], finalTimes[2][7];
    int aux = 0, i = 0, j;
    int *v;

    for(i = 500; i <= 32000; i*=2){
        v = malloc(sizeof (int) * i);
        func(v, i);
        for(j = 0; j < 3; j++){
            insertion[j][aux] = ordTime(v, i, 10, ord_ins);
            shell[j][aux] = ordTime(v, i, 1000, ord_shell);
        }
        aux++;
        free(v);
    }

    bestTimes(finalTimes, insertion, shell);

    printRes(finalTimes, iniType);
}

void run_test(int n) {

    int v[n];

    printf("-- INSERCIÓN --");
    aleatorio(v, n);
    printf("Vector Muestra\n");
    listar_vector(v, n);
    printf("\nOrdenado? %d\n\n", is_sorted(v, n));
    test_ins(v, n);

    printf("-- SHELL --");
    aleatorio(v, n);
    printf("Vector Muestra\n");
    listar_vector(v, n);
    printf("\nOrdenado? %d\n\n", is_sorted(v, n));
    test_shell(v, n);

    printf("Inicialización descendente\n");
    initialize_desc(v, n);

    listar_vector(v, n);
    printf("\nOrdenado? %d\n\n", is_sorted(v, n));

    printf("-- INSERCIÓN --\n\n");
    test_ins(v, n);

    printf("-- SHELL --\n\n");
    initialize_desc(v, n);
    test_shell(v, n);

    test_times(initialize_asc, "ascendente");
    test_times(initialize_desc, "descendente");
    test_times(aleatorio, "aleatoria");
}