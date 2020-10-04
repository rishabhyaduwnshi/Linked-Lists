#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

struct Node *head = NULL;

void insertNode(struct Node *temp,int x)
{
	struct Node *t,*last;
	int i;
	temp = head;
	if(temp == NULL)
	{
		t = (struct Node *)malloc(sizeof(struct Node));
		t->data = x;
		t->next = NULL;
		head = t;
		last = head;
 	}
 	else if(temp!=NULL)
 	{
 		t = (struct Node *)malloc(sizeof(struct Node));
 		last->next = t;
 		t->data = x;
 		t->next = NULL;
 		last = t;
	}
 	
}

void insertSorted(struct Node *temp,int key)
{
	struct Node *p,*q,*t;
	
	if(temp->data > key)
	{
		t = (struct Node *)malloc(sizeof(struct Node));
		t->next = temp;
		t->data = key;
		head = t;
	}
	else
	{
	q = NULL;
	p = temp;
	while(p!=NULL && p->data < key)
	{
		q = p;
		p = p->next;
	}
	
	t = (struct Node *)malloc(sizeof(struct Node));
	t->next = q->next;
	t->data = key;
	q->next = t;
	head = temp;
	}
}

void displayList(struct Node *temp)
{
	temp = head;
	while(temp)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
}
int main()
{
	insertNode(head,5);
	insertNode(head,15);
	insertNode(head,25);
	insertNode(head,35);
	insertNode(head,45);
	
	printf("Initially the list is : \n");
	displayList(head);
	
	
	printf("\n");
	printf("\nAfter insertion at sorted postion : \n");
	
	insertSorted(head,1);
	insertSorted(head,29);
	insertSorted(head,99);
	
	
	displayList(head);
	
	return 0;
}
