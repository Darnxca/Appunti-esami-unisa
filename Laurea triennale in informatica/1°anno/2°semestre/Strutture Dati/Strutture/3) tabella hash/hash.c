// hash.c

#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "hash.h"

struct shashtable
{
	int size;
   	struct snode **table;
};

struct snode 
{
  	item value;
  	struct snode *next;
};

// funzione per creare una tabella hash
hashtable newHashtable (int size)
{
 	hashtable h = (hashtable) malloc (sizeof (struct shashtable));

  	h->size = size;

  	h->table = (struct snode**) malloc (size * sizeof (struct snode*));

  	for(int i = 0; i < size; i++)
    		h->table[i] = NULL;

  	return h; 
}

static int hash (int key, int size) 
{
  	return key % size;
}

int insertHash (hashtable h, item value) 
{
  	if (h == NULL) 
		return -1;

  	int i = hash (getKey(value), h->size);

  	struct snode *head = h->table[i], *p = head;

	// rimuovere se la chiave non è univoca
  	while (p != NULL)
  	{ 
    		if (eq(p->value,value) == 0) 
				return -1;

    		p = p->next;
  	}

  	p = (struct snode*) malloc (sizeof (struct snode));

  	p->value = value; 
	p->next = head; 
	h->table[i] = p;

  	return 0;
}

item searchHash (hashtable h, item value) 
{
  	if (h == NULL) 
		return NULL;
  
  	int i = hash (getKey(value), h->size);
  
  	struct snode *head = h->table[i], *p = head;
   
	// vale solo per chiave univoca
  	while (p != NULL) 
  	{ 
    		if (eq(p->value,value) == 0)
	 		return (p->value);

    		p = p->next;
  	}
  	return NULL;
}

int deleteHash (hashtable h, item value) 
{
  	if (h == NULL)
           	return -1;
  
  	int i = hash (getKey(value), h->size);
  
  	struct snode *head = h->table[i], *p = head;
  
  	while (p != NULL)
  	{ 
   		if (eq(p->value,value) == 0) 
      		{ 
           		if (p == h->table[i])
				 h->table[i] = p->next;

           		else 
				head->next = p->next;
   
       		free (p);
       		return 0; // rimuovere per chiave non univoca
      		}
   		head = p; p = p->next;
  	}
  	return -1;
}

int filterHash (hashtable h, item value)
{
   	if (h == NULL || value == NULL) 
		return -1;
  
   	struct snode *p;
   	int errcode = -1;

   	for (int i = 0; i < h->size; ++i)
   	{
      		p = h->table[i];
      		
		while (p != NULL)
      		{
         		if(filterItem (value, p->value) == 0) 
          		{
             			output_item(p->value);
             			errcode = 0;
          		}
         		p = p->next;
      		}
   	}  
   	return errcode;
}

int outputTable (hashtable h) 
{
  	if (h == NULL) 
		return -1;
  
  	struct snode *head, *p;
  
	for (int i = 0; i < h->size; ++i)
	{
    		p = head = h->table[i];
    
		while (p != NULL) 
    		{
      			if(p == head)
           			printf ("%3d] ", i);
      			else
         			printf("     ");
      
			output_item(p->value);
		      	p = p->next;
    		}
  	}  
  
	return 0;
}

void destroyHash(hashtable h)
{
	int i;
	for(i=0;i<h->size;i++)
	  {
	  	deleteList(h->table[i]);
          }
	free(h->table);
	return;
}

static void deleteList(node  p)
{
	if(p==NULL) return;
	deleteList(p->next);
	free(p);
}
