#ifndef LABAS2_UTILS_H
#define LABAS2_UTILS_H


/* -- HEADERS -- */
void inicializar_semilla();
void aleatorio(int[], int);
void listar_vector(int[], int);
int is_sorted(const int[], int);
void initialize_desc(int[], int);


double microsegundos();
float ord_ins_time(int v[], int n, int k);
float ord_shell_time(int v[], int n, int k);


#endif //LABAS2_UTILS_H
