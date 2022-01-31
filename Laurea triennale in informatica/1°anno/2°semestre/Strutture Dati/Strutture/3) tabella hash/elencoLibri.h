// elencoLibri.h
#include "hash.h"

typedef struct libreria * Libreria;

Libreria newLibreria(int size);

int insertLibro(Libreria l, item x);
int deleteLibro(Libreria l, char *codice);

void incNum_Copie(Libreria l, char *codice, int delta);
int decNum_Copie(Libreria l, char *codice, int delta);

int outputLibro(Libreria l, char *codice);
int outputLibreria(Libreria l, char *autore);

void stampaLibreria(Libreria l);
void destroyLibreria(Libreria l);
