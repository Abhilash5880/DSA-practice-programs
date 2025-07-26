#include<stdio.h>
#include<stdlib.h>

typedef struct array
{
    int max_size;
    int size;
    int *arr;
}array;

int partition (struct array* A)
{
    for (int k=0; k<A->size-1; k++)
    {
        int pivot=A->arr[k]; //storing the Initial pivots index;
        int i=k+1; //will start from the very next element after pivot
        
        int j=A->size-1; //will start from last index
        int temp;
        do
        {
            while(A->arr[i]<=pivot) //finds the very next element that is higher  
            //compared to pivot and keeps on doing it as long as this condition is not false
            {
               i++;
            }
            while(A->arr[j]>pivot)
            //get the very next lower value in the unsorted list compared to pivot 
            //and keeps on doing it as long as this condition n is not false
            {
               j--;
            }
            //also indexes are updated
            if(i<j)
            //if this condition is true....then number higher than pivot is closer to it
            //compared to number lower to it....
            //so the elements are exchanged
            {
                temp=A->arr[i];
                A->arr[i]=A->arr[j];
                A->arr[j]=temp;
            }
        }while(i<j);
        //swap A[j] which was storing lower values directly with pivot 
        temp=A->arr[k];
        A->arr[k]=A->arr[j];
        A->arr[j]=temp;
        return j;
    }
}

void quickSort(array* A, int low, int high)
{
    int partitionIndex; // Index of pivot after partition

    if (low < high)
    {
        partitionIndex = partition(A); 
        quickSort(A, low, partitionIndex - 1);  // sort left subarray 
        quickSort(A, partitionIndex + 1, high); // sort right subarray
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
    quickSort(A, 0, (A->size-1));
    printf("Sorted array :\n");
    for (int i = 0; i < A->size; i++) 
    {
        printf("%d ",(A->arr[i])); // Read elements into the array
    }
}
