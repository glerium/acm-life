#include "mpi.h"
#include <stdio.h>
int main(int argc, char * argv[]) {
    int myid, size, value;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if(myid == 0) {
        printf("Enter a value: ");
        scanf("%d", &value);
        printf("Read %d from user input.\n", value);
    }else{
        MPI_Recv(&value, 1, MPI_INT, myid-1, 0, MPI_COMM_WORLD, &status);
        printf("Process %d received %d from Process %d\n", myid, value, myid-1);
    }
    if(myid != size - 1) {
        MPI_Send(&value, 1, MPI_INT, myid+1, 0, MPI_COMM_WORLD);
        printf("Process %d sent %d to Process %d\n", myid, value, myid+1);
    }
    MPI_Finalize();
    return 0;
}