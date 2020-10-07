#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};


struct Node* createLL()
{
	int n,i,x;
	struct Node *t,*last,*temp;
	
	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	
	printf("Enter Head Node data : ");
	scanf("%d",&x);
	
	temp = (struct Node *)malloc(sizeof(struct Node));
	temp->next = NULL;
	temp->data = x;
	last = temp;
	
	for(i=1;i<n;i++)
	{
		printf("Enter node data : ");
		scanf("%d",&x);
		
		t = (struct Node *)malloc(sizeof(struct Node));
		t->next = NULL;
		t->data = x;
		
		last->next = t;
		last = t;
	}
	return temp;
}

struct Node* concatenateList(struct Node *temp1,struct Node *temp2)
{
	struct Node *temp;
	temp = temp1;
	while(temp->next != NULL)
	{
		temp = temp->next; 
	}
	temp->next = temp2;
	temp = temp1;
	return temp;
}


void printList(struct Node *temp)
{
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
}


int main()
{
	struct Node *first,*second,*third;
	
	
	first = createLL();
	printf("\n");
	second = createLL();
	printf("\n");
	printf("First List : ");
	printList(first);
	printf("\n\n");
	printf("Second List : ");
	printList(second);
	printf("\n");
	third = concatenateList(first,second);
	printf("\n");
	printf("Concatenated List : ");
	printList(third);
}
