#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

int display(struct Node* head)
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
	return n;
}
//insert at end
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
//inser at first
struct Node* insertAtfirst (struct Node* head, int x)
{
	struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
	ptr->data=x;
	ptr->next=head;
	head=ptr;
	return head;
}
//insert at index
struct Node* insertAtIndex (struct Node* head, int x)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p=head;
    int i=0;
    int n=display(head);
    int index=0;
    printf("Enter the index at which to insert (starting for 0) : \n");
    scanf("%d",&index);
    if(index>n || index<0)
    {
    	printf("Index out of range...\n");
    	return head;
    }
    else
    {
    	while(i!=index-1)
    	{
    		p=p->next;
    		i++;
    	}
    	ptr->data=x;
    	ptr->next=p->next;
    	p->next=ptr;
    	return head;
    }
}
//deleting at first
struct Node* deleteFirst (struct Node* head)
{
	struct Node* ptr=head;
	head=head->next;
	free(ptr);
	return head;
}
//deleting at index
struct Node* deleteAtIndex (struct Node* head)
{
	struct Node* p=head;
	struct Node*q =head->next;
	
	int n=display(head);
    int index=0;
    printf("Enter the index at which to insert : \n");
    scanf("%d",&index);
	
	if(index>n || index<1)
    {
    	printf("Index out of range...\n");
    	return head;
    }
    else
    {
    	int i=0;
    	for(int i=0; i<index-1;i++)
	    {
		    p=p->next;
	    	q=q->next;
     	}
	    p->next=q->next;
	    free(q);
		return head;
    }
}


//delete at end
struct Node* deleteAtEnd(struct Node* head)
{
	
	if(head==NULL)
	{
		printf("No element in the linked list");
		return NULL;
	}
	//checks if head is the only node in the linked list
	if(head->next==NULL)
	{
		free(head);
		return NULL;
	}
	struct Node* p= head;
	//traverses to the 2nd last node   _____ -> _____ -> NULL
	while(p->next->next!=NULL)
	{
		p=p->next;
	}
	struct Node* lastNode=p->next;
	p->next=NULL;
	free(lastNode);
	return head;
}

int main()
{
	struct Node* head=NULL;
	int n;
	int x;
	int ch=-1;
	printf("Enter number of elements to add  to the linkd list for initialization :");
	scanf("%d",&n);
	for(int i=0; i<n;i++)
	{
	    int element;
		printf("Enter element to add : ");
		scanf("%d",&element);
		head=insertAtEnd(head,element );
	}
	int choice=-1;
	while(choice!=0)
	{
		printf("\n---Linked List operations---\n");
		printf("Enter 1 to insert\nEnter 2 to delete\nEnter 3 to display elements\nEnter 0 to exit program\nEnter your choice\n");
	    scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			
			//insertion

				printf("Enter the element to insert :\n");
				scanf("%d",&x);
				printf("\n---Insertion operations---\n");
				printf("Enter 1 to insert at first\nEnter 2 to insert at end\nEnter 3 insert at index\n");
				scanf("%d",&ch);

				//different insertion operations

				switch(ch)
				{
					case 1:
					   head=insertAtfirst(head, x);
					   printf("Element inserted at the start of linked list\n");
					   break;
					case 2:
					   head=insertAtEnd(head,x);
                       printf("Element inserted at the end of linked list\n");
					   break;
					case 3:
					   head=insertAtIndex(head,x);
					   printf("Element inserted at the specified index\n");
					   break;
				}
				ch=-1;
				break;
			
			//deletion

		    case 2:
				printf("\n---Deletion operations---\n");
				printf("Enter 1 to delete at first\nEnter 2 to delete at end\nEnter 3 delete at index\n");
				scanf("%d",&ch);

				//different insertion operations

				switch(ch)
				{
					case 1:
					   head=deleteFirst(head);
					   printf("Element deleted at the start of linked list\n");
					   break;
					case 2:
					   head=deleteAtEnd(head);
                       printf("Element deleted at the end of linked list\n");
					   break;
					case 3:
					   head=deleteAtIndex(head);
					   printf("Element deleted at the specified index\n");
					   break;
				}
				break;
		    case 3:
		    	display(head);
		    	break;
		    case 0:
		    	printf("Exiting Program...\n");
		    	break;
		    default:
		        printf("Invalid choice. Please try again.\n");
				break;	
		}	
	}
	printf("Progrm exited Succesfully\n");
	return 0;
}

