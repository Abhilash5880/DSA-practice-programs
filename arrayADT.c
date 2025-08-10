#include <stdio.h>
#include <stdlib.h> 

struct array {
    int* arr;
    int size;
    int max_size;
};

void display(struct array* A) {
    printf("Elements of the array:\n");
    for (int i = 0; i < A->size; i++) {
        printf("%d ", A->arr[i]);
    }
    printf("\n");
}

void append(struct array* A) {
    printf("Enter elements:\n");
    
    
    for (int i = 0; i < A->size; i++) {
        int n;
        scanf("%d", &n);
        A->arr[i] = n;
    }
    display(A);
}


struct array* insert(struct array* A) {
    int pos, n;

    if (A->size >= A->max_size) {
        printf("Maximum size reached... cannot be inserted\n");
        return A; // Return without making changes
    }

    printf("Enter position at which element is to be inserted:\n");
    scanf("%d", &pos);

    if (pos < 0 || pos > A->size) {
        printf("Invalid position.\n");
        return A;
    }

    printf("Enter element to be inserted:\n");
    scanf("%d", &n);
    
    for (int i = A->size; i > pos; i--) {
        A->arr[i] = A->arr[i - 1];
    }
    A->arr[pos] = n;    
    A->size++;
    display(A);
    return A;
}


struct array* delete(struct array* A)
{
    A->size--;
    display(A);
}

int main() {
    // Declare the struct variable
    struct array A;
    int n;

    // Set the max_size
    A.max_size = 10000;
    
    // Dynamically allocate memory for the array
    // This is a crucial step that was missing
    A.arr = (int*)malloc(A.max_size * sizeof(int));
    
    // Check if memory allocation was successful
    if (A.arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit with an error code
    }

    printf("Enter the total number of elements (max elements 9999):\n");
    scanf("%d", &n);
    
  
    A.size = n;
    append(&A);
    insert(&A);
    delete(&A);
    free(A.arr);
    return 0;
}