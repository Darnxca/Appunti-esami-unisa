#include "BST.h"

typedef struct libreria *Libreria;

Libreria newLibreria(void);

void insertLibro(Libreria T, item x);

void stampaLibreria(Libreria T);

int EmptyLibreria(Libreria L);

void FirstLibro(Libreria L);

int NumeroLibri(Libreria L);

int deleteLibro(Libreria T);

int cercaLib(Libreria T);

void AddCopie(Libreria T,char *isbn, int x);

void SubCopie(Libreria T,char *isbn, int x);

void LibSenzaCopie(Libreria T);