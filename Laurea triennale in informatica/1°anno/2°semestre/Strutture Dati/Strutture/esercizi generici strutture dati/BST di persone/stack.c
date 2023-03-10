#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "stack.h"


#define STARTSIZE 50
#define ADDSIZE 20

struct c_stack{
	item *vet;
	int size;   //serve a mantenere dimensione corrente
	int top;    //mantiene la posizione
};


stack newStack(void)
{
	struct c_stack *s= malloc(sizeof(struct c_stack));  //alloco memoria per il nuovo stack
	if(s==NULL)	//controllo se lo stack è stato allocato
	return NULL;
	
	s->vet=malloc(STARTSIZE*sizeof(item));   //alloco memoria per l'array
	if(s->vet==NULL)   //se l'array non puo essere allocato restituisco NULL
		return NULL;
	s->size=STARTSIZE; 
	s->top=0;
	return s;
}


int emptyStack(stack s)
{
	return s->top==0;
}


int push(item val,stack s)
{
	if(s->top==s->size)   //se l'array ha raggiunto la dimesione STARTSIZE devo reallocare la memoria 
		{
			item *tmp= realloc(s->vet,(s->size+ADDSIZE)*sizeof(item));
			if(tmp==NULL)
				return 0;
			
			s->vet=tmp;
			s->size=s->size+ADDSIZE;
		}
	s->vet[s->top]=val;
	(s->top)++;
	return 1;
}


int pop(stack s)
{
	if(s->top==0)
		return 0;
	
	(s->top)--;
	return 1;
}

item top(stack s)
{
	item e;
	if(s->top > 0)
		e= s->vet[s->top-1];
	else 
        	e=NULLITEM;
	return e;	
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





