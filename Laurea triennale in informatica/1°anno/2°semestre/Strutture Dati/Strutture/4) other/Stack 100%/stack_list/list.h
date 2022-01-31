typedef struct c_list *list;


//prototipi

list newList(void);
/*Funzione che crea una nuova lista; 
// Input: --
 Output: nuova lista*/

int emptyList(list l);
/*Funzione che controlla se una lista é vuota o no; restituisce 1 se la lista é vuota, 0 altrimenti. Come parametro prende soltanto la lista da controllare.*/
//input: lista l


item getItem(list l,int pos);
//funzione per prendere un item nella posizione pos 
//Prende in input la lista l e la posizione pos
//In output restituisce l'item

int insertList(list l,int pos,item val);
//funzione per inserire un item nella posizione pos
//Input: la lista, la posizione dove inserire l'item e l'item stesso

int removeList(list l, int pos);
//funzione per rimuovere l'elemento nella posizione pos 
//Input: la lista da dove cancellare l'elemento e la posizione dell'elemento stesso

int posItem(list l,item val);
//restituisce la posizione del item 

int sizeList(list l);
//restiuisce il numero di elementi in una lista

list reverseList1 (list l);
//inverte la lista creando una nuova lista 

int revereseList2 (list l);
//inverte la lista senza crearne una nuova ma aggiorna soltanto i puntatori

int deleteList(list l);
//elemina una lista

list cloneList(list l);
//crea una copia della lista

void destoyList(list *l);
//elimina una lista ed il suo puntatore

list inputList(int n);
//La funzione prende in ingresso un intero n e restituisce una lista con n elementi

int outputList(list l);
//esegue l'output della lista
