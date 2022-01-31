#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "item.h"

struct Libro{
	char ISBN[16];
	char titolo[30];
	char autori[30];
	int n_copie;
};

int eq(item x, item y)
{
	//controlla se l'item x è uguale all'item y
	
	if(strcmp(x->ISBN,y->ISBN)==0)
		return 0;
	else if(strcmp(x->ISBN,y->ISBN)<0)  
		return -1;
	else
		return 1;
}
item newItem(char *ISBN, char *titolo, char *autore, int copie)
{
	item x=malloc(sizeof(struct Libro));
	strcpy(x->ISBN,ISBN);
	strcpy(x->titolo,titolo);
	strcpy(x->autori,autore);
	x->n_copie=copie;
	
	return x;
}
char *getISBN(item x)
{
	return x->ISBN;
}

char *getTitolo(item x)
{
	return x->titolo;
}

char *getAutori(item x)
{
	return x->autori;
}

int getN_copie(item x)
{
	return x->n_copie;
}

void setISBN(item x, char *y)
{
	strcpy(x->ISBN,y);
}

void setTitolo(item x, char *y)
{
	strcpy(x->titolo,y);
}

void setAutori(item x, char *y)
{
	strcpy(x->autori,y);
}

void incN_copie(item x, int y)
{
	x->n_copie+=y;
}

int decN_copie(item x, int y)
{
	if(y>x->n_copie)
	{
		return -1;
	}
	else
	{
		x->n_copie-=y;
		return 0;
	}
}

item input_item()
{
	//esegue l'input dell'item
	item x=malloc(sizeof(struct Libro));

	printf("Inserisci codice ISBN\n");
	scanf("%s",&(x->ISBN[0]));
	printf("Inserisci titolo\n");
	scanf("%s",&(x->titolo[0]));
	printf("Inserisci autore/i\n");
	scanf("%s",&(x->autori[0]));
	printf("Inserisci numero di copie'\n");
	scanf("%d",&(x->n_copie));
		
	return x;
}

void output_item(item x)
{
	//esegue l'output dell'item
	printf("\nISBN: %s Titolo: %s Autore/i: %s numero copie: %d\n",x->ISBN,x->titolo,x->autori,x->n_copie);
}

int filterItem(item x)
{
	return x->n_copie;
}


