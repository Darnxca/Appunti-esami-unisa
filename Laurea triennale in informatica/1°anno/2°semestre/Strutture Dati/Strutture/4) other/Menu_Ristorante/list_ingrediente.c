#include <stdio.h>
#include <stdlib.h>
#include "ingrediente.h"
#include "list_ingrediente.h"

struct list_ingrediente {
     struct node *first;
     int size;
};

struct node {
     ingrediente value;
     struct node *next;
};


list_ingrediente newListIngrediente(void) 
{
  struct list_ingrediente *l;
  l = malloc (sizeof(struct list_ingrediente));
  if (l != NULL) {
    l->first = NULL;
  	l->size = 0;
  }
  return l;   
// il programma client dovrà controllare che il risultato non sia NULL  
}


static struct node* makeNode(ingrediente val, struct node* n)
{
      struct node *nuovo = malloc (sizeof(struct node));
      
      if (nuovo != NULL) {
     	    nuovo->value = val;
        	nuovo->next = n;
	    }

      return nuovo;
}

ingrediente getIngrediente (list_ingrediente l, int pos)
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




static struct node* insertNode(struct node* n, int pos, ingrediente val)
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


int insertIngrediente (list_ingrediente l, int pos, ingrediente val)
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


int stampa_ingredienti (list_ingrediente l)
{
  if(l == NULL)
     return 0;
  ingrediente val; 
  struct node* n=l->first;
  if(n!=NULL) {
          val = n->value; 
          stampa_ingrediente(val);  
          n = n->next;
  } 
  while(n!=NULL) {  
          printf("; ");
          val = n->value; 
          stampa_ingrediente(val);
          n = n->next;
  } 
  printf (". ");
  return 1;
}

int totale_kcal (list_ingrediente l)
{

  int toReturn = 0;
  ingrediente val;
  if(l == NULL)
     return toReturn; 
  struct node* n=l->first;
  while(n!=NULL) {  
          val = n->value; 
          toReturn += getKcal(val);
          n = n->next;
  } 
  return toReturn;
}
