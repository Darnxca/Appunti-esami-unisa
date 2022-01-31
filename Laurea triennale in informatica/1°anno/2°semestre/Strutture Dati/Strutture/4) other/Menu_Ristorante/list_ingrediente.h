// file list.h

typedef struct list_ingrediente *list_ingrediente;

// prototipi

list_ingrediente newListIngrediente(void);

ingrediente getIngrediente (list_ingrediente l, int pos);

int insertIngrediente (list_ingrediente l, int pos, ingrediente val);

int stampa_ingredienti (list_ingrediente l);

int totale_kcal (list_ingrediente l);
