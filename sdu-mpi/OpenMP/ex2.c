#include <stdio.h>
#include <omp.h>
#define NUM_THREADS 4
int main() {
    int i;
    int k=100;
    omp_set_num_threads(NUM_THREADS);
    #pragma omp parallel for firstprivate(k)
    for(i=0; i<NUM_THREADS; i++) {
        k+=i;
        printf("k = %d from Thread %d\n", k, omp_get_thread_num());
    }
    printf("Last k = %d\n", k);
    return 0;
}