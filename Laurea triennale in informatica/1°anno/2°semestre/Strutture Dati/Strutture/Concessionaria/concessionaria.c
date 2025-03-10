#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "BST.h"
#include "concessionaria.h"

struct concessionaria
{
	char nome[20];
	char indirizzo[100];
	BST T;
};

Concessionaria newConcessionaria(void)
{	
	Concessionaria L=malloc(sizeof(struct concessionaria));

	printf("Inserisci nome concessionaria: ");
	scanf("%s",&(L->nome[0]));
	printf("Inserisci indirizzo concessionaria: ");
	scanf("%s",&(L->indirizzo[0]));

	L->T=newBST();
	
	return L;
}

void insertMacchina(Concessionaria L, item x)
{
	insert(&(L->T),x);
}

void stampaConcessionaria(Concessionaria L)
{
	visita_preorder(L->T);
}

int EmptyConcessionaria(Concessionaria L)
{
	return emptyBST(L->T);
}

void FirstMacchina(Concessionaria L)
{
	output_item(getRoot(L->T));
}

int NumeroTipiDiMacchine(Concessionaria L)
{
	return numNodi(L->T);
}

int deleteMacchina(Concessionaria L)
{	
	item key;
	char Targa[6];

	printf("Targa da eliminare\n");
	scanf("%s",&Targa[0]);

	key=newItem(Targa,"","",0,0);
	deletebst(L->T,key);
}

int cercaMacchina(Concessionaria L)
{
	item key;
	char Targa[6];

	printf("Targa da cercare\n");
	scanf("%s",&Targa[0]);

	key=newItem(Targa,"","",0,0);
	return contains(L->T,key);
}

void AddDisp(Concessionaria L,char *targa, int x)
{
	item key;

	key=newItem(targa,"","",0,0);
	item current=search((L->T),key);
	
	//incDisp(current,x);
}

void SubDisp(Concessionaria L,char *targa, int x)
{
	item key;

	key=newItem(targa,"","",0,0);
	item current=search((L->T),key);
	
	decDisp(current,x);
}

void LibSenzaDisp(Concessionaria L)
{
	visita_Nullvalue(L->T);
}

void MacchineCostose(Concessionaria L)
{
	visita_Magg(L->T);
}

void CostoParcoMacchine(Concessionaria L)
{
	printf("%.3f\n",visita_ParcoMacchine(L->T));
}