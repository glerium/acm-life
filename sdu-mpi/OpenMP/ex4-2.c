#include <stdio.h>
#include <omp.h>
#define NUM_THREADS 2
int main() {
    int i;
    omp_set_num_threads(NUM_THREADS);
#pragma omp parallel for schedule(guided, 2)
    for(i=0; i<30; i++) {
        printf("Thread %d, i = %d\n", omp_get_thread_num(), i);
    }
    return 0;
}