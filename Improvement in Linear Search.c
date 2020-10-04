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

int searchLL(struct Node *temp,int key)
{
	struct Node *p,*q;
	p = temp;
	while(p!=NULL)
	{
		if(p->data == key)
		{
			q->next = p->next;
			p->next = head;
			head = p;
			return 1;
		}
		q = p;
		p = p->next;
	}
	return -1;
}

void recursiveDisplay(struct Node *temp)
{
	if(temp!=NULL)
	{
		printf("%d ",temp->data);
		recursiveDisplay(temp->next);
	}
}

int main()
{
	int key,p;
	
	createLL(head);
	
	printf("Enter the element to search : ");
	scanf("%d",&key);
	
	p = searchLL(head,key);
	if(p == 1)
	printf("Key Found\n");
	else
	printf("Key Not Found\n");
	recursiveDisplay(head);
	

}
