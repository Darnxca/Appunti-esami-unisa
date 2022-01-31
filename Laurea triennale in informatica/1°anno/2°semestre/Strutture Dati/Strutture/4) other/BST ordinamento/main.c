#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "stack.h"
#include "BST.h"



int main (void)
{	

	BST T;
	item val;
	int scelta,key;	
	

	while(1)
	{
		printf("Scegli tra le seguenti opzioni:\n"
		       " 1) Crea albero;\n"
		       " 2) Input albero\n"
		       " 3) Conrollare se l'albero è vuoto\n"
		       " 4) Sapere la radice dell'albero\n"
		       " 5) Sapere l'altezza dell'albero\n"
		       " 6) Sapere il numero di nodi presenti nell'albero\n"
		       " 7) Stamapre l'albero in preorder (ricorsiva)\n"
		       " 8) Stamapre l'albero in inorder (ricorsiva)\n"
		       " 9) Stamapre l'albero in postorder (ricorsiva)\n"
		       "10) Stamapre l'albero in Levelorder (iterativa)\n"
		       "11) Stamapre l'albero in postorder_iter (iterativa)\n"
		       "12) Stamapre l'albero in visita_inorder_iter (iterativa)\n"
		       "13) Eliminare un nodo\n"
		       "14) Cercare un item\n"
		       "15) Esci\n");
		scanf("%d",&scelta);
		
		switch(scelta)
		{

			case 1:
				T=newBST();
				printf("Albero creato \n");		
				break;
	
			case 2:
				printf("Inserisci il valore: ");
				input_item(&val);
				insert(&T,val);
				break;

			case 3:
				if(emptyBST(T)==1)
					printf("L'albero è vuoto\n");
				else 
					printf("L'albero non è vuoto \n");
				break;
	
			case 4:
				printf("La radice è %d\n",getRoot(T));
				break;
				
			case 5: 
				printf("L'altezza è %d\n",altezzalbero(T));  //root
				break;

			case 6:
				printf("L'albero contiene %d nodi\n",numNode(T));  //root
				break;
			
			case 7:
				printf("L'albero è:\n");
				visita_preorder(T);
				printf("\n");
				break;
			
			case 8:
				printf("L'albero è:\n");
				visita_inorder(T);
				printf("\n");
				break;

			case 9:
				printf("L'albero è:\n");
				visita_postorder(T);
				printf("\n");
				break;

			case 10:
				printf("L'albero è:\n");
				Levelorder(T);
				printf("\n");
				break;
			
			/*case 11:
				printf("L'albero è:\n");
				postorder_iter(T);
				printf("\n");
				break;
		
			case 12:
				printf("L'albero è:\n");
				visita_inorder_iter(T);
				printf("\n");
				break;*/
		
			case 13:
				printf("inserisci il nodo da eliminare\n");
				scanf ("%d",&key);
				deleteNode(T,key);
				break;
			
			case 14:
				printf("Inserisci il valore da cercare: ");
				input_item(&val);
				
				if(contains(T,val))
					printf("L'elemento è presente\n");
				
				else
					printf("L'elemento non è presente\n");

				break;
					
			case 15:
				exit(1);
		}	
	}
		
	







 }

	
