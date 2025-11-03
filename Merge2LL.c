#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

struct Node* insertAtEnd(struct Node* head, int x)
{
	struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    if(ptr==NULL)
    {
    	printf("Memory not allocated :\n");
    	return head;
    }
	ptr->data=x;
    ptr->next=NULL;
    if(head==NULL)
    {
    	printf("Success! Head element %d added.\n",x);
        return ptr;
	}
    else
    {
    	struct Node* p=head;
    	while(p->next!=NULL)
    	{
    		p=p->next;
    	}
    	p->next=ptr;
    }
	printf("Success! Element %d added.\n ",x);
	return head;
}

void display(struct Node* head)
{
	int n=-1;
	if(head==NULL)
	{
		printf("linked list is empty");
		return n;
	}
	struct Node*p=head;
    while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
		n++;
	}	
	printf("\n");
	
}

int main()
{
    struct Node* head1=NULL;
    struct Node* head2=NULL;
    int n1;
    int n2;
    int x;
    printf("Enter number of nodes for LL 1:");
    scanf("%d",&n1);
    struct Node* curr=NULL;
    
    for (int i=0; i<n1; i++)
    {
        printf("Enter the value : ");
        scanf("%d",&x);
        head1=insertAtEnd(head1,x);
    }

    printf("Enter number of nodes for LL 2:");
    scanf("%d",&n2);

    for (int i=0; i<n2; i++)
    {
        printf("Enter the value : ");
        scanf("%d",&x);
        head2=insertAtEnd(head2,x);
    }

    struct Node*p=head1;
    while(p->next!=NULL)
    	{
    		p=p->next;
    	}
    p->next=head2;
    display(head1);
    return 0;
}