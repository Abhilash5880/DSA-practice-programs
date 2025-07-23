#include<stdio.h>
#include<stdlib.h>
// Define the Node structure
typedef struct Node
{
    int data;
    struct Node* next;
} Node; // Using typedef for cleaner code (Node instead of struct Node)

// Function to check if the queue is logically full (based on max size)
// For a linked list, this is only true if a max size is enforced.
int isFull(int current_elements_count, int max_size)
{
    if (max_size != -1 && current_elements_count >= max_size) // -1 means no max size limit
    {
        return 1; // Queue is full
    }
    return 0; // Queue is not full
}

// Function to check if the queue is empty
int isEmpty(Node* head)
{
    if(head == NULL) // Queue is empty if head is NULL
    {
        return 1;
    }
    return 0;
}

// Function to add an element to the queue (enqueue)
// Returns the new head of the queue and updates element count
Node* enqueue(Node* head, Node** tail_ptr, int* elements_count_ptr, int max_size)
{
    if (isFull(*elements_count_ptr, max_size))
    {
        printf("Queue is Full. Cannot add element.\n");
        return head; // Return current head, no change
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed. Cannot add element.\n");
        return head; // Return current head, memory error
    }

    int val;
    printf("Enter element to add to queue: ");
    scanf("%d", &val); 
    newNode->data = val; //setting up newNode to be attached to the original list
    newNode->next = NULL;

    if (head == NULL) // If queue is empty, new node is both head and tail
    {
        head = newNode;
        *tail_ptr = newNode; // Update tail pointer
    }
    else // Add to the end of the queue
    {
        (*tail_ptr)->next = newNode; // Link current tail to new node
        *tail_ptr = newNode; // Update tail pointer to new node
    }

    (*elements_count_ptr)++; // Increment element count (not the variable but the address)
    printf("Element %d is added to the queue.\n", val);
    return head;
}

// Function to remove an element from the queue (dequeue)
// Returns the new head of the queue and updates element count
int dequeue(Node** head_ptr, Node** tail_ptr, int* elements_count_ptr)
{
    if (isEmpty(*head_ptr)) // FIX: Correctly call isEmpty with head
    {
        printf("No elements in the queue. Nothing to dequeue.\n");
        return -1; // Return a sentinel value indicating failure
    }
    else
    {
        Node* temp = *head_ptr; // Store current head
        int val = temp->data; // Get data from head
        *head_ptr = (*head_ptr)->next; // Move head to next node

        if (*head_ptr == NULL) // If queue becomes empty after dequeue
        {
            *tail_ptr = NULL; // Tail also becomes NULL
        }

        free(temp); // Free the dequeued node
        (*elements_count_ptr)--; // Decrement element count
        printf("Element %d removed from queue.\n", val);
        return val; // Return the dequeued value
    }
}

// Function to display elements of the queue
void display(Node* head)
{
    if (isEmpty(head)) // FIX: Correctly call isEmpty with head
    {
        printf("Queue is empty. Nothing to display.\n");
        return;
    }
    Node* ptr = head;
    int x = 0;
    printf("Current Queue elements:\n");
    while(ptr != NULL)
    {
        printf("Element at position %d = %d\n", x, ptr->data);
        ptr = ptr->next;
        x++;
    }
}

int main()
{
    Node* head = NULL; // Front of the queue
    Node* tail = NULL; // Rear of the queue (important for O(1) enqueue)
    int elements_count = 0; // To keep track of the number of elements (replaces backd)
    int size; // Max size of the queue (if -1, no limit)

    printf("Enter the maximum size of the queue (-1 for no limit): ");
    scanf("%d", &size); // FIX: Added & for scanf

    int choice = -1; // Initialize to a non-zero value to enter the loop

    while (choice != 0)
    {
        printf("\n--- Queue Operations ---\n"); // FIX: Changed to Queue Operations
        printf("Enter 1 to enqueue (add to queue)\n");
        printf("Enter 2 to dequeue (remove from queue)\n");
        printf("Enter 3 to display queue elements\n");
        printf("Enter 0 to exit program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                head = enqueue(head, &tail, &elements_count, size);
                break;
            case 2:
                dequeue(&head, &tail, &elements_count); // Dequeue modifies head directly via pointer
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

    // Free all dynamically allocated nodes before exiting
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    printf("Program exited successfully, all memory freed.\n");

    return 0;
}