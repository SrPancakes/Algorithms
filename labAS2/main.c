#include "main.h"

// ORDENACIÓN POR INSERCIÓN
void ord_ins(int v[], int n) {
    int x, j,
        i = 1;

    for(; i < n; i++){
        x = v[i];
        j = i-1;

        while(j >= 0 && v[j] > x){
            v[j+1] = v[j];
            j = j-1;
        }

        v[j+1] = x;
    }
}

// ORDENACIÓN SHELL
void ord_shell(int v[], int n) {
    int tmp, i, j, keepgoing,
            increment = n;

    while (increment > 1) {
        increment = increment / 2;
        for (i = increment; i < n; i++) {
            tmp = v[i];
            j = i;
            keepgoing = 1;
            while (j - increment >= 0 && keepgoing) {
                if (tmp < v[j - increment]) {
                    v[j] = v[j - increment];
                    j = j - increment;
                } else {
                    keepgoing = 0;
                }
            }
            v[j] = tmp;
        }
    }
}

int main() {

    inicializar_semilla();
    run_test(17);

    return 0;
}
