#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"


int main(void)
{
	
	int scelta,n,elem,pos;
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
	       "15) Esci\n");
	
	scanf("%d",&scelta);
	
	switch(scelta){
	
		case 1:
			
			l=newList();
			printf("Ho creato la lista.\n");
			break;
		
		case 2:

			printf("Quanti elementi vuoi inserire? ");
			scanf("%d",&n);
			l=inputList(n);
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
		
		case 5://Controllare
			printf("Inserisci l'elemento di cui vuoi sapere la posizione\n");
			scanf("%d",&elem);
			if(posItem(l,elem)==(-1))
				printf("L'elemento non è stato trovato\n");
			else
				printf("L'elemento è presente nella posizione %d\n",posItem(l,elem));
			break;

		case 6:
			printf("Inserisci l'elemento da inserire: ");
			scanf("%d",&elem);
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
			printf("L'elemento presente nella posizione %d è: %d\n",pos,getItem(l,pos));
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
			exit(1);		
						
}
}
}
