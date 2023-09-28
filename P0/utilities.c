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

/*
  La función exTime elimina el exceso de tiempo
  que se perdió al inicializar el vector las K veces
*/

float exTime(int v[], int n, int k){
  double a = microsegundos();
  for(int i = 0; i < k; i++){
    aleatorio(v, n);
  }
  double b = microsegundos();
  return b-a;
}

float subMaxCuadTime(int v[], int n, int k){
  double a = microsegundos();
  sumaSubMaxCuad(v, n);
  double b = microsegundos();

  if((b-a) < 500){
    a = microsegundos();
    for(int i = 0; i < k; i++){
      aleatorio(v, n);
      sumaSubMaxCuad(v, n);
    }
    b = microsegundos();
    return ((b-a) - exTime(v, n, k)) / k;
  }

  return b - a;
}

float subMaxLinealTime(int v[], int n, int k){
  double a = microsegundos();
  sumaSubMaxLineal(v, n);
  double b = microsegundos();

  if((b-a) < 500){
    a = microsegundos();
    for(int i = 0; i < k; i++){
      aleatorio(v, n);
      sumaSubMaxLineal(v, n);
    }
    b = microsegundos();

    return ((b-a) - exTime(v, n, k)) / k;
  }

  return b - a;
}
