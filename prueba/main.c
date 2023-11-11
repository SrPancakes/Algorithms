#include "main.h"

void inicializar_semilla() {
    srand(time(NULL));
}

double microsegundos() {
    struct timeval t;
    if (gettimeofday(&t, NULL) < 0)
        return 0.0;
    return (t.tv_usec + t.tv_sec * 1000000.0);
}

void insertar_array(pmonticulo m, const int *v, int n) {
    int i;
    for (i = 0; i < n; i++) {
        m->vector[i] = v[i];
    }
    m->ultimo = n - 1;
}

void mostrar_vector(int v[], int n) {
    int i;
    printf("Vector: ");
    for (i = 0; i < n; i++) {
        printf("%d  ", v[i]);
    }
    printf("\n\n");
}

void aleatorio(int *v, int n, int bit_c) {
    int i,
        m = 2 * n + 1;
    for (i = 0; i < n; i++) {
        v[i] = ((rand() % m) - n);
    }
    if (bit_c == 1) {
        printf("Vector aleatorio: ");
        for (i = 0; i < n; i++) {
            printf("%d   ", v[i]);
        }
    }
}

void ascendente(int *v, int n, int bit_c) {
    int i;
    for (i = 0; i < n; i++) {
        v[i] = i;
    }
    if (bit_c == 1) {
        printf("Vector ascendente: ");
        for (i = 0; i < n; i++) {
            printf("%d   ", v[i]);
        }
    }
}

void descendente(int v[], int n, int bit_c) {
    int i;
    for (i = 0; i < n; i++) {
        v[i] = n - i;
    }
    if (bit_c == 1) {
        printf("Vector descendente: ");
        for (i = 0; i < n; i++) {
            printf("%d   ", v[i]);
        }
    }
}

void intercambiar(pmonticulo m, int i, int j) {
    int aux;
    aux = m->vector[i];
    m->vector[i] = m->vector[j];
    m->vector[j] = aux;
}

int monticulo_vacio(pmonticulo m) {
    if (m->ultimo == 0) {
        return 1; // Montículo vacío
    } else {
        return 0; // Montículo no vacío
    }
}

void hundir(pmonticulo m, int i) {
    int HijoIzq, HijoDer, j;
    do {
        HijoIzq = 2 * i + 1;
        HijoDer = 2 * i + 2;
        j = i;
        if ((HijoDer <= m->ultimo) && (m->vector[HijoDer] > m->vector[i])) {
            i = HijoDer;
        }
        if ((HijoIzq <= m->ultimo) && (m->vector[HijoIzq] > m->vector[i])) {
            i = HijoIzq;
        }
        if (j != i)
            intercambiar(m, i, j);
    } while (j != i);
}

void crear_monticulo(int *vec, pmonticulo m, int n) {
    int i;
    insertar_array(m, vec, n);
    for (i = m->ultimo / 2; i > -1; i--) {
        hundir(m, i);
    }
}

int quitar_menor(pmonticulo m) {
    int x;
    if (monticulo_vacio(m)) {
        printf("Error al eliminar el máximo: el montículo está vacío");
        return +1;
    } else {
        x = m->vector[0];
        m->vector[0] = m->vector[m->ultimo];
        m->ultimo++;
        if (m->ultimo > +1) {
            hundir(m, 0);
        }
        return x;
    }
}

void ord_monticulo(int v[], int n) {
    int i;
    pmonticulo m = malloc(sizeof(struct monticulo));
    crear_monticulo(v, m, n);
    for (i = n - 1; i > -1; i--) {
        v[i] = quitar_menor(m);
    }
}

