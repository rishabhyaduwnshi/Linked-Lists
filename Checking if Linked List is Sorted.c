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


int isSorted(struct Node *temp)
{
	struct Node *p;
	int x = INT_MIN;
	
	while(temp!=NULL)
	{
		if(temp->data < x)
		return 0;
		
		x = temp->data;
		temp = temp->next;
	}
	return 1;
}
void displayList(struct Node *temp)
{
	printf("The List is : ");
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
	insertNode(head,35);
	displayList(head);
	printf("\n");
	if(isSorted(head))
		printf("List is Sorted");
	else
	 	printf("List is Not Sorted");
	return 0;
}
