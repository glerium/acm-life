#include <stdio.h>
#include <omp.h>
int main() {
    int i;
#pragma omp parallel for
    for(i=0;i<4;i++) {
        printf("Thread %d, i = %d\n", omp_get_thread_num(), i);
    }
    return 0;
}