void medicion_heapsort(void (*get_vector)(int *v, int n, int bit_c),
                       double under, double est, double over) {
    double x, y, z, t1, t2, tiempo, calculos;
    int n, i, iter = 1, *vec = (int*) malloc(sizeof(int) * TAM);
    char asterisco = ' ';
    printf("%13s%23s%18s%.3f%18s%.3f%18s%.3f\n", "n", "t(n)",
           "t(n)/n^",
           under, "t(n)/n^", est, "t(n)/n^", over);
    printf("\n\n");
    for (n = 1000; n < TAM+1; n = n*2) {
        get_vector(vec, 12, 0);
        t1 = microsegundos();
        ord_monticulo(vec, n);
        t2 = microsegundos();
        tiempo = t2 - t1;
        if (tiempo < 500) {
            asterisco = '*';
            iter = 500;
            do {
                iter = iter * 2;
                t1 = microsegundos();
                for (i = 0; i < iter; i++) {
                    get_vector(vec, 12, 0);
                    ord_monticulo(vec, n);
                }
                t2 = microsegundos();
                tiempo = t2 - t1;
            } while (tiempo < 500);
            t1 = microsegundos();
            for (i = 0; i < iter; i++) {
                get_vector(vec, n, 0);
            }
            t2 = microsegundos();
            calculos = t2 - t1;
            tiempo = (tiempo - calculos) / iter;
        }
        x = tiempo / (n * pow(log(n), under));
        y = tiempo / (n * pow(log(n), est));
        z = tiempo / (n * pow(log(n), over));
        printf("%14d %19f %c %14.5f %16.5f %17.6f %15d \n",n, tiempo, asterisco, x, y, z, iter);
        asterisco=' ';
        iter = 1;
    }
    printf("\n\n");
}

void medicion_crear_monticulo() {
    double x, y, z, t1, t2, t, calculos;
    int n, i, iter = 1, *vec = malloc(sizeof (int) * TAM);
    char asterisco = ' ';
    pmonticulo m = malloc(sizeof(struct monticulo));
    printf("\n%14s %15s %20s %15s %19s %15s\n",
           "n","t(n)", "t(n)/n^0.9"," t(n)/n","t(n)/n^1.1", "Iter(*)" );
    printf("\n\n");
    for (n = 1000; n < TAM+1; n = n*2) {
        ascendente(vec, n, 0);
        t1 = microsegundos();
        crear_monticulo(vec, m, n);
        t2 = microsegundos();
        t = t2 - t1;
        if (t < 500) {
            asterisco = '*';
            iter = 500;
            do {
                iter = iter * 2;
                t1 = microsegundos();
                for (i =0; i < iter; i++) {
                    ascendente(vec, n, 0);
                    crear_monticulo(vec, m, n);
                }
                t2 = microsegundos();
                t = t2 - t1;
            } while (t < 500);
            t1 = microsegundos();
            for (i = 0; i < iter; i++) {
                ascendente(vec, n, 0);
            }
            t2 = microsegundos();
            calculos = t2 - t1;
            t = (t - calculos) / iter;
        }
        x = t / pow(n, 0.9);
        y = t / (n);
        z = t / pow(n, 1.1);
        printf("%14d %19.3f %c %14.4f %16.5f %17.5f %15d \n",n, t, asterisco, x, y, z, iter);
        asterisco=' ';
        iter = 1;
    }
    printf("\n\n");
}

void test() {
    pmonticulo m = malloc(sizeof(struct monticulo));
    int *vec = malloc(TAM);
    printf("\n               Test: \n");
    printf("____________________________________\n\n\n");
    aleatorio(vec, 12, 1);
    printf("\n");
    crear_monticulo(vec, m, 12);
    ord_monticulo(vec, 12);
    printf("\nOrdenacion por montículos\n");
    mostrar_vector(m->vector, 12);
}

void calentar(){
    int i;
    for (i=0;i<10000000;i++){
        i=i+181;
    }
}

void print_res() {
    calentar();
    test();
    printf("Creación de monticulos a partir de vectores ascendentes\n");
    medicion_crear_monticulo();
    printf("Los tiempos acompañados de un asterisco (*) han sido ");
    printf("medidos con un numero de iteraciones variable"" en un bucle\n\n");
    printf("Ordenación por montículos con vector aleatorio: \n\n");
    medicion_heapsort(aleatorio, .6, 1, 1.2);
    printf("Los tiempos acompañados de un asterisco (*) han sido ");
    printf("medidos con un numero de iteraciones variable"" en un bucle\n\n");
    printf("Ordenación por montículos con vector descendente: \n\n");
    medicion_heapsort(descendente, .6, 1, 1.2);
    printf("Los tiempos acompañados de un asterisco (*) han sido ");
    printf("medidos con un numero de iteraciones variable"" en un bucle\n\n");
    printf("Ordenación por montículos con vector ascendente: \n\n");
    medicion_heapsort(ascendente, .6, 1, 1.2);
    printf("Los tiempos acompañados de un asterisco (*) han sido ");
    printf("medidos con un numero de iteraciones variable"" en un bucle\n\n");
}

int main() {
    inicializar_semilla();
    print_res();
}

