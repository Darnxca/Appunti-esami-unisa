#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "stack.h"

#define MAXSTACK 50


struct c_stack{

	item vet[MAXSTACK];    //grandezza massima dello stack
	int top;               //restitusce la posizione di dove io posso inserire il nuovo elemento
};

stack newStack(void)     //crea un nuovo stack
{
	struct c_stack *s;  //s è un puntatore alla struttura c_stack 
	s=malloc(sizeof(struct c_stack));  //alloco memoria per la struttura
	
	if(s==NULL)
	  {
		return NULL;  //controllo sull'allocazione di memoria
	  }

	s->top=0;  //s punta a top che in questo caso è 0 perche lo stack è vuoto
	return s; //ritorno la struttura
}

int emptyStack(stack s) 
{
	return s->top==0;  //il primo elemento è 0
}

int push(item val,stack s)
{
	if(s->top==MAXSTACK)
	  {
		return 0;    //se lo stack ha raggiunto la dimensione massima non posso aggiungere un altro elemento
	  }

	s->vet[s->top]=val;  //s punta alla posizione s->top del vettore vet
	(s->top)++; //incremento s->top e passo all'elemento successivo
	return 1; //l'operazione di inserimento è andata a buon fine
}

int pop( stack s)
{
	if(s->top==0)
	  {
	  	return 0;  // se lo stack è vuoto non posso togliere un elemento
	  }

	(s->top)--;   //s->top punta all'elemento precedente 

	return 1; //l'operazione è andata a buon fine
}


item top(stack s)
{
	item e; //creo una varibile di tipo item a cui assegnerò il valore di top

	if(s->top>0)
	  {
		e=s->vet[s->top-1];  //top-1= all'ultimo elemento inserito
	  }

	else
	  {
		e=NULLITEM;    // se lo stack è vuoto e=NULL
   	  }

	return e; //ritorno il valore di e
}


void printStack(stack s)
{
	int i;
	if(emptyStack(s))
	 {
		printf("Lo stack è vuoto\n\n");
	 }

	else
	  {
		printf("Lo stack è: \n");
 		for(i=(s->top); i>0; i--)
		  {
			output_item(s->vet[i-1]);
			//printf("NULL \n\n");
		  }
		
	  }	
}




