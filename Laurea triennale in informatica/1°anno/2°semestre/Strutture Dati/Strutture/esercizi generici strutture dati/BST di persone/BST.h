typedef struct bst *BST;

//prototipi

BST newBST(void);
/*
    Funzione per creare un nuovo albero.
    Parametri in ingresso: void;
    restituisce un albero binario di ricerca vuoto
 */

 
int emptyBST(BST T);
/*
     Funzione per controllare se un albero binario di ricerca è vuoto
    
	Parametri in ingresso:
     Tipo		Nome		Descrizione
     BST		T		l'albero binario di ricerca
    
     Valori di ritorno:
     la funzione restitusce 1 se l'albero è vuoto, altrimenti restituisce 0. 
 */


item getRoot(BST T);
/*
     Funzione per prendere la radice di un albero binario di ricerca
	 
     Parametri in ingresso:
     Tipo		Nome		Descrizione
     BST		T		l'albero binario di ricerca da cui estrarre la radice
	 
     Valori di ritorno:
	la funzione restituisce la radice dell'albero di tipo "item"
 */

 
BST figlioSX (BST T);
/*
     Funzione che restituisce il figlio sinistro di un albero binario di ricerca
    
	Parametri in ingresso:
     Tipo		Nome		Descrizione
     BST		T		l'albero binario di ricerca
 */

 
BST figlioDX (BST T);
/*
     Funzione che restituisce il figlio destro di un albero binario di ricerca
    
	Parametri in ingresso:
     Tipo		Nome		Descrizione
     BST		T		l'albero binario di ricerca
 
 */

 
int altezzalbero(BST T);
/*
	Funzione per sapere l'altezza di un BST
	
	Parametri in ingresso:
	Tipo		Nome		Descrizione
     BST		T		l'albero binario di ricerca
     
     Valori di ritorno:
     la funzione restituisce l'altezza dell'albero, 0 altrimenti
 */


int numNodi(BST T);
/*
	Funzione per sapere il numero di nodi presenti 
	
	Parametri in ingresso:
     Tipo		Nome		Descrizione
     BST		T		l'albero binario di ricerca
     
     Valori di ritorno:
     la funzione restituisce il totale dei nodi presenti nell'albero, 0 altrimenti
 */


int contains(BST T, item elem);
/*
	Funzione per controllare se un item è già presente in un albero binario di ricerca
	
	Parametri in ingresso:
     Tipo		Nome		Descrizione
     BST		T		l'albero binario di ricerca
     item		elem		l'elemento da ricercare
	
     Valori di ritorno:
     la funzione restituisce 1 se l'item è contenuto 0 altrimenti
 */


struct bst  *insert(BST *T, item elem);
/*
	Funzione per inserire un nuovo elemento in un albero binario di ricerca
 	
	Parametri in ingresso:
	Tipo		Nome		Descrizione
	BST		T		l'albero binario di ricerca
	item		elem		l'elemento da inserire

	Valori di ritorno:
	la funzione crea una nuova foglia dove inserisce l'item
 */


BST creaFoglia(item elem);
/*
	La funzione crea una nuova foglia e viene utilizzata dalla funzione contains
	
	Parametri in ingresso:
	Tipo		Nome		Descrizione
	item		elem		elemento da inserire nella foglia
 */


struct bst  *deletebst (struct bst  *root, item key);
/*
	Funzione per cancellare un nodo dell'albero binario di ricerca
	
	Parametri in ingresso:
	Tipo				Nome		Descrizione
	struct Libreria *	root		radice dell'albero binario di ricerca
	item				key		nodo da cancellare
 */

struct bst  *minValue (struct bst  *Libreria );  //trova il valore piu piccolo tra due elementi

void visita(struct bst  *T);
	/*
	Funzione per stampare una singola Libreria  di un albero binario di ricerca 
	
	Parametri in ingresso:
	Tipo				Nome		Descrizione
	struct Libreria * 	T		l'albero binario di ricerca
		
 */




void visita_preorder(BST T);
/*
	Funzione per stampare un albero binario di ricerca in preorder
	
	Parametri in ingresso:
	Tipo		Nome		Descrizione
	BST		T		l'albero binario di ricerca
		
 */


void visita_inorder(BST T);
/*
	Funzione per stampare un albero binario di ricerca in inorder
	
	Parametri in ingresso:
	Tipo		Nome		Descrizione
	BST		T		l'albero binario di ricerca
		
 */



void visita_postorder(BST T);
/*
	Funzione per stampare un albero binario di ricerca in postorder
	
	Parametri in ingresso:
	Tipo		Nome		Descrizione
	BST		T		l'albero binario di ricerca
		
 */
item  search(BST T, item val);
/*
	Funzione ricorsiva per ricercare un item in un albero binario di ricerca
	
	Parametri in ingresso:
	Tipo		Nome		Descrizione
	BST		T		l'albero binario di ricerca
	item		val		item da cercare
	
	Valori di ritorno:
	La funzione restituisce il nodo dove è presente l'elemento
 */


void Nullvalue(struct bst  *T);
	/*
	Funzione per stampare una singola Libreria  di un albero binario di ricerca  avente un valore dell'item nullo 
	
	Parametri in ingresso:
	Tipo				Nome			Descrizione
	struct Libreria * 	T			l'albero binario di ricerca
		
 */
 
void visita_Nullvalue(BST T);
/*
	Funzione per stampare un albero binario di ricerca in preorder avente un valore di item nullo
	
	Parametri in ingresso:
	Tipo		Nome		Descrizione
	BST		T		l'albero binario di ricerca
		
 */