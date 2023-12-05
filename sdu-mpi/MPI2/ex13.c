#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char ** argv) {
    MPI_Init(&argc, &argv);
    int i, rank, size, value;
    MPI_Status status;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    do {
        MPI_Barrier(MPI_COMM_WORLD);
        if(rank == 0) {
            printf("Input a value: ");
            scanf("%d", &value);
            printf("Process %d read %d from user input.\n", rank, value);
            if(size > 1) {
                MPI_Send(&value, 1, MPI_INT, rank+1, 0, MPI_COMM_WORLD);
                printf("Process %d send %d to Process %d\n", rank, value, rank+1);
            } 
        }else{
            MPI_Recv(&value, 1, MPI_INT, rank-1, 0, MPI_COMM_WORLD, &status);
            printf("Process %d reveive %d from Process %d\n", rank, value, rank-1);
            if(rank < size-1) {
                MPI_Send(&value, 1, MPI_INT, rank+1, 0, MPI_COMM_WORLD);
                printf("Process %d send %d to Process %d\n", rank, value, rank+1);
            }
        }
        MPI_Barrier(MPI_COMM_WORLD);
    } while(value>0);
    MPI_Finalize();
    return 0;
}