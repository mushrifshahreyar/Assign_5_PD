#include<stdio.h>
#include<stdlib.h>

struct Linked_List
{
	int data;
	struct Linked_List *left;
	struct Linked_List *right;
	struct Linked_List *parent;
};

typedef struct Linked_List *node;

int size;

node Create_node()
{
	node temp;
	temp=(node)malloc(sizeof(struct Linked_List));
	if(temp == NULL)
	{
		printf("\nMemory not alloted\n");
		exit(0);
	}
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
node insert(node head,int* a,int i)
{
	if(i>=size)
	{
		return NULL;
	}
	if(i<size)
	{
		node temp=Create_node();
		temp->data=a[i];
		head=temp;
	
		head->left=insert(head,a,2*i+1);
		head->right=insert(head,a,2*i+2);
	}
	return head;	
}

void pre_order_print(node head)
{
	
	if(head != NULL)
	{
		printf(" %d ",head->data);
		pre_order_print(head->left);
		pre_order_print(head->right);
	}
}
void post_order_print(node head)
{
	
	if(head != NULL)
	{
		pre_order_print(head->left);
		pre_order_print(head->right);
		printf(" %d ",head->data);
	}
}
void in_order_print(node head)
{
	
	if(head != NULL)
	{
		pre_order_print(head->left);
		printf(" %d ",head->data);
		pre_order_print(head->right);
	}
}


	
void main()
{
	node head=NULL;
	int *a;

	printf("\nEnter the size of array: ");
	scanf("%d",&size);
	a=(int *)malloc(sizeof(int)*size);
	printf("\nEnter the elements :\n");
	for(int i=0;i<size;++i)
	{
		scanf("%d",&a[i]);
	}
	head=insert(head,a,0);
	printf("\nPRE-ORDER PRINT \n");
	pre_order_print(head);
	printf("\nIN-ORDER PRINT \n");
	in_order_print(head);
	printf("\nPOST-ORDER PRINT \n");
	post_order_print(head);
}	
