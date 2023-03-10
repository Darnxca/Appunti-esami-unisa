typedef struct Persona *item;
/*
Specifica sintattica:
	Tipo di riferimento: item
	Tipo usati: stringa, intero
Specifica semantica:
	Il tipo item è l'insieme delle quadruple(CF, Cognome, nome, eta), dove CF, cognome e nome sono stringhe mentre eta è un intero
*/	


#define NULLITEM 0;
// Nullitem è un elemento che viene restituito quando la precondizione getFirst viene violata


int eq(item x, item y);
/*
Funzione per confrontare due oggetti di tipo item
	Specifica sintattica:
		eq(item, item) -> integer
	Specifica semantica:
		eq(x,y) ->  b
		Post: b=0 se x = y allora , b=-1 se  x < y, b=1 se  x > y
*/


item input_item();
/*
Funzione per inserire un oggetto di tipo item da tastiera
	Specifica sintattica:
		input_item() -> item
	Specifica semantica:
		input_item() ->  item
		Post: item = (CF, Cognome, Nome, eta)
*/


void output_item(item x);
/*
Funzione per stampare un oggetto di tipo item 
	Specifica sintattica:
		output_item(item) -> --
	Specifica semantica:
		output_item(item) ->  --
		Post: item = (CF, Cognome, Nome, eta)
*/


item newItem(char *x, char *y, char *z, int a);
/*
Funzione per instanziare un oggetto di tipo item 
	Specifica sintattica:
		newItem(string, string, string, integer) -> item
	Specifica semantica:
		newItem(CF, Cognome, Nome, eta) ->  item
		Post: item = (CF, Cognome, Nome, eta)
*/
