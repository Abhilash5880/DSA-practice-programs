#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node* insertAtEnd(Node* head)
{
    printf("Enter number of elements :\n");
    int n;
    scanf("%d",&n);
    
    printf("Enter the elements :\n");
    int x;

    if(head==NULL && n!=0)
    {
        Node*ptr=(Node*)malloc(sizeof(Node));
        scanf("%d",&x); 
        ptr->data=x;
        ptr->next=NULL;
        head=ptr;
    }
    Node*p=head;
    for (int i=0;i<n-1;i++)
    {
            Node* ptr=(Node*)malloc(sizeof(Node));
            scanf("%d",&x);
            while(p->next!=NULL)
            {
                p=p->next; //traversing to the last element
            }
            ptr->data=x;
            ptr->next=NULL;
            p->next=ptr;
    }
    return head;
}

void display(Node* head)
{
    Node*p=head;
    while(p!=NULL)
    {
        printf("%d",p->data);
        p=p->next;
    }
}
int main()
{
    Node* head=NULL;
    head=insertAtEnd(head);
    display(head);
    return 0;
    
}