#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char ** argv) {
    MPI_Init(&argc, &argv);
    int i, rank, size, value;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int buf;
    value = rank * 10;
    MPI_Scan(&value, &buf, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
    printf("Process %d got value buf = %d\n", rank, buf);
    MPI_Finalize();
    return 0;
}