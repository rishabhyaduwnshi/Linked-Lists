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
	printf("Enter the number of nodes in list : ");
	scanf("%d",&n);
	
	t = (struct Node *)malloc(sizeof(struct Node));
	
	printf("Enter data of first Node : ");
	scanf("%d",&x);
	
	t->data = x;
	t->next = NULL;
	last = t;
	
	for(i=1;i<n;i++)
	{
		printf("Enter Data : ");
		scanf("%d",&x);
		
		temp = (struct Node *)malloc(sizeof(struct Node));
		temp->data = x;
		temp->next = NULL;
		
		last->next = temp;
		last = temp;
	}
	
	head = t;
}

void recursiveDisplay(struct Node *temp)
{
	if(temp!=NULL)
	{
		printf("%d ",temp->data);
		recursiveDisplay(temp->next);
	}
}

void recursiveDisplay2(struct Node *temp)
{
	if(temp!=NULL)
	{
		recursiveDisplay(temp->next);//first calling on temp->next and then displaying
		printf("%d ",temp->data);
		
	}
}

int main()
{
	createLL(head);
	printf("\n\n");
	printf("Elements in Linked List are : ");
	recursiveDisplay(head);
	printf("\n\n");
	printf("Reverse of Linked List is : ");
	recursiveDisplay2(head);
		
}
