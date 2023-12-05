#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char ** argv) {
    MPI_Init(&argc, &argv);
    int i, rank, size, value;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int buf[size], val[size];
    for(i=0;i<size;i++) 
        buf[i] = rank * size + i;
    MPI_Alltoall(buf, 1, MPI_INT, val, 1, MPI_INT, MPI_COMM_WORLD);
    for(i=0;i<size;i++)
        printf("Process %d got value val[%d] = %d\n", rank, i, val[i]);
    MPI_Finalize();
    return 0;
}