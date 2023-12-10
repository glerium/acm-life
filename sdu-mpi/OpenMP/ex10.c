#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#define NUM_THREADS 3

void print_time(int tid, char *comment) {
    time_t tp;
    time(&tp);
    printf("Thread %d %s barrier at %s", tid, comment, ctime(&tp));
}
int main() {
    int tid;
#pragma omp parallel num_threads(NUM_THREADS) private(tid)
    {
        tid = omp_get_thread_num();
        if(tid < omp_get_num_threads() / 2)
            system("sleep 5");
        print_time(tid, "before");
#pragma omp barrier
        print_time(tid, "after");
    }
    return 0;
}