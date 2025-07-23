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

void enqueue (struct queue* Q)
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

int dequeue (struct queue* Q)
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
    int s;
    int x=1; //initialize to a non-0 valeu to enter the loop
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

    while(x != 0)
	{
		printf("\nEnter 1 to add to queue\nEnter 2 to remove form queue\nEnter 3 to display queue elements\nEnter 0 to end program\n");
		printf("Your choice: ");
		scanf("%d", &x);
		
		if(x == 1)
		{
			enqueue(Q);
		}
		else if(x == 2)
		{
		 	dequeue(Q);	
		}
		else if(x == 3)
		{
			display(Q); // Passed 's' as an argument
		}
		/*else if(x==4)
		{
            peek(s);
		}*/
		else if(x == 0)
		{ 
		 	break;	
		}
		else
		{
			printf("Invalid choice. Please enter a correct value.\n"); 
		}
	}
	printf("Program exited successfully.\n"); // Added newline
    free(Q->arr); // Free the dynamically allocated array
    free(Q); // Free the dynamically allocated stack structure
	return 0;
}


