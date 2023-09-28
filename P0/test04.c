#include "main.h"

/*

  Los tiempos se registran de la siguiente forma:
  Tenemos un array bidimensional de 3x7.
  Se miden los tiempos tres veces, de manera que en cada
  fila queda registrado un intento.

  Ejemplo:
  V1 (Cuadrática)
  3 5 1 6 5 3 9
  2 6 2 4 3 9 8
  5 2 4 2 1 5 8

  V2 (Lineal)
  3 5 1 6 5 3 9
  5 6 2 4 3 9 3
  5 2 4 7 1 5 8

  La función bestTimes asignará en un nuevo Array de 2x7
  los mejores tiempos de cada fila.

  De manera que quedará: (finalTimes)
  sumaSubMaxCUAD :    2 2 1 2 1 3 8
  sumaSubMaxLINEAL:   3 2 1 4 1 3 3

*/

void bestTimes(float times[2][7], float v1[3][7], float v2[3][7]){
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

void printRes(float finalTimes[2][7]){
  int i;
  char *ast = " ";
  double n;

  printf("\n\nTEST 4\n\nSumaSubMax Cuad (microsegundos)\n\n");
  printf("%13s%23s%23s%23s%23s\n", "n", "t(n)", "t(n)/n^1.8",
         "t(n)/n^2", "t(n)/n^2.2");

  for(i = 0; i < 7; i++){
    n = 500 * pow(2.0, i);
    if(finalTimes[0][i] < 500) ast = YELLOW"*"; else ast = RESET" ";
    printf("%s%12.0f%23.3f%23f%23f%23.7f\n"RESET, ast, n,
    finalTimes[0][i], finalTimes[0][i] / pow(n, 1.8),
     finalTimes[0][i] / pow(n, 2.0), finalTimes[0][i] / pow(n, 2.2));
  }

  printf("\n\nSumaSubMax Lineal (microsegundos)\n\n");
  printf("%13s%23s%23s%23s%23s\n", "n", "t(n)", "t(n)/n^0.7",
         "t(n)/n", "t(n)/n^1.1");

  for(i = 0; i < 7; i++){
    n = 500 * pow(2.0, i);
    if(finalTimes[1][i] < 500) ast = YELLOW"*"; else ast = RESET" ";

    printf("%s%12.0f%23.3f%23f%23f%23.7f\n"RESET, ast, n,
    finalTimes[1][i], finalTimes[1][i] / pow(n, 0.7),
     finalTimes[1][i] / pow(n, 0.9), finalTimes[1][i] / pow(n, 1.1));
  }
}


void test4(){
  float cuadTimes[3][7];
  float linealTimes[3][7];
  int aux = 0;
  int i, j;
  for(i = 500; i <= 32000; i*=2){
    int v[i];
    aleatorio(v, i);
    for(j = 0; j < 3; j++){
      cuadTimes[j][aux] = subMaxCuadTime(v, i, 10);
      linealTimes[j][aux] = subMaxLinealTime(v, i, 1000);
    }
    aux++;
  }

  float finalTimes[2][7];
  bestTimes(finalTimes, cuadTimes, linealTimes);

  printRes(finalTimes);

}
