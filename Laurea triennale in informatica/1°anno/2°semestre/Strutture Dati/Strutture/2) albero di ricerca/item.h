#include <string.h>

typedef struct Libro *item;
/*
Specifica sintattica:
	Tipo di riferimento: item
	Tipo usati: stringa, intero
Specifica semantica:
	Il tipo item è l'insieme delle quadruple(ISBN, Autore, Titolo, nCopie), dove ISBN, autore e titolo sono stringhe mentre nCopie è un intero
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
		Post: item = (ISBN, Autore, Titolo, nCopie)
*/


item newItem(char *ISBN, char *titolo, char *autore, int copie);
/*
Funzione per instanziare un oggetto di tipo item 
	Specifica sintattica:
		newItem(string, string, string, integer) -> item
		Input: string s, string s1, string s2, string s3, integer n
		Output: item x
	Specifica semantica:
		newItem(ISBN, Autore, Titolo, nCopie) ->  item
		Post: item = (ISBN, Autore, Titolo, nCopie)
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
		Post: item = (ISBN, Autore, Titolo, nCopie)
*/


char *getISBN(item x);
/*
Funzione per restituire il codice ISBN di un item
	Specifica sintattica:
		getISBN(item)-> string
		Input: item x
		Output: string s
	Specifica semantica:
		getISBN(lb) -> ISBN
		Post: item = (ISBN, Autore, Titolo, nCopie)
*/


char *getTitolo(item x);
/*Funzione per restituire il titolo di un item
	Specifica sintattica:
		getTitolo(item)-> string
		Input: item x
		Output: string s
	Specifica semantica:
		getTitolo(lb) -> titolo
		Post: item = (ISBN, Autore, Titolo, nCopie)
*/


char *getAutori(item x);
/*
Funzione per restituire l'autore di un item
	Specifica sintattica:
		getAutori(item)-> string
		Input: item x
		Output: string s
	Specifica semantica:
		getAutori(lb) -> autori
		Post: item = (ISBN, Autore, Titolo, nCopie)
*/


int getN_copie(item x);
/*
Funzione per restituire ilnumero copie di un item
	Specifica sintattica:
		getN_copie(item)-> integer
		Input: item x, string y
		Output: --
	Specifica semantica:
		getN_copie(lb) -> nCopie
		Post: item = (ISBN, Autore, Titolo, nCopie)
*/


void setISBN(item x, char *y);
/*
Funzione per inserire un valore al codiceISBN di item
	Specifica sintattica:
		setISBN(item, string)-> --
		Input: item x, string y
		Output: --
	Specifica semantica:
		setISBN(x,str) -> --
		Post: item = (ISBN, Autore, Titolo, nCopie)
*/


void setTitolo(item x, char *y);
/*
Funzione per inserire un valore al titolo di item
	Specifica sintattica:
		setTitolo(item, string)-> --
		Input: item x, string y
		Output: --
	Specifica semantica:
		setTitolo(x,str) -> --
		Post: item = (ISBN, Autore, Titolo, nCopie)
*/


void setAutori(item x, char *y);
/*
Funzione per inserire un valore al campo autori di item
	Specifica sintattica:
		setAutori(item, string)-> --
		Input: item x, string y
		Output: --
	Specifica semantica:
		setAutori(x,str) -> --
		Post: item = (ISBN, Autore, Titolo, nCopie)
*/


void incN_copie(item x, int y);
/*
Funzione per incrementare il numero di copie di item
	Specifica sintattica:
		incN_copie(item, integer)-> --
		Input: item x, integer y
		Output: --
	Specifica semantica:
		incN_copie(x,y) -> --
*/


int decN_copie(item x, int y);
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