#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int size;
    int f;
    int b;
    int *arr;
};

int isEmpty(struct queue* Q)
{
  if(Q->f==Q->b)
  {
    return 1;
  }
  return 0;  
}
int isFull(struct queue* Q)
{
    if(Q->b==Q->size-1)
    {
       return 1;
    }
    return 0;
}

void enqueue (struct queue* Q)
{
    if(isFull(Q))
    {
        printf("Queue overflow\n");
        return;
    }
    else
    {
        int n;
        printf("Enter value to add to queue\n");
        scanf("%d",&n);
        Q->b++; //incrementing back pointer first
        Q->arr[Q->b]=n; //then adding element the new position
        printf("Element %d added to the queue\n",n);
        return;
    }
}

int dequeue(struct queue* Q)
{
    if(isEmpty(Q))
    {
        printf("Queue underflow\n");
        return -1;
    }
    else
    {
        int a;
        Q->f++; //increment front pointer
        a=Q->arr[Q->f]; //get the element fron teh new front position
        printf("Element %d is removed from queue\n",a);
        return a;        
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