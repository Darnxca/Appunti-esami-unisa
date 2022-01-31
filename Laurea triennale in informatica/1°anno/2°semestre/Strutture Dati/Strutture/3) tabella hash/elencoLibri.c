// elencoLibri.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "elencoLibri.h"
#include "item.h"
#include "hash.h"

struct libreria
{
	hashtable table;
};

Libreria newLibreria(int size) 
{

	Libreria l = (Libreria)malloc(sizeof(struct libreria));

	if(l==NULL)
	{
		printf("Memoria insufficiente.\n");
		exit(-1);
	}
	else 
	{
		l->table = newHashtable(size);
	}
	return l;
}

int insertLibro(Libreria l, item x)
{

	if(l==NULL) 
	{
		return -1;
	}

	return insertHash(l->table, x);
}

int deleteLibro(Libreria l, char *codice) 
{

	if(l==NULL) 
	{
		return -1;
	}

	item x = newItem(codice, "", "", 0);
	
	if(x==NULL)
	{
		return -1;
	}
	
	int errcode = deleteHash(l->table, x);
	free(x);
	return errcode;
}

void incNum_Copie(Libreria l, char *codice, int delta) 
{

	if(delta <= 0) 
	{
		printf("impossibili aggingere %d copie \n",delta);
	}

	if(l==NULL) 
	{
		printf("La libreria in cui inserire libri non esiste!\n");
	}

	item x = newItem(codice, "", "", 0);

	if(x==NULL) 
	{
		printf("Errore nella creazione dell'item di appoggio\n");
	}

	item found = searchHash(l->table, x);

	if(found==NULL) 
	{
		printf("Libro non presente!\n");
	}
	free(x);
	incN_copie(found, delta);
	printf("Aggiunta riuscita\n");
}

int decNum_Copie(Libreria l, char *codice, int delta) 
{

	if(l!=NULL) 
	{
		item x = newItem(codice, "", "", 0);
		if(x!=NULL) 
		{
			item found = searchHash(l->table, x);
			free(x);
			if(found==NULL) 
			{
				return -1;
			}
			return decN_copie(found, delta);
		}
	}
}

int outputLibro(Libreria l, char *codice) 
{

	if(l!=NULL)
	{

		item x = newItem(codice, "", "", 0);
		if(x!=NULL) 
		{
			item found = searchHash(l->table, x);

			output_item(found);
			free(x);
			return 0;
		}
	}
}

int outputL_autori(Libreria l, char *autore) 
{

	if(l==NULL || autore==NULL) 
	{
		return -1;
	}

	item x = newItem("", "", autore, 0);

	if(x!=NULL) 
	{
		int errcode = filterHash(l->table, x);
		free(x);
		return errcode;
	}
}

void stampaLibreria(Libreria l)
{
	if(l==NULL) 
	{
		printf("La libreria non esiste!\n");
	}
	else
	{
		outputTable(l->table);	
	}
}

void destroyLibreria(Libreria l)
{
	destroyHash(l->table);
}