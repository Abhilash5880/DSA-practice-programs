#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
    int size; // addding a 'size' to make the queue LIMITED
    int backInd; //adding an indexing to make the list not exceed it's size (it will initialize with -1)
};

int isFull(struct Node* head)
{
    if(head->backInd==head->size-1)
    {
        printf("Queue Overflow\n");
        return 1;
    }
    return 0;
}

int isEmpty(struct Node* head)
{
    if(head->backInd==-1)
    {
        printf("Queue Underflow\n");
        return 1;
    }
    return 0;
}

struct Node* inqueue(struct Node* head) //inserting at the last Node of the Linked List
{
    
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node* head;
    while
    
    
    

}
