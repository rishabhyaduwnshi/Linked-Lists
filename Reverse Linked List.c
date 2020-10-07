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

void reverseList(struct Node *temp)
{
	struct Node *p,*q,*r;
	r = NULL;
	q = NULL;
	p = temp;
	
	while(p!=NULL)
	{
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	head = q;
}


void recursiveReverse(struct Node *q,struct Node *p)
{
	if(p!=NULL)
	{
		recursiveReverse(p,p->next);
		p->next = q;
	}
	else
	 head = q;
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
	
	printf("List before reversing \n");
	displayList(head);
	
	printf("\n\n");
	printf("List after reversing \n");
	recursiveReverse(NULL,head);
	displayList(head);
	
	printf("\n\n");
	printf("List after reversing \n");
	reverseList(head);
	displayList(head);
	
	return 0;
}
