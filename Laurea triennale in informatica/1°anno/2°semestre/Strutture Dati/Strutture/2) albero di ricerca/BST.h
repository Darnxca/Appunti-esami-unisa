typedef struct bst *BST;
/*
	Specifica sintattica:
		TIPI: ALBEROBIN, BOOLEAN, NODO, ITEM
	Specifica semantica:
		ALBEROBIN: insieme degli alberi binari, dove: ᴧ ϵ ALBEROBIN (albero vuoto) se N ϵ NODO, T1 e T2 ϵ ALBEROBIN allora <N, T1, T2> ϵ ALBEROBIN
		BOOLEAN = {vero, falso}
		NODO è un qualsiasi insieme non vuoto
		ITEM è un qualsiasi insieme non vuoto
*/

//prototipi

BST newBST(void);
/* 
    Funzione per creare un nuovo albero.
    Specifica sintattica:
		newBST() -> BST
		Input: --
		Output: t 
    Specifica semantica:
		newBST(void) - t
		post: T = NULL
*/

 
int emptyBST(BST T);
/*
     Funzione per controllare se un albero binario di ricerca è vuoto
    Specifica sintattica:
		emptyBST(BST) -> integer
		Input: bst t
		Output: integer b
    Specifica semantica:
		emptyBST(t) -> b
		post: se t è vuoto, allora b = vero, altrimenti b = falso
 */


item getRoot(BST T);
/*
     Funzione per prendere la radice di un albero binario di ricerca
	Specifica sintattica:
		getRoot(bst) -> item
		Input: bst t
		Output: item i
	Specifica semantica:
		getRoot(t) -> i'
		pre: t = <i,tsx, tdx> non è l’albero vuoto
		post: i = i’
 */

 
BST figlioSX (BST T);
/*
     Funzione che restituisce il figlio sinistro di un albero binario di ricerca
	Specifica sintattica:
		figlioSX(bst) -> bst
		Input: bst t
		Output: bst t'
	Specifica semantica:
		figlioSX(t) -> t'
		pre: t = <N, tsx, tdx> non è l’albero vuoto
		post: t’ = Tsx
 */

 
BST figlioDX (BST T);
/*
    Funzione che restituisce il figlio destro di un albero binario di ricerca
    Specifica sintattica:
		figlioDX(bst) -> bst
		Input: bst t
		Output: bst tì'
	Specifica semantica:
		figlioDX(t) -> t'
		pre: T = <N, Tsx, Tdx> non è l’albero vuoto
		post: T’ = Tsx
 */

 
int altezzalbero(BST T);
/*
	Funzione per sapere l'altezza di un BST
	Specifica sintattica:
		altezzalbero(bst) -> integer
		Input: bst t
		Output: integer b 
	Specifica semantica:
		altezzalbero(t) -> b
		pre: T = <N, Tsx, Tdx> non è l’albero vuoto
 */


int numNodi(BST T);
/*
	Funzione per sapere il numero di nodi presenti 
	Specifica sintattica:
		numNodi(bst) -> integer
		Input: bst t
		Output: integer b 
	Specifica semantica:
		numNodi(t) -> b
		pre: t = <N, Tsx, Tdx> non è l’albero vuoto
 */


int contains(BST T, item elem);
/*
	Funzione per controllare se un item è già presente in un albero binario di ricerca
	Specifica sintattica:
		contains(bst, item) -> integer
		Input: bst t, item i
		Output: integer b 
	Specifica semantica:
		contains(t, i) -> b
		pre: t = <N, Tsx, Tdx> non è l’albero vuoto
		post: se l'elemento è presente nell'albero b = true altrimenti b = false
 */


struct bst  *insert(BST *T, item elem);
/*
	Funzione per inserire un nuovo elemento in un albero binario di ricerca
 	Specifica sintattica:
		insert(bst, item) -> bst
		Input: bst t, item i
		Output: bst t' 
	Specifica semantica:
		insert(t, i) -> t'
		pre: t = <N, Tsx, Tdx> non è l’albero vuoto
		post: t' = t + il nuovo item i inserito in modo ordinato
 */


