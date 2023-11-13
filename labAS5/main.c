#include <stdio.h>
#include <limits.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}

typedef int **matriz;

/*
procedimiento dijkstra( M[1..n,1..n], Distancias[1..n,1..n] );
    para m := 1 hasta n hacer
        noVisitados := { 1, 2, ..., m-1, m+1, ..., n };
        para i := 1 hasta n hacer
            Distancias[m, i] := M[m, i]
        fin para
        repetir n-2 veces:
            v := nodo de noVisitados que minimiza Distancias[m, v];
            noVisitados := noVisitados - { v };
            para cada w en noVisitados hacer
                si Distancias[m, w] > Distancias[m, v] + M[v, w]
                    entonces Distancias[m, w] := Distancias[m, v] + M[v, w]
                fin si
            fin para
        fin repetir
    fin para
fin procedimiento
*/

void dijkstra(matriz grafo, matriz distancias, int tam) {
    int n, i, j, min, v = 0;
    int *noVisitados = malloc(tam * sizeof(int));
    
    for (n = 0; n < tam; n++) {
        // Inicializar noVisitados
        for (i = 0; i < tam; i++) {
            noVisitados[i] = 1;
            distancias[n][i] = grafo[n][i];
        }
        noVisitados[n] = 0;

        // Repetir n-2 veces
        for (n = 0; n < tam - 2; n++) {
            // Encontrar nodo de noVisitados que minimiza Distancias[m, v]
            min = INT_MAX;
            for (i = 0; i < tam; i++) {
                if (noVisitados[i] && distancias[n][i] < min) {
                    min = distancias[n][i];
                    v = i;
                }
            }

            // Actualizar noVisitados
            noVisitados[v] = 0;

            // Actualizar Distancias[m, w] para cada w en noVisitados
            for (j = 0; j < tam; j++) {
                if (noVisitados[j] && distancias[n][j] > distancias[n][v] + grafo[v][j]) {
                    distancias[n][j] = distancias[n][v] + grafo[v][j];
                }
            }
        }

        free(noVisitados);
    }
}
