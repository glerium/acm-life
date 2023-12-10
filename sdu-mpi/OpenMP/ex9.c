#include <stdio.h>
#include <omp.h>
static omp_lock_t lock;
int main() {
    omp_init_lock(&lock);
    int i;
#pragma omp parallel for
    for(i=0;i<5;i++) {
        omp_set_lock(&lock);
        printf("i=%d", i);
        printf(", ");
        printf("i*i=%d", i*i);
        printf("\n");
        omp_unset_lock(&lock);
    }
    omp_destroy_lock(&lock);
    return 0;
}