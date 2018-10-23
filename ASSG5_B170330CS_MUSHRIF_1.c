#include<stdio.h>
#include<stdlib.h>

int global_size=0;
void push(int a[],int ele)
{
	if(global_size == 0)
	{
		a[global_size]=ele;
	}
	else
	{
		for(int i=global_size-1;i>=0;--i)
		{
			a[i+1]=a[i];
		}
		a[0]=ele;
	} 
} 
void pop(int a[])
{
	printf("\nDeleted element is: %d",a[0]);
	for(int i=1;i<global_size;++i)
	{
		a[i-1]=a[i];
	}
}
void print(int a[])
{
	for(int i=0;i<global_size;++i)
	{
		printf(" %d ",a[i]);
	}	
}
void main()
{
	int choice,ele,size;
	int *a;
	
	printf("\nEnter the size of the array: ");
	scanf("%d",&size);
	
	a=(int*)malloc(sizeof(int) * size);
	do
	{
		printf("\n1\t-PUSH");
		printf("\n2\t-POP");
		printf("\n3\t-PRINT");
		printf("\n4\t-EXIT");
		printf("\n\nEnter the option :");
		scanf("%d",&choice);
		if(choice == 1)
		{
			printf("\nEnter the element to be inserted: ");
			scanf("%d",&ele);
			if(global_size < size)
			{	
				push(a,ele);
				global_size++;
			}
			else
				printf("\nOVERFLOW\n");
		}
		else if(choice == 2)
		{
			if(global_size ==  0)
			{
				printf("\nUNDERFLOW\n");
			}
			else
			{
				if(global_size == 1)
				{
					printf("\nDeleted element is: %d",a[global_size-1]);
					global_size--;
				}
				else
				{
					pop(a);
					global_size--;
				}
			}
		}
		else if(choice == 3)
		{
			if(global_size == 0)
			{
				printf("\nEmpty List\n");
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
