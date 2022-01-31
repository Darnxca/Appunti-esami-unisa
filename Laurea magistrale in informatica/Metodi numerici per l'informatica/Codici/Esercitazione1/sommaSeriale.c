#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

#define RANGE 5

int main (int argc, char **argv){

  	int n;
    float somma = 0,*vett;
    double T_inizio,T_fine;

    printf("Inserire il numero di elementi da sommare: \n");
		fflush(stdout);
		scanf("%d",&n);

    vett=(float*)calloc(n,sizeof(float));


    /*Inizializza la generazione random degli addendi utilizzando l'ora attuale del sistema*/
    srand((unsigned int) time(0));

    for(int i=0; i<n; i++){
      /*creazione del vettore contenente numeri casuali */
      //*(vett+i)=(int)rand()%5-2;
      *(vett+i) = (float)rand()/(float)(RAND_MAX/RANGE)-2;
    }


    // Stampa del vettore che contiene i dati da sommare, se sono meno di 100
    if (n<100){
      for (int i=0; i<n; i++){
        printf("\n\nElemento %d del vettore =%f ",i,*(vett+i));
      }
    }
    T_inizio=MPI_Wtime();
    for(int i=0;i<n;i++){
  		somma=somma+*(vett+i);
  	}
    T_fine=MPI_Wtime()-T_inizio;


    printf("\nLa somma degli elementi del vettore è: %f\n ",somma );
    printf("\nIl tempo impiegato è: %lf\n ",T_fine );

}
