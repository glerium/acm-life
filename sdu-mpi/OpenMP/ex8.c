#include <stdio.h>
#include <omp.h>
int main() {
    int i, n=2023, ic=0;
#pragma omp parallel for shared(ic, n) private(i)
    for(i=0;i<n;i++) {
#pragma omp atomic
        ic = 2-ic;
    }
    printf("Counter = %d\n", ic);
    return 0;
}