#include <stdio.h>
#include <omp.h>
int main() {
    int a=0, i;
#pragma omp parallel for num_threads(10) private(i)
    for(i=1; i<101; i++)
        a += i;
    printf("a = %d\n", a);

    a = 0;
#pragma omp parallel for num_threads(10) private(i) reduction(+:a)
    for(i=1; i<101; i++)
        a += i;
    printf("a = %d\n", a);

    a = 0;
    for(i=1; i<101; i++)
        a += i;
    printf("a = %d\n", a);
    return 0;
}