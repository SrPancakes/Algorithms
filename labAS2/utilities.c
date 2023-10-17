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


double microsegundos() { /* obtiene la hora del sistema en microsegundos */
    struct timeval t;
    if (gettimeofday(&t, NULL) < 0 )
        return 0.0;
    return (t.tv_usec + t.tv_sec * 1000000.0);
}

int isSorted(int v[], int n){
    int sorted = 1;
    for(int i = 0; i < n-1; i++){
        if(v[i] > v[i+1]) sorted = 0;
    }
    return sorted;
}