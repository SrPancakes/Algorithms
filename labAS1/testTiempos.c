//
// Created by Lucas Núñez González on 18/9/23.
//

#include "main.h"

void testTiempos() {
    int *rv;
    int n;
    double tiempo_inicio, tiempo_fin, tiempo_total, tiempo1, tiempo2;

    printf("Test Tiempos SumaSubMax\n"
           "%5s %15s %15s\n",
           "n", "SumaSubMax 1", "SumaSubMax 2");
    for (n = 500; n <= 32000; n *= 2) {
        rv = malloc(sizeof (int) * n);
        aleatorio(rv, n);

        tiempo_inicio = microsegundos();
        sumaSubMaxCuad(rv, n);
        tiempo_fin = microsegundos();
        tiempo1 = tiempo_fin - tiempo_inicio;

        tiempo_inicio = microsegundos();
        sumaSubMaxLineal(rv, n);
        tiempo_fin = microsegundos();
        tiempo2 = tiempo_fin - tiempo_inicio;

        printf("%5d %15.3f %15.3f\n",
               n, tiempo1, tiempo2);
        free(rv);
    }

    printf("\nSumaSubMax 1\n"
           "%5s %15s %15s %15s %15s\n",
           "n", "t(n)", "t(n)/n^1.8", "t(n)/n^2.0", "t(n)/n^2.2");
    for (n = 500; n <= 32000; n *= 2) {
        rv = malloc(sizeof (int) * n);
        tiempo_inicio = microsegundos();
        aleatorio(rv, n);
        sumaSubMaxCuad(rv, n);
        tiempo_fin = microsegundos();
        tiempo_total = tiempo_fin - tiempo_inicio;

        printf("%5d %15.3f %15f %15f %15.7f\n",
               n, tiempo_total, tiempo_total/pow(n, 1.8),
               tiempo_total/pow(n, 2.0), tiempo_total/pow(n, 2.2));
        free(rv);
    }

    printf("\nSumaSubMax 2\n"
           "%5s %15s %15s %15s %15s\n",
           "n", "t(n)", "t(n)/n^1.8", "t(n)/n^2.0", "t(n)/n^2.2");
    for (n = 500; n <= 32000; n *= 2) {
        rv = malloc(sizeof (int) * n);
        tiempo_inicio = microsegundos();
        aleatorio(rv, n);
        sumaSubMaxLineal(rv, n);
        tiempo_fin = microsegundos();
        tiempo_total = tiempo_fin - tiempo_inicio;
        printf("%5d %15.3f %15.8f %15.9f %15.10f\n",
               n, tiempo_total, tiempo_total/pow(n, 1.8),
               tiempo_total/pow(n, 2.0), tiempo_total/pow(n, 2.2));
        free(rv);
    }
}