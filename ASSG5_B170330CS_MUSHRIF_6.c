#include<stdio.h>
#include<stdlib.h>

int front=-1;
int rear=-1;
int size;

void push(int *a,int ele)
{
	if((rear == size-1 && front == 0) || front == rear+1)
	{
		printf("\nOVERFLOW");
	}
	else if(rear == size-1 && front != 0)
	{
		rear=-1;
	}
	else
	{
		printf("\nEnter the element :");
		scanf("%d",&ele);
		rear++;
		a[rear]=ele;
		if(front == -1)
		{
			front = 0;
		}
	}
}

void pop(int *a)
{
	if(front == -1 || rear == -1)
	{
		printf("\nUNDERFLOW");
	}
	else
	{
		printf("\nDeleted element is : %d",a[front++]);
		if(front == size)
		{
			front=-1;
		}
		if(rear == front-1)
		{
			front=-1;
			rear=-1;
		}
	}
}
	
void print(int *a)
{
	if(front == -1)
	{
		printf("\nEMPTY LIST");
	}
	else
	{
		if(front <= rear)
		{
			for(int i=front;i<=rear;++i)
			{
				printf(" %d ",a[i]);
			}
		}
		else
		{
			for(int i=front;i<size;++i)
			{
				printf(" %d ",a[i]);
			}
			for(int i=0;i<=rear;++i)
			{
				printf(" %d ",a[i]);
			}
		}
	}	
}

void main()
{
	int choice,ele;
	int *a;

	printf("\nEnter the size of the the array: ");
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
			push(a,ele);
		}
		else if(choice == 2)
		{
			pop(a);
		}
		else if(choice == 3)
		{
			print(a);
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
