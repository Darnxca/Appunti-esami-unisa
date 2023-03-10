#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "stack.h"
#include "BST.h"

struct bst{
	
	item value;
	struct bst *left;
	struct bst  *right;
};


item getItem(struct bst  *N)
{
	if(N==NULL)
		return NULLITEM;
	
	return N->value;
}

void setItem(struct bst  *N, item el)
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


int numNodi(BST T)
{
	if(T==NULL)  return 0;
        return 1+numNodi(T->left)+numNodi(T->right);
}


int contains(BST T, item val)
{
	if(T==NULL) return 0;

	if(eq(getItem(T),val)==0)  return 1;

	if(eq(getItem(T),val)>0)
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

struct bst  *insert(BST *T, item elem)
{
	if(*T==NULL) 
	return *T=creaFoglia(elem);
	
	else if (eq(getItem(*T),elem)>0)
		insert(&((*T)->left),elem);
	else 
		insert(&((*T)->right),elem);
}

BST creaFoglia(item elem)
{
	struct bst  *N;
	N=malloc(sizeof(struct bst ));
	if(N==NULL)  return NULL;
	setItem(N,elem);
	N->left=NULL;
	N->right=NULL;
	return N;
}


struct bst  *minValue (struct bst  *bst )
{
	struct bst  *current=bst ;
	while(current ->left != NULL)
		current =current->left;
	return current;
}

struct bst  *deletebst (struct bst  *root, item key)
{
	if(root==NULL)  
		return root;

	if(eq(key,root->value)<0)
		root->left=deletebst (root->left, key);
	
	else if(eq(key,root->value)>0)
		root->right=deletebst (root->right, key);

	else 
	{
		if(root->left==NULL)
		  {
			struct bst  *temp = root->right;
			free(root);
			return temp;
		  }
		else if(root->right ==NULL)
		  {
			struct bst  *temp= root->left;
			free(root);
			return temp;
		  }
		struct bst  *temp=minValue(root->right);
		root->value= temp->value;
		root->right=deletebst (root->right, temp->value);
	}
	return root;
}


//algoritmi di visite ricorsive
void visita(struct bst  *T)
{
	output_item(T->value);
}

void Nullvalue(struct bst  *T)
{
	if(filterItem(T->value)==0)
		output_item(T->value);
}

void visita_Nullvalue(BST T)
{
	if(T)
	{	
	    Nullvalue(T);
	    visita_Nullvalue(T->left);
	    visita_Nullvalue(T->right);
	}
}

void Magg(struct bst  *T)
{
	if(getPrezzo(getItem(T))>2000)
		output_item(T->value);
}

void visita_Magg(BST T)
{
	if(T)
	{	
	    Magg(T);
	    visita_Magg(T->left);
	    visita_Magg(T->right);
	}
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

float ParcoMacchine(struct bst  *T)
{
	return getPrezzo(T->value) * getDisponibili(T->value);
}

float visita_ParcoMacchine(BST T)
{
	float costo=0;

	if (T!=NULL)
	 {
	    visita_ParcoMacchine(T->left);
	    costo+=ParcoMacchine(T);
	    visita_ParcoMacchine(T->right);
	 }
	
	return costo;
}
//Funzione ricorsiva che dato in input un item esergue la ricerca di quest'ultimo in un albero binario di ricerca

item  search(BST T, item val)
{
	if(emptyBST(T) || eq(getItem(T),val)==0)
		return getItem(T);
	
	else if(eq(getItem(T),val)<0){
		printf("vado a sinistra\n");
		return search(T->right, val);
	}
	else{
		printf("vado a destra\n");
		return search(T->left, val);
	}
}
