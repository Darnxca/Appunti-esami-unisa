#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "libreria.h"

int main (void)
{
	Libreria T;
	item val,key;
	int scelta,x;
	char isbn[10];

	while(1)
	{
		printf("Scegli tra le seguenti opzioni:\n"
		       " 1) Crea Libreria;\n"
		       " 2) Input Libreria\n"
		       " 3) Conrollare se la libreria ha almeno un libro\n"
		       " 4) Sapere il primo libro della libreria\n"
		       " 5) Sapere il numero di libri presenti nell'albero\n"
		       " 6) Stamapre la libreria\n"
		       " 7) Eliminare un libro\n"
		       " 8) Cercare un libro\n"
		       " 9) Libri senza copie\n"
		       "10) Aggiungi copie ad un libro\n"
		       "11) Togli copie ad un libro\n"
		       "12) Esci\n");

		scanf("%d",&scelta);

		switch(scelta)
		{

			case 1:
				T=newLibreria();
				printf("libreria creata \n");		
				break;
	
			case 2:
				printf("Inserisci il valore: ");
				val=input_item();
				insertLibro(T,val);
				break;

			case 3:
				if(EmptyLibreria(T)==1)
					printf("La libreria è vuota\n");
				else 
					printf("La libreria non è vuota \n");
				break;
			
			case 4:
				printf("Il primo libro è :\n");
				FirstLibro(T);
				break;
		
			case 5:
				printf("La libreria contiene %d libri\n",NumeroLibri(T));  //root
				break;
			
			case 6:
				printf("La libreria è:\n");
				stampaLibreria(T);
				printf("\n");
				break;
	
			case 7:
				
				deleteLibro(T);
				break;
			
			case 8:
		
				if(cercaLib(T))
					printf("L'elemento è presente\n");
				
				else
					printf("L'elemento non è presente\n");

				break;
			case 9:
				LibSenzaCopie(T);
				break;
			case 10:
				printf("Inserisci codice isbn del libro a cui aggiungere:\n");
				scanf("%s",&isbn[0]);	
				printf("Quante copie aggiungere?:\n");
				scanf("%d",&x);	
				AddCopie(T, isbn, x);
				break;
			case 11:
				printf("Inserisci codice isbn del libro a cui togliere:\n");
				scanf("%s",&isbn[0]);	
				printf("Quante copie vuoi togliere?:\n");
				scanf("%d",&x);	
				SubCopie(T, isbn, x);
				break;
			case 12:
				exit(1);
		}	
	}	
}