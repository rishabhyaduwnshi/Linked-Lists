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

int countNodes(struct Node *temp)
{
	int count = 0;
	while(temp!=NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

void deleteNode(struct Node *temp,int pos)
{
	int i=1;
	if(countNodes(temp) < pos)
	 return;
	else
	 {
	 	struct Node *p,*q;
	 	if(pos == 1)
	 	{
	 		p = temp;
	 		temp = temp->next;
	 		head = temp;
	 		free(p);
		 }
		 else
		 {
		 	p = head;
		 	q = NULL;
		 	for(i=1;i<=pos-1;i++)
		 	{
		 		q = p;
		 		p = p->next;
			 }
			 
			 q->next = p->next;
			 free(p);
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
	insertNode(head,15);
	insertNode(head,25);
	insertNode(head,35);
	insertNode(head,45);
	
	
	printf("List before deletion : \n");
	displayList(head);
	
	printf("\n\n");
	
	deleteNode(head,2);
	printf("List after deletion : \n");
	displayList(head);
	return 0;
}
