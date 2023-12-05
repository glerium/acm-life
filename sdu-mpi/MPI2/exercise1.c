#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#define TAG_COL_COUNT (0)
#define TAG_VECTOR (3)
#define TAG_ROW_COUNT (6)
#define TAG_COLUMN(x) (x*3+1)
#define TAG_ANSWER(x) (x*3+2)

int main(int argc, char ** argv) {
    int rank, size, i, j;
    int n, m;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if(rank == 0) {
        printf("Enter row count: ");
        scanf("%d", &n);
        printf("Enter column count: ");
        scanf("%d", &m);
        if(m > size) {
            fprintf(stderr, "column count can't be greater then %d! Exiting\n", size-1);
            exit(1);
        }
        int matrix[n+5][m+5], vec[m+5], ans[n+5];
        for(i=1;i<=size-1;i++) MPI_Send(&n, 1, MPI_INT, i, TAG_ROW_COUNT, MPI_COMM_WORLD);
        for(i=1;i<=size-1;i++) MPI_Send(&m, 1, MPI_INT, i, TAG_COL_COUNT, MPI_COMM_WORLD);

        printf("Enter a matrix of shape (%d, %d):\n", n, m);
        for(i=1;i<=n;i++) {
            for(j=0;j<m;j++)
                scanf("%d", &matrix[i][j]);
        }

        int tmp[m+5];
        for(i=1;i<=n;i++) {
            for(j=0;j<m;j++)
                tmp[j]=matrix[i][j];
            MPI_Send(tmp, m, MPI_INT, i, TAG_COLUMN(i), MPI_COMM_WORLD);
        }

        printf("Enter a column vector of shape (%d, 1):\n", m);
        for(j=0;j<m;j++)
            scanf("%d", &vec[j]);
        for(i=1;i<=n;i++) 
            MPI_Send(vec, m, MPI_INT, i, TAG_VECTOR, MPI_COMM_WORLD);

        MPI_Status status;
        for(i=1;i<=n;i++)
            MPI_Recv(&ans[i], 1, MPI_INT, i, TAG_ANSWER(i), MPI_COMM_WORLD, &status);
        printf("Answer: [");
        for(i=1;i<=n;i++) printf("%d%s", ans[i], i!=n?" ":"]\n");
    }else if(rank <= n){
        MPI_Status status;
        int n, m;
        MPI_Recv(&n, 1, MPI_INT, 0, TAG_ROW_COUNT, MPI_COMM_WORLD, &status);
        MPI_Recv(&m, 1, MPI_INT, 0, TAG_COL_COUNT, MPI_COMM_WORLD, &status);
        if(rank > n) goto end;
        int vec[m+5], column[m+5], ans=0;
        MPI_Recv(vec, m, MPI_INT, 0, TAG_VECTOR, MPI_COMM_WORLD, &status);

        MPI_Recv(column, m, MPI_INT, 0, TAG_COLUMN(rank), MPI_COMM_WORLD, &status);

        for(i=0;i<m;i++) ans+=column[i]*vec[i];
        MPI_Send(&ans, 1, MPI_INT, 0, TAG_ANSWER(rank), MPI_COMM_WORLD);
    }
end:
    MPI_Finalize();
    return 0;
}