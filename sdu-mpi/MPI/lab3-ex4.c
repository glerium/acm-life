#include "mpi.h"
#include <stdio.h>
int main(int argc, char * argv[]) {
    int myid, size, buf[1];
    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if(myid == 0) {
        for(int i=0; i<10*(size-1); i++) {
            MPI_Recv(buf, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
            fprintf(stderr, "Msg = %d from Process %d with tag %d\n", buf[0], status.MPI_SOURCE, status.MPI_TAG);
        }
    } else {
        for(int i=0; i<10; i++) {
            buf[0] = 10 * myid + i;
            MPI_Send(buf, 1, MPI_INT, 0, i, MPI_COMM_WORLD);
        }
    }
    MPI_Finalize();
    return 0;
}