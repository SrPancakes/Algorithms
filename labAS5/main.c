#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define TAM_MAX 20

typedef int **matriz;

matriz crearMatriz(int n) {
    int i;
    matriz aux;
    if ((aux = malloc(n*sizeof(int *))) == NULL)
        return NULL;
    for (i=0; i<n; i++)
        if ((aux[i] = malloc(n*sizeof(int))) == NULL)
            return NULL;
    return aux;
}
/* Inicializacion pseudoaleatoria [1..TAM_MAX] de un grafo completo
no dirigido con n nodos, representado por su matriz de adayencia */
void iniMatriz(matriz m, int n) {
    int i, j;
    for (i=0; i<n; i++)
        for (j=i+1; j<n; j++)
            m[i][j] = rand() % TAM_MAX + 1;
    for (i=0; i<n; i++)
        for (j=0; j<=i; j++)
            if (i==j)
                m[i][j] = 0;
            else
                m[i][j] = m[j][i];
}
void liberarMatriz(matriz m, int n) {
    int i;
    for (i=0; i<n; i++)
        free(m[i]);
    free(m);
}

void dijkstra(matriz grafo, matriz distancias, int tam) {
    int n, i, j, min, v = 0, w = 0;
    int *noVisitados = malloc(tam * sizeof(int));
    for (n = 0; n < tam; n++) {
        // Inicializar noVisitados
        for (i = 0; i < tam; i++) {
            noVisitados[i] = 1;
            distancias[n][i] = grafo[n][i];
        }
        noVisitados[n] = 0;
        // Repetir n-2 veces
        for (w = 0; w < (tam - 2); w++) {
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

void listar_matriz(matriz m, int n){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

void testAlgoritmo(){
    matriz m = crearMatriz(5);
    matriz dist = crearMatriz(5);

    dijkstra(m, dist, 5);
    listar_matriz(dist, 5);
    liberarMatriz(m, 5);
    liberarMatriz(dist, 5);
}

int main() {
    testAlgoritmo();
    return 0;
}
