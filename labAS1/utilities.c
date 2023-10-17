//
// Created by Lucas Núñez González on 18/9/23.
//

#include "main.h"

void inicializar_semilla() {
    srand(time(NULL));
}

void aleatorio(int values[], int n) {
    int i, m=2*n+1;
    for (i=0; i < n; i++)
        values[i] = (rand() % m) - n;
}

void listar_vector(int values[], int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%3d ", values[i]);
    }
    printf("]");
}

double microsegundos() {
    struct timeval t;
    if (gettimeofday(&t, NULL) < 0)
        return 0.0;
    return (t.tv_usec + t.tv_sec * 1000000.0);
}

double estimar_tiempo(int *rv, int n, int k, int func(int *rv, int n)) {
    int i = 0;
    double tiempo_inicio, tiempo_fin, tiempo1, tiempo2, tiempo_total;

    k = 10;
    tiempo_inicio = microsegundos();
    for(; i < k; i++) {
        aleatorio(rv, n);
        func(rv, n);
    }
    tiempo_fin = microsegundos();
    tiempo1 = tiempo_fin - tiempo_inicio;

    tiempo_inicio = microsegundos();
    for(i = 0; i < k; i++) {
        aleatorio(rv, n);
    }
    tiempo_fin = microsegundos();
    tiempo2 = tiempo_fin - tiempo_inicio;

    tiempo_total = (tiempo1 - tiempo2) / k;

    return tiempo_total;
}