#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char ** argv) {
    int rank, value, size, i;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    int buf[size];
    for(i = 0; i < size; i++) buf[i] = -1;
    value = rank * 10;
    MPI_Gather(&value, 1, MPI_INT, buf, 1, MPI_INT, 0, MPI_COMM_WORLD);
    for(i = 0; i < size; i++) {
        printf("Process %d got value buf[%d] = %d\n", rank, i, buf[i]);
    }
    MPI_Finalize();
    return 0;
}