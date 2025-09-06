#include <stdio.h>

int main() {
    int r1, c1, r2, c2; // Rows and columns for matrices
    int A[10][10], B[10][10], C[10][10]; // Matrices, with a maximum size of 10x10
    int i, j, k;

    printf("Enter rows and columns for the first matrix (e.g., 2 3): ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns for the second matrix (e.g., 3 2): ");
    scanf("%d %d", &r2, &c2);

    // Check if matrix multiplication is possible
    if (c1 != r2) {
        printf("Error: Matrix multiplication is not possible. The number of columns in the first matrix must equal the number of rows in the second matrix.\n");
        return 1;
    }

    // Input elements for the first matrix
    printf("\nEnter elements of the first matrix:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            printf("Enter element a[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    // Input elements for the second matrix
    printf("\nEnter elements of the second matrix:\n");
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            printf("Enter element b[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    // Initialize the resultant matrix with zeros
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            C[i][j] = 0;
        }
    }

    // Perform matrix multiplication
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            for (k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Print the resultant matrix
    printf("\nResultant Matrix:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}