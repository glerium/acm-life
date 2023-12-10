#include <stdio.h>
#include <omp.h>
int main() {
    int tid;
    omp_set_num_threads(4);
#pragma omp parallel private(tid)
    {
        tid = omp_get_thread_num();
        if(tid == 0) printf("Section 1, tid = %d\n", tid);
        else if(tid == 1) printf("Section 2, tid = %d\n", tid);
        else if(tid == 2) printf("Section 3, tid = %d\n", tid);
        else if(tid == 3) printf("Section 4, tid = %d\n", tid);
    }
    return 0;
}