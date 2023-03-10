#include "BST.h"

#define nullconcessionaria NULL

typedef struct concessionaria *Concessionaria;

Concessionaria input_Concessionaria(void);

void insertMacchina(Concessionaria T);

void output_Concessionaria(Concessionaria x);

int eq1(Concessionaria x, Concessionaria y);

void StampaAuto(Concessionaria T);

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

Concessionaria newConcessionaria(char *nome, char *ind);