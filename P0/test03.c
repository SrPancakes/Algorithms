#include "main.h"

void printTimes(float times[2][7]){
  printf("\n\nTEST 3\n\nTIEMPOS:\n\n%9s%35s%37s\n", "n", "SSM CUAD "
                "(microsegundos)", "SSM LIN (microsegundos)");
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

void test3(){
  int aux = 0;
  float times[2][7];
  int i;
  for(i = 500; i <= 32000; i*=2){
    int v[i];
    aleatorio(v, i);
    times[0][aux] = subMaxCuadTime(v, i, 10);
    times[1][aux] = subMaxLinealTime(v, i, 1000);
    aux++;
  }

  printTimes(times);

}
