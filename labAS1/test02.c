//
// Created by Lucas Núñez González on 18/9/23.
//

#include "main.h"

void test2() {
    int i, a, b;
    int v[9];
    printf("test\n");
    printf("%33s%15s%15s\n", "", "sumaSubMax1", "sumaSubMax2");
    for (i=0; i<10; i++) {
        aleatorio(v, 9);
        listar_vector(v, 9);
        a = sumaSubMaxCuad(v, 9);
        b = sumaSubMaxLineal(v, 9);
        printf("%15d%15d\n", a, b);
    }
    printf("\n");
}