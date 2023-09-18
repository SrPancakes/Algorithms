//
// Created by Lucas Núñez González on 18/9/23.
//

#include "main.h"

int sumaSubMaxCuad(int values[], int n) {
    int sumaMax = 0;
    for (int i = 0; i < n; i++) {
        int estaSuma = 0;
        for (int j = 0; j < n; j++) {
            estaSuma += values[j];
            if (estaSuma > sumaMax) sumaMax = estaSuma;
        }
    }
    return sumaMax;
}