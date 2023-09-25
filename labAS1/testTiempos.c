//
// Created by Lucas Núñez González on 18/9/23.
//

#include "main.h"

void testTiempos() {
    int *rv;
    int n;
    double tiempo_inicio, tiempo_fin, tiempo_total;

    printf("SumaSubMax 1\n"
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
        printf("%5d %15.3f %15f %15f %15.7f\n",
               n, tiempo_total, tiempo_total/pow(n, 1.8),
               tiempo_total/pow(n, 2.0), tiempo_total/pow(n, 2.2));
        free(rv);
    }
}