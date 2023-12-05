#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[]) {
    int rank, value, size, i;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    int buf[size];
    if(rank == 0) {
        for(i = 0; i < size; i++) {
            buf[i] = (i + 1) * 10;
        }
    }
    MPI_Scatter(buf, 1, MPI_INT, &value, 1, MPI_INT, 0, MPI_COMM_WORLD);
    printf("Process %d got value %d\n", rank, value);
    MPI_Finalize();
    return 0;
}