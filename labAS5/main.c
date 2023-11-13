#include <stdio.h>

typedef int ** matriz;
void dijkstra(matriz grafo, matriz distancias, int tam) {
    int n, i, j, min, v = 0;
    int *noVisitados = malloc(tam * sizeof(int));
    for (n = 0; n < tam; n++) {
        for (i = 0; i < tam; i++) {
            noVisitados[n] = 1;
            distancias[n][i] = grafo[n][i];
        }
        noVisitados[n] = 0;
    }
    free(noVisitados);
}

int main() {
    printf("Hello, World!\n");
    return 0;
}