#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "BST.h"
#include "RegistroAnagrafe.h"

struct RegistroAnagrafe
{
	char citta[20];
	BST T;
};

Anagrafe newAnagrafe(void)
{	
	Anagrafe L=malloc(sizeof(struct RegistroAnagrafe));

	printf("Inserisci nome del comune: ");
	scanf("%s",&(L->citta[0]));

	L->T=newBST();
	
	return L;
}

void insertPersona(Anagrafe L, item x)
{
	insert(&(L->T),x);
}

void stampaPersone(Anagrafe L)
{
	visita_preorder(L->T);
}

int EmptyAnagrafe(Anagrafe L)
{
	return emptyBST(L->T);
}

void FirstPersona(Anagrafe L)
{
	output_item(getRoot(L->T));
}

int NumeroPersone(Anagrafe L)
{
	return numNodi(L->T);
}

int deletePersona(Anagrafe L)
{	
	item key;
	char CF[16];

	printf("CF da eliminare\n");
	scanf("%s",&CF[0]);

	key=newItem(CF,"","",0);
	deletebst(L->T,key);
}

int cercaPersona(Anagrafe L)
{
	item key;
	char CF[16];

	printf("CF da cercare\n");
	scanf("%s",&CF[0]);

	key=newItem(CF,"","",0);
	return contains(L->T,key);
}

void PersonaNullEta(Anagrafe L)
{
	visita_Nullvalue(L->T);
}