#ifndef LABAS2_UTILS_H
#define LABAS2_UTILS_H


/* -- HEADERS -- */
void inicializar_semilla();
void aleatorio(int[], int);
void listar_vector(int[], int);
int is_sorted(const int[], int);
void initialize_desc(int[], int);


double microsegundos();
double ordTime(int v[], int n, int k, void (*func)(int[], int));


#endif //LABAS2_UTILS_H
