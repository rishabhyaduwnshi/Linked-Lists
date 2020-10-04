#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

struct Node *head = NULL;

void createLL(struct Node *t)
{
	int n,x,i;
	struct Node *last,*temp;
	printf("Enter the number of elements in list : ");
	scanf("%d",&n);
	
	t = (struct Node *)malloc(sizeof(struct Node));
	
	printf("Enter data of first Node : ");
	scanf("%d",&x);
	
	t->data = x;
	t->next = NULL;
	last = t;
	
	for(i=1;i<n;i++)
	{
		printf("Enter Data of next Node : ");
		scanf("%d",&x);
		
		temp = (struct Node *)malloc(sizeof(struct Node));
		temp->data = x;
		temp->next = NULL;
		
		last->next = temp;
		last = temp;
	}
	
	head = t;
}

void displayLL(struct Node *temp)
{
	while(temp)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
}
int main()
{
	createLL(head);
	displayLL(head);
		
}
