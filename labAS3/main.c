#include "main.h"

int main() {

    inicializar_semilla();
    pmonticulo m = (pmonticulo) malloc(sizeof (struct monticulo));
    int *v = malloc(sizeof (int)* 10);
    aleatorio(v, 10);
    crearMonticulo(v, 10, m);
    listar_vector(v, 10);

    return 0;
}

void inicializar_semilla() {
    srand(time(NULL));
}

void aleatorio(int values[], int n) {
    int i = 0,
            m=2*n+1;

    for (; i < n; i++)
        values[i] = (rand() % m) - n;
}

void crearMonticulo(const int v[], int n, pmonticulo m) {
    int i = 1,
        k = i,
        heap, j;

   m->ultimo = n;

    for (; i <= n; i++) {
        m->vector[i] = v[i - 1];
    }


    for (i = n / 2; i >= 1; i--) {
        int v2 = m->vector[k];
        heap = 0;

        while (!heap && 2 * k <= n) {
            j = 2 * k;
            if (j < n && m->vector[j] > m->vector[j + 1]) {
                j++;
            }
            if (v2 <= m->vector[j]) {
                heap = 1;
            } else {
                m->vector[k] = m->vector[j];
                k = j;
            }
        }

        m->vector[k] = v2;
    }
}

int quitarMenor(pmonticulo m) {
    int menor = m->vector[1],
        ultimo = m->vector[m->ultimo--],
        i = 1,
        heap = 0,
        j;

    if (m->ultimo == 0) {
        printf("Error: El montículo está vacío.\n");
        return -1;
    }

    while (!heap && 2 * i <= m->ultimo) {
        j = 2 * i;
        if (j < m->ultimo && m->vector[j] > m->vector[j + 1]) {
            j++;
        }
        if (ultimo <= m->vector[j]) {
            heap = 1;
        } else {
            m->vector[i] = m->vector[j];
            i = j;
        }
    }

    m->vector[i] = ultimo;

    return menor;
}
