#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "coda.h"
#include "stack.h"
#include "BST.h"

struct node{
	
	item value;
	struct node *left;
	struct node *right;
};

//struttura coda
struct qnodeB {
	
	struct node *value;
	struct qnodeB *next;
};

struct c_queueB{
	
	struct qnodeB *head;
	struct qnodeB *tail;
	int numel;
};
typedef struct c_queueB *queueB;

queueB newQueueB (void)
{
	queueB q;
	q=malloc(sizeof(struct c_queueB));
	if(q==NULL)
		return NULL;
	q->numel=0;
	q->head=NULL;
	q->tail=NULL;
	return q;
}


int emptyQueueB(queueB q)
{
	if(q==NULL)
		return -1;
	return q->numel==0;
}


int enqueueB(struct node *val,queueB q)
{
	if(q==NULL)
		return -1;
	struct qnodeB *nuovo;
	nuovo=malloc(sizeof(struct qnodeB));
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


struct node *dequeueB(queueB q)
{
	if(q==NULL)
		return NULLITEM;
	if(q->numel==0)
		return NULLITEM;
	
	struct node *result;
	struct qnodeB *temp;
	temp=q->head;
	result=temp->value;
	q->head=q->head->next;
	if(q->head==NULL)
		q->tail=NULL;
	free (temp);
	(q->numel)--;
	return result;
}
//fine struttura cosa con relative funzioni


item getItem(struct node *N)
{
	if(N==NULL)
		return NULLITEM;
	
	return N->value;
}

void setItem(struct node *N, item el)
{
	if (N==NULL)  return;
	N->value=el;
}

BST newBST(void)
{
	return NULL;
}

BST figlioSX(BST T)
{
	return T->left;
}

BST figlioDX(BST T)
{
	return T->right;
}

int emptyBST(BST T)
{
	return T==NULL;
}

int max(int a, int b)
{
	if(a<=b) return b;
	else return a;	
}

int altezzalbero(BST T)
{
	if(T==NULL || (T->left==NULL && T->right==NULL) ) return 0;
	else 
 	  return 1+max(altezzalbero(T->left),altezzalbero(T->right));
}


int numNode(BST T)
{
	if(T==NULL)  return 0;
        return 1+numNode(T->left)+numNode(T->right);
}


int contains(BST T, item val)
{
	if(T==NULL) return 0;

	if(eq(val,getItem(T)))  return 1;

	if(val<getItem(T))
		return (contains(figlioSX(T),val));
	else 
	   	return (contains(figlioDX(T),val));
}


item getRoot(BST T)
{
	if(T==NULL)
		return NULLITEM;
	else 
		return T->value;
}

struct node *insert(BST *T, item elem)
{
	if(*T==NULL) 
	return *T=creaFoglia(elem);
	
	else if (elem<getItem(*T))
		insert(&((*T)->left),elem);
	else 
		insert(&((*T)->right),elem);
}

BST creaFoglia(item elem)
{
	struct node *N;
	N=malloc(sizeof(struct node));
	if(N==NULL)  return NULL;
	setItem(N,elem);
	N->left=NULL;
	N->right=NULL;
	return N;
}


struct node *minValue (struct node *node)
{
	struct node *current=node;
	while(current ->left != NULL)
		current =current->left;
	return current;
}

struct node *deleteNode(struct node *root, item key)
{
	if(root==NULL)  
		return root;

	if(key<(root->value))
		root->left=deleteNode(root->left, key);
	
	else if(key> (root->value))
		root->right=deleteNode(root->right, key);

	else 
	{
		if(root->left==NULL)
		  {
			struct node *temp = root->right;
			free(root);
			return temp;
		  }
		else if(root->right ==NULL)
		  {
			struct node *temp= root->left;
			free(root);
			return temp;
		  }
		struct node *temp=minValue(root->right);
		root->value= temp->value;
		root->right=deleteNode(root->right, temp->value);
	}
	return root;
}


//algoritmi di visite ricorsive
void visita(struct node *T)
{
	output_item(T->value);
}


void visita_preorder(BST T)
{
	if(T)
	{	
	    visita(T);
	    visita_preorder(T->left);
	    visita_preorder(T->right);
	}
}

void visita_inorder(BST T)
{
	if (T!=NULL)
	 {
	    visita_inorder(T->left);
	    visita(T);
	    visita_inorder(T->right);
	 }
}

void visita_postorder(BST T)
{
	if(T!=NULL)
	 {
		visita_postorder(T->left);
		visita_postorder(T->right);
		visita(T);
	 }
}


void Levelorder(BST pt)
{
	struct c_queueB *c= newQueueB();
	BST temp= newBST();
	
	if(pt!=NULL)
		enqueueB(pt,c);

	while(!emptyQueueB(c))
	{
		temp=dequeueB(c);
		output_item(temp->value);
		
		if(figlioSX(temp)!=NULL)
		{
			enqueueB(figlioSX(temp),c);
		}

		if(figlioDX(temp)!=NULL)
		{
			enqueueB(figlioDX(temp),c);
		}
	}
}


//Funzione ricorsiva che dato in input un item esergue la ricerca di quest'ultimo in un albero binario di ricerca

struct node *search(BST T, item val)
{
	if(emptyBST(T)|| getItem(T))
		return T;
	
	if(getItem(T)<val)
		return search(T->left, val);
	
	else
		return search(T->right, val);
}



//versione iterativa
struct node *search_iter(BST T, item val)
{
	struct node *temp;
	temp=T;
	int found=0;

	if(emptyBST(T))
			return temp;

	while(!found && temp!=NULL)
	{
		if(val==getItem(temp))
			found=1;
		else if(val<getItem(temp))
			temp=T->left;
		else
			temp=T->right;
	}
	
	return temp;

}



//Funziione che dato in input un albero verifica se è un BST
int controllo(BST T)
{
	if (emptyBST(T)||(T->left==NULL && T->right==NULL))
	{
		return 1;
	}

	if (getItem(T->left)<getItem(T))			//se l'item di sinistra è maggiore della radice ritorna 0 perchè non è un BST
	{
		return controllo(T->left);
	}
	else
		return 0;
	if (getItem(T->right)>getItem(T))
	{
		return controllo(T->right);
	}
	else
		return 0;

}

