#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "stack.h"
#include "list.h"


struct node{
	
	item value;
	struct node *next;
};

struct c_stack{
	
	struct node *top;
	int numel;
};


stack newStack(void)
{
	struct c_stack *s;
	s=malloc(sizeof(struct c_stack));
	if(s==NULL)
		return NULL;

	s->numel=0;
	s->top=NULL;
	return s;
}


int emptyStack(stack s)
{
	return (s->numel==0);
}

int push(item val,stack s)
{
	struct node *nuovo;
	nuovo= malloc (sizeof(struct node));
	if(nuovo==NULL)
		return 0;
	
	nuovo->value=val;
	nuovo->next=s->top;
        s->top=nuovo;
	(s->numel)++;
	
	return 1;
}


int pop(stack s)
{
	
	if(s->numel==0)
		return 0;
	
	struct node *temp;
	temp=s->top;
	s->top=s->top->next;
	free(temp);
	(s->numel)--;

	return 1; 
}

item top(stack s)
{
	item e;
	if(s->numel>0)
		e=s->top->value;
	else 
	e=NULLITEM;

	return e;
}

void printStack(stack s)    //completare
{
	int i,n;
	if(s->numel==0)
	 {
		printf("Lo stack è vuoto\n\n");
	 }

	else
	  {	
		stack tmp=newStack();
                n = s->numel;		
		for(i=0;i<n;i++)
		{	
			output_item(s->top->value);
			push(top(s),tmp);
			pop(s);	
		}
		for(i=0;i<n;i++)
		{		
			push(top(tmp),s);
			pop(tmp);		
		}
	  }	
}
