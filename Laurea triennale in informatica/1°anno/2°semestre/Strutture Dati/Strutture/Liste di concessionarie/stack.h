typedef struct c_stack *stack;
/*
Specifica sintattica:
	Tipo di riferimento: stack
	Tipi usati: item, boolean
Specifica semantica:
	stack è l'insieme delle sequenze S = a1, a2,...,an di tipo item.
	L'insieme stack contiene in oltre un elemento nil che rappresenta la pila vuota
*/

stack newStack(void);
/*
funzione per creare uno stack
	Specifica sintattica:
		newStack() → stack
		Input: --
		Output: s
	Specifica semantica:
		newStack() → s
		Post: s = nil
*/


int emptyStack(stack s);
/*
funzione per controllare se uno stack è vuoto
	Specifica sintattica:
		emptyStack(stack) → boolean
		Input: stack s
		Output: boolean b
	Specifica semantica:
		emptyStack(s) → b
		Post: se s=nil allora b = true altrimenti b = false
*/


int  pop(stack s);
/*
Funzione per prelevare un elemento dallo stack
	Specifica sintattica:
		pop(stack) → boolean
		Input: stack s
		Output: boolean b
	Specifica semantica:
		pop(s) → b
		Pre: s = <a1, a2, …, an> n>0
		Post: se il prelievo riesce b = true altrimenti b = false
*/


int push(item val, stack s);
/*
Funzione per inserire un elemento nello stack
	Specifica sintattica:
		push(item, stack) → boolean
		Input: item x, stack s
		Output: bolean b
	Specifica semantica:
		push(e, s) → b
		Post: s = <a1, a2, … an> AND se l'inserimento riesce b = true altrimenti b = false
*/


item top(stack s);
/*
Funzione per prendere l'emento in testa allo stack
	Specifica sintattica:
		top(stack) → item
		Input: stack s
		Output: item x
	Specifica semantica:
		top(s) → x
		Pre: s = <a1, a2, …, an> n>0
		Post: x = a1
*/


void printStack(stack s);
/*
Funzione per stampare lo stack
	Specifica sintattica:
		printStack(stack) -> --
		Input: stack s
		Output: --
	Specifica semantica:
		printStack(s) → s
*/


