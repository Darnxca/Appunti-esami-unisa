typedef struct c_list *list;


//prototipi

list newList(void);
/*
Funzione che crea una nuova lista; 
	Specifica sintattica:
		newList() → list
		Input: --
		Output: nuova lista
	Specifica semantica:
		newList() → l
		Post: l = nil
*/


int emptyList(list l);
/*
Funzione che controlla se una lista é vuota o no; restituisce 1 se la lista é vuota, 0 altrimenti. Come parametro prende soltanto la lista da controllare. 
	Specifica sintattica:
		Input: lista l
		Output: valore booleano
	Specifica semantica:
		emptyList(l) → b
		Post: se l=nil allora b = true altrimenti b = false
*/


item getItem(list l,int pos);
/*
funzione per prendere un item nella posizione pos Prende in input la lista l e la posizione pos In output restituisce l'item
	Specifica sintattica:
		getItem(list, integer) → item
		Input: lista l, intero pos
		Output: item 
	Specifica semantica:
		getItem(l, pos) → e
		Pre: pos >= 0 AND sizeList(l) > pos
		Post: e è l’elemento che occupa in l la posizione pos
*/


int insertList(list l,int pos,item val);
/*
funzione per inserire un item nella posizione pos
	Specifica sintattica:
		insertList(list, integer, item) → list
		Input: lista l , la posizione pos  dove inserire l'item e l'item val
		Output: valore booleano per controllare l'esito dell'inserimento
	Specifica semantica:
		insertList(l, pos, val) → l’
		Pre: sizeList(l) ≥ pos 
		Post: l’ si ottiene da l inserendo x in posizione pos
*/


int removeList(list l, int pos);
/*
funzione per rimuovere l'elemento nella posizione pos 
	Specifica sintattica:
		removeList(list, integer) → list
		Input: la lista da dove cancellare l'elemento e la posizione dell'elemento stesso
		Output: valore booleano per controllare l'esito della cancellazione
	Specifica semantica:
		removeList(l, pos) → l’
		Pre: sizeList(l) > pos // assumiamo 0 come prima posizione
		Post: l’ si ottiene da l eliminando l’elemento in posizione pos
*/


int posItem(list l,item val);
/*
restituisce la posizione del item
	Specifica sintattica:
		posItem(list, item) → integer
		Input: lista l, item val
		Output: posizone dell'elemento
	Specifica semantica:	
		posItem(l, val) → p
		Post: se l'elemento è stato inserito ritorna 1 altrimenti 0
*/


int sizeList(list l);
/*
restiuisce il numero di elementi in una lista
	Specifica sintattica:
		sizeList(list) → integer 
		Input: list l
		Output: numero di elementi della lista
	Specifica semantica:
		sizeList(l) → n
		Post: l = <a1, a2, …, an> AND n ≥ 0
*/
	
	
int searchItem(list l, item x);
/*
funzione per cercare un elemento nella lista
	Specifica sintattica:
		searchItem(list, item) → boolean
		Input: lista l, item val
		Output: valore booleano per controllare l'esito della ricerca
	Specifica semantica:
		searchItem(l, x) → b
		Post: se x è contenuto in l allora b = true else b = false
*/	
	
	
list reverseList1 (list l);
/*
inverte la lista creando una nuova lista 
	Specifica sintattica:
		reverseList1(list) → list
		Input: lista l
		Output: lista l'
	Specifica semantica:
		reverseList1(l) → b
		Post: l = <a1, a2, …, an> AND  se la reverse è effetuata b=true else b=false
*/


int reverseList2 (list l);
/*
inverte la lista senza crearne una nuova ma aggiorna soltanto i puntatori
	Specifica sintattica:
		reverseList2(list) → integer
		Input: lista l
		Output: valore booleano per controlllare la riuscita dell'inversione
	Specifica semantica:
		reverseList1(l) → integer
		Post: l = <a1, a2, …, an> AND l’ = <an, ..., a2, a1>
*/


int deleteList(list l);
/*
elemina una lista
	Specifica sintattica:
		deleteList(list) → integer
		Input: lista l
		Output: valore booleano per verificare se la lista è stata cancellata o meno
	Specifica semantica:
		deleteList(l) → integer
		Pre: sizeList(l) > pos
		Post: l = <a1, a2, …, an>
*/


list cloneList(list l);
/*
crea una copia della lista
	Specifica sintattica:
		cloneList(list) → list
		Input: lista l
		Output: lista l'
	Specifica semantica:
		cloneList(l) → l’
		Post: l = <a1, a2, …, an> AND l’ = <a1, a2, …, an>
*/


int destroyList(list *l);
/*
elimina una lista ed il suo puntatore
	Specifica sintattica:
		destroyList(list) → integer
		Input: lista l
		Output: integer b
	Specifica semantica:
		destroyList(l) → b
		Post: l = <a1, a2, …, an> AND se la reverse è effetuata b=true else b=false
*/


void inputList(int n, list l);
/*
La funzione prende in ingresso un intero n e restituisce una lista con n elementi
	Specifica sintattica:
		inputList(integer, list) → --
		Input: integer n, lista l
		Output: --
	Specifica semantica:
		inputList(n, l) → --
		Post: n >= 0
*/


int outputList(list l);
/*
esegue l'output della lista
	Specifica sintattica:
		outputList(list) → integer
		Input: lista l
		Output: valore booleano  n
	Specifica semantica:
		outputList(l) → b
		Post: se l'autput  riesce b = true else b = false
*/


int removeItem(list l, item x);
/* Funzione per rimuove un item dalla lista
	Specifica sintattica:
		removeItem(list, item) → integer
		Input: lista l, item x
		Output:valore booleano per controllare l'avvenuta cancellazione
	Specifica semantica:
		removeItem(l, x) → l’
		Post: se x è contenuto in l, allora l’ si ottiene da l, eliminando la prima occorrenza di x in l, altrimenti l’ = l
*/