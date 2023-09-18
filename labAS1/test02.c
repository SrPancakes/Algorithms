//
// Created by Lucas Núñez González on 18/9/23.
//

#include "main.h"

void test2() {
    int i, a, b;
    int v[9];
    printf("test\n");
    printf("%43s%15s%15s\n", "", "sumaSubMax1", "sumaSubMax2");
    for (i=0; i<10; i++) {
        aleatorio(v, 9);
        listar_vector(v, 9);
        a = sumaSubMaxCuad(v, 9);
        b = sumaSubMaxLineal(v, 9);
        a != b ? printf("\033[0;31m") : printf("\033[0m");
        printf("%15d%15d\n", a, b);
        printf("\033[0m");
    }
    printf("\n");
}