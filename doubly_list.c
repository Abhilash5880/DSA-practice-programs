#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *prev;
	struct node *next;
};

struct node* insertatend(struct node* head, int x)
{
	struct node* ptr=(struct node*)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("Memory allocation failure! Cannot add element %d.\n",x);
		return head;
	}
	ptr->data=x;
	ptr->next=NULL;
	if(head==NULL)
	{
		ptr->prev=NULL;
		printf("Success! Head element %d added.\n", x);
		return ptr;
	}
	else
	{
	    struct node* p=head;
	    while(p->next!=NULL)
	    {
		   p=p->next;
	    }
	    ptr->prev=p;
	    p->next=ptr;
    }
	printf("Success! Element is added.\n");
	return head;
}
void traversal(struct node* head)
{
	struct node* p=head;
	if(p==NULL)
	{
		printf("Doubly linked list is empty\n");
		return;
	}
	while(p!=NULL)
	{
		printf("Element is : %d\n",p->data);
		p=p->next;
	}
	printf("NULL\n");
}
struct node* insertatindex (struct node* head)
{
	int index,x,i=0;
	printf("enter the index at which to insert element :\n");
	scanf("%d",&index);
	printf("enter the element :\n");
	scanf("%d",&x);
	
	struct node* ptr=(struct node*)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("Memory allocation to insert node failed! Cannot add element %d.\n",x);
		return head;
	}
	ptr->data=x;
	ptr->next=NULL;
	ptr->prev=NULL;
	if (index == 0) 
	{
        ptr->next = head;
        if (head != NULL) 
		{ // If list is not empty, update old head's prev
            head->prev = ptr;
        }
        printf("Success! Element %d inserted at the beginning.\n", x);
        return ptr; // New node is the new head
    }
	struct node*p=head;
    for (i = 1; i < index && p != NULL; i++) 
	{
        p = p->next;
    }
    //check if given index is valid
	if (p == NULL) {
        printf("Error: Index %d is out of bounds. Cannot insert element %d.\n", index, x);
        free(ptr); // Free the allocated memory for the new node
        return head;
    }

    // Case 3: Insert at the end (p is the last node) or in the middle
    ptr->next = p->next; // New node's next points to p's original next
    ptr->prev = p;       // New node's prev points to p

    if (p->next != NULL) 
	{ // If p is not the last node, update p->next's prev
        p->next->prev = ptr;
    }
    p->next = ptr; // p's next points to the new node

    printf("Success! Element %d inserted after index %d.\n", x, index);
    traversal(head);
    return head; // Head remains the same
}

int main()
{
	
	int x,n;
	struct node* head=NULL; //Initizalize head to null
	
	printf("enter the head element(which will be the head) : \n");
	scanf("%d",&x);
    head=insertatend(head, x);//1st insertion will create head node
    
	printf("Enter the number of additional nodes in the list : \n");
	scanf("%d",&n);
	printf("Enter the elements : \n");
	for(int i=0;i<n;i++)
	{
		x=0;
		scanf("%d",&x);
		head=insertatend(head,x); //update head with the returned value
	}
	traversal(head);
	insertatindex(head);
	return 0;
}
	

