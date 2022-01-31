#include <stdio.h>
#include "item.h"



int eq(item x, item y)
{
	return x==y;    //controlla se l'item x è uguale all'item y
}



void input_item(item *x)
{
	scanf("%d",x);   //esegue l'input dell'item
}

void output_item(item x)
{
	printf("%d\n", x);    //esegue l'output dell'item
}




