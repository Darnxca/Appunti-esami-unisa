// file item.c 

/* il modulo contiene per ora tre 
operatori che useremo nel seguito. 
Aggiungerne altri all’occorrenza */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ingrediente.h"

struct ingrediente {
      char nome[20];
      int kcal;
}; 

ingrediente newIngrediente(char* nome, int kcal) 
{
      struct ingrediente* i = malloc (sizeof(struct ingrediente));
      if (i != NULL) {
             strcpy(i->nome,nome);
             i->kcal = kcal;
      }
      return i;   
// il programma client dovrà controllare che il risultato non sia NULL  
}



int eq(ingrediente x, ingrediente y) {
   return strcmp(x->nome,y->nome)==0;
}

ingrediente input_ingrediente() {
    char nome[20];
    int kcal;
    printf("inserisci nome dell'ingrediente: \n");
     scanf("%s", nome);
     if (!strcmp(nome, "FINE")){
	return NULL;
     }
     printf("inserisci il numero di chilocalorie: \n");
     scanf("%d", &kcal);
     return newIngrediente(nome, kcal);
} 

void stampa_ingrediente(ingrediente x){
   printf("%s",x->nome);
}

int getKcal(ingrediente i){
	return i->kcal;
}
