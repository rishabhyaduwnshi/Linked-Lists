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

struct Node* mergeLists(struct Node *p,struct Node *q)
{
	struct Node *third,*last;
	
	if(p->data < q->data)
	{
		third = p;
		last = p;
		p = p->next;
		third->next = NULL;
	}
	else
	 {
	 	third = q;
		last = q;
		q = q->next;
		third->next = NULL;
	 }
	 
	 while(p!=NULL && q!=NULL)
	 {
	 	if(p->data > q->data)
	 	{
	 		last->next = q;
	 		last = q;
	 		q = q->next;
			last->next = NULL;
		}
		else
		 {
		 	last->next = p;
	 		last = p;
	 		p = p->next;
			last->next = NULL;
		 }
	 }
	 if(p!=NULL)
	 last->next = p;
	 else
	 last->next = q;
	 
	return third;
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
	third = mergeLists(first,second);
	printf("Merged List is : ");
	printList(third);
	
}
