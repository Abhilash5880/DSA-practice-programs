#include<stdio.h>
#include<stdlib.h>
//https://g.co/gemini/share/660617e19137
typedef struct array
{
  int max_size;
  int size;
  int *arr;
}array;

array* SSort(array* A)
{
    for(int i=0; i<A->size-1; i++)
    {
        int min =A->arr[i];
        int j=i+1;
        while(j<A->size)
        {
            if(A->arr[j] < min)
            {
                int temp=A->arr[j];
                A->arr[j]=min;
                min=temp;
            }
            j++;
        }
        A->arr[i]=min;
    }
    return A;
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
    A=append(A);
    A=SSort(A);
    printf("Sorted array :\n");
    for (int i = 0; i < A->size; i++) 
    {
        printf("%d ",(A->arr[i])); // Read elements into the array
    }
}