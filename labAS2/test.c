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
}