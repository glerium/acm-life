#include <stdio.h>
#include <omp.h>
#define NUM_THREADS 4
int main() {
    int tid, i=0;
    int s=0, sum=0;
    int a[4];
    for(i=0;i<4;i++) a[i]=i;
#pragma omp parallel num_threads(NUM_THREADS) private(i, tid) firstprivate(s) shared(sum)
    {
        tid = omp_get_thread_num();
#pragma omp for
        for(i=0; i<4; i++) {
            s += a[i];
        }
#pragma omp critical
        {
            sum += s;
            printf("Thread %d, sum = %d, SUM = %d\n", tid, s, sum);
        };
    }
    return 0;
}