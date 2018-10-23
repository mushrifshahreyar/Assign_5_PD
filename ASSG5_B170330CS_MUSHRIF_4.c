#include<stdio.h>
#include<stdlib.h>

int global_size=0;

struct Linked_List
{
	int data;
	struct Linked_List *next;
};
typedef struct Linked_List *node;

node Create_node()
{
	node temp;
	temp=(node)malloc(sizeof(struct Linked_List));
	if(temp == NULL)
	{
		printf("\nMemory not alloted");
		exit(0);
	}
	temp->next=NULL;
	return temp;
}

node push(node head,int ele)
{
	node temp;
	temp=Create_node();
	temp->data=ele;
	temp->next=head;
	return temp;
}
node pop(node head)
{
	node temp;
	if(head == NULL)
	{
		printf("\nUNDERFLOW\n");
		return NULL;
	}
	else if(head->next == NULL)
	{
		printf("\nDeleted element is: %d",head->data);
		return NULL;
	}
	else
	{
		printf("\nDeleted element is :%d",head->data);
		temp=head;
		head=head->next;
		free(temp);
		return head;
	}
}
void print(node head)
{
	node array;
	array=head;
	if(head == NULL)
	{
		printf("\nEmpty List");
	}
	while(array!=NULL)
	{
		printf(" %d ",array->data);
		array=array->next;
	}
}

void main()
{
	
	int data,ele,choice;
	
	node head;
	head=Create_node();
	do
	{
		printf("\nLIST\n");
		printf("1\t-  PUSH\n");
		printf("2\t-  POP\n");
		printf("3\t-  DISPLAY\n");
		printf("4\t-  EXIT\n");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		if(choice == 1)
		{
			printf("\nEnter the element: ");
			scanf("%d",&ele);
			if(global_size == 0)
			{
				head->data=ele;
			}
			else
			{
				head=push(head,ele);
			}
			global_size++;		
		}
		else if(choice == 2)
		{
			head=pop(head);
			global_size--;
		}
			
		else if(choice == 3)
		{
			print(head);
		}
		else if(choice == 4)
		{
			printf("\nThank you for using the program\n");
			exit(0);
		}
		else
		{
			printf("\nPlease enter a valid choice");
			continue;
		}
	
	}while(1);
}
