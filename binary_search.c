#include <stdio.h>
#include <stdlib.h>

// Define the Array Abstract Data Type (ADT)
// This structure holds the necessary information for our dynamic array.
typedef struct
{
    int size;       // Current number of elements in the array
    int max_size;   // Maximum capacity of the array
    int *arr;       // Pointer to the dynamically allocated integer array
} Array;

// Function to create and initialize the Array ADT
// It prompts the user for the maximum size and allocates memory.
void createArray(Array *a)
{
    printf("Enter the maximum size of the array: ");
    scanf("%d", &a->max_size);

    // Dynamically allocate memory for the array
    a->arr = (int *)malloc(a->max_size * sizeof(int));
    if (a->arr == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    a->size = 0; // Initially, the array is empty
}

// Function to get elements from the user
// It prompts for the actual number of elements and fills the array.
void getArrayElements(Array *a)
{
    printf("Enter the number of elements (up to %d): ", a->max_size);
    scanf("%d", &a->size);

    if (a->size > a->max_size)
    {
        printf("Error: Number of elements exceeds maximum size. Using max size.\n");
        a->size = a->max_size;
    }

    printf("Enter %d elements:\n", a->size);
    for (int i = 0; i < a->size; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &a->arr[i]);
    }
}

// Function to print the elements of the array
void printArray(Array a)
{
    printf("Array elements: ");
    for (int i = 0; i < a.size; i++)
    {
        printf("%d ", a.arr[i]);
    }
    printf("\n");
}

// A simple bubble sort function to sort the array
// Binary search requires a sorted array to work correctly.
void sortArray(Array *a)
{
    int temp;
    for (int i = 0; i < a->size - 1; i++)
    {
        for (int j = 0; j < a->size - i - 1; j++)
        {
            if (a->arr[j] > a->arr[j + 1])
            {
                // Swap elements
                temp = a->arr[j];
                a->arr[j] = a->arr[j + 1];
                a->arr[j + 1] = temp;
            }
        }
    }
}

// The core binary search algorithm implementation
// Returns the index of the element if found, otherwise returns -1.
int binarySearch(Array a, int key)
{
    int low = 0;
    int high = a.size - 1;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (a.arr[mid] == key)
        {
            return mid; // Element found, return its index
        }
        else if (key < a.arr[mid])
        {
            high = mid - 1; // Key is in the left half
        }
        else
        {
            low = mid + 1;  // Key is in the right half
        }
    }
    return -1; // Element not found
}

int main()
{
    Array myArray;
    int searchKey;
    int result;

    // 1. Create and initialize the array
    createArray(&myArray);

    // 2. Get the elements from the user
    getArrayElements(&myArray);

    printf("\nOriginal ");
    printArray(myArray);

    // 3. Sort the array for binary search
    sortArray(&myArray);
    printf("Sorted ");
    printArray(myArray);

    // 4. Get the element to search for
    printf("\nEnter the element to search for: ");
    scanf("%d", &searchKey);

    // 5. Perform binary search
    result = binarySearch(myArray, searchKey);

    // 6. Print the result
    if (result != -1)
    {
        printf("Element %d found at index %d in the sorted array.\n", searchKey, result);
    }
    else
    {
        printf("Element %d not found in the array.\n", searchKey);
    }

    // 7. Free the dynamically allocated memory
    free(myArray.arr);

    return 0;
}