#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ordinamento.h"

int dim=0;

void settaElementi(int *v)
{
	int n;
	
	printf("Quanti elementi vuoi inserire? ");
	scanf("%d",&n);
	
	*v=(int)malloc(sizeof(int)*n);
	dim=n;
	setDim(n);
}

int carica(int *v)
{	
	if(dim==0)
		return 0;
	else
	{
		for(int i=0;i<dim;i++)
		{
			printf("Posizione %d : ",i);
			scanf("%d",&v[i]);		
		}
		return 1;
	}
}

void stampaIndex()
{
	printf("Array:\npos: ");
	for(int i=0;i<dim;i++)
		printf("\t| %d | ",i);
	printf("\n\nele: ");
}
int stampa(int *v)
{	
	if(dim==0)
		return 0;
	else
	{	
		stampaIndex();
		
		for(int i=0;i<dim;i++)
		{
			printf("\t| %d | ",v[i]);
					
		}
		printf("\n");
		return 1;
	}
}

void menu(void)
{
	printf("Segli quale operazione compiere:\n"
	       "1)Inscerisci numeri di elementi.\n"
	       "2)Carica elementi nell'array.\n"
	       "3)Stampa elementi dell'array.\n"
	       "4)Ordina con MergeSort.\n"
	       "5)Ordina con QuickSort.\n"
	       "6)Ordina con SelectionSort.\n"
	       "7)Ordina con InsertionSort.\n"
	       "8)Ordina con BubbleSort.\n"
	       "0)Esci.\n\n"); 
}

int main(void)
{
	int *v,op;

	while(1)
	{
		menu();
		printf("Quale operazione vuoi compiere? ");
		scanf("%d",&op);
		
		switch(op)
		{
			case 1:
				settaElementi(v);
				break;
			case 2:
				if(carica(v)==1)
					printf("caricamento ruscito.\n\n");
				else
					printf("caricamento non riuscito, array vuoto.\n\n");
				break;
			case 3: 
				if(stampa(v)==0)
					printf("stampa non riuscita, array vuoto.\n\n");
				break;
			case 4:
				
				if(dim==0)
					printf("ordinamento non riuscito, array vuoto.\n\n");
				else
					MergeSort(v,0,dim-1);
				break;
			case 5:
				if(dim==0)
					printf("ordinamento non riuscito, array vuoto.\n\n");
				else
					QuickSort(v,0,dim-1);
				break;
			case 6:
				if(dim==0)
					printf("ordinamento non riuscito, array vuoto.\n\n");
				else
					selectionSort(v);
				break;
			case 7:
				if(dim==0)
					printf("ordinamento non riuscito, array vuoto.\n\n");
				else
					insertionSort(v);
				break;
			case 8:
				if(dim==0)
					printf("ordinamento non riuscito, array vuoto.\n\n");
				else
					bubblesort(v);
				break;
			case 0:
				write(1,"Uscita in corso",sizeof("Uscita in corso"));

				for(int i=0;i<3;i++)
				{
					sleep(1);
					write(1,".",1);
				}
				printf("\nUscita Effettuata!\n");
				exit(0);
			default:
				printf("Operazione non ammessa dal sistema!\n\n");
				break;
		}
	}
}