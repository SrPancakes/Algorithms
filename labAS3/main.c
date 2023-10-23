#include "main.h"

void inicializar_semilla() {
    srand(time(NULL));
}

void aleatorio(int values[], int n) {
    int i, m=2*n+1;
    for (i=0; i < n; i++)
        values[i] = (rand() % m) - n;
}

void createAsc(int values[], int n) {
    int i;
    for (i=0; i < n; i++)
        values[i] = i;
}

void createDesc(int values[], int n) {
    int i;
    for (i=0; i < n; i++)
        values[i] = n - i;
}

double microsegundos() { /* obtiene la hora del sistema en microsegundos */
    struct timeval t;
    if (gettimeofday(&t, NULL) < 0 )
        return 0.0;
    return (t.tv_usec + t.tv_sec * 1000000.0);
}

void crearMonticulo(int v[], int n, pmonticulo m){
    int i = 1, k = i, heap, j;
    m->ultimo = n;
    for (; i <= n; i++) {
        m->vector[i] = v[i - 1];
    }
    for (i = n / 2; i >= 1; i--) {
        int v2 = m->vector[k];
        heap = 0;
        while (!heap && 2 * k <= n) {
            j = 2 * k;
            if (j < n && m->vector[j] > m->vector[j + 1]) {
                j++;
            }
            if (v2 <= m->vector[j]) {
                heap = 1;
            } else {
                m->vector[k] = m->vector[j];
                k = j;
            }
        }
        m->vector[k] = v2;
    }
}

void OrdenarPorMonticulos(int v[], int n){

}
int quitarMenor(pmonticulo m){
    int menor = m->vector[1], ultimo = m->vector[m->ultimo--], i = 1,
            heap = 0, j;

    if (m->ultimo == 0) {
        printf("Error: El montículo está vacío.\n");
        return -1;
    }
    while (!heap && 2 * i <= m->ultimo) {
        j = 2 * i;
        if (j < m->ultimo && m->vector[j] > m->vector[j + 1]) {
            j++;
        }
        if (ultimo <= m->vector[j]) {
            heap = 1;
        } else {
            m->vector[i] = m->vector[j];
            i = j;
        }
    }
    m->vector[i] = ultimo;
    return menor;
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


void print_res(float time[], char *type, char *method,
               double under, double est, double over){
    int i = 0; double n; char *ast;
    printf("\n\nVerificación tiempos del algoritmo %s %s\n\n",
           method, type);
    printf("%13s%23s%18s%.3f%18s%.3f%18s%.3f\n", "n", "t(n)",
           "t(n)/n^",
           under, "t(n)/n^", est, "t(n)/n^", over);
    for(;i < 7; i++){
        n = 500 * pow(2.0, i);
        if(time[i] < 500) ast = YELLOW"*"; else ast = RESET" ";
        printf("%s%12.0f%23.3f%23f%23f%23.7f\n"RESET, ast, n,
               time[i], time[i] / pow(n, under),
               time[i]/ pow(n, est), time[i] / pow(n,
                                                   over));
    }
}

/*
  MEDIR TIEMPO RESIDUAL
  La función exTime elimina el exceso de tiempo
  que se perdió al inicializar el vector las K veces
  o si se tuvo que revertir
*/

float exTime(int v[], int n, int k, int sorted){
    int i = 0;
    double a = microsegundos(), b;
    for(; i < k; i++){
        if(sorted == 0) aleatorio(v, n);
        if(sorted == 2){ createDesc(v, n); }
    }
    b = microsegundos();
    return b-a;
}

float calcCreateTime(int v[], int n, pmonticulo m, int k){
    int i = 0;
    double a, b;
    aleatorio(v, i);
    a = microsegundos();
    crearMonticulo(v, n, m);
    b = microsegundos();

    if((b-a) < 500){
        a = microsegundos();
        for(; i < k; i++){
            aleatorio(v, n);
            crearMonticulo(v, n, m);
        }
        b = microsegundos();

        return (((float)(b-a)) - exTime(v, n, k, 0)) / (float)k;
    }

    return b - a;
}

void timeTestCreate(){
    pmonticulo m = malloc(sizeof (struct monticulo));
    int i, j, aux = 0;
    int *v;
    float bestTime[7], tempTime[3][7];
    for(i = 500; i <= 32000; i*=2){
        v = malloc(sizeof (int) * i);
        for(j = 0; j < 3; j++){
            tempTime[j][aux] =
                    calcCreateTime(v, i, m, 1000);
            if(j == 0) bestTime[aux] = tempTime[j][aux];
            else{
                if(tempTime[j][aux] < bestTime[aux])
                    bestTime[aux] = tempTime[j][aux];
            }
        }
        free(v);
        aux++;
    }
    print_res(bestTime, "", "crearMonticulo",
              0.9, 1.0, 1.1);
}

float calcOrdenarTime(int v[], int n, int k, int sorted){
    int i = 0;
    double a, b;
    if(sorted == 1) createAsc(v, n);
    else if(sorted == 2) createDesc(v, n);
    else aleatorio(v, i);
    a = microsegundos();
    OrdenarPorMonticulos(v, n);
    b = microsegundos();

    if((b-a) < 500){
        a = microsegundos();
        for(; i < k; i++){
            if(sorted == 0) aleatorio(v, n);
            if(sorted == 2){ createDesc(v, n); }
            OrdenarPorMonticulos(v, n);
        }
        b = microsegundos();

        return (((float)(b-a)) - exTime(v, n, k, sorted)) / (float)k;
    }

    return b - a;
}

void timeTestOrdenar(){
    float times[3][7];
    int aux = 0, i, j, k;
    float tempTime[6], bestTime[6];
    int *v;
    for(i = 500; i <= 32000; i*=2){
        v = malloc(sizeof (int) * i);
        for(j = 0; j < 3; j++){
            for(k = 0; k < 3; k++){
                tempTime[k] = calcOrdenarTime(v,
                   i, 10 * ((int)pow(100, k/2 == 1)), k/2);
                if(j == 0) bestTime[k] = tempTime[k];
                if(tempTime[k] <= bestTime[k]) bestTime[k] = tempTime[k];
                times[k][aux] = bestTime[k];
            }
        }
        aux++;
        free(v);
    }
    print_res(times[0], "con vector aleatorio",
              "OrdenarPorMonticulos",1.8, 2, 2.2);
    print_res(times[1], "con vector ascendente",
              "OrdenarPorMonticulos",1.1, 1.2, 1.3);
    print_res(times[2], "con vector descendente",
              "OrdenarPorMonticulos",0.95, 1, 1.05);
}

int main(){
    inicializar_semilla();
    timeTestCreate();
    timeTestOrdenar();
}
