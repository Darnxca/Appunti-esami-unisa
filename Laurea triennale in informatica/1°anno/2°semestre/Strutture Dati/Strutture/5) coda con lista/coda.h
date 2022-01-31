typedef struct c_queue *queue;
/*
	Specifica sintattica:
		Tipo di riferimento: queue
		Tipo usati: item, boolean
	Specifica semantica:
		queue è l'insieme delle sequenza S = a1, a2,..., an di tipo item.
		L'insieme queue contiene inoltre un elemento nil che rappresenta la coda vuota
*/


queue newQueue (void);
/*
Funzione per creare una nuova coda
	Specifica sintattica:
		newQueue() -> queue
		Input: --
		Output: queue
	Specifica semantica:
		newQueue() → q
		Post: q = nil
*/


int emptyQueue(queue q);
/*
Funzione per controllare se la coda è vuota
	Specifica sintattica:
		emptyQueue(queue) → boolean
		Input: queue q
		Output: boolean b
	Specifica semantica:
		emptyQueue(q) → b
		Post: se q=nil allora b = true altrimenti b = false
*/


int enqueue(item val,queue q);
/*
Funzione per inserire un elemento in  una coda
	Specifica sintattica:
		enqueue(item, queue) → boolean
		Input: item val, queue q
		Output: boolean
	Specifica semantica:
		enqueue(e, q) → b e la coda diventa q’
		Pre: q = <a1, a2, … an> con n >= 0
		Post: se q’ = <e, a1, a2, …, an> allora b = true
*/


item dequeue(queue q);
/*
Funzione per eliminare e restituire l'elemento in testa alla coda
	Specifica sintattica:
		dequeue(queue) → item
		Input: queue q
		Output: item x
	Pecifica semantica:
		dequeue(q) → an e la coda diventa q’
		Pre: q = <a1, a2, …, an-1, an> n>0
		Post: q’ = <a1,a2, …, an-1>
*/


void printQueue(queue q);
/*
Funzione per stampare una nuova coda
	Specifica sintattica:
		printQueue(queue) -> --
		Input: queue q
		Output: --
	Specifica semantica:
		printQueue(q) -> --
*/


int searchqueue(queue q, item value);
/*
Funzione per cercare un elemento nella coda
	Specifica sintattica:
		searchqueue(queue, item) -> boolean
		Input: queue q, item val
		Output: boolean b
	Specifica semantica:
		searchqueue(q, val) -> b
		Post: se val è contenuto in q allora b = true else b = false
*/