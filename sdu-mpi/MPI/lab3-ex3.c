#include <stdio.h>
#include "mpi.h"
int main(int argc, char * argv[]) {
    int myid, size, value;
    double begin, end, diff;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    begin = MPI_Wtime();
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (myid == 0) {
        fprintf(stderr, "Input a value: ");
        scanf("%d", &value);
        fprintf(stderr, "Process %d read from user: %d\n", myid, value);

        MPI_Send(&value, 1, MPI_INT, myid + 1, 0, MPI_COMM_WORLD);
        fprintf(stderr, "Process %d send value %d to Process %d\n", myid, value, myid+1);
    } else {
        MPI_Recv(&value, 1, MPI_INT, myid-1, 0, MPI_COMM_WORLD, &status);
        fprintf(stderr, "Process %d receive value %d from Process %d\n", myid, value, myid-1);
        if (myid < size - 1) {
            MPI_Send(&value, 1, MPI_INT, myid+1, 0, MPI_COMM_WORLD);
            fprintf(stderr, "Process %d send value %d to Process %d\n", myid, value, myid+1);
        }
    }
    end = MPI_Wtime();
    diff = end - begin;
    MPI_Finalize();

    return 0;
}