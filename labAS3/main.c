#include "main.h"

int main() {

    inicializar_semilla();
    timeTestCreate();
    timeTestOrdenar();
    return 0;
}

void inicializar_semilla() {
    srand(time(NULL));
}

void aleatorio(int values[], int n) {
    int i = 0,
            m=2*n+1;

    for (; i < n; i++)
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
        values[i] = n - i - 1;
}

double microsegundos() {
    struct timeval t;
    if (gettimeofday(&t, NULL) < 0)
        return 0.0;
    return (t.tv_usec + t.tv_sec * 1000000.0);
}

void listar_monticulo(pmonticulo m, int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%3d ", m->vector[i]);
    }
    printf("]");
}

void hundir (pmonticulo m, int i) {
    int hizq, hder, j=-1,aux; 
    while (j != i) { 
        hizq =  2*i+1; 
        hder =  2*i+2; 
        j = i; 
        if (hder <= m->ultimo && (m->vector[hder] < m->vector[i])) { 
            i = hder;
        }
        if (hizq <= m->ultimo && (m->vector[hizq] < m->vector[i])) {
            i = hizq; 
        }
        aux=m->vector[j];
        m->vector[j]=m->vector[i];
        m->vector[i]=aux;
    }
 
}

void crearMonticulo(const int v[], int n, pmonticulo m) {
    int i;
    for ( i = 0; i < n; i++) {
        m->vector[i] = v[i];
    }
    m->ultimo=n-1;
    for(i = (m->ultimo)/2; i>=0;i--){
        hundir(m, i);
    }
}

void OrdenarPorMonticulos(int v[], int n){
	int i = 0;
	pmonticulo m = malloc(sizeof (struct monticulo));
	crearMonticulo(v, n, m);
	for(; i < n; i++) v[i] = quitarMenor(m);
	free(m);

}

int quitarMenor(pmonticulo m){
	int x;
	if(m->ultimo < 0) printf("MONTICULO VACIO");
	else{
		x = m->vector[0];
		m->vector[0] = m->vector[m->ultimo];
		m->ultimo--;
		if(m->ultimo > -1) hundir(m, 0);
	}
	return x;
	
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
               time[i] / pow(n, est), time[i] / pow(n,
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
    free(m);
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
                tempTime[k] = calcOrdenarTime(v, i, 1000, k/2);
                if(j == 0) bestTime[k] = tempTime[k];
                if(tempTime[k] <= bestTime[k]) bestTime[k] = tempTime[k];
                times[k][aux] = bestTime[k];
            }
        }
        aux++;
        free(v);
    }
    print_res(times[0], "con vector aleatorio",
              "OrdenarPorMonticulos",1, 1.1, 1.2);
    print_res(times[1], "con vector ascendente",
              "OrdenarPorMonticulos",1, 1.1, 1.2);
    print_res(times[2], "con vector descendente",
              "OrdenarPorMonticulos",1.1, 1.2, 1.3);
}
