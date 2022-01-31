#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "piatto.h"
#include "list_piatto.h"
#include "menu.h"

struct menu {
	 char nome[20];
	 list_piatto piatti;
};

menu new_menu(char *n){
	struct menu *nuovo;
	nuovo = malloc (sizeof(struct menu));
	if (nuovo != NULL) {
		strcpy(nuovo->nome,n);
		nuovo->piatti = newListPiatto();
	}
	return nuovo;
}

int add_piatto(menu m, piatto x){
	if (m==NULL)
	   return 0;
	
	return insertPiatto(m->piatti,0,x);
}

int stampa_menu(menu m){
	if(m == NULL)
	   return 0;
	printf("\n*** Menu %s ***\n\n", m->nome);
	stampa_piatti(m->piatti);	
	return 1;
}

list_piatto getPiatti(menu m){
	return m->piatti;
}
