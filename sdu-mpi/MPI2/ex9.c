#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char ** argv) {
    MPI_Init(&argc, &argv);
    int i, rank, size, value;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int buf[size];
    value = rank * 10;
    MPI_Allgather(&value, 1, MPI_INT, &buf, 1, MPI_INT, MPI_COMM_WORLD);
    for(i = 0; i < size; i++)
        printf("Process %d got value buf[%d] = %d\n", rank, i, buf[i]);
    MPI_Finalize();
    return 0;
}