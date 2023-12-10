#include <stdio.h>
#include <omp.h>
int main() {
    int i,j;
    for (i=0; i<4; i++) {
#pragma omp parallel for private(j)
        for(j=6; j<10; j++) {
            printf("i = %d, j = %d\n", i, j);
        }
    }
    return 0;
}