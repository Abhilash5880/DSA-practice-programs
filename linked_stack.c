#include<stdio.h>
#include<stdlib.h> // For malloc and free

// Define the Node structure
typedef struct Node
{
    int data;
    struct Node* next;
} Node; // Using typedef for simplicity

// Function to push an element onto the stack
// Returns the new head of the stack
struct Node* push(struct Node* head)
{
    int x;
    printf("Enter the element to push: ");
    scanf("%d", &x);

    // Allocate memory for the new node
    struct Node* new_Node = (struct Node*)malloc(sizeof(Node));
    if (new_Node == NULL) { // Always check for malloc failure
        printf("Memory allocation failed!\n");
        return head; // Return original head on failure
    }

    new_Node->data = x;
    new_Node->next = head; // New node points to the old head
    head = new_Node;       // Head now points to the new node

    printf("Element %d is pushed to stack\n", x);
    return head; // Return the updated head
}

// Function to pop an element from the stack
// Returns the new head of the stack
struct Node* pop(struct Node* head)
{
    if (head == NULL)
    {
        printf("Stack underflow: Stack is empty\n");
        return NULL; // Return NULL as stack is empty
    }
    else
    {
        struct Node* temp = head; // Store the current head
        int popped_data = temp->data; // Get data to be popped
        head = head->next;          // Move head to the next node
        free(temp);                 // Free the old head node
        printf("Element %d is popped from stack\n", popped_data);
        return head; // Return the updated head
    }
}

// Function to display the elements of the stack
void display(struct Node* head) // head is passed by value, which is fine for display
{
    if (head == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    struct Node* current = head; // Start traversal from the current head
    int position = 0;
    printf("Stack elements (from top to bottom):\n");
    while (current != NULL) // Iterate until the end of the list
    {
        printf("Element at position %d: %d\n", position, current->data);
        current = current->next;
        position++;
    }
    return;
}


// Main function to run the stack operations
int main()
{
    struct Node* head = NULL; // Initialize head of the stack to NULL
    int choice = -1;

    while (choice != 0)
    {
        printf("\n--- Stack Operations ---\n");
        printf("Enter 1 to push\n");
        printf("Enter 2 to pop\n");
        printf("Enter 3 to display linked stack\n");
        printf("Enter 0 to exit program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                head = push(head); // Update head with the returned new head
                break;
            case 2:
                if (head != NULL) { // Only pop if stack is not empty
                    head = pop(head); // Update head with the returned new head
                } else {
                    printf("Stack underflow: Cannot pop from an empty stack.\n");
                }
                break;
            case 3:
                display(head);
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    // Free any remaining nodes before exiting
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    printf("Program exited successfully, all memory freed.\n");

    return 0;
}