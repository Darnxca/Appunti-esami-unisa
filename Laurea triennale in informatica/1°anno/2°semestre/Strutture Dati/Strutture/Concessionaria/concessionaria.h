#include "BST.h"

typedef struct concessionaria *Concessionaria;

Concessionaria newConcessionaria(void);

void insertMacchina(Concessionaria T, item x);

void stampaConcessionaria(Concessionaria T);

int EmptyConcessionaria(Concessionaria L);

void FirstMacchina(Concessionaria L);

int NumeroTipiDiMacchine(Concessionaria L);

int deleteMacchina(Concessionaria T);

int cercaMacchina(Concessionaria T);

void AddDisp(Concessionaria T,char *targa, int x);

void SubDisp(Concessionaria T,char *targa, int x);

void LibSenzaDisp(Concessionaria T);

void MacchineCostose(Concessionaria L);

void CostoParcoMacchine(Concessionaria L);
