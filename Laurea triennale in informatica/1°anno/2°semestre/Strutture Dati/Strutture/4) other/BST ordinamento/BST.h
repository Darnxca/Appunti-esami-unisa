typedef struct node *BST;

//prototipi

/*
    Funzione per creare un nuovo albero.
    Parametri in ingresso: void;
    restituisce un albero binario di ricerca vuoto
 */
BST newBST (void);


/*
     Funzione per controllare se un albero binario di ricerca è vuoto
     Parametri in ingresso:
     Tipo	Nome	Descrizione
     BST	T	l'albero binario di ricerca
    
     Valori di ritorno:
     la funzione restitusce 1 se l'albero è vuoto, altrimenti restituisce 0. 
 */

int emptyBST(BST T);


/*
     Funzione per prendere la radice di un albero binario di ricerca
     Parametri in ingresso:
     Tipo	Nome	Descrizione
     BST	T	l'albero binario di ricerca da cui estrarre la radice
     Valori di ritorno:
	la funzione restituisce la radice dell'albero di tipo "item"
 */

item getRoot(BST T);


/*
  cancella un item presente nell'albero
 */
BST delete(BST T,item elem);

/*
     Funzione che restituisce il figlio sinistro di un albero binario di ricerca
     Parametri in ingresso:
     Tipo	Nome	Descrizione
     BST	T	l'albero binario di ricerca
 */

BST figlioSX (BST T);


/*
     Funzione che restituisce il figlio destro di un albero binario di ricerca
     Parametri in ingresso:
     Tipo	Nome	Descrizione
     BST	T	l'albero binario di ricerca
 
 */
BST figlioDX (BST T);

/*
 Funzione per sapere l'altezza di un BST
 Parametri in ingresso:
    Tipo	Nome	Descrizione
    BST		T	l'albero binario di ricerca
     
    Valori di ritorno:
    la funzione restituisce l'altezza dell'albero, 0 altrimenti
 */
int altezzalbero(BST T);


/*
 Funzione per sapere il numero di nodi presenti 
 Parametri in ingresso:
    Tipo	Nome	Descrizione
    BST		T	l'albero binario di ricerca
     
    Valori di ritorno:
    la funzione restituisce il totale dei nodi presenti nell'albero, 0 altrimenti
 */
int numNode(BST T);



/*
   Funzione per controllare se un item è già presente in un albero binario di ricerca
   Parametri in ingresso:
     Tipo	Nome	Descrizione
     BST	T	l'albero binario di ricerca
     item	elem	l'elemento da ricercare
	
    Valori di ritorno:
    la funzione restituisce 1 se l'item è contenuto 0 altrimenti
 */

int contains(BST T, item elem);

/*
	Funzione per inserire un nuovo elemento in un albero binario di ricerca
 	Parametri in ingresso:
	Tipo	Nome	Descrizione
	BST	T	l'albero binario di ricerca
	item	elem	l'elemento da inserire

	Valori di ritorno:
	la funzione crea una nuova foglia dove inserisce l'item
 */

struct node *insert (BST *T, item elem);


/*
	La funzione crea una nuova foglia e viene utilizzata dalla funzione contains
	Parametri in ingresso:
	Tipo	Nome	Descrizione
	item	elem	elemento da inserire nella foglia
 */

BST creaFoglia(item elem);


/*
	Funzione per cancellare un nodo dell'albero binario di ricerca
	Parametri in ingresso:
	Tipo		Nome	Descrizione
	struct node*	root	radice dell'albero binario di ricerca
	item		key	nodo da cancellare
 */
struct node *deleteNode(struct node *root, item key);
struct node *minValue (struct node *node);  //trova il valore piu piccolo tra due elementi


/*
	/*
	Funzione per stampare un singolo node di un albero binario di ricerca 
	Parametri in ingresso:
	Tipo		Nome	Descrizione
	struct node* 	T	l'albero binario di ricerca
		
 */

void visita(struct node *T);


/*
	Funzione per stampare un albero binario di ricerca in preorder
	Parametri in ingresso:
	Tipo	Nome	Descrizione
	BST	T	l'albero binario di ricerca
		
 */

void visita_preorder(BST T);


/*
	Funzione per stampare un albero binario di ricerca in inorder
	Parametri in ingresso:
	Tipo	Nome	Descrizione
	BST	T	l'albero binario di ricerca
		
 */

void visita_inorder(BST T);


/*
	Funzione per stampare un albero binario di ricerca in postorder
	Parametri in ingresso:
	Tipo	Nome	Descrizione
	BST	T	l'albero binario di ricerca
		
 */
void visita_postorder(BST T);

/*
	 Funzione ricorsiva per stampare un albero binario di ricerca per livelli
	 Parametri in ingresso:
	 Tipo	 Nome	 Descrizione
	 BST	 T	 l'albero binario di ricerca

         Valori di ritorno:
	 La funzione restituisce il nodo dove è presente l'elemento
 */
void Levelorder(BST pt);


/*
	Funzione ricorsiva per ricercare un item in un albero binario di ricerca
	Parametri in ingresso:
	Tipo	Nome	Descrizione
	BST	T	l'albero binario di ricerca
	item	val	item da cercare
	
	Valori di ritorno:
	La funzione restituisce il nodo dove è presente l'elemento
 */


struct node *search(BST T, item val);




/*
	Funzione iterativa per ricercare un item in un albero binario di ricerca
	Parametri in ingresso:
	Tipo	Nome	Descrizione
	BST	T	l'albero binario di ricerca
	item	val	item da cercare
	
	Valori di ritorno:
	La funzione restituisce il nodo dove è presente l'elemento
 */
struct node *search_iter(BST T, item val);


/*
	Funzione che controlla se un albero è un albero binario di ricerca
	Parametri in ingresso:
	Tipo	Nome	Descrizione
	BST	T	l'albero binario di ricerca	
	Valori di ritorno
	la funzione restitusce uno se l'albero è un albero binario di ricarca, 0 altrimenti
 */
int controllo(BST T);
