#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"


static struct node* makeNode(item val, struct node* nxt);
static struct node* removeNode(struct node* n, int pos);

struct c_list{
	struct node *first;  //punta al primo nodo // puntatore all’ultimo nodo di l1della lista	
	int size;            //numero di elementi in una lista
};

struct node{
	item value;
	struct node *next;
};

list newList(void)
{
	struct c_list *l;
	l=malloc(sizeof(struct c_list));
	if(l!=NULL)
	  {
		l->first=NULL;
		l->size=0;
	  }

	return l;
}

int emptyList(list l)
{
       if(l==NULL)
	{
	   return -1;
	}
	return (l->size==0);
}


int sizeList(list l)
{
	if(l==NULL)                 //se la lista l è NULL ritorno -1 (errore)
	   {                      
  		return -1;
	   }
	return l->size;
}


int posItem(list l,item val)
{
	if (l==NULL)   //se la lista l è vuota restituisco -1 (errore)
	  {
		return -1;
	  }

	int pos=0;    // mi salva la posizione dell'item 
	int found=0;  //viene settata ad 1 se l'item è stato trovato

	struct node *temp= l->first;  //il puntatore temp punta al primo elemento della lista l

	while(temp!=NULL && !found)
	   {
		if(eq(temp->value,val)==0)
		   {
 			found=1;    //elemento trovato
		   }
		else
		  {
			temp=temp->next;    //temp punta al prossimo elemento e continua la ricerca nella lista
		        pos++;
		  }
	   }
	
	if(!found)
	{
	   pos=-1;	
	}  

	return pos;
}

int searchItem(list l, item x)
{
	if (l==NULL)   //se la lista l è vuota restituisco -1 (errore)
	  {
		return -1;
	  }

	int found=0;
	
	struct node *temp= l->first;  //il puntatore temp punta al primo elemento della lista l

	while(temp!=NULL)
	   {
		if(eq(temp->value,x)==0)
		   {
 			return 1;    //elemento trovato
		   }
		else
		  {
			temp=temp->next;    //temp punta al prossimo elemento e continua la ricerca nella lista
		  }
	   }

	return 0;
}

item getItem(list l, int pos) 
{
	if(l==NULL)          //se l non esiste restituisco nullitem
	  {
		return NULLITEM;
	  }
   
	if(pos<0||pos>=l->size)   //se la posizione inserita è minore di 0 o piu grande della grandzza della lista restituisco NULLITEM
	 {
		return NULLITEM;   // precondizione non verificata
	 }	   

	struct node *temp=l->first;   //creo un puntatore temporaneo (temp) di tipo struct node che punta al primo elemento della lista 
	
	int i=0;

	while(i<pos)    //continuo il ciclo fino a quando non arrivo al nodo di posizione pos
	  {
		i++;
		temp=temp->next;  // temp punta al prossimo elemento
	  }

	return temp->value;  //ritorno il valore presente nel nodo della posizone pos
}





void inputList(int n,list l)
{

	int i=0,j=n-1;

	if(n<=0)
	  {
		printf("Hai deciso di non inserire nessun elemento\n");
	  }

	item val;
	 
	if(l->first==NULL)
	{
		printf("Inserisci elemento\n ");
		val=input_item();
		l->first=makeNode(val,NULL);  // inserimento primo elemento 
		n--;
		l->size++;
	}
	
	while(n>0)
	{
		val=input_item();			
		insertList(l,l->size,val);
		n--;
	}
}


int outputList(list l)
{
	if(l==NULL)	//controllo se la lista l esiste
	{
		return 0;
	}

	int i=0;   //posizione dell'elemento
	struct node *temp=l->first;   

	while(temp != NULL)
	  {
		printf("L'elemento in posizione %d: ",i);
		output_item(temp->value);
		printf("\n");

		temp=temp->next;   //aggiorno temp
	  	i++;
	  }
	return 1;    //l'operazione è andata a buon fine
}

static struct node* makeNode(item val, struct node* nxt)
{
	struct node *nuovo=malloc(sizeof(struct node));  //alloco memoria per la nuova struct node "nuovo"
	if(nuovo != NULL)
	  {
		nuovo->value=val;
		nuovo->next=nxt;
	  }
	return nuovo;
}

static struct node* insertNode (struct node* n, int pos, item val)
{
	struct node *n1;

	if(pos==0)
	  {
		return makeNode(val,n);
	  }

	int i=0;
	struct node* prec=n;
	while(i<pos-1)
	  {
		prec=prec->next;
		i++;
	  }
	n1=makeNode(val,prec->next);  //creo un nuovo nodo
	
	if(n1==NULL)
	  {	
		return NULL;   //makeNode non eè riuscito ad allocare memoria
	  }

	prec->next=n1;
	return n;
}


int insertList(list l,int pos,item val)
{
	  //controllare
	
	if(l==NULL)
	  { 
 		return 0;   //nel caso la lista non esiste
	  }
	
	if(pos<0||pos>l->size)  
	  {
 		return 0;    //nel caso che la posizione inserita sia minore di 0 o maggiore della lunghezza della lista
	  }	

	struct node *tmp = insertNode(l->first,pos,val);  //creo una struttura tmp 

	if(tmp==NULL)
	  {
		return 0;   // restituisco 0 se non sono riuscito ad inserire nella lista, esce senza modificafre la lista
	  }

	//se l'inserimento è riuscito allora modifico la lista 

	l->first= tmp;   //il primo elemento della lista è ugiale a tmp 
	l->size++;   //incremento la size di 1

	return 1;  
}

