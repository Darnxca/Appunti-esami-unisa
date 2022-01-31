#include <math.h>
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Funzione che esegue il prodotto matrice vettore
 */
void prod_mat_vett(double w[], double *a, int ROWS, int COLS, double v[]) {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        w[i] = 0;
        for (j = 0; j < COLS; j++) {
            w[i] += a[i * COLS + j] * v[j];
        }
    }
}

int main(int argc, char **argv) {
    int nproc;           // Numero di processi totale
    int idProc;              // Il mio id
    int righe, colonne;  // Dimensione della matrice
    int local_m;         // Dimensione dei dati locali
    int p, q;  // p e q processori
    int i, j;            // Iteratori vari



    int nproc_grid, IDrow, IDcol;
    int dim, *ndim, reorder, *period,belongs[2];
    int coordinate[2],a,coordinate_righe[2],coordinate_colonne[2];

    // Variabili di lavoro
    double *A, *v, *localA,*localAt, *local_w,*A_Righe_local,*local_v ,*w;
    double T_inizio, T_fine, T_max;

    MPI_Comm comm_grid,commcol,commrow;
    /*Attiva MPI*/
    MPI_Init(&argc, &argv);
    /*Trova il numero totale dei processi*/
    MPI_Comm_size(MPI_COMM_WORLD, &nproc);
    /*Da ad ogni processo il proprio numero identificativo*/
    MPI_Comm_rank(MPI_COMM_WORLD, &idProc);

    // Se sono a radice
    if (idProc == 0) {
      printf("inserire numero di processori riga p = \n");
      scanf("%d", &p);

      printf("inserire numero di processori colonna q = \n");
      scanf("%d", &q);

      printf("inserire numero di righe m = \n");
      scanf("%d", &righe);


        if(righe % p != 0)
            printf("Il numero di righe deve essere multiplo del numero di p\n");

        printf("inserire numero di colonne n = \n");
        scanf("%d", &colonne);

        if(colonne % q != 0)
            printf("Il numero di colonne deve essere multiplo del numero di q\n");



        // Alloco spazio di memoria
        A = malloc(righe * colonne * sizeof(double));
        v = malloc(sizeof(double) * colonne);
        w = malloc(sizeof(double) * righe);

        printf("v = \n\n");

        for (j = 0; j < colonne; j++) {
            v[j] = j;
            printf("%f    ", v[j]);
        }

        printf("\n\n");

        printf("A = \n\n");

        for (i = 0; i < righe; i++) {
            for (j = 0; j < colonne; j++) {
                if (j == 0) {
                    A[i * colonne + j] = 1.0 / (i + 1) - 1;
                    //A[i * colonne + j] = i;
                } else {
                    A[i * colonne + j] = 1.0 / (i + 1) - pow(1.0 / 2.0, j);
                    //A[i * colonne + j] = i;
                }

                printf("%f    ", A[i*colonne+j] );
            }
            printf("\n\n");
        }

    }  // fine idProc==0


    // creazione griglia

    /* Spedizione di row da parte di 0 a tutti i processori */
    MPI_Bcast(&righe, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&colonne, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&p, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&q, 1, MPI_INT, 0, MPI_COMM_WORLD);

    dim = 2;           /* Numero di dimensioni della griglia */
    /* vettore contenente le lunghezze di ciascuna dimensione*/
    ndim = (int *)calloc(dim, sizeof(int));
    ndim[0] = p;
    ndim[1] = q;
    /* vettore contenente la periodicit� delle dimensioni */
    period = (int *)calloc(dim, sizeof(int));
    period[0] = 0;
    period[1] = 0;
    reorder = 0;
    /* Definizione della griglia bidimensionale */
    MPI_Cart_create(MPI_COMM_WORLD, dim, ndim, period, reorder, &comm_grid);
    MPI_Comm_rank(comm_grid, &nproc_grid);
    /* Definizione delle coordinate di ciascun processo  nella griglia
     * bidimensionale */
    MPI_Cart_coords(comm_grid, nproc_grid, dim, coordinate);
    /* crea le sottogriglie di righe*/
    belongs[0] = 0;
    belongs[1] = 1; /*dim. variabile*/
    MPI_Cart_sub(comm_grid, belongs, &commrow);
    MPI_Comm_rank(commrow, &IDrow);
    MPI_Cart_coords(commrow, IDrow, 1, coordinate_righe);
    /* crea le sottogriglie di colonne*/
    belongs[0] = 1; /* dim. variabile*/
    belongs[1] = 0;
    MPI_Cart_sub(comm_grid, belongs, &commcol);
    MPI_Comm_rank(commcol, &IDcol);
    MPI_Cart_coords(commcol, IDcol, 1, coordinate_colonne);
    //coordinate
    int indice_i = *coordinate;
    int indice_j = *(coordinate+1);
    MPI_Barrier(MPI_COMM_WORLD);      // sincronizzazion
    //matrice d'appoggio ogni processo della prima colonna della griglia ha gli elementi di tutta la riga di cui fa parte
    A_Righe_local= malloc(sizeof(double) * (righe/p)*colonne);
    //matrice localA trasposta d'appoggio
    localAt = malloc(sizeof(double) * (righe/p)*(colonne/q));
    //numero di elementi di x[0]
    int num = colonne/q;
    local_v = malloc(sizeof(double) * num);
    //P00 distribuisce il vettore alla sua riga
    if(*coordinate_colonne==0){
      MPI_Scatter(&v[0],num, MPI_DOUBLE, &local_v[0],num,MPI_DOUBLE, 0, commrow);
      //printf("processo %d %d ha come vettore locale : %lf %lf \n", indice_i,indice_j, local_v[0],local_v[1]);

    }
    MPI_Barrier(MPI_COMM_WORLD);
    //Ogni processo della prima riga distribuisce il vettore alla sua colonna
    MPI_Bcast(&local_v[0], num, MPI_DOUBLE, 0, commcol);
    //printf("processo %d %d ha come vettore locale : %lf %lf \n", indice_i,indice_j, local_v[0],local_v[1]);

    //numero di elementi di A_Righe_local
     int num1= (righe/p)*colonne;
     // distribuisco le righe ai processi della prima colonna della griglia
     if(*coordinate_righe == 0){
        MPI_Scatter(&A[0], num1, MPI_DOUBLE, &A_Righe_local[0], num1, MPI_DOUBLE, 0,commcol);
        printf("processo %d %d ha come A_Righe_local: \n",indice_i,indice_j);
      for(int j=0;j<righe/p;j++){
          for(int i=0;i<colonne;i++){
            printf("%lf  ",A_Righe_local[j * colonne + i]);
            }
            printf("\n\n");
          }
        }
    MPI_Barrier(MPI_COMM_WORLD);
    //trasposizione di A_Righe_local
    double *At = malloc(sizeof(double) * colonne*(righe/p));
    for (int i = 0; i < colonne; i++){
        for (int j = 0; j < (righe/p); j++) {
            At[i * righe/p + j] = A_Righe_local[j * colonne + i];

            }
          }
  //distribuisco gli elementi ad ogni processo
   int num2=righe/p * colonne/q;
   MPI_Barrier(MPI_COMM_WORLD);
   MPI_Scatter(&At[0], num2, MPI_DOUBLE, &localAt[0], num2, MPI_DOUBLE, 0,commrow);
   MPI_Barrier(MPI_COMM_WORLD);
    //trasposizione di localA
    localA = malloc(sizeof(double) * (righe/p)*(colonne/q));
    for (int i = 0; i < colonne/q; i++){
        for (int j = 0; j < (righe/p); j++) {
            localA[j * colonne/q + i] = localAt[i * righe/p + j];
            }
          }
            MPI_Barrier(MPI_COMM_WORLD);

      //stampo LocalA
    if(righe<=100){
        printf("processo %d %d ha come localA: \n",indice_i,indice_j);
        for(int z=0;z<(righe/p); z++){
            for(int k=0;k<(colonne/q);k++){
              if(righe<=100)
              printf(" %lf ", localA[z*(colonne/q)+k]);
            }
            if(righe<=100)
            printf("\n\n ");
        }
        }
        MPI_Barrier(MPI_COMM_WORLD);

    MPI_Finalize(); /* Disattiva MPI */
    return 0;
}
