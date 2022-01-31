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
    int me;              // Il mio id
    int righe, colonne;  // Dimensione della matrice
    int local_m_gen,local_m,resto;         // Dimensione dei dati locali
    int i, j,num,*displs,*scounts,offset,*recvcounts,*displs_gathers,offset_gather;
    // Variabili di lavoro
    double *A, *v, *localA, *local_w, *w;
    double T_inizio, T_fine, T_max;

    /*Attiva MPI*/
    MPI_Init(&argc, &argv);
    /*Trova il numero totale dei processi*/
    MPI_Comm_size(MPI_COMM_WORLD, &nproc);
    /*Da ad ogni processo il proprio numero identificativo*/
    MPI_Comm_rank(MPI_COMM_WORLD, &me);

    // Se sono a radice
    if (me == 0) {
        printf("inserire numero di righe m = \n");
        scanf("%d", &righe);

        printf("inserire numero di colonne n = \n");
        scanf("%d", &colonne);

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
        printf("\n\n");


    if(righe<=100) printf("A = ");
        for (i = 0; i < righe; i++) {
            for (j = 0; j < colonne; j++) {
                if (j == 0) {
                    A[i * colonne + j] = 1.0 / (i + 1) - 1;
                     //A[i * colonne + j] = i;
                } else {
                    A[i * colonne + j] = 1.0 / (i + 1) - pow(1.0 / 2.0, j);
                     //A[i * colonne + j] = i;
                }

                if(righe<=100)
                printf("   %f  ", A[i*colonne+j] );

            }
            printf("\n\n   ");
        }
        printf("\n\n");

        // Numero di righe da processare genericamente
        local_m_gen = righe / nproc; //divisione intera
        resto= righe % nproc;
        //alloco variabili per ScatterV
        displs = (int *)malloc((nproc-1) * sizeof(int)); // array che contiene nell'indice i da dove la ScatterV deve partire per l'i-esimo processo
        scounts = (int *)malloc(nproc * sizeof(int)); // array che contiene nell'indice i il numero di elementi che deve avere l'i-esimo processo
        offset=0;//variabile temporanea per calcolare displs
        //alloco variabili per GatherV
        displs_gathers=(int *)malloc((nproc-1) * sizeof(int));//array che contiene nell'indice i da dove la GatherV deve iniziare ad inserire per l'i-esimo processo
        recvcounts= (int *)malloc(nproc * sizeof(int));//array che contiene nell'indice i il numero di elementi che riceveremo dall'i-esimo processo
        offset_gather=0;//variabile temporanea per displs_gathers
        //numero di elementi da dare ai processi < resto
        int num1=(local_m_gen+1)*colonne;
        //numero di elementi da dare ai processi < resto
        int num2= local_m_gen*colonne;
        //compilo i parametri che serviranno per ScatterV e GatherV
        for(int i=0;i<nproc;i++){
          if(i<resto){
            //parametri Scatterv
            displs[i]=offset;
            scounts[i]= num1;
            offset=offset+ (num1);
            //parametri Gatherv
            displs_gathers[i]=offset_gather;
            recvcounts[i]=local_m_gen+1;
            offset_gather=offset_gather + recvcounts[i];
          }else{
            //parametri Scatterv
            displs[i]=offset;
            scounts[i]= num2;
            offset=offset+ (num2);
            //parametri Gatherv
            displs_gathers[i]=offset_gather;
            recvcounts[i]=local_m_gen;
            offset_gather=offset_gather + recvcounts[i];
          }
        }
    }  // fine me==0

    // Spedisco le variabili calcolate da P0 e che mi serviranno per tutti i processi
    MPI_Bcast(&righe, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&colonne, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&local_m_gen, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&displs, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&scounts, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&recvcounts, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&displs_gathers, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&resto, 1, MPI_INT, 0, MPI_COMM_WORLD);
    // Se sono un figlio alloco v
    if (me != 0) v = malloc(sizeof(double) * colonne);

    MPI_Bcast(&v[0], colonne, MPI_DOUBLE, 0, MPI_COMM_WORLD);


    // Se resto è non nullo, i primi resto processi ricevono una riga in piu'
    if (me < resto) {
       local_m = local_m_gen + 1;
       num= local_m*colonne;
       // tutti allocano A locale e il vettore dei risultati
       localA = malloc(local_m * colonne * sizeof(double));
       local_w = malloc(local_m * sizeof(double));
       // 0 invia a tutti un pezzo della matrice a localA che avrà una riga in più
       MPI_Scatterv(&A[0], scounts,displs, MPI_DOUBLE, &localA[0], num, MPI_DOUBLE, 0,
                 MPI_COMM_WORLD);

    } else {
        local_m = local_m_gen;
        num= local_m*colonne;
        // tutti allocano A locale e il vettore dei risultati
        localA = malloc(local_m * colonne * sizeof(double));
        local_w = malloc(local_m * sizeof(double));
        // 0 invia a tutti un pezzo della matrice a localA che avrà righe/nproc righe
        MPI_Scatterv(&A[0], scounts,displs, MPI_DOUBLE, &localA[0], num, MPI_DOUBLE, 0,
                  MPI_COMM_WORLD);

    }
     MPI_Barrier(MPI_COMM_WORLD);      // sincronizzazione
     //stampo localA per ogni processo
     if(righe<=100){
     int num3=(local_m_gen+1)*colonne;
     int num4= local_m_gen*colonne;
      printf("matrice locale del processo %d = \n",me);
      if(me<resto){
      for(int z=0;z<num3;z++){
        printf("  %lf ",localA[z]);
      }
    printf("\n\n");
  }else{
    for(int z=0;z<num4;z++){
      printf("  %lf ",localA[z]);
    }
  printf("\n\n");
    }
  }

    T_inizio = MPI_Wtime();
    // Effettuiamo i calcoli
    prod_mat_vett(local_w, localA, local_m, colonne, v);

    // 0 raccoglie i risultati parziali
    if(me<resto){
        //In questo caso da local_w dobbiamo prendere un elemento in più visto che è la local_w di un proc a cui era stata una riga in più
        MPI_Gatherv(&local_w[0], (local_m_gen+1), MPI_DOUBLE, &w[0], recvcounts,displs_gathers, MPI_DOUBLE, 0,
               MPI_COMM_WORLD);

      }else{
              MPI_Gatherv(&local_w[0], local_m_gen, MPI_DOUBLE, &w[0], recvcounts,displs_gathers, MPI_DOUBLE, 0,
                     MPI_COMM_WORLD);
            }

    MPI_Barrier(MPI_COMM_WORLD);      // sincronizzazione
    T_fine = MPI_Wtime() - T_inizio;  // calcolo del tempo di fine
    MPI_Reduce(&T_fine, &T_max, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);
    // 0 stampa la soluzione
    if (me == 0) {
      if(righe<=100){
        printf("w = \n");
      for (i = 0; i < righe; i++){
            printf("   %f  ", w[i]);
        }
        printf("\n\n");
      }
        printf("\nTempo calcolo locale: %lf\n", T_fine);
        printf("\nMPI_Reduce max time: %f\n", T_max);
    }

    MPI_Finalize(); /* Disattiva MPI */
    return 0;
}
