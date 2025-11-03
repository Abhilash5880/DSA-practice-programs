#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void display(struct Node* head) {
    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    struct Node* p = head;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

struct Node* insertAtEnd(struct Node* head, int x) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    if (ptr == NULL) {
        printf("Memory not allocated:\n");
        return head;
    }
    ptr->data = x;
    ptr->next = NULL;
    if (head == NULL) {
        printf("Success! Head element %d added.\n", x);
        return ptr;
    } else {
        struct Node* p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = ptr;
    }
    printf("Success! Element %d added.\n", x);
    return head;
}

struct Node* reverse(struct Node* head) {
    struct Node* curr = head;
    struct Node* prev = NULL;
    while (curr != NULL) {
        struct Node* temp = curr->next; // Store the next node
        curr->next = prev; // Reverse the pointer
        prev = curr; // Move prev forward
        curr = temp; // Move curr forward
    }
    return prev; // Returning the new head
}

int main() {
    struct Node* head = NULL;
    int n = 0;
    int x = 0;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) 
    {
        printf("Enter the value: ");
        scanf("%d", &x);
        head = insertAtEnd(head, x);
    }

    printf("Original list: ");
    display(head);

    head = reverse(head);

    printf("Reversed list: ");
    display(head); 

    return 0;
}
