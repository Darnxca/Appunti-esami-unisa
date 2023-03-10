#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "concessionaria.h"

int main (void)
{
	Concessionaria T;
	item val,key;
	int scelta,x;
	char targa[6];

	while(1)
	{
		printf("Scegli tra le seguenti opzioni:\n"
		       " 1) Crea Concessionaria;\n"
		       " 2) Input Concessionaria\n"
		       " 3) Conrollare se la Concessionaria ha almeno un macchina\n"
		       " 4) Sapere il numero di macchine presenti nella concessionaria\n"
		       " 5) Stampare la Concessionaria\n"
		       " 6) Eliminare un macchina\n"
		       " 7) Cercare un macchina per targa\n"
		       " 8) macchine senza disponibilita'\n"
		       " 9) Aggiungi disponibilita' ad un macchina\n"
		       "10) Togli disponibilita' ad un macchina\n"
		       "11) ricerca per prezzo\n"
		       "12) valore parco macchine\n"
		       "13) Esci\n");

		scanf("%d",&scelta);

		switch(scelta)
		{

			case 1:
				T=newConcessionaria();
				printf("Concessionaria creata \n");		
				break;
	
			case 2:
				printf("Inserisci il valore: ");
				val=input_item();
				insertMacchina(T,val);
				break;

			case 3:
				if(EmptyConcessionaria(T)==1)
					printf("La Concessionaria è vuota\n");
				else 
					printf("La Concessionaria non è vuota \n");
				break;

			case 4:
				printf("La Concessionaria contiene %d macchine\n",NumeroTipiDiMacchine(T));  //root
				break;
			
			case 5:
				printf("La Concessionaria è:\n");
				stampaConcessionaria(T);
				printf("\n");
				break;
	
			case 6:
				
				deleteMacchina(T);
				break;
			
			case 7:
		
				if(cercaMacchina(T))
					printf("L'elemento è presente\n");
				
				else
					printf("L'elemento non è presente\n");

				break;
			case 8:
				LibSenzaDisp(T);
				break;
			case 9:
				printf("Inserisci codice targa del macchina a cui aggiungere:\n");
				scanf("%s",&targa[0]);	
				printf("Quante copie aggiungere?:\n");
				scanf("%d",&x);	
				AddDisp(T, targa, x);
				break;
			case 10:
				printf("Inserisci codice targa del macchina a cui togliere:\n");
				scanf("%s",&targa[0]);	
				printf("Quante copie vuoi togliere?:\n");
				scanf("%d",&x);	
				SubDisp(T, targa, x);
				break;
			case 11:
				MacchineCostose(T);
				break;
			case 12:
				CostoParcoMacchine(T);
				break;
			case 13:
				exit(1);
		}	
	}	
}