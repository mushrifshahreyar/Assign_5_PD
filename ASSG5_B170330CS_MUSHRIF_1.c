#include<stdio.h>
#include<stdlib.h>

int n,k=0;
void push(int a[],int p)
{
	if(k==0)
	{
		a[k]=p;
	}
	else
	{
		for(int i=0;i<k;++i)
		{
			a[i+1]=a[i];
		}
		a[0]=p;
	}
	
} 
void pop(int a[])
{
	printf("\nDeleted element is: %d",a[0]);
	for(int i=1;i<k;++i)
	{
		a[i-1]=a[i];
	}
}
void print(int a[])
{
	if(k == 0)
	{	
		printf("%d\n",a[0]);
	}	
	else
	{
		for(int i=k-1;i>=0;--i)
		{
			printf("%d ",a[i]);
		}
	}
	printf("\n");
}
void main()
{
	int choice,ele;
	
	printf("\nEnter the size of the array: ");
	scanf("%d",&n);
	int *a;
	a=(int*)malloc(sizeof(int) *n);
	do
	{
		printf("\n1\t-PUSH");
		printf("\n2\t-POP");
		printf("\n3\t-PRINT");
		printf("\n\nEnter the option :");
		scanf("%d",&choice);
		if(choice == 1)
		{
			printf("\nEnter the element to be inserted: ");
			scanf("%d",&ele);
			if(k<n)
			{	push(a,ele);
				k++;
			}
			else
				printf("\nOverflow");
		}
		else if(choice == 2)
		{
			if(k < 0)
			{
				printf("\nEmpty List");
			}
			else
			{
				pop(a);
				k--;
			}
			
		}
		else if(choice == 3)
		{
				if(k<=-1)
				{
					printf("\nEmpty List");
				}
				else
					print(a);
		}
		else
		{
			if(choice != 4)
			printf("\nInvalid choice\n");
		}
	}while(choice!=4);
	
	printf("\nThank you for using the program\n");
}		