static struct node* removeNode(struct node* n, int pos)
{
   struct node *n1;     //puntatore al nodo che devo eliminare

   	if(pos==0)      //caso in cui devo eliminare in prima posione
          {
             n1=n;      //il puntatore n1 punta ad n  che è il puntaore al primo elemento della lista
 	     n=n->next;  //n punta all'elemento successivo che diviene il primo 
	     free(n1);  //libero n1
          }

         else      //caso di eliminazione in cui pos è maggiore di 0
	    {
		int i=0;   
		struct node* prec=n;  //puntatore al precendete (pos-1)
		
		while(i<pos-1)
		  {
  			prec=prec->next;   //scorriamo fino a pos-1 
			i++; 
			//Alla fine del ciclo, prec->next punta al nodo da eliminare.
		  }

		n1=prec->next;    //n1 punta al node che devo eliminare
                prec->next=n1->next;  //aggiorno il nodo che devo eliminare e lo faccio puntare al successivo
                free(n1);        //libero n1 che è il node da eliminare
	    }
	return n;
}

int removeList(list l, int pos)
{
	if(l==NULL)
          {
	      return 0;    //caso in cui la lista non esite
	  }

	if(pos<1||pos>l->size)
          {
		return 0;      //precondizione non soddisfatta
	  }

       l->first = removeNode(l->first,(pos-1)); 
       l->size--;
       
       return 1;
}


int removeItem(list l, item x)
{
	int pos=posItem(l,x)+1;

	if(removeList(l,pos)==1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

list reverseList1(list l)
{
	if (l==NULL)
	  {
		return NULL;
	  }	

	list l1=newList();    //creiamo la nuova lista di output
	struct node *temp=l->first; // serve per scorrere la lista di input

//in questo ciclo si scorre la lista di input e si inseriscono i valori in testa alla nuova lista 
	while(temp!=NULL)
	  {
		l1->first=makeNode(temp->value,l1->first);

		if (l1->first==NULL)
		   {
			return NULL;
		   }
		temp=temp->next;   //temp punta al prossimo nodo
	  }

   // l1->first è NULL se l è vuota o se makeNode non ha allocato memoria
	if(l1->first!=NULL)  //In questo ciclo si assegna alla nuova lista la size di quella di input
	  {
		l1->size=l->size;
	  }

   // se l1->first è NULL allora l1->size è 0 (quella inizializzata da newList)
	return l1;   //ritorno la nuova lista  
}


int reverseList2(list l)   //inverte la lista senza crearne una nuova, inverterndo solo i puntatori
{
 
	if(l==NULL)
	  {
             return 0;
	  }

	struct node *n=l->first;     //serve per scorrere la lista 
	struct node *prec=NULL;  //punta al predecessore di n
	struct node *succ;  //usato per salvare il successore di n
	
	// si scorre la lista di input e n->next viene posto uguale a prec
	while(n!=NULL)
	  {
		succ=n->next;  //salviamo il successore
		n->next=prec;  //il successore di n diviene il suo predecessore
		prec=n;        //avanziamo prec sulla lista
		n=succ;        //avanziamo n sulla lista
	  }

	/* all’uscita del ciclo prec punta all’ultimo nodo della lista di input
che ora diventa il primo nodo della reversed list
*/
	l->first=prec;
	return 1;   //L'operazione è andata a buon fine
}



list cloneList(list l)
{
	
	if(l==NULL)
  	  {
             return NULL;   // si controlla se esiste la lista
	  }
	
	if(emptyList(l))
	  {
		return newList();
	  }

	struct node *temp=l->first;  //serve per scorrere la lista di input	
	
	list l1=newList();  //creiamo la nuova lista di output
	l1->first=makeNode(temp->value,NULL);    // creazione primo nodo

	struct node *temp1=l1->first;    // puntatore all’ultimo nodo di l1

	while(temp->next!=NULL)
	  {
		temp1->next=makeNode(temp->next->value,NULL);

		  if(temp1->next==NULL)
		    {
			return NULL;
		    }

		temp=temp->next;
		temp1=temp1->next;
	  }


	l1->size=l->size;   // assegno la size della lista di input a quella clonata
	return l1;    //ritorno la lista clonata
}



int deleteList(list l)   //questa funzione cancella solo i nodi della lista e non l'intera lista
{
	if(l==NULL)
	  {
            return 0;    // controllo se la lista l esiste
	  }

	struct node *temp=l->first;   //serve a scorre la lista di input
	struct node *temp1;           //punta al nodo da eliminare

	while(temp!=NULL)
	  {
		temp1=temp;
		temp=temp->next;
		free(temp1);
	  }

	l->first=NULL;
	l->size=0;
	return 1;  //l'operazione è andata a buon fine
}

int destroyList(list *l)
{
	if(*l!=NULL)
	  {
		deleteList(*l);  //senza *
	  }

	free(*l);
	*l=NULL;
	return 1;
}











