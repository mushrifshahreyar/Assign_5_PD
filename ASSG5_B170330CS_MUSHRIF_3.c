#include<stdio.h>
#include<stdlib.h>

int global_size=0;
void dequeue(int *a)
{
	printf("\nDeleted element is :%d",a[0]);
	
	for(int i=1;i<global_size;++i)
	{
		a[i-1]=a[i];
	}
}
void enqueue(int *a, int ele)
{
	a[global_size]=ele;
}
void print(int *a)
{
	for(int i=0;i<global_size;++i)
	{
		printf(" %d ",a[i]);
	}
}

void main()
{
	int size,choice,ele;
	int *a;
	printf("\nEnter the size of array :");
	scanf("%d",&size);
	a=(int*)malloc(sizeof(int)*size);

	while(1)
	{
		printf("\n1\t-  ENQUEUE\n");
		printf("2\t-  DEQUEUE\n");
		printf("3\t-  PRINT\n");
		printf("4\t-  EXIT\n");
		printf("\nEnter the choice :");
		scanf("%d",&choice);
		if(choice == 1)
		{
			if(global_size >= size)
			{
				printf("\nOVERLOAD");
			}
			else
			{
				printf("\nEnter the element you want to insert:");
				scanf("%d",&ele);
				enqueue(a,ele);
				global_size++;								
			}
		}
		else if(choice == 2)
		{
			if(global_size == 0)
			{
				printf("\nUNDERFLOW");
			}
			else
			{
				if(global_size == 1)
				{
					printf("\nDeleted element is : %d",a[global_size-1]);
					global_size--;
				}
				else
				{
					dequeue(a);
					global_size--;
				}
			}
		}
				
		else if(choice == 3)
		{
			if(global_size == 0)
			{
				printf("\nEmpty list");
			}
			else
			{
				print(a);
			}
		}	
		else if(choice == 4)
		{
			printf("\nThank you for using the program\n");
			exit(0);
		}
		else
		{
			printf("\nPlease enter a valid choice\n");
			continue;	
		}
	}
}	
