# include <stdio.h>
# include <stdlib.h>
# include "piatto.h"
# include "ingrediente.h"
# include "menu.h"

int main() 
{ 
	menu m;
	char nome[20];
	printf("Inserisci il nome del ristorante: ");
	scanf("%s", nome); 
	m= new_menu(nome);
	int n=1, n2=1;
   	piatto p;
	ingrediente ing; 
	printf("INSERIMENTO PIATTI - TERMINA CON PIATTO CON NOME 'FINE'\n");
	while(n==1){ 
		n2 = 1;
		p = input_piatto();
		if(p!=NULL){
			int ris = add_piatto(m, p);
			if(!ris){
				printf("Impossibile effettuare l'inserimento nel menu.");
			}
			else{
				printf("INSERIMENTO INGREDIENTI - TERMINA CON INGREDIENTE CON NOME 'FINE'\n");
				while(n2==1){ 
					ing = input_ingrediente();
					if(ing!=NULL){
						int ris = add_ingrediente(p, ing);
						if(!ris)
							printf("Impossibile effettuare l'inserimento nel piatto.");
					}
					else n2=0;
			    	}
			}  
		
		}
		else n=0;
    	}  
	int pos;
	double newPrezzo;
	printf("Di quale piatto vuoi modificare il prezzo?\n");
	stampa_piatti(getPiatti(m));
	scanf("%d",&pos);
	printf("Inserisci il nuovo prezzo: ");
	scanf("%lf",&newPrezzo);
	modifica_prezzo(getPiatto(getPiatti(m),pos-1),newPrezzo);

	if(!stampa_menu(m))
		printf("Impossibile visualizzare il menu.");
}
