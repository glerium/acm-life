#include <stdio.h>
#include <omp.h>
int main() {
#pragma omp parallel sections num_threads(4)
    {
    #pragma omp section
        {
            printf("Section 1, Thread %d\n", omp_get_thread_num());
        }
    #pragma omp section
        {
            printf("Section 2, Thread %d\n", omp_get_thread_num());
        }
    #pragma omp section
        {
            printf("Section 3, Thread %d\n", omp_get_thread_num());
        }
    #pragma omp section
        {
            printf("Section 4, Thread %d\n", omp_get_thread_num());
        }
    }
    return 0;
}