#include "main.h"

void inicializar_semilla() {
    srand(time(NULL));
}

void aleatorio(int values[], int n) {
    int i = 0,
        m=2*n+1;

    for (; i < n; i++)
        values[i] = (rand() % m) - n;
}

void listar_vector(int values[], int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%3d ", values[i]);
    }
    printf("]");
}

double microsegundos() {
    struct timeval t;
    if (gettimeofday(&t, NULL) < 0)
        return 0.0;
    return (t.tv_usec + t.tv_sec * 1000000.0);
}

int is_sorted(const int v[], int n){
    int sorted = 1, i = 0;

    for(; i < n-1; i++){
        if(v[i] > v[i+1]) sorted = 0;
    }
    return sorted;
}

void initialize_desc(int v[], int n) {
    int i = 0,
        j = n;

    for (; i < n; i++) {
        v[i] = j;
        j--;
    }
}

void initialize_asc(int v[], int n) {
    int i = 0;

    for (; i < n; i++) {
        v[i] = i;
    }
}

double ex_time(int v[], int n, int k){
    int i = 0;
    double a = microsegundos(), b;
    for(; i < k; i++){
        aleatorio(v, n);
    }
    b = microsegundos();
    return b - a;
}

double ord_time(int v[], int n, int k, void (*func)(int[], int)){
    int i = 0;
    double a = microsegundos(), b;
    func(v, n);
    b = microsegundos();

    if((b-a) < 500){
        a = microsegundos();
        for(; i < k; i++){
            aleatorio(v, n);
            func(v, n);
        }
        b = microsegundos();
        return ((b-a) - ex_time(v, n, k)) / k;
    }

    return b - a;
}

void best_times(double times[2][7], double v1[3][7], double v2[3][7]){
    for(int i = 0; i < 7; i++){
        if(v1[0][i] >= v1[1][i] && v1[0][i] >= v1[2][i])
            times[0][i] = v1[0][i];
        else if (v1[1][i] >= v1[0][i] && v1[1][i] >= v1[2][i])
            times[0][i] = v1[1][i];
        else times[0][i] = v1[2][i];

        if(v2[0][i] >= v2[1][i] && v2[0][i] >= v2[2][i])
            times[1][i] = v2[0][i];
        else if (v2[1][i] >= v2[0][i] && v2[1][i] >= v2[2][i])
            times[1][i] = v2[1][i];
        else times[1][i] = v2[2][i];
    }
}

void print_times(double times[2][7], char *string){
    printf("\n\n-- %s --\n\nTIEMPOS:\n\n%9s%35s%37s\n", string, "n", "ORD INS "
                                                           "(ms)", "ORD SHELL (ms)");
    char *ast = " ";
    double n;
    int i;
    for(i = 0; i < 7; i++){
        n = 500 * pow(2.0, i);
        if(times[0][i]<500) ast = YELLOW"*";
        else ast = RESET" ";
        printf("%s%8.0f%35.3f%37.3f\n"RESET, ast, n,
               times[0][i], times[1][i]);
    }
}

void print_res(double finalTimes[2][7], char *string){
    int i;
    char *ast;
    double n;

    printf("\n\nOrdenación por Inserción con inicialización %s\n\n", string);
    printf("%13s%23s%23s%23s%23s\n", "n", "t(n)", "t(n)/n^1.8",
           "t(n)/n^2", "t(n)/n^2.2");

    for(i = 0; i < 7; i++){
        n = 500 * pow(2.0, i);
        if(finalTimes[0][i] < 500) ast = YELLOW"*"; else ast = RESET" ";
        printf("%s%12.0f%23.3f%23f%23f%23.7f\n"RESET, ast, n,
               finalTimes[0][i], finalTimes[0][i] / pow(n, 1.8),
               finalTimes[0][i] / pow(n, 2.0), finalTimes[0][i] / pow(n, 2.2));
    }

    printf("\n\nOrdenación Shell con inicialización %s\n\n", string);
    printf("%13s%23s%23s%23s%23s\n", "n", "t(n)", "t(n)/n^1.8",
           "t(n)/n", "t(n)/n^2.2");

    for(i = 0; i < 7; i++){
        n = 500 * pow(2.0, i);
        if(finalTimes[1][i] < 500) ast = YELLOW"*"; else ast = RESET" ";

        printf("%s%12.0f%23.3f%23f%23f%23.7f\n"RESET, ast, n,
               finalTimes[1][i], finalTimes[1][i] / pow(n, 1.0),
               finalTimes[1][i] / pow(n, 1.3) * log(n), finalTimes[1][i] / pow(n, 1.3));
    }
}

