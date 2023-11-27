#include "mpi.h"
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]) {
    int numprocs, procnum;
    int namelen;
    char pro_name[MPI_MAX_PROCESSOR_NAME];

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &procnum);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Get_processor_name(pro_name, &namelen);
    printf("Hello world! Processor %d of %d on %s\n", procnum, numprocs, pro_name);

    MPI_Finalize();
    return 0;
}