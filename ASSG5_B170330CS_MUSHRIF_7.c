#include<stdio.h>
#include<stdlib.h>

int left(int i)
{
	return (2*i);
}
int right(int i)
{
	return ((2*i)+1);
}


struct LinkedList{
	int data;
	struct LinkedList* next;
	
};
typedef struct LinkedList* node;
node head;

node createNode(int data)
{
	node temp = (node) malloc(sizeof(struct LinkedList));
	temp->data=data;
	temp->next=NULL;
	return temp;
}
void addNode(int data)
{
	node temp = createNode(data);
	temp->next = head;
	head = temp;
}


node position(int index)
{
	node cursor = head;
	for(int i =0; i< index;i++)
	{
		cursor = cursor->next;
	}
	return cursor;
}

void swap(int a, int b)
{
	int temp = position(b)->data;
	position(b)->data= position(a)->data;
	position(a)->data= temp;
}
void max_heapify(int i, int heapsize)
{
	int l = left(i);
	int r = right(i);
	int largest=i;
	if(l<=heapsize)
	{

		if(position(l-1)->data>position(i-1)->data)
			largest = l;
		else
			largest = i;
	}
	if(r<=heapsize)
	{
		if(position(r-1)->data>position(largest-1)->data)
			largest = r;
	}

	if(largest!=i)
	{

		swap(i-1,largest-1);


			max_heapify(largest,heapsize);
	}
}

void build_max_heap(int length)
{
	for(int i = length;i>0;i--)
	{
		max_heapify(i,length);
	}
}

void heapSort(int length)
{
	int heapsize = length;
	build_max_heap(length);
	for(int i = length; i>1; i--)
	{

		swap(0,i-1);
		heapsize--;
		max_heapify(1,heapsize);
	}
}
void print(node head)
{
	node array=head;
	while(array!=NULL)
	{
		printf("%d ",array->data);
		array=array->next;
	}
}
int main(int argc,char *argv[])
{
	FILE *fp;
	int temp;
	int length=0;
	fp = fopen(argv[1],"r");
	while(!feof(fp))
	{
		fscanf(fp,"%d ",&temp);
		addNode(temp);
		length++;
	}

	heapSort(length);
	node array = head;
	print(head);	

}


