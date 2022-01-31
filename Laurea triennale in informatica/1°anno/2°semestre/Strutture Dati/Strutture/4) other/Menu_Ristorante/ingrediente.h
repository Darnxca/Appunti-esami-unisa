// file item.h 


typedef struct ingrediente *ingrediente;

ingrediente newIngrediente(char* nome, int kcal);

int eq(ingrediente x, ingrediente y);

ingrediente input_ingrediente(); 

void stampa_ingrediente(ingrediente x);

int getKcal(ingrediente i);
