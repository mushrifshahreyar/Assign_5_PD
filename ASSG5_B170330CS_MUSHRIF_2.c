#include<stdio.h>
#include<stdlib.h>

int parent(int i)
{
	return i/2;
}
int left(int i)
{
	return(2*i);
}
int right(int i)
{
	return((2*i)+1);
}
void max_heapify(int a[],int i,int heapsize)
{
	int largest;
	int l=left(i);
	int r=right(i);
	if(l<=heapsize && a[l]>a[i])
	{
		largest=l;
	}
	else
		largest=i;
	
	if(r<=heapsize && a[r]>a[largest])
	{
		largest=r;
	}

	if(largest != i)
	{
		int swap=a[i];
		a[i]=a[largest];
		a[largest]=swap;
		
		max_heapify(a,largest,heapsize);
	}
}	
void build_max_heap(int a[],int n)
{
	
	for(int i=n/2;i>=1;--i)
	{
		max_heapify(a,i,n);
	}
}

void heap_sort(int a[],int n)
{
	build_max_heap(a,n);
	int heapsize=n;
	for(int i=n;i>=2;--i)
	{
		int swap=a[1];
		a[1]=a[i];
		a[i]=swap;
		heapsize=heapsize-1;
		max_heapify(a,1,heapsize);
	}
}	

void print(int a[],int n)
{
	printf("\nNew array is:\n");
	for(int i=1;i<=n;++i)
	{
		printf(" %d ",a[i]);
	}
}	
void main()
{
	int n;
	int a[100];
	printf("\nEnter n:");
	scanf("%d",&n);
	printf("\nEnter array :\n");
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
	}
	//print(a,n);
	heap_sort(a,n);
	print(a,n);
}
		
