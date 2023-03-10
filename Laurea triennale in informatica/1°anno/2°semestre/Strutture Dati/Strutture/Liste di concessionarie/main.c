#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "concessionaria.h"
#include "list.h"

int main (void)
{
	Concessionaria temp,T;
	item val,key;
	struct c_list *l;
	int scelta,x,n;
	char targa[6],nome[30];

	while(1)
	{
		printf("Scegli tra le seguenti opzioni:\n"
		       " 1) Crea Lista Concessionaria;\n"
		       " 2) Inserire concessionarie\n"
		       " 3) inserire una macchina nella concessionaria\n"
		       " 4) Stampare il parco macchine di una concessionaria\n"
		       " 5) Stampare la lista di concessionaria\n"
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
				l=newList();
				printf("lista concessionaria creata \n");		
				break;
	
			case 2:
				printf("Quante concessionarie vuoi inserire? ");
				scanf("%d",&n);
				
				inputList(n,l);
				
				break;

			case 3:
				printf("In quale concessionaria vuoi inserire la macchina? ");
				scanf("%s",&nome[0]);
				
				temp=newConcessionaria(nome,"");
				
				T=searchConcessionaria(l,temp);
				insertMacchina(T);
				break;
			
			case 4:
				printf("In quale concessionaria vuoi inserire la macchina? ");
				scanf("%s",&nome[0]);
				
				temp=newConcessionaria(nome,"");
				
				T=searchConcessionaria(l,temp);
				StampaAuto(T);
				break;
			
			case 5:
				printf("Le concessionarie sono:\n");
				outputList(l);
				printf("\n");
				break;
			
			case 6:
				printf("In quale concessionaria vuoi eliminare la macchina? ");
				scanf("%s",&nome[0]);
				
				temp=newConcessionaria(nome,"");
				
				T=searchConcessionaria(l,temp);
				deleteMacchina(T);
				break;
			
			case 7:
				printf("In quale concessionaria vuoi cercare la macchina? ");
				scanf("%s",&nome[0]);
				
				temp=newConcessionaria(nome,"");
				
				T=searchConcessionaria(l,temp);
				if(cercaMacchina(T))
					printf("L'elemento è presente\n");
				
				else
					printf("L'elemento non è presente\n");

				break;
			case 8:
				printf("Di quale concessionaria vuoi vedere le macchine senza disponibilita'? ");
				scanf("%s",&nome[0]);
				
				temp=newConcessionaria(nome,"");
				
				T=searchConcessionaria(l,temp);
				LibSenzaDisp(T);
				break;
			case 9:
				printf("Inserisci nome della concessionaria a cui accedere ");
				scanf("%s",&nome[0]);
				
				temp=newConcessionaria(nome,"");
				
				T=searchConcessionaria(l,temp);

				printf("Inserisci codice targa del macchina a cui aggiungere:\n");
				scanf("%s",&targa[0]);	
				printf("Quante copie aggiungere?:\n");
				scanf("%d",&x);	

				AddDisp(T, targa, x);
				break;
			case 10:
				printf("Inserisci nome della concessionaria a cui accedere ");
				scanf("%s",&nome[0]);
				
				temp=newConcessionaria(nome,"");
				
				T=searchConcessionaria(l,temp);				
				
				printf("Inserisci codice targa del macchina a cui togliere:\n");
				scanf("%s",&targa[0]);	
				printf("Quante copie vuoi togliere?:\n");
				scanf("%d",&x);
	
				SubDisp(T, targa, x);
				break;
			case 11:
				printf("Inserisci nome della concessionaria a cui accedere ");
				scanf("%s",&nome[0]);
				
				temp=newConcessionaria(nome,"");
				
				T=searchConcessionaria(l,temp);					
				
				MacchineCostose(T);
				break;
			case 12:
				printf("Inserisci nome della concessionaria a cui accedere ");
				scanf("%s",&nome[0]);
				
				temp=newConcessionaria(nome,"");
				
				T=searchConcessionaria(l,temp);

				printf("Il costo del parco macchine della concessionaria %s e':\n",nome);
				CostoParcoMacchine(T);
				break;
			case 13:
				exit(1);
		}	
	}	
}