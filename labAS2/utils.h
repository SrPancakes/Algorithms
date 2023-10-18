#ifndef LABAS2_UTILS_H
#define LABAS2_UTILS_H


/* -- HEADERS -- */
void inicializar_semilla();
void aleatorio(int[], int);
void listar_vector(int[], int);
int is_sorted(const int[], int);
void initialize_desc(int[], int);
void initialize_asc(int[], int);


double microsegundos();
double ord_time(int v[], int n, int k, void (*func)(int[], int));
void best_times(double[2][7], double[3][7], double[3][7]);
void print_times(double[2][7], char*);
void print_res(double[2][7], char*);


#endif //LABAS2_UTILS_H
