#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"


int main(void)
{
	
	int scelta,n,pos;
	item elem,x;
	char cf[16];
	struct c_list *l;
	while(1)
{	
	printf("\n\n");
	printf("Cosa vuoi fare?\n");
	printf(" 1) Creare una nuova lista;\n"
	       " 2) Inserire elementi in una lista\n"
	       " 3) Stampare una lista\n"
	       " 4) Controllare se la lista è vuota\n"
	       " 5) Sapere la posizione di un elemento\n"
	       " 6) Inserire un nuovo elemento in una lista\n"
	       " 7) Rimuovere un elemento in una lista\n"
	       " 8) Prendere l'elemento in una determinata posizione\n"
	       " 9) Sapere la size della lista\n"
	       "10) Fare la reverse della lista (v.1 con new list)\n"
	       "11) Fare la reverse della lista (v.2 senza new list)\n"
	       "12) Eliminare una lista\n"
	       "13) Clonare una lista\n"
	       "14) Distruggere una lista\n"
	       "15) Controllare se un item è presente\n"
	       "16) Eliminare un elemento dalla lista\n"
	       "17) Esci\n");
	
	scanf("%d",&scelta);
	
	switch(scelta){
	
		case 1:
			
			l=newList();
			printf("Ho creato la lista.\n");
			break;
		
		case 2:

			printf("Quanti elementi vuoi inserire? ");
			scanf("%d",&n);
			
			inputList(n,l);
			break;
		
		case 3:
			outputList(l);
			break;
	
		case 4:
			if(emptyList(l)==0)

				printf("La lista non è vuota\n");
			else 
				printf("La lista è vuota");
			break;
		
		case 5:
			elem=input_item();
			if(posItem(l,elem)==(-1))
				printf("L'elemento non è stato trovato\n");
			else
				printf("L'elemento è presente nella posizione %d\n",posItem(l,elem));
			break;

		case 6:
			elem=input_item();
			printf("In che posizione vuoi inserilo? ");
			scanf("%d",&pos);
			
			if(insertList(l,pos-1,elem)==1)
				printf("Inserimento riuscito perfettamente.");
			else 
				printf("Inserimento non riuscito");
			break;

		case 7:
			printf("Inserisci la posizione dell'elemento che vuoi cancellare: ");
			scanf("%d",&pos);
			if(removeList(l,pos)==1)			
				printf("Eliminazione riuscita perfettamente.");
			else 
				printf("Eliminazione non riuscita");
			break;

		case 8:
			printf("Inserisci la posizione di cui vuoi conoscere l'elemento: ");
			scanf("%d",&pos);
			printf("L'elemento presente nella posizione %d è:\n",pos);
			output_item(getItem(l,pos));
			break;
			
		case 9:
			printf("La lista ha %d elementi\n",sizeList(l));
			break;

		case 10:
			outputList(reverseList1(l));
			break;
		
		case 11:
			reverseList2(l);
			outputList(l);
			break;

		case 12:
			if(deleteList(l)==1)
				printf("Eliminazione riuscita perfettamente.");
			else 
				printf("Eliminazione non riuscita");
			break;
		
		case 13:
			outputList(cloneList(l));
			break;
		case 14:
			if(destroyList(&l)==1)
			printf("Eliminazione riuscita.\n");
			else 
			printf("Eliminazione non riuscita.\n");
			
			break;
		case 15:
			printf("Inserisci codice fiscale da cercare: ");
			scanf("%s",&cf[0]);
			
			x=newItem(cf,"","",0);
			if(searchItem(l,x)==1)
				printf("l'elemento è presente\n");
			else if(searchItem(l,x)==0)
				printf("l'elemento non è presente\n");
			else
				printf("lista vuota");
			break;
		case 16:
			printf("Inserisci codice fiscale da eliminare: ");
			scanf("%s",&cf[0]);
			
			x=newItem(cf,"","",0);
			if(removeItem(l,x)==1)
				printf("elemento cancellato\n");
			else if(removeItem(l,x)==0)
				printf("l'elemento non è presente\n");
			else 
				printf("lista vuota\n");
			break;
		case 17:
			exit(1);		
						
}
}
}
