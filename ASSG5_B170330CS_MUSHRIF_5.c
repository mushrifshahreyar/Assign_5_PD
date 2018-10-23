#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
	int swap;
	swap=*a;
	*a=*b;
	*b=swap;
}
int partition(int a[],int p,int r)
{
	int x=a[r];
	int i=p-1;
	for(int j=p;j<r;++j)
	{
		if(a[j]<=x)
		{
			i=i+1;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[r]);
	return i+1;
}
void quick_sort(int a[],int p,int r)
{
	int q;
	if(p<r)
	{
		q=partition(a,p,r);
		quick_sort(a,p,q-1);
		quick_sort(a,q+1,r);
	}
}
int check_asc(int a[],int n)
{
	for(int i=0;i<n-1;++i)
	{
		if(a[i]>a[i+1])
		{
			return 0;
		}
	}
	return 1;
}
int check_dsc(int a[],int n)
{
	for(int i=0;i<n-1;++i)
	{
		if(a[i]<a[i+1])
		{
			return 0;
		}
	}
	return 1;
}

void print(int a[],int n)
{
	printf("\nNew array is:\n");
	for(int i=0;i<n;++i)
	{
		printf(" %d ",a[i]);
	}
	printf("\n");
}		
void main()
{
	int n;
	int a[100];
	printf("\nEnter the n:");
	scanf("%d",&n);
	printf("\nEnter the array:\n");
	for(int i=0; i<n;++i)
	{
		scanf("%d",&a[i]);
	}
	
	if(check_asc(a,n))
	{
		printf("\nArray is sorted in ascending order");
	}
	else if(check_dsc(a,n))
	{
		printf("\nArray is sorted in  descending order");
	}
	else
	{
		printf("\nArray is not sorted\n");
		quick_sort(a,0,n-1);
		print(a,n);
	}
}
