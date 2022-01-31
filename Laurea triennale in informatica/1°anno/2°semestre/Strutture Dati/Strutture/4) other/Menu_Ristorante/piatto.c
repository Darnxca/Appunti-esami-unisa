#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "piatto.h"
#include "list_ingrediente.h"

struct piatto {
      char nome[20];
      double prezzo;
      list_ingrediente ingredienti;      
}; 

piatto newPiatto(char* nome, double prezzo) 
{
      struct piatto* p = malloc (sizeof(struct piatto));
      if (p != NULL) {
             strcpy(p->nome,nome);
             p->prezzo = prezzo;
	     p->ingredienti = newListIngrediente();
      }
      return p;   
// il programma client dovrà controllare che il risultato non sia NULL  
}

int add_ingrediente(piatto p, ingrediente i){
	if (p==NULL)
	   return 0;
	
	return insertIngrediente(p->ingredienti,0,i);
}

int eq_piatti(piatto x, piatto y) {
   return strcmp(x->nome,y->nome)==0;
}

piatto input_piatto() {
    char nome[20];
    double prezzo;
    printf("inserisci nome del piatto:\n");
	scanf("%s", nome);
 	if (!strcmp(nome, "FINE")){
		return NULL;
	}
	printf("inserisci il prezzo:\n");
	scanf("%lf", &prezzo);
	return newPiatto(nome, prezzo);
} 


void stampa_piatto(piatto x) {
      printf("%s: ", x->nome);
      stampa_ingredienti(x->ingredienti);
      printf(" %.2f €", x->prezzo);
	  printf(" (%d kcal)\n", calcola_kcal(x));
} 

int modifica_prezzo(piatto p, double newPrezzo){
	if (newPrezzo > 0){
		p->prezzo = newPrezzo;
		return 1;
	}
	return 0;
}

int calcola_kcal(piatto p){
	return totale_kcal(p->ingredienti);
}


