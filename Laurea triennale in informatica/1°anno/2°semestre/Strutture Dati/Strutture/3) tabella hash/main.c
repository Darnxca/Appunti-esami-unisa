#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "elencoLibri.h"

int main(int argc, char *argv[])
{
	int scelta,copie;
	Libreria l;
	char autore[25],codice[16];
	item x;

	while(1)
	{
		printf("\nCosa vuoi fare?\n"
		"1) Crea libreria\n"
		"2) Inseriri i dati di un nuovo libro\n"
		"3) Visualizzare le informazioni di un libro\n"
		"4) Decrementare il numero di copie di un libro\n"
		"5) Incrementare il numero di copie di un libro\n"
		"6) Cancellare un libro\n"
		"7) Stampa tutti i libri della libreria\n"
		"8) Cancellare la libreria\n"
		"9) Uscire dal programma\n");
		scanf("\n%d", &scelta);

		switch(scelta)
		{
		
			case 1: 
				l=newLibreria(30);
				break;
			case 2:
				x=input_item();
				if (x != NULL && insertLibro(l, x) == 0)
	      				printf ("Libro inserito con successo\n");
   	    			else
   	      				printf ("Inserimento libro non riuscito\n");
	   			break;
			case 3:
				 printf ("ISBN del libro da cercare: "); 
	    			 scanf("%s", &codice[0]);
 	   			 if(outputLibro(l, codice) != 0)
   	      				printf ("Corso non trovato\n");
	    			 break;
			case 4:
				printf("Inserisci ISBN del libro: "); 
				scanf("%s", &codice[0]);
        			printf("Numero di copie da rimuovere: "); 
				scanf("%d", &copie);
       				decNum_Copie(l, codice, copie);
				break;
			case 5:
				printf("Inserisci ISBN del libro: "); 
				scanf("%s", &codice[0]);
        			printf("Numero di copie da aggiungere: "); 
				scanf("%d", &copie);
        			incNum_Copie(l, codice, copie);
				break;
			case 6:
				printf ("ISBN del libro da cancellare: "); 
				scanf("%s", &codice[0]);
 	    			if (deleteLibro(l, codice) == 0)
   	      				printf ("Corso eliminato con successo\n");
   	    			else
   	      				printf ("Rimozione non riuscita\n");
				break;
			case 7:
				stampaLibreria(l);
				break;
			case 8:
				destroyLibreria(l);
				break;
			case 9:
				exit(0);
		}

	}	
}