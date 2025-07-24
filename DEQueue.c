// will be implemented as a circular array
#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int size;
    int f;
    int b;
    int *arr;
};

int isFull(struct queue* Q)
{
  if((Q->b+1)%Q->size==Q->f) //circular increment
  {
    return 1;
  }
  return 0;  
}

int isEmpty(struct queue* Q)
{
    if(Q->b==Q->f)
    {
       return 1;
    }
    return 0;
}

void enqueueF (struct queue* Q) //insertion from front
{
    if(isFull(Q))
    {
        printf("Queue Overflow. Cannot add elements.\n");
    }

    else
    {
        int val;
        printf("Enter value to add to queue :\n");
        scanf("%d",&val);
        Q->f=(Q->f-1)%Q->size; //circular incremenet  //opration being done at front so 'f' will be changed
        Q->arr[Q->f]=val;
        printf("Element %d added to the queue.\n",val);
    }
}

void enqueueR (struct queue* Q) //insertion from rear //the normal way
{
    if(isFull(Q))
    {
        printf("Queue Overflow. Cannot add elements.\n");
    }

    else
    {
        int val;
        printf("Enter value to add to queue :\n");
        scanf("%d",&val);
        Q->b=(Q->b+1)%Q->size; //circular incremenet
        Q->arr[Q->b]=val;
        printf("Element %d added to the queue.\n",val);
    }
}

int dequeueF (struct queue* Q) //deletion from front normal way
{
    if(isEmpty(Q))
    {
        printf("Queue underflow. Nothing to dequeue\n");
    }
    else
    {
        int val;
        Q->f=(Q->f+1)%Q->size;
        val=Q->arr[Q->f];
        printf("Element %d removed from queue.\n",val);
        return val;
    }
}

int dequeueR (struct queue* Q) //deletion from rear
{
    if(isEmpty(Q))
    {
        printf("Queue underflow. Nothing to dequeue\n");
    }
    else
    {
        int val;
        val=Q->arr[Q->b];
        Q->b=(Q->b-1)%Q->size;
        printf("Element %d removed from queue.\n",val);
        return val;
    }
}

void display(struct queue* Q)
{
    if(isEmpty(Q))
    {
        printf("Queue is empty. Nothing to display.\n");
        return;
    }
    printf("Current Queue elements :\n");
    for(int i=Q->f+1; i<=Q->b; i++)
    {
        printf("Element at %d of queue : %d\n",i,Q->arr[i]);
    }
}

int main()
{ 
    struct queue* Q=(struct queue*)malloc(sizeof(struct queue));
    if (Q==NULL) 
    {
       printf("Memory allocation failed for Queue structure.\n");
       return 1; //indicate error
    }
    int s,y;
    int x=-1; //initialize to a non-0 valeu to enter the loop
    printf("Enter the size of the queue :\n");
    scanf("%d",&s);
    Q->size=s;
    Q->f=Q->b=-1; //no element is present when both are same/equal to -1
    Q->arr=(int*)malloc(Q->size*sizeof(int));
    if (Q->arr == NULL) 
    {
       printf("Memory allocation failed for Queue array.\n");
       free(Q); // Free the previously allocated stack structure
       return 1;
    }

    while (x != 0)
    {
        printf("\n--- Queue Operations ---\n"); // FIX: Changed to Queue Operations
        printf("Enter 1 to enqueue (add to queue) (**Front insertion can be till front index is 0; since this is a circular queue, -1 index is invalid. It is just to show that index has not been moved even once**)\n");
        printf("Enter 2 to dequeue (remove from queue)\n");
        printf("Enter 3 to display queue elements\n");
        printf("Enter 0 to exit program\n");
        printf("Enter your choice: ");
        scanf("%d", &x);

        switch (x)
        {
            //case 1 for insertion
            case 1: //in insertion, f should not no go beyong 0(since if f is -1, then either at 0 element is there or queue is empty)
                printf("Enter 1 to insert from rear\nEnter 2 to insert from front.\n");
                scanf("%d",&y);
                if(y==1)
                {
                    enqueueR(Q);
                }
                if(y==2)
                {
                    if(y==2 && Q->f>0)
                    {
                        enqueueF(Q);
                    }
                    else
                    {
                        printf("Front of queue is blocked. Can only be inserted from rear end\n");
                        enqueueR(Q);
                    }
                }
                else
                {
                    printf("Invalid choice");
                }
                break;
            //case 2 for deletion    
            case 2:
                printf("Enter 1 to delete from rear\nEnter 2 to delete from front.\n");
                scanf("%d",&y);
                if(y==1)
                {
                    dequeueR(Q);
                }
                else if(y==2)
                {
                    dequeueF(Q); //normal case
                }
                else
                {
                    printf("Invalid choice");
                }
                break;
            case 3:
                display(Q);
                break;
            case 4:
                printf("Front Index : %d",Q->f);
                break;
            case 5:
                printf("Back Index : %d", Q->b);
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

	printf("Program exited successfully.\n"); // Added newline
    free(Q->arr); // Free the dynamically allocated array
    free(Q); // Free the dynamically allocated stack structure
	return 0;
}


