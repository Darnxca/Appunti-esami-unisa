#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
void main(int argc, char *argv[]) {
    int nrow, mcol, i, lastrow, p, root;
    int Iam, id2D, colID, ndim;
    int coords1D[1], coords2D[2], dims[2], aij, alocal[3];
    int belongs[2], periods[2], reorder;
    MPI_Comm comm2D, commcol;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &Iam); /*identificativo*/
    MPI_Comm_size(MPI_COMM_WORLD, &p);   /*numero di processi */

    nrow = 3;
    mcol = 2;
    ndim = 2;
    root = 0;
    periods[0] = 1;
    periods[1] = 0;
    reorder = 1;

    /* crea la topologia cartesiana 2D */
    dims[0] = nrow; /* numero di righe */
    dims[1] = mcol; /* numero di colonne */
    MPI_Cart_create(MPI_COMM_WORLD, ndim, dims, periods, reorder, &comm2D);
    MPI_Comm_rank(comm2D, &id2D);
    MPI_Cart_coords(comm2D, id2D, ndim, coords2D);

    /* Crea le sottogriglie di colonne 1D */
    belongs[0] = 1;
    belongs[1] = 0;
    MPI_Cart_sub(comm2D, belongs, &commcol);
    MPI_Comm_rank(commcol, &colID);
    MPI_Cart_coords(commcol, colID, 1, coords1D);

    /* la barrier assicura che tutti conoscano le proprie coordinate prima di
     * assegnare aij*/
    MPI_Barrier(MPI_COMM_WORLD);

    /* aij = (i+1)*10 + j + 1; 1 elemento matrice per ogni processore di posto
     * (i,j) */
    aij = (coords2D[0] + 1) * 10 + coords2D[1] + 1;

    /* crea alocal */
    for (i = 0; i <= nrow - 1; i++) {
        alocal[i] = -1;
    }

    /*gather in ogni colonna all'ultimo processo, che memorizza i dati ricevuti
     * in alocal */
    lastrow = nrow - 1; /* id dell�ultimo elemento della colonna */
    MPI_Gather(&aij, 1, MPI_INT, alocal, 1, MPI_INT, lastrow, commcol);

    if (Iam == root) {
        printf("\n	MPI_Cart_sub example:");
        printf("\n 3x2 cartesian grid ==> 2 (3x1) column subgrids\n");
        printf("\n Iam \t 2D \t	2D \t 1D \t 1D \t	aij");
        printf("\n Rank \t Rank \t coords. \t Rank \t coords.\n");
        fflush(stdout);
    }

    // la barrier garantisce che stampi prima root
    MPI_Barrier(MPI_COMM_WORLD);

    printf("%6d|%6d|%6d %6d|%6d|%8d|", Iam, id2D, coords2D[0], coords2D[1],
           colID, coords1D[0]);
    for (i = 0; i <= lastrow; i++) {
        printf("%6d ", alocal[i]);
    }
    printf("\n");
    MPI_Finalize();
}
