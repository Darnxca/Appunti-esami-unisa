#include <stdio.h>
#include <stdlib.h>
#include "piatto.h"
#include "list_piatto.h"

struct list_piatto {
     struct node *first;
     int size;
};

struct node {
     piatto value;
     struct node *next;
};


list_piatto newListPiatto(void) 
{
  struct list_piatto *l;
  l = malloc (sizeof(struct list_piatto));
  if (l != NULL) {
    l->first = NULL;
  	l->size = 0;
  }
  return l;   
// il programma client dovrà controllare che il risultato non sia NULL  
}


static struct node* makeNode(piatto val, struct node* n)
{
      struct node *nuovo = malloc (sizeof(struct node));
      
      if (nuovo != NULL) {
     	    nuovo->value = val;
        	nuovo->next = n;
	    }

      return nuovo;
}

piatto getPiatto (list_piatto l, int pos)
{
  if(l == NULL)
    return NULL;
  
  if (pos<0 || pos>=l->size)
        return NULL;
        
  struct node *temp = l->first;
  int i =0;

  while (i < pos){
      i++;
      temp=temp->next;
  }
  
  return temp->value;
}




static struct node* insertNode(struct node* n, int pos, piatto val)
{
     
	  if(pos == 0)          // inserimento in posizione 0
        return makeNode(val, n);

	  int i = 0;
	  struct node* prec = n;         
    while (i < pos-1) {   
        prec = prec->next;
        i++;
    }
    
    struct node* n1 = makeNode(val, prec->next);
    if(n1 == NULL) 
        return NULL;

    prec->next = n1;
    return n;  
}


int insertPiatto (list_piatto l, int pos, piatto val)
{
  if(l == NULL)
     return 0;
  if (pos<0 || pos>l->size) 
     return 0;
    
  struct node* tmp= insertNode(l->first, pos, val);
  if(tmp==NULL) 
     return 0;
    
  l->first = tmp;
  l->size++;
  return 1;                            
}


int stampa_piatti (list_piatto l)
{
  if(l == NULL)
     return 0;
  int i =1;
  piatto val; 
  struct node* n=l->first;
  while(n!=NULL) {
          val = n->value;
          printf("%d) ", i);  
          stampa_piatto(val);  
          printf("\n");
          n = n->next;
          i++;
  } 
  return 1;
}
