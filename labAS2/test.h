#ifndef LABAS2_TEST_H
#define LABAS2_TEST_H


/* -- HEADERS -- */
void test_ins(int[], int);
void test_shell(int[], int);
void test_times(void (*func)(int[], int), char*);
void test_complexity(void (*func)(int[], int), char*);
void run_test(int);


#endif //LABAS2_TEST_H
