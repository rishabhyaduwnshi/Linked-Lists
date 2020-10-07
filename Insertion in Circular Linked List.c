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
	
	temp = (struct Node *)malloc(sizeof(struct Node)); //creating head node
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
	t->next = temp; //Making the last node point on head node
	return temp;
}

int countNodes(struct Node *temp)
{
	struct Node *p;
	p = temp;
	int count=0;
	do
	{
		count++;
		p = p->next;
	}
	while(p!=temp);
	return count;
}


struct Node* insertNode(struct Node *temp,int pos)
{
	int value;
	struct Node *p,*last,*q;
	last = temp;
	
	printf("Enter Value to be inserted : ");
	scanf("%d",&value);
	
	if(pos == 0)
	{
		
		while(last->next!=temp)
		{
			last = last->next;
		}	
		
		p = (struct Node *)malloc(sizeof(struct Node));
		last->next = p;
		p->next = temp;
		p->data = value;
		return p;
	}
	else
	{
		int i;
		if(pos<0 || pos>countNodes(temp))
		return;
		else
		{
			for(i=0;i<pos-1;i++)
			last = last->next;
			
			p = (struct Node *)malloc(sizeof(struct Node));
			p->next = last->next;
			last->next = p;
			p->data = value;
			return temp;
		}
	}
	
	
}

void printList(struct Node *temp)
{
	struct Node *p;
	p = temp;
	do
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
	while(p!=temp);
}


int main()
{
	int x;
	struct Node *circularLL,*q;
	circularLL = createLL();
	printf("\nCurrent List : ");
	printList(circularLL);
	
	printf("\n\nEnter the position at which data is to be inserted : ");
	scanf("%d",&x);
	
	circularLL = insertNode(circularLL,x);
	
	printf("\nList after Insertion : ");
	printList(circularLL);
	
}
