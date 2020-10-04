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

struct Node* searchLL(struct Node *temp,int key)
{
	struct Node *t;
	t = temp;
	while(t!=NULL)
	{
		if(t->data == key)
		return t;
		t = t->next;
	}
	return NULL;
}

int main()
{
	int key;
	struct Node *p;
	
	createLL(head);
	
	printf("Enter the element to search : ");
	scanf("%d",&key);
	
	
	p = searchLL(head,key);
	
	if(p == NULL)
	printf("Key not found\n");
	else
	printf("%d is Found in List \n",p->data);
}
