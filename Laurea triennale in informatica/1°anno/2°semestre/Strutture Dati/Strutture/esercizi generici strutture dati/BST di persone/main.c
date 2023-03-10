#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "RegistroAnagrafe.h"

int main (void)
{
	Anagrafe T;
	item val,key;
	int scelta,x;

	while(1)
	{
		printf("Scegli tra le seguenti opzioni:\n"
		       " 1) Crea Anagrafe;\n"
		       " 2) Input Anagrafe\n"
		       " 3) Conrollare se l'anagrafe ha almeno una persona\n"
		       " 4) Sapere il primo libro dell'anagrafe\n"
		       " 5) Sapere il numero di persone registrate nell'anagrafe\n"
		       " 6) Stamapre l'anagrafe\n"
		       " 7) Eliminare una persona\n"
		       " 8) Cercare una persona\n"
		       " 9) Persone di cui non si conosce l'eta'\n"
		       "10) Esci\n");

		scanf("%d",&scelta);

		switch(scelta)
		{

			case 1:
				T=newAnagrafe();
				printf("Anagrafe creata \n");		
				break;
	
			case 2:
				val=input_item();
				insertPersona(T,val);
				break;

			case 3:
				if(EmptyAnagrafe(T)==1)
					printf("L' anagrafe è vuota\n");
				else 
					printf("L' anagrafe non è vuota \n");
				break;
			
			case 4:
				printf("La prima persona è :\n");
				FirstPersona(T);
				break;
		
			case 5:
				printf("L'anagrafe ha registratp %d persona\e\n",NumeroPersone(T));  //root
				break;
			
			case 6:
				printf("Il contenuto dell'anagrafe è:\n");
				stampaPersone(T);
				printf("\n");
				break;
	
			case 7:
				
				deletePersona(T);
				break;
			
			case 8:
		
				if(cercaPersona(T))
					printf("L'elemento è presente\n");
				
				else
					printf("L'elemento non è presente\n");

				break;
			case 9:
				PersonaNullEta(T);
				break;
			case 10:
				exit(1);
		}	
	}	
}