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


void removeDuplicates(struct Node *temp)
{
	struct Node *p,*q;
	p = temp;
	q = temp->next;
	
	while(q!=NULL)
	{
		if(p->data == q->data)
		{
			p->next = q->next;
			free(q);
			q = p->next;
		}
		else
		{
			p = q;
			q = q->next;
		}
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
	insertNode(head,5);
	insertNode(head,25);
	insertNode(head,35);
	insertNode(head,45);
	insertNode(head,45);
	printf("Initially the List is \n");
	displayList(head);
	printf("\n\n");
	printf("List after deletion of duplicates \n");
	removeDuplicates(head);
	displayList(head);
	return 0;
}
