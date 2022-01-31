// file item.h 
#include "ingrediente.h"


typedef struct piatto *piatto;

#define NULLITEM NULL


piatto newPiatto(char* nome, double prezzo);

int add_ingrediente(piatto p, ingrediente i);

int eq_piatti(piatto x, piatto y);

piatto input_piatto(); 

void stampa_piatto(piatto x);

int modifica_prezzo(piatto p, double newPrezzo);

int calcola_kcal(piatto p);
