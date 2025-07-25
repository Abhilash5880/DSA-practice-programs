#include<stdio.h>
#include<stdlib.h>

typedef struct array
{
  int max_size;
  int size;
  int *arr;
}array;

struct array* bubble(struct array* A)
{
   for (int i=0; i<A->size-1; i++) //will conduct 'a->size-1' number of of passes to arrange each element
   { //'size-1' passes are enough. (because by the end, the lowest integer will be at index 0)
       for(int j=0; j<(A->size)-1-i; j++) //will run till the 2nd last element of each 'pass' since in each pass, the largest element will be sent at the end

       {
           if(A->arr[j]>A->arr[j+1])
           {
               int temp = A->arr[j]; // FIX: Use a single temporary variable for swap
               A->arr[j] = A->arr[j+1];
               A->arr[j+1] = temp;
           }
       }
   }
   return A;    
}

struct array* append(struct array* A)
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
    struct array* A = (struct array*)malloc(sizeof(struct array));
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
    A=append(A);
    A=bubble(A);
    printf("Sorted array :\n");
    for (int i = 0; i < A->size; i++) 
    {
        printf("%d ",(A->arr[i])); // Read elements into the array
    }
}