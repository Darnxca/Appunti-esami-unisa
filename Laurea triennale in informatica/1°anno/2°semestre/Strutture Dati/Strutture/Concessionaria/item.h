#include <string.h>

typedef struct macchina *item;
/*
Specifica sintattica:
	Tipo di riferimento: item
	Tipo usati: stringa, intero, float
Specifica semantica:
	Il tipo item è l'insieme delle quadruple(Targa, Modello, Marca, Prezzo, disponibilita), dove Targa, Modello e Marca sono stringhe, Prezzo è float mentre disponibilita è un intero
*/


#define NULLITEM 0
// Nullitem è un elemento che viene restituito quando la precondizione getFirst viene violata


int eq(item x, item y);
/*
Funzione per confrontare due oggetti di tipo item
	Specifica sintattica:
		eq(item, item) -> integer
		Input: item x, item y
		Output: integer b
	Specifica semantica:
		eq(x,y) ->  b
		Post: b=0 se x = y allora , b=-1 se  x < y, b=1 se  x > y
*/


item input_item();
/*
Funzione per inserire un oggetto di tipo item da tastiera
	Specifica sintattica:
		input_item() -> item
		Input: --
		Output: item x
	Specifica semantica:
		input_item() ->  item
		Post: item = (Targa, Modello, Marca, Prezzo, disponibilita)
*/


item newItem(char *targa, char *modello, char *marca, float prezzo, int disponibili);
/*
Funzione per instanziare un oggetto di tipo item 
	Specifica sintattica:
		newItem(string, string, string, float, integer) -> item
		Input: string s, string s1, string s2, string s3, float f1, integer n
		Output: item x
	Specifica semantica:
		newItem(Targa, Modello, Marca, Prezzo, disponibilita) ->  item
		Post: item = (Targa, Modello, Marca, Prezzo, disponibilita)
*/


void output_item(item x);
/*
Funzione per stampare un oggetto di tipo item 
	Specifica sintattica:
		output_item(item) -> --
		Input: item x
		Output: --
	Specifica semantica:
		output_item(item) ->  --
		Post: item = (Targa, Modello, Marca, Prezzo, disponibilita)
*/


char *getTarga(item x);
/*
Funzione per restituire il codice ISBN di un item
	Specifica sintattica:
		getTarga(item)-> string
		Input: item x
		Output: string s
	Specifica semantica:
		getTarga(lb) -> Targa
		Post: item = (Targa, Modello, Marca, Prezzo, disponibilita)
*/


char *getModello(item x);
/*Funzione per restituire il titolo di un item
	Specifica sintattica:
		getModello(item)-> string
		Input: item x
		Output: string s
	Specifica semantica:
		getModello(lb) -> Modello
		Post: item = (Targa, Modello, Marca, Prezzo, disponibilita)
*/


char *getMarca(item x);
/*
Funzione per restituire l'autore di un item
	Specifica sintattica:
		getMarca(item)-> string
		Input: item x
		Output: string s
	Specifica semantica:
		getMarca(lb) -> Marca
		Post: item = (Targa, Modello, Marca, Prezzo, disponibilita)
*/

float getPrezzo(item x);
/*
Funzione per restituire il prezzo di un item
	Specifica sintattica:
		getPrezzo(item)-> float
		Input: item x, string y
		Output: --
	Specifica semantica:
		getPrezzo(lb) -> Prezzo
		Post: item = (Targa, Modello, Marca, Prezzo, disponibilita)
*/


int getDisponibili(item x);
/*
Funzione per restituire il numero copie di un item
	Specifica sintattica:
		getDisponibili(item)-> integer
		Input: item x, string y
		Output: --
	Specifica semantica:
		getDisponibili(lb) -> disponibita
		Post: item = (Targa, Modello, Marca, Prezzo, disponibilita)
*/


void setTarga(item x, char *y);
/*
Funzione per inserire un valore al codiceISBN di item
	Specifica sintattica:
		setTarga(item, string)-> --
		Input: item x, string y
		Output: --
	Specifica semantica:
		setTarga(x,str) -> --
		Post: item = (Targa, Modello, Marca, Prezzo, disponibilita)
*/


void setModello(item x, char *y);
/*
Funzione per inserire un valore al titolo di item
	Specifica sintattica:
		setModello(item, string)-> --
		Input: item x, string y
		Output: --
	Specifica semantica:
		setModello(x,str) -> --
		Post: item = (Targa, Modello, Marca, Prezzo, disponibilita)
*/


void setMarca(item x, char *y);
/*
Funzione per inserire un valore al campo autori di item
	Specifica sintattica:
		setMarca(item, string)-> --
		Input: item x, string y
		Output: --
	Specifica semantica:
		setMarca(x,str) -> --
		Post: item = (Targa, Modello, Marca, Prezzo, disponibilita)
*/

void setPrezzo(item x, float y);
/*
Funzione per modificare il prezzo di item
	Specifica sintattica:
		setPrezzo(item, float)-> --
		Input: item x, integer y
		Output: --
	Specifica semantica:
		setPrezzo(x,y) -> --
*/


void incDisp(item x, int y);
/*
Funzione per incrementare il numero di copie di item
	Specifica sintattica:
		incN_copie(item, integer)-> --
		Input: item x, integer y
		Output: --
	Specifica semantica:
		incN_copie(x,y) -> --
*/


int decDisp(item x, int y);
/*
Funzione per decrementare il numero di copie di item
	Specifica sintattica:
		decN_copie(item, integer)-> boolean
		Input: item x, integer y
		Output: boolean b
	Specifica semantica:
		decN_copie(x,y) -> b
		Post: se le copie vengono decrementate b=true else b=false
*/


int filterItem(item x);
/*
Funzione per filtrare un elemento di valore nullo nell' item
	Specifica sintattica:
		filterItem(item)-> integer
		Input: item x
		Output: ritorna il valore dell'elemento n filtrato da item
	Specifica semantica:
		filterItem(x) -> n
*/