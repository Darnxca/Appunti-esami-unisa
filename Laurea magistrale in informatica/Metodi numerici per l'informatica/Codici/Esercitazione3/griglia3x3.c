#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
/* Scopo: definizione di una topologia a griglia bidimensionale nproc=row*col */
int main(int argc, char **argv) {
    int menum, nproc, menum_grid, row, col;
    int dim, *ndim, reorder, *period;
    int coordinate[2],a;


    MPI_Comm comm_grid; /* definizione di tipo communicator */
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &menum);
    MPI_Comm_size(MPI_COMM_WORLD, &nproc);
    /* Numero di righe della griglia di processo */
    if (menum == 0) {
        printf("Numero di righe della griglia ");
        scanf("%d", &row);
    }
    /* Spedizione di row da parte di 0 a tutti i processori */
    MPI_Bcast(&row, 1, MPI_INT, 0, MPI_COMM_WORLD);
    col =  row; /* Numero di colonne della griglia */
    dim = 2;           /* Numero di dimensioni della griglia */
    /* vettore contenente le lunghezze di ciascuna dimensione*/
    ndim = (int *)calloc(dim, sizeof(int));
    ndim[0] = row;
    ndim[1] = col;
    /* vettore contenente la periodicit� delle dimensioni */
    period = (int *)calloc(dim, sizeof(int));
    period[0] = 0;
    period[1] = 0;
    reorder = 0;
    /* Definizione della griglia bidimensionale */
    MPI_Cart_create(MPI_COMM_WORLD, dim, ndim, period, reorder, &comm_grid);
    MPI_Comm_rank(comm_grid, &menum_grid);
    /* Definizione delle coordinate di ciascun processo  nella griglia
     * bidimensionale */
    MPI_Cart_coords(comm_grid, menum_grid, dim, coordinate);
    /* Stampa delle coordinate */
    int i = *coordinate;
    int j = *(coordinate+1);
    if(i == j){// cordinate = i, 
        a = i * i;
        printf("Processore %d coordinate nella griglia  (%d,%d) valore: %d\n", menum,
           *coordinate, *(coordinate + 1),a);
    }else {
        a =  i + 2 * j;
        printf("Processore %d coordinate nella griglia  (%d,%d) valore: %d\n", menum,
           *coordinate, *(coordinate + 1),a);
    }
    
    MPI_Finalize();
    return 0;
}