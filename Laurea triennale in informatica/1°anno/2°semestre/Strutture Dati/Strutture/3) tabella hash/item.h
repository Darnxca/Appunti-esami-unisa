#include <string.h>

typedef struct Libro *item;


#define NULLITEM 0
// Nullitem è un elemento che viene restituito quando la precondizione getFirst viene violata


int eq(item x, item y);

item input_item();

void output_item(item x);

char *getISBN(item x);

char *getTitolo(item x);

char *getAutori(item x);

int getKey(item x);

int getN_copie(item x);

void setISBN(item x, char *y);

void setTitolo(item x, char *y);

void setAutori(item x, char *y);

void incN_copie(item x, int y);

int decN_copie(item x, int y);

int filterItem(item x, item y);

item newItem(char *ISBN, char *titolo, char *autori, int n_copie);
