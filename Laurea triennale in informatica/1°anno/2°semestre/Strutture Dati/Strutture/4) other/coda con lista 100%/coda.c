#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "coda.h"


struct node {
	
	item value;
	struct node *next;
};

struct c_queue{
	
	struct node *head;
	struct node *tail;
	int numel;
};


queue newQueue (void)
{
	struct c_queue *q;
	q=malloc(sizeof(struct c_queue));
	if(q==NULL)
		return NULL;
	q->numel=0;
	q->head=NULL;
	q->tail=NULL;
	return q;
}


int emptyQueue(queue q)
{
	if(q==NULL)
		return -1;
	return q->numel==0;
}


int enqueue(item val,queue q)
{
	if(q==NULL)
		return -1;
	struct node *nuovo;
	nuovo=malloc(sizeof(struct node));
	if(nuovo==NULL)
		return 0;
	nuovo->value=val;
		
	if(q->head==NULL)     //se nuovo è il primo elemento della coda allora setto la testa uguale a nuovo altrimenti devo spostare solo il puntatore alla coda
		q->head=nuovo;
	else 
	q->tail->next=nuovo;
	
	q->tail=nuovo;
	(q->numel)++;
	return 1;
}


item dequeue(queue q)
{
	if(q==NULL)
		return NULLITEM;
	if(q->numel==0)
		return NULLITEM;
	
	item result;
	struct node *temp;
	temp=q->head;
	result=temp->value;
	q->head=q->head->next;
	if(q->head==NULL)
		q->tail=NULL;
	free (temp);
	(q->numel)--;
	return result;
}


void printQueue(queue q)
{
	int pos;
	
	if((q->numel)==0)
		printf("La coda è vuota\n");
	else
	{
		struct node *temp;
		temp=q->head;
		for (pos=0;pos<(q->numel);pos++)
		{
			output_item(temp->value);
			temp=temp->next;	
		}
	}
}



int searchqueue(queue q, item value)
{
	if((q->numel)==0)
		printf("La coda non ha nessun elemento\n");
	else 
	{
		int pos=q->numel;
		int found=0;
		struct node *temp;
		temp=q->head;
		while(!found && pos!=0)
		{
			//if(eq(temp->value,value)==1)
			//		return 1;

			if(eq(temp->value,value)==1)
				{
					return 1;
									
				}

			else
			{
				temp=temp->next;
				pos--;
			}		
		}

		if(pos==0)
			return 0;
		// printf("L'elemento non è presente nella coda\n");
	}

}
