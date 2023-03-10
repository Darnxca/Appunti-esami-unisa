#include "BST.h"

typedef struct RegistroAnagrafe *Anagrafe;

Anagrafe newAnagrafe(void);

void insertPersona(Anagrafe T, item x);

void stampaPersone(Anagrafe T);

int EmptyAnagrafe(Anagrafe L);

void FirstPersona(Anagrafe L);

int NumeroPersone(Anagrafe L);

int deletePersona(Anagrafe T);

int cercaPersona(Anagrafe T);

void PersonaNullEta(Anagrafe T);