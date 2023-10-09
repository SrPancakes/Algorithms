//
// Created by Lucas Núñez González on 18/9/23.
//

#include "main.h"

void test1() {
    int a, b;

    int v[][5] = {
            {-9, 2, -5, -4, 6},
            {4, 0, 9, 2, 5},
            { -2, -1, -9, -7, -1 },
            { 9, -2, 1, -7, -8 },
            { 15, -2, -5, -4, 16 },
            { 7, -5, 6, 7, -7 }
    };

    printf("test\n");
    printf("%28s%15s%15s\n", "", "sumaSubMax1", "sumaSubMax2");
    for (int i = 0; i < 6; i++) {
        listar_vector(v[i], 5);
        a = sumaSubMaxCuad(v[i], 5);
        b = sumaSubMaxLineal(v[i], 5);
        a != b ? printf("\033[0;31m") : printf("\033[0m");
        printf("%15d%15d\n", a, b);
        printf("\033[0m");
    }
    printf("\n");
}
