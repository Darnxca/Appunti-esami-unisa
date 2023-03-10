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

	if(strcmp(x->CF,y->CF)==0)	//controlla se la persona x è uguale alla persona y
		return 0;
	else if(strcmp(x->CF,y->CF)<0)  
		return -1;
	else
		return 1;
}	


item input_item()
{
	   //esegue l'input della persona
	item x=malloc(sizeof(struct Persona));

	printf("Inserisci codice fiscale\n");
	scanf("%s",&(x->CF[0]));
	printf("Inserisci cognome\n");
	scanf("%s",&(x->Cognome[0]));
	printf("Inserisci nome\n");
	scanf("%s",&(x->Nome[0]));
	printf("Inserisci eta'\n");
	scanf("%d",&(x->eta));
		
	return x;
}

item newItem(char *x, char *y, char *z, int a)
{
	item o=malloc(sizeof(struct Persona));
	
	strcpy(o->CF,x);
	strcpy(o->Cognome,y);
	strcpy(o->Nome,z);
	o->eta=a;

	return o;

}

void output_item(item x)
{
	    //esegue l'output della persona
	printf("Codice fiscale: %s Cognome: %s Nome: %s eta: %d",x->CF,x->Cognome,x->Nome,x->eta);
}




