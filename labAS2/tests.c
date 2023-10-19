#include "tests.h"

// TEST ORDENACIONES
void testOrdenacion(void (*func)(int v[], int n), int n, char *funcName){
    int v[n];
    aleatorio(v, n);
    printf("Inicialización aleatoria: \n");
    listar_vector(v, n);
    printf("Está ordenado? %d\n", isSorted(v, n));
    printf("Ordenación por %s: \n", funcName);
    func(v, n);
    listar_vector(v, n);
    printf("Está ordenado? %d\n\n\n", isSorted(v, n));

    revert(v, n);
    printf("Inicialización descendente: \n");
    listar_vector(v, n);
    printf("Está ordenado? %d\n", isSorted(v, n));
    printf("Ordenación por %s: \n", funcName);
    func(v, n);
    listar_vector(v, n);
    printf("Está ordenado? %d\n\n\n", isSorted(v, n));
}

/*  FUNCION timeTests()

    * times[6][7]: columnas 0, 2 y 4 estáran los tiempos del algoritmo
    *              de inserción (aleatorio, ordenado ascendente y
    *              ordenado descendente respectivamente)
    *
    *              columnas 1, 3 y 5 estáran los tiempos del algoritmo
    *              de shell (aleatorio, ordenado ascendente y
    *              ordenado descendente respectivamente)
    *
    * Se repite tres veces para cada disposición del vector y se quedará
    *              con el tiempo más bajo.
    *
    * Posteriormente se imprimirán los resultados con sus respectivas cotas
    *
    * Repetimos 6 veces (dos para cada disposición del
    *      vector, pues tenemos dos metodos de ordenación)
    *
    * Sorted tiene valores 0 (desordenado), 1 (ordenado
    *      ascendente) y 2 (ordenado descendente)
    *
    * Con k/2 tendremos que en las primeras 2 iteraciones
    *      sorted = 0, en las dos siguientes sorted = 1
    *      y en las dos últimas sorted = 2
    *
    * Con 10 * ((int)pow(100, k/2 == 1)) multiplicamos
    *      por 1000 sólo cuando lo necesitamos en el
    *      algoritmo de inserción: cuando el vector
    *      está ordenado ascendentemente
*/
void timeTests(){
    float times[6][7];
    int aux = 0, i, j, k;
    float tempTime[6], bestTime[6];
    int *v;
    for(i = 500; i <= 32000; i*=2){
        v = malloc(sizeof (int) * i);
        for(j = 0; j < 3; j++){
            for(k = 0; k < 6; k++){
                aleatorio(v, i);
                if(k%2==0) {
                    tempTime[k] = calcTime(ord_ins, v, i, 10 *
                        ((int)pow(100, k/2 == 1)), k/2);
                }else{
                    tempTime[k] = calcTime(ord_shell, v, i,
                                           1000, k/2);
                }
                if(j == 0) bestTime[k] = tempTime[k];
                if(tempTime[k] <= bestTime[k]) bestTime[k] = tempTime[k];
                times[k][aux] = bestTime[k];
            }
        }
        aux++;
        free(v);
    }
    printRes(times[0], "insercion", "aleatorio",
             1.8, 2, 2.2);
    printRes(times[1], "shell", "aleatorio",
             1.1, 1.2, 1.3);
    printRes(times[2], "insercion", "ascendente",
             0.95, 1, 1.05);
    printRes(times[3], "shell", "ascendente",
             1.05, 1.15, 1.3);
    printRes(times[4], "insercion", "descendente",
             1.8, 2, 2.2);
    printRes(times[5], "shell", "descendente",
             1.1, 1.14, 1.2);
}
