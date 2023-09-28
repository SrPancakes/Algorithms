#include "main.h"

void test2() {
    int i, a, b;
    int v[9];
    printf("\n\nTEST 2\n\n");
    printf("%43s%11s%19s\n", "", "sumaSubMax1", "sumaSubMax2");
    for (i=0; i<10; i++) {
        aleatorio(v, 9);
        listar_vector(v, 9);
        a = sumaSubMaxCuad(v, 9);
        b = sumaSubMaxLineal(v, 9);
        a != b ? printf(RED) : printf(RESET);
        printf("%15d%19d\n"RESET, a, b);
    }
    printf("\n");
}