#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "item.h"

struct macchina{
	char Targa[6];
	char Modello[30];
	char Marca[30];
	float Prezzo;
	int disponibilita;
};

int eq(item x, item y)
{
	//controlla se l'item x è uguale all'item y
	
	if(strcmp(x->Targa,y->Targa)==0)
		return 0;
	else if(strcmp(x->Targa,y->Targa)<0)  
		return -1;
	else
		return 1;
}
item newItem(char *Targa, char *Modello, char *Marca,float prezzo, int disponibilita)
{
	item x=malloc(sizeof(struct macchina));
	strcpy(x->Targa,Targa);
	strcpy(x->Modello,Modello);
	strcpy(x->Marca,Marca);
	x->Prezzo=prezzo;
	x->disponibilita=disponibilita;
	
	return x;
}
char *getTarga(item x)
{
	return x->Targa;
}

char *getModello(item x)
{
	return x->Modello;
}

char *getMarca(item x)
{
	return x->Marca;
}

float getPrezzo(item x)
{
	return x->Prezzo;	
}

int getDisponibili(item x)
{
	return x->disponibilita;
}

void setTarga(item x, char *y)
{
	strcpy(x->Targa,y);
}

void setModello(item x, char *y)
{
	strcpy(x->Modello,y);
}

void setMarca(item x, char *y)
{
	strcpy(x->Marca,y);
}

void setPrezzo(item x, float y)
{
	x->Prezzo=y;
}

void incDisp(item x, int y)
{
	x->disponibilita+=y;
}

int decDisp(item x, int y)
{
	if(y>x->disponibilita)
	{
		return -1;
	}
	else
	{
		x->disponibilita-=y;
		return 0;
	}
}

item input_item()
{
	//esegue l'input dell'item
	item x=malloc(sizeof(struct macchina));

	printf("Inserisci codice Targa\n");
	scanf("%s",&(x->Targa[0]));
	printf("Inserisci Modello\n");
	scanf("%s",&(x->Modello[0]));
	printf("Inserisci Marca/i\n");
	scanf("%s",&(x->Marca[0]));
	printf("Inserisci prezzo auto'\n");
	scanf("%f",&(x->Prezzo));
	printf("Inserisci numero di auto disponibili'\n");
	scanf("%d",&(x->disponibilita));
		
	return x;
}

void output_item(item x)
{
	//esegue l'output dell'item
	printf("\nTarga: %s Modello: %s Marca: %s Prezzo: %.2f numero disponibilita: %d\n",x->Targa,x->Modello,x->Marca,x->Prezzo,x->disponibilita);
}

int filterItem(item x)
{
	return x->disponibilita;
}


