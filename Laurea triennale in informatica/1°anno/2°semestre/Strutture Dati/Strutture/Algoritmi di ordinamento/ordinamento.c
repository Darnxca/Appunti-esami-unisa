#include "ordinamento.h"
#include <stdio.h>

int dim1=0;

void setDim(int n)
{
	dim1=n;
}

void Merge(int *v, int p, int q, int r)
{
	int B[dim1], i, j, k;

	for(i = p, j = q+1, k = p; i <= q && j <= r;)
	{
		if(v[i] < v[j])
		{
			B[k++] = v[i++];
		}	
		else
		{
			B[k++] = v[j++];
		}
	}
	
	for(; i <= q;) B[k++] = v[i++];
	for(; j <= r;) B[k++] = v[j++];
	for(k = p; k <= r; k++) v[k] = B[k];
}

void MergeSort(int *v, int p, int r)
{
	int q;
	
	if(p < r)
	{
		q = (p + r) /2;
		MergeSort(v, p, q);
		MergeSort(v, q+1, r);
		Merge(v, p, q, r);
	}
}

int Partition(int *v, int p, int r)
{
	int x, i, j, temp;
	x = v[p];
	i = p-1;
	j = r+1;
		
	while(i < j)
	{
		while(v[--j] > x);
		while(v[++i] < x);
		if(i < j)
		{
			temp = v[i];
			v[i] = v[j];
			v[j] = temp;
		}
	}

	return (j);
}

void QuickSort(int *v, int p, int r)
{
	int q;
	
	if(p < r)
	{
		q = Partition(v, p, r);
		QuickSort(v, p, q);
		QuickSort(v, q+1, r);
	}
}

void selectionSort(int *v)
{
	int i,j,tmp=0;
	
	for (i=0; i<dim1-1; i++)
	{
		for (j=i+1; j<dim1; j++)
		{
			if (v[j] < v[i])
			{
				tmp = v[j];
				v[j] = v[i];
				v[i] = tmp;
			}
		}
	}
}

void insertionSort(int *v)
{
	int i,next,j;
	
   	for (i=1; i<dim1; i++) 
	{
    		next = v[i];
    		j = i-1;

    		while (j>=0 && v[j]>next)
		{
      			v[j+1] = v[j];
      			j--;
    		}
    		
		v[j+1] = next;
  	}
 	
	return;
}

void bubblesort(int *v)
{
	int i,j,temp,ordinato = 0;
	i = 1;

	while (i < dim1 && !ordinato)
	{
		ordinato=1;
		
		for(j=0;j<dim1-1;j++)
		{
			if (v[j]>v[j+1]) /* sostituire ">" con "<" per avere un ordinamento decrescente */
        		{ 
             			temp = v[j]; 
             			v[j] = v[j+1]; 
             			v[j+1] = temp;
             			ordinato=0;
    			}
    		}
    		
		i++;
	}
}