#include <omp.h>
#include <stdio.h>
#define NUM_THREADS 16
int main() {
    int i;
    omp_set_num_threads(NUM_THREADS);
#pragma omp parallel for
    for(i=0; i<NUM_THREADS; i++){
        printf("Hello world from Thread %d\n", omp_get_thread_num());
    }
    printf("Hello world from Main Thread.\n");
    return 0;
}