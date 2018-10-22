#include<stdio.h>
#include<stdlib.h>

int parent(int i)
{
	return(i/2);
}
int left(int i)
{
	return(2*i);
}
int right(int i)
{
	return((2*i)+1);
}
void max_heapify(int a[], int i,int n)
{
	int largest,swap;
	int heapsize=n;
	int l=left(i);
	int r=right(i);
	if(l<=heapsize && a[l]>a[i])
	{
		largest=l;
	}
	else
		largest =i;
	
	if(r<=heapsize && a[r]>a[i])
	{
		largest=r;
	}
	else
		largest=i;
	
	if(largest != i)
	{
		swap=a[largest];
		a[largest]=a[i];
		a[i]=swap;
		max_heapify(a,largest,n);
	}
}
void build_max_heap(int a[],int n)
{
	int heapsize=n; 
	for(int i=n/2;i>=1;--i)
	{
		max_heapify(a,i,n);
	}
}

void heapsort(int a[],int n)
{
	int heapsize=n;
	int swap;
	build_max_heap(a,n);
	for(int i=n;i>=1;--i)
	{
		swap=a[1];
		a[1]=a[i];
		a[i]=swap;
	
		heapsize--;
		max_heapify(a,1,heapsize);
	}
}
void main()
{
	int n;
	int* a;
	printf("\nEnter n:");
	scanf("%d",&n);
	a=(int*)malloc(sizeof(int)*n);
	printf("\nEnter the array:\n");
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
	}
	heapsort(a,n);
	
	printf("\nNew array is:\n");
	for(int i=1;i<=n;++i)
	{
		printf(" %d\t",a[i]);
	}
}

