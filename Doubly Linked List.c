#include<stdio.h>
#include<stdlib.h>

struct Node
{
	struct Node *prev;
	int data;
	struct Node *next;
};

struct Node* createDoublyLL()
{
	int i,nodes,x;
	struct Node *temp,*last,*t;
	printf("Enter number of nodes : ");
	scanf("%d",&nodes);
	
	printf("Enter node data : ");
	scanf("%d",&x);
	
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = NULL;
	temp->prev = NULL;
	last = temp;
	
	for(i=1;i<nodes;i++)
	{
		t = (struct Node*)malloc(sizeof(struct Node));\
		
		printf("Enter Node Data : ");
		scanf("%d",&x);
		
		last->next = t;
		t->prev = last;
		t->next = NULL;
		t->data = x;
		last = t;
	}
	return temp;
}

int countNodes(struct Node *temp)
{
	struct Node *p;
	p = temp;
	int count=0;
	do
	{
		count++;
		p = p->next;
	}
	while(p!=temp);
	return count;
}

void printList(struct Node *temp)
{
	while(temp)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
}

void printList2(struct Node *temp)
{
	while(temp->next) //travesring the temp pointer to point on last node
	temp = temp->next;
	while(temp)
	{
		printf("%d ",temp->data);
		temp = temp->prev;
	}
}

int main()
{
	int i;
	struct Node *doubly,*temp;
	doubly = createDoublyLL();
	temp = doubly;
	printf("\nPrinting using next pointer : ");
	printList(doubly);
	
	
	
	printf("\n\nPrinting using previous pointer : "); 
	printList2(temp);	
	
}
