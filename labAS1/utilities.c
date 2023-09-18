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
        printf("%2d ", values[i]);
    }
    printf("]");
}