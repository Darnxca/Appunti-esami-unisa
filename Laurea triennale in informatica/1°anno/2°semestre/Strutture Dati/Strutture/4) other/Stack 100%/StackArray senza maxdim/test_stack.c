#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "stack.h"

void istruzioni()
{
	printf("Scegli tra le seguenti opzioni: \n"
	       "1) Inserisci un valore \n"
	       "2) Eliminina un elemento \n"
	       "3) Esci \n");
}



int main (void)
{
	stack s1=newStack();  //inizializzo uno stack s1

	int scelta;  //variabile della scelta
	int value; //elemento inserito
	
	istruzioni();  //mosta il menu

	scanf("%d",&scelta);

	while(scelta !=3)  //cicla finche non si inserisce 3
	{
	    switch (scelta){

		case 1:
			printf("Inserisci un elemento: ");
			scanf("%d",&value);
			push(value,s1);
			printStack(s1);
			break;

		case 2: 
			if(!emptyStack(s1))
			 {
				printf("Il valore eliminato è: %d. \n",top(s1));
				pop(s1);
		         }
			printStack(s1);
			break;
		default: 
			printf("Scegli tra le seguenti opzioni. \n \n");
		
	}
		istruzioni();
		scanf("%d",&scelta);
    }
}










