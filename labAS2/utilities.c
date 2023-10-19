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
    for (int i = 0; i < n; i++) {
        if(i == n-1) printf("%d\n", values[i]);
        else printf("%3d, ", values[i]);
    }
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

/*
  MEDIR TIEMPO RESIDUAL
  La función exTime elimina el exceso de tiempo
  que se perdió al inicializar el vector las K veces
  o si se tuvo que revertir
*/

float exTime(int v[], int n, int k, int sorted){
    double a = microsegundos();
    for(int i = 0; i < k; i++){
        if(sorted == 0) aleatorio(v, n);
        if(sorted == 2){ revert(v, n); }
    }
    double b = microsegundos();
    return b-a;
}

// MEDIR TIEMPOS
float calcTime(void (*func)(int v[], int n), int v[],
               int n, int k, int sorted){

    if(sorted == 1 || sorted == 2) ord_ins(v, n);
    if(sorted == 2) revert(v, n);
    double a = microsegundos();
    func(v, n);
    double b = microsegundos();

    if((b-a) < 500){
        a = microsegundos();
        for(int i = 0; i < k; i++){
            if(sorted == 0) aleatorio(v, n);
            if(sorted == 2){ revert(v, n); }
            func(v, n);
        }
        b = microsegundos();

        return (((float)(b-a)) - exTime(v, n, k, sorted)) / (float)k;
    }

    return b - a;
}

//REVERTIR UN ARRAY
void revert(int v[], int n){
    int i = 0, aux;
    for(; i < (n/2 + 1); i++){
        aux = v[i];
        v[i] = v[n-i-1];
        v[n-i-1] = aux;
    }
}

void printRes(float time[], char *method, char *type, double under, double est, double over){
    int i;
    char *ast;
    double n;

    printf("\n\nOrdenación por %s con inicialización %s\n\n", method, type);
    printf("%13s%23s%18s%.3f%18s%.3f%18s%.3f\n", "n", "t(n)", "t(n)/n^", under,
           "t(n)/n^", est, "t(n)/n^", over);

    for(i = 0; i < 7; i++){
        n = 500 * pow(2.0, i);
        if(time[i] < 500) ast = YELLOW"*"; else ast = RESET" ";
        printf("%s%12.0f%23.3f%23f%23f%23.7f\n"RESET, ast, n,
               time[i], time[i] / pow(n, under),
               time[i] / pow(n, est), time[i] / pow(n, over));
    }

}