BST creaFoglia(item elem);
/*
	La funzione crea una nuova foglia e viene utilizzata dalla funzione contains
	Specifica sintattica:
		creaFoglia(item) -> bst
		Input: item i
		Output: bst t 
	Specifica semantica:
		creaFoglia(i) -> t
 */


struct bst  *deletebst (struct bst  *root, item key);
/*
	Funzione per cancellare un nodo dell'albero binario di ricerca
	Specifica sintattica:
		deletebst(bst, item) -> bst
		Input: bst t, item i
		Output: bst t' 
	Specifica semantica:
		deletebst(t, i) -> t'
		pre: t = <N, Tsx, Tdx> non è l’albero vuoto
		post: t' = t - il nuovo item i inserito in modo ordinato
 */

struct bst  *minValue (struct bst  *Libreria );  
/*
	trova il valore piu piccolo tra due elementi
	Specifica sintattica:
		minValue(bst, Libreria) -> bst
		Input: bst t, Libreria l
		Output: bst t' 
	Specifica semantica:
		minValue(t, l) -> t'
		pre: t = <N, Tsx, Tdx> non è l’albero vuoto
		post: se l di t' < di l di t allora ritorna t' altrimenti t
*/

void visita(struct bst  *T);
	/*
	Funzione per stampare una singola Libreria  di un albero binario di ricerca 
	Specifica sintattica:
		visita(bst) -> --
		Input: bst t
		Output: -- 
	Specifica semantica:
		visita(t) -> --
		pre: t = <N, Tsx, Tdx> non è l’albero vuoto
 */


void visita_preorder(BST T);
/*
	Funzione per stampare un albero binario di ricerca in preorder
	Specifica sintattica:
		visita_preorder(bst) -> --
		Input: bst t
		Output: -- 
	Specifica semantica:
		visita_preorder(t) -> --
		pre: t = <N, Tsx, Tdx> non è l’albero vuoto
		
 */


void visita_inorder(BST T);
/*
	Funzione per stampare un albero binario di ricerca in inorder
	Specifica sintattica:
		visita_inorder(bst) -> --
		Input: bst t
		Output: -- 
	Specifica semantica:
		visita_inorder(t) -> --
		pre: t = <N, Tsx, Tdx> non è l’albero vuoto
 */



void visita_postorder(BST T);
/*
	Funzione per stampare un albero binario di ricerca in postorder
	Specifica sintattica:
		visita_postorder(bst) -> --
		Input: bst t
		Output: -- 
	Specifica semantica:
		visita_postorder(t) -> --
		pre: t = <N, Tsx, Tdx> non è l’albero vuoto
 */
 
 
item  search(BST T, item val);
/*
	Funzione ricorsiva per ricercare un item in un albero binario di ricerca
	Specifica sintattica:
		search(bst, item) -> item
		Input: bst t, item i
		Output: item i' 
	Specifica semantica:
		search(t, i) -> i'
		pre: t = <N, Tsx, Tdx> non è l’albero vuoto
		post: i' = i se l'elemento viene trovato
 */


void Nullvalue(struct bst  *T);
	/*
	Funzione per stampare una singola Libreria  di un albero binario di ricerca  avente un valore dell'item nullo 
	Specifica sintattica:
		Nullvalue(bst) -> --
		Input: bst t
		Output: -- 
	Specifica semantica:
		Nullvalue(t) -> --
		pre: t = <N, Tsx, Tdx> non è l’albero vuoto
 */
 
void visita_Nullvalue(BST T);
/*
	Funzione per stampare un albero binario di ricerca in preorder avente un valore di item nullo
	Specifica sintattica:
		visita_Nullvalue(bst) -> --
		Input: bst t
		Output: -- 
	Specifica semantica:
		visita_Nullvalue(t) -> --
		pre: t = <N, Tsx, Tdx> non è l’albero vuoto	
 */