#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "item.h"

struct Persona{
	char CF[16];
	char Cognome[30];
	char Nome[30];
	int eta;
};

int eq(item x, item y)
{
	//controlla se l'item x è uguale all'item y
	
	if(strcmp(x->CF,y->CF)==0)
		return 0;
	else if(strcmp(x->CF,y->CF)<0)  
		return -1;
	else
		return 1;
}
item newItem(char *CF, char *Cognome, char *Nome, int eta)
{
	item x=malloc(sizeof(struct Persona));
	strcpy(x->CF,CF);
	strcpy(x->Cognome,Cognome);
	strcpy(x->Nome,Nome);
	x->eta=eta;
	
	return x;
}
char *getCF(item x)
{
	return x->CF;
}

char *getCognome(item x)
{
	return x->Cognome;
}

char *getNome(item x)
{
	return x->Nome;
}

int getEta(item x)
{
	return x->eta;
}

void setCF(item x, char *y)
{
	strcpy(x->CF,y);
}

void setCognome(item x, char *y)
{
	strcpy(x->Cognome,y);
}

void setNome(item x, char *y)
{
	strcpy(x->Nome,y);
}

void incEta(item x, int y)
{
	x->eta+=y;
}

item input_item()
{
	//esegue l'input dell'item
	item x=malloc(sizeof(struct Persona));

	printf("Inserisci codice fiscale\n");
	scanf("%s",&(x->CF[0]));
	printf("Inserisci titolo\n");
	scanf("%s",&(x->Cognome[0]));
	printf("Inserisci autore/i\n");
	scanf("%s",&(x->Nome[0]));
	printf("Inserisci eta' di %s %s\n",x->Cognome,x->Nome);
	scanf("%d",&(x->eta));
		
	return x;
}

void output_item(item x)
{
	//esegue l'output dell'item
	printf("\nCF: %s Cognome: %s Nome: %s eta: %d\n",x->CF,x->Cognome,x->Nome,x->eta);
}

int filterItem(item x)
{
	return x->eta;
}


