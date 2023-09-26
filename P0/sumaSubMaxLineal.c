//
// Created by Lucas Núñez González on 18/9/23.
//

#include "main.h"

int sumaSubMaxLineal(int values[], int n) {
    int estaSuma = 0, sumaMax = 0;
    for (int j = 0; j < n; j++) {
        estaSuma += values[j];
        if (estaSuma > sumaMax) sumaMax = estaSuma;
        else if (estaSuma < 0) estaSuma = 0;
    }
    return sumaMax;
}
