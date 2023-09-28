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

    printf("\n\nTEST 1\n\n");
    printf("%28s%11s%21s\n", "", "sumaSubMax1", "sumaSubMax2");
    for (int i = 0; i < 6; i++) {
        listar_vector(v[i], 5);
        a = sumaSubMaxCuad(v[i], 5);
        b = sumaSubMaxLineal(v[i], 5);
        a != b ? printf(RED) : printf(RESET);
        printf("%15d%21d\n"RESET, a, b);
    }
    printf("\n");
}
