#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

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
    int me;              // Il mio id
    int righe, colonne;  // Dimensione della matrice
    int i, j;            // Iteratori vari

    // Variabili di lavoro
    double *A, *v, *w;  // w = risultati
    double T_inizio,T_fine;

    // Se sono a radice
    printf("inserire numero di righe m = \n");
    scanf("%d", &righe);

    printf("inserire numero di colonne n = \n");
    scanf("%d", &colonne);
    // Numero di righe da processare

    // Alloco spazio di memoria
    A = malloc(righe * colonne * sizeof(double));
    v = malloc(sizeof(double) * colonne);
    w = malloc(sizeof(double) * righe);


    if(righe<=100) printf("v = ");
    for (j = 0; j < colonne; j++) {
        v[j] = j;
        if(righe<=100)
        printf("  %f   ", v[j]);

    }
  if(righe<=100)
printf("\n\n");


    if(righe<=100) printf("A = ");

    for (i = 0; i < righe; i++) {
        for (j = 0; j < colonne; j++) {
            if (j == 0) {
                A[i * colonne + j] = 1.0 / (i + 1) - 1;
            } else {
                A[i * colonne + j] = 1.0 / (i + 1) - pow(1.0 / 2.0, j);
            }
            if(righe<=100)
            printf("   %f  ", A[i*colonne+j] );

        }
          if(righe<=100)
          printf("\n\n   ");
    }
    if(righe<=100)
    printf("\n\n");

    T_inizio=MPI_Wtime();

    prod_mat_vett(w, A, righe, colonne, v);

    T_fine=MPI_Wtime()-T_inizio;

    // 0 stampa la soluzione
    if(righe<=100){
      printf("w = ");
    for (i = 0; i < righe; i++){
          printf("   %f  ", w[i]);


      }
      if(righe<=100)
      printf("\n\n");
    }
    printf("\nTempo impiegato: %lf\n", T_fine);

    return 0;
}
