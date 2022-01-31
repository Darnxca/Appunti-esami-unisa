#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "BST.h"
#include "libreria.h"

struct libreria
{
	char nome[20];
	BST T;
};

Libreria newLibreria(void)
{	
	Libreria L=malloc(sizeof(struct libreria));

	printf("Inserisci nome libreria: ");
	scanf("%s",&(L->nome[0]));

	L->T=newBST();
	
	return L;
}

void insertLibro(Libreria L, item x)
{
	insert(&(L->T),x);
}

void stampaLibreria(Libreria L)
{
	visita_preorder(L->T);
}

int EmptyLibreria(Libreria L)
{
	return emptyBST(L->T);
}

void FirstLibro(Libreria L)
{
	output_item(getRoot(L->T));
}

int NumeroLibri(Libreria L)
{
	return numNodi(L->T);
}

int deleteLibro(Libreria L)
{	
	item key;
	char ISBN[16];

	printf("Codice ISBN da eliminare\n");
	scanf("%s",&ISBN[0]);

	key=newItem(ISBN,"","",0);
	deletebst(L->T,key);
}

int cercaLib(Libreria L)
{
	item key;
	char ISBN[16];

	printf("Codice ISBN da cercare\n");
	scanf("%s",&ISBN[0]);

	key=newItem(ISBN,"","",0);
	return contains(L->T,key);
}

void AddCopie(Libreria L,char *isbn, int x)
{
	item key;

	key=newItem(isbn,"","",0);
	item current=search((L->T),key);
	
	incN_copie(current,x);
}

void SubCopie(Libreria L,char *isbn, int x)
{
	item key;

	key=newItem(isbn,"","",0);
	item current=search((L->T),key);
	
	decN_copie(current,x);
}

void LibSenzaCopie(Libreria L)
{
	visita_Nullvalue(L->T);
}