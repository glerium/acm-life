#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char ** argv) {
    MPI_Init(&argc, &argv);
    int i, rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    double ain[size], aout[size];
    int ind[size];
    struct {
        double val;
        int rank;
    } in[size], out[size];
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    srand((unsigned)(rank + time(NULL)));
    for(i = 0; i < size; i++) ain[i] = (1.0 * rand()) / RAND_MAX;
    for(i = 0; i < size; i++) {
        in[i].val = ain[i];
        in[i].rank = rank;
    }
    for(i = 0; i < size; i++)
        printf("rank=%d, %.3f\n", rank, ain[i]);
    MPI_Reduce(in, out, size, MPI_DOUBLE_INT, MPI_MAXLOC, 0, MPI_COMM_WORLD);
    if(rank == 0){
        printf("Reduce result:\n");
        for(i = 0; i < size; i++) {
            aout[i] = out[i].val;
            ind[i] = out[i].rank;
            printf("Max value in %d column is %.3f from rank %d\n", i, aout[i], ind[i]);
        }
    }
    MPI_Finalize();
    return 0;
}