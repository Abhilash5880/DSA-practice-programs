#include<stdio.h>
#include<stdlib.h>

typedef struct array
{
    int max_size;
    int size;
    int *arr;
}array;

void insertion (struct array* A)
{
    for(int i=1; i<A->size; i++) //starts traversing from index 1 to last index
    {
       int key=A->arr[i];
       int j=i-1;//start comparing form the element just before the key
       // Move elements of A->arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while(j >= 0 && A->arr[j] > key)
        {
            A->arr[j+1] = A->arr[j]; // Shift element to the right
            j--;                     // Move to the left
        }
        A->arr[j+1] = key; // Place the key in its correct sorted position
    }
}
void add_elements(struct array* A)
{
    printf("Enter elements into the array(press ENTER to append each element) :\n");
    for(int i=0;i<A->size; i++)
    {
        scanf("%d",&A->arr[i]);//read elements directly into the array
    }
}

int main()
{
    struct array* A=(struct array*)malloc(sizeof(struct array));
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
        exit(EXIT_FAILURE); //exit program immediately
    }

    A->size=n;
    A->arr=(int*)malloc(A->size*sizeof(int));

    add_elements(A);
    insertion(A);
    
    printf("Sorted array :\n");
    for (int i = 0; i < A->size; i++) 
    {
        printf("%d ",(A->arr[i])); // Read elements into the array
    }
}
