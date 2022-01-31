#include <math.h>
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Funzione che esegue il prodotto matrice vettore
 */
 void prod_mat_vett(double w[], double *a, int ROWS, int COLS, double v[]) {
     int i, j;

     for (i = 0; i < COLS; i++) {
         w[i] = 0;
         for (j = 0; j < ROWS; j++) {
             w[i] += a[j * COLS + i] * v[j];
         }
     }
 }

int main(int argc, char **argv) {
    int nproc;           // Numero di processi totale
    int me;              // Il mio id
    int righe, colonne;  // Dimensione della matrice
    int local_m,local_m_gen,resto;         // Dimensione dei dati locali
    int i, j,num,*displs_v,*scounts_v,offset_v,*displs_At,*scounts_At,offset_At;

    // Variabili di lavoro
    double *A,*At, *v, *localA, *local_w, *w,*local_v;
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
        At = malloc(righe * colonne * sizeof(double));
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
            if(righe<=100)
              printf("\n\n   ");
        }

        // trasposizione della matrice
        for (int i = 0; i < colonne; ++i){
            for (int j = 0; j < righe; ++j) {
              At[i * righe + j] = A[j * colonne + i];
                //At[j * colonne + i] = A[i * righe + j];
            }
        }

        //stampo matrice trasposta
        printf("\n\n");
        if(righe<=100) printf("At = ");
        for(int z=0;z<colonne; z++){
          for(int k=0;k<righe;k++){
            if(righe<=100)
            printf(" %lf ", At[z*righe+k]);
          }
          if(righe<=100)
          printf("\n\n     ");
        }

        // Numero di colonne da processare genericamente
        local_m_gen = colonne/ nproc; //divisione intera
        resto= colonne % nproc;
        //alloco variabili per ScatterV del vettore
        displs_v = (int *)malloc((nproc-1) * sizeof(int)); // array che contiene nell'indice i da dove la ScatterV deve partire per l'i-esimo processo
        scounts_v = (int *)malloc(nproc * sizeof(int)); // array che contiene nell'indice i il numero di elementi che deve avere l'i-esimo processo
        offset_v=0;//variabile temporanea per calcolare displs
        //alloco variabili per ScatterV della matrice
        displs_At=(int *)malloc((nproc-1) * sizeof(int));//array che contiene nell'indice i da dove la GatherV deve iniziare ad inserire per l'i-esimo processo
        scounts_At= (int *)malloc(nproc * sizeof(int));//array che contiene nell'indice i il numero di elementi che riceveremo dall'i-esimo processo
        offset_At=0;//variabile temporanea per displs_gathers
        //numero di colonne da dare ai processi < resto
        int num1=local_m_gen+1;
        //numero di colonne da dare ai processi < resto
        int num2= local_m_gen;
        //compilo i parametri che serviranno per le due ScatterV
        for(int i=0;i<nproc;i++){
          if(i<resto){
            //parametri Scatterv per vettore
            displs_v[i]=offset_v;
            scounts_v[i]= num1;
            offset_v=offset_v+ (num1);
            //parametri ScatterV per matrice
            displs_At[i]=offset_At;
            scounts_At[i]=(local_m_gen+1)*righe;
            offset_At=offset_At + scounts_At[i];
          }else{
            //parametri Scatterv per vettore
            displs_v[i]=offset_v;
            scounts_v[i]= num2;
            offset_v=offset_v+ (num2);
            //parametri ScatterV per matrice
            displs_At[i]=offset_At;
            scounts_At[i]=local_m_gen*righe;
            offset_At=offset_At + scounts_At[i];
          }
        }
    }  // fine me==0


    // // Spedisco le variabili calcolate da P0 e che mi serviranno per tutti i processi
    MPI_Bcast(&righe, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&colonne, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&local_m_gen, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&displs_v, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&scounts_v, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&scounts_At, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&displs_At, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&resto, 1, MPI_INT, 0, MPI_COMM_WORLD);

    // Se resto è non nullo, i primi resto processi ricevono una colonna in piu'
    if(me<resto){
      local_m= local_m_gen +1;
      num=local_m*righe;
      // tutti allocano A locale e il vettore dei risultati
      localA = malloc(local_m * righe * sizeof(double));
      local_w = malloc(righe * sizeof(double));
      local_v = malloc(sizeof(double) * local_m);
      // 0 invia a tutti il pezzo del vettore v che gli servirà per il prodotto locale
      MPI_Scatterv(&v[0], scounts_v,displs_v, MPI_DOUBLE, &local_v[0], local_m, MPI_DOUBLE, 0,
                MPI_COMM_WORLD);
      // 0 invia a tutti un pezzo della matrice trasposta a localA che avrà una riga in più
      MPI_Scatterv(&At[0], scounts_At,displs_At, MPI_DOUBLE, &localA[0], num, MPI_DOUBLE, 0,
                          MPI_COMM_WORLD);

      }else{
        local_m= local_m_gen;
        num=local_m*righe;
        // tutti allocano A locale e il vettore dei risultati
        localA = malloc(local_m * righe * sizeof(double));
        local_w = malloc(righe * sizeof(double));
        local_v = malloc(sizeof(double) * local_m);
        // 0 invia a tutti il pezzo del vettore v che gli servirà per il prodotto locale
        MPI_Scatterv(&v[0], scounts_v,displs_v, MPI_DOUBLE, &local_v[0], local_m, MPI_DOUBLE, 0,
                  MPI_COMM_WORLD);
        // 0 invia a tutti un pezzo della matrice trasposta a localA che avrà una riga in più
        MPI_Scatterv(&At[0], scounts_At,displs_At, MPI_DOUBLE, &localA[0], num, MPI_DOUBLE, 0,
                            MPI_COMM_WORLD);

      }


    T_inizio = MPI_Wtime();
    // Effettuiamo i calcoli
    if(me<resto){
      prod_mat_vett(local_w, localA,(local_m_gen+1),righe, local_v);
    }else{
      prod_mat_vett(local_w, localA,local_m_gen,righe, local_v);
    }


    // 0 raccoglie i risultati parziali
    MPI_Reduce(local_w,w,  righe, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    T_fine = MPI_Wtime() - T_inizio;  // calcolo del tempo di fine

    MPI_Barrier(MPI_COMM_WORLD);

    MPI_Reduce(&T_fine, &T_max, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);
    // 0 stampa la soluzione
    if (me == 0) {

      if(righe<=100){
        printf("w = ");
        for (i = 0; i < righe; i++){
          printf("%f    ", w[i]);
        }
        printf("\n\n");
      }
        printf("\nTempo calcolo locale: %lf\n", T_fine);
        printf("\nMPI_Reduce max time: %f\n", T_max);
    }

    MPI_Finalize(); /* Disattiva MPI */
    return 0;
}
