#include<stdio.h>
#include<stdlib.h>

struct stack
{
	int size;
	int top;
	int *arr;
}; // Added a semicolon here

int isEmpty(struct stack* ptr) // to check for stack underflow
{
	if(ptr->top == -1)
	{
		return 1;
	}
	return 0;
}

int isFull(struct stack* ptr) // to check for stack overflow
{
	if(ptr->top == ptr->size - 1)
	{
		return 1;
	}
	return 0;
}

void push(struct stack* ptr) 
{
	if(isFull(ptr))
	{
		printf("Stack Overflow! Cannot push more elements.\n"); // Added newline for better formatting
	}
	else
	{
		int v;
		printf("Enter the element to push: "); // Added newline for better formatting
		scanf("%d", &v);
		ptr->top++;
		ptr->arr[ptr->top] = v;
		printf("Element %d pushed to stack.\n", v); // Confirmation message
	}
}

int pop(struct stack* ptr) // Removed extra semicolon
{
	if(isEmpty(ptr))
	{
		printf("Stack Underflow! Cannot pop from an empty stack.\n"); // Added newline for better formatting
		return -1; // Return a sentinel value for error
	}
	else
	{
		int val = ptr->arr[ptr->top]; // Corrected array indexing
		ptr->top = ptr->top - 1;
		printf("Element %d popped from stack.\n", val); // Added %d to print popped value and newline
		return val;
	}
}

void display(struct stack* ptr) // Removed extra semicolon and added ptr as argument
{
    if (isEmpty(ptr)) {
        printf("Stack is empty. Nothing to display.\n");
        return;
    }
	printf("Stack elements:\n"); // Added header for clarity
	for(int i = 0; i <= ptr->top; i++) // Loop condition changed to include ptr->top
	{
	 	printf("Element at index %d : %d\n", i, ptr->arr[i]); // Added newline
	}
	printf("End of stack.\n"); // More descriptive message
}

void peek(struct stack* ptr)
{
	int x;
	printf("Enetr the element index");
	scanf("%d",&x);

	if(x>(ptr->top) || x<0)
	{
		printf("Element not available/invalid index\n");
	}
	else
	{
        printf("Element at position %d : %d", x, ptr->arr[x]);
	}
}

int main()
{
	int n;
	int x = -1; // Initialize x to a non-zero value to enter the loop
	printf("Enter the max size of the stack: "); // Added newline for better formatting
	scanf("%d", &n);
	
	struct stack* s = (struct stack*)malloc(sizeof(struct stack)); // Dynamically allocate memory for the stack structure itself
    if (s == NULL) {
        printf("Memory allocation failed for stack structure.\n");
        return 1;
    }

	s->size = n;
	s->top = -1;
	s->arr = (int*)malloc(s->size * sizeof(int));
    if (s->arr == NULL) {
        printf("Memory allocation failed for stack array.\n");
        free(s); // Free the previously allocated stack structure
        return 1;
    }

	while(x != 0)
	{
		printf("\nEnter 1 to PUSH\nEnter 2 to POP\nEnter 3 to display stack elements\nEnter 4 to display at specific index\nEnter 0 to end program\n");
		printf("Your choice: ");
		scanf("%d", &x);
		
		if(x == 1)
		{
			push(s);
		}
		else if(x == 2)
		{
		 	pop(s);	
		}
		else if(x == 3)
		{
			display(s); // Passed 's' as an argument
		}
		else if(x==4)
		{
            peek(s);
		}
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
    free(s->arr); // Free the dynamically allocated array
    free(s); // Free the dynamically allocated stack structure
	return 0;
}
