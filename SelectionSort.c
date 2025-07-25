#include <stdio.h> // For potential printf/scanf in a full program
#include <stdlib.h> // For potential malloc/free in a full program


 typedef struct array
{
    int max_size;    
    int size;
    int *arr;

} array;

// The standard Selection Sort algorithm function
void SSort_Standard(array* A) // Returns void because it modifies the array in-place
{
    // Outer loop: iterate through the unsorted portion of the array
    // We only need to go up to A->size - 1 because the last element
    // will naturally be in place after n-1 iterations.
    for (int i = 0; i < A->size - 1; i++)
    {
        // Assume the current element is the minimum of the unsorted part
        // We store its INDEX, not just its value.
        int min_idx = i;

        // Inner loop: find the index of the actual minimum element
        // in the remaining unsorted portion (from i+1 to the end)
        for (int j = i + 1; j < A->size; j++)
        {
            // If we find an element smaller than the current minimum
            if (A->arr[j] < A->arr[min_idx])
            {
                // Update min_idx to point to the new minimum's position
                min_idx = j;
            }
        }

        // After the inner loop completes, min_idx holds the index of the
        // smallest element in the entire unsorted segment A->arr[i...size-1].

        // Now, swap the smallest found element with the element at the current position 'i'.
        // This places the smallest element into its correct sorted position.
        // Optimization: Only swap if the minimum element is not already at position 'i'
        if (min_idx != i)
        {
            int temp = A->arr[i];
            A->arr[i] = A->arr[min_idx];
            A->arr[min_idx] = temp;
        }
    }
}

array* append(array* A)
{
    int x;
    printf("Enter elements into the array(press ENTER to append each element) :\n");
    for(int i=0;i<A->size; i++)
    {
        scanf("%d",&x);
        A->arr[i]=x;
    }
    return A;
}

int main()
{
    array* A = ( array*)malloc(sizeof(array));
    //allocating memory for the struct array itself
    int n;
    if(A==NULL)
    {
        printf("Memory allocation failure\n");
        exit(EXIT_FAILURE); //exit program immediately
    }
    A->max_size=10000;
    printf("Enter no. of elements in the array(max size 10000) : \n");
    scanf("%d",&n);
    if (n <= 0 || n > A->max_size) {
        printf("Invalid number of elements entered.\n");
        free(A); // Free the allocated struct before exiting
        exit(EXIT_FAILURE);
    }
    A->size=n;
    A->arr=(int*)malloc(A->size*sizeof(int));
    append(A);
    SSort_Standard(A);
    printf("Sorted array :\n");
    for (int i = 0; i < A->size; i++) 
    {
        printf("%d ",(A->arr[i])); // Read elements into the array
    }
}