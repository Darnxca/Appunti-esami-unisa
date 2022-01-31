// hash.h

#include "item.h"

typedef struct shashtable *hashtable;
/*
Specifica sintattica:
	Tipo di riferimento: hashtable
	Tipi usati: item, boolean
Specifica semantica:
	Tipo di riferimento: hashtable è l’insieme di elementi T={a1,a2,…,an} di tipo item.
	Un item contiene dei dati associati
*/


typedef struct snode *node;// nodo contenente gli item


hashtable newHashtable (int size);
/*
Funzione per creare una tabella hash
	Specifica sintattica:
		newHashTable() → hashtable
		Input: integer size
		Output: hashtable
	Specifica semantica:
		newHashtable() → t
		Post: t = {}
*/


int insertHash (hashtable h , item value);
/*
Funzione per inserire un item nella tabella hash
	Specifica sintattica:
		insertHash(item, hashtable) → boolean
		Input: hashtable h, item value
		Output: boolean b
	Specifica semantica:
		insertHash(t, e) → b
		Post: t = {a1, a2, … an} AND se l'elemento viene inserito allora b = true else b=false
*/


int deleteHash (hashtable h, item value);
/*
Funzione per eliminare un item nella tabella hash
	Specifica sintattica:
		deleteHash(hashtable, item) → boolean
		Input: hashtable h, item value
		Output: boolean b
	Specifica semantica:
		deleteHash(t, e) → b
		Pre: t = {a1, a2, …, an} n>0
		Post: se l'elemento viene cancellato allora b = true else b=false
*/


item searchHash (hashtable h, item value);
/*
Funzione per ricercare un item nella tabella hash
	Specifica sintattica:
		searchHash(hashtable, item) → item
		Input: hashtable h, item value
		Output: item x
	Specifica semantica:
		searchHash(h, value) → item
		Pre: h = {a1, a2, …, an} n>0
		Post: value = ai con 1 ≤ i ≤ n se key di a = key di value
*/


int filterHash (hashtable h, item value);
/*
Funzione per ricercare un elemento nella tabella hash con un determinato filtro
	Specifica sintattica:
		filterHash(hashtable, item) → boolean
		Input: hashtable h, item x
		Output: boolean b
	Specifica semantica:
		filterHash(h, x) → b
		Post: se l' elemento filter viene trovato allora b = true else b=false
*/


int outputTable (hashtable h);
/*
Funzione per stampare una tabella hash
	Specifica sintattica:
		outputTable(hashtable) → boolean
		Input: hashtable h
		Output: boolean b
	Specifica semantica:
		outputTable(h) → b
		Post: se la tabella viene stampata allora b = true else b=false
*/


static void deleteList(node p);
/*
Funzione per eliminare un nodo tabella hash
	Specifica sintattica:
		deleteList(node) → --
		Input: node p
		Output: --
	Specifica semantica:
		deleteList(p) → --
*/


void destroyHash(hashtable h);
/*
Funzione per eliminare la tabella hash
	Specifica sintattica:
		destroyHash(hashtable) → --
		Input: hashtable h
		Output: --
	Specifica semantica:
		destroyHash(h) → --
*/