#include<stdio.h>
#include<stdlib.h>

typedef struct array
{
    int max_size;    
    int size;
    int *arr;

} array;

void countSort (struct array* A)
{
    //finding the maximum element  
    int max=A->arr[0];
    for (int i=1; i<A->size; i++)
    {
        if(A->arr[i]>max)
        {
            max=A->arr[i];
        }
    }
    int a[max+1];
    //initialize to 0;
    for (int i=0; i<max+1; i++)
    {
        a[i]=0;
    }
    //adding the frequency of each element starting from 0 on the count array
    for(int i=0;i<A->size;i++)
    {
        a[A->arr[i]]=a[A->arr[i]]+1;
    }
    //traversing through the count array to display-
    int arr_ind=0;
    for(int i=0;i<max+1;i++)
    {
        if(a[i]==0)
        {
            continue;
        }

        int ind=0;
        while(ind!=a[i])
        {
            A->arr[arr_ind]=i;
            ind++;
            arr_ind++;
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
    countSort(A);
    printf("Sorted array :\n");
    for (int i = 0; i < A->size; i++) 
    {
        printf("%d ",(A->arr[i])); // Read elements into the array
    }
}