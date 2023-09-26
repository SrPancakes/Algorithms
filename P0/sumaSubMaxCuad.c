//
// Created by Lucas Núñez González on 18/9/23.
//

#include "main.h"

int sumaSubMaxCuad(int values[], int n) {
    int i, j;
    int estaSuma, sumaMax = 0;
    for (i = 0; i < n; i++) {
        estaSuma = 0;
        for (j = i; j < n; j++) {
            estaSuma += values[j];
            if (estaSuma > sumaMax) sumaMax = estaSuma;
        }
    }
    return sumaMax;
}