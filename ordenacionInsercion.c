#include "main.h"

void ord_ins(int v[], int n) {
    for(int i = 1; i < n; i++){
        int x = v[i];
        int j = i-1;
        while(j >= 0 && v[j] > x){
            v[j+1] = v[j];
            j = j-1;
        }
        v[j+1] = x;
    }
}