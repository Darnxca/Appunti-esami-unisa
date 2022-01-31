#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "coda.h"

int main (void)
{
	int scelta;
	item val;
	struct c_queue *q;
	while(1)
{
	
	printf("\n\nCoasa vuoi fare:\n"
	       "1) Creare una nuova coda;\n"
	       "2) Inserire elemento\n"
	       "3) Eliminare un elemento\n"
	       "4) Stampa coda\n"
	       "5) Vedere se la coda è vuota\n"
	       "6) Cercare un elemento in coda\n"
	       "7) Esci\n");
	scanf("%d",&scelta);
	printf("\n");

	switch (scelta){


	case 1:
		q=newQueue();
		printf("Coda creata\n");
		break;
	
	case 2:
		printf("Inserisci l'elemento: ");
		input_item(&val);
		
		enqueue(val,q);
		break;
		
	case 3:	
		printf("L'elemento eliminato è %d\n",dequeue(q));
		break;

	case 4:
		printQueue(q);
		break;	

	case 5:
		if(emptyQueue(q)==1)
			printf("La coda vuota\n");
		else 
		printf("La coda non è vuota\n");
		break;

	case 6:
		printf("Inserisci l'elemento che vuoi cercare: ");
		input_item(&val);
		if(searchqueue(q,val)==1)
			printf("L'elemento cercato è presente nella coda\n");
		else 
			printf("L'elemento cercato non è presente nella coda\n");
		break;	
	
	case 7:
		exit (1);
		break;

	default:
		printf("Scegli tra le seguenti opzioni\n"); 
		break;
}




}
}
