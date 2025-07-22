#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure definition for the stack
struct stack
{
   int top;
   int size;
   char* arr;
}; // Semicolon was missing here

// Function to check for stack underflow
int isEmpty(struct stack* ptr)
{
	if(ptr->top == -1)
	{
		return 1;
	}
    else
    {
        return 0;
    }
}

// Function to check for stack overflow
int isFull(struct stack* ptr)
{
	if(ptr->top == ptr->size - 1)
	{
		return 1;
	}
	return 0;
}

// Function to push an element onto the stack
void push(struct stack* ptr, char ch)
{
    // No direct "Stack overflow" print here; handled by balanced()
    ptr->top++;
    ptr->arr[ptr->top]=ch;
}

// Function to pop an element from the stack
char pop(struct stack* ptr)
{
    // No direct "Stack underflow" print here; handled by balanced()
    char c = ptr->arr[ptr->top];
    ptr->top--;
    return c;
}

// Function to check if the expression has balanced parentheses
void balanced(char* exp)
{
    // Allocate memory for the stack structure itself
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    if(s == NULL)
    {
        printf("Memory allocation failed for stack structure\n");
        return;
    }

    s->top = -1;
    // Set size to strlen(exp) to accommodate all characters,
    // which is a safe upper bound for parentheses storage.
    s->size = strlen(exp);
    // Allocate memory for the character array (the actual stack elements)
    s->arr = (char*)malloc(s->size * sizeof(char));
    if(s->arr == NULL)
    {
        printf("Memory allocation failed for stack array\n");
        free(s); // Free the stack structure if array allocation fails
        return;
    }

    // Loop through the expression
    for(int i = 0; i < strlen(exp); i++)
    {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            if(isFull(s))
            {
                printf("Error: Stack overflow - Too many opening parentheses for allocated stack size.\n");
                free(s->arr);
                free(s);//always free allocated memory while exiting program.
                return; // Not balanced, exit immediately
            }
            push(s, exp[i]);

        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']') // Use else if for efficiency
        {
            if(isEmpty(s))
            {
                printf("Error: Unbalanced: Closing parenthesis without a matching opening one.\n");
                free(s->arr);
                free(s);//always free allocated memory while exiting program.
                return; // Not balanced, exit immediately
            }
            char popch=pop(s);
            if(popch!=exp[i])
            {
               printf("Sequencing of parenthesis not correct. Unbalanced");
               return;
               free(s->arr);
               free(s); //free all memory and exit immediately
            }
        }
        // You can extend this to handle other types of brackets ([{}])
        // or ignore other characters like operators and operands.
    }

    // After traversing the entire expression, check if the stack is empty
    if(isEmpty(s))
    {
        printf("The expression is balanced.\n");
    }
    else
    {
        printf("The expression is not balanced. (Unmatched opening parentheses remain).\n");
    }

    // Free allocated memory to prevent memory leaks
    free(s->arr);
    free(s);
}

int main()
{
    // Declare a character array to store the expression
    // Size 10000 means it can hold 9999 characters + null terminator
    char exp[10000];
    printf("Enter the mathematical expression (Max length: 9999 characters):\n");
    // Use %9999s to prevent buffer overflow and pass 'exp' directly
    scanf("%9999s", exp);

    balanced(exp);
    return 0;
}