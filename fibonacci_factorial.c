// A C program to demonstrate recursion for
// Fibonacci series and factorial calculation.

#include <stdio.h>

// Function to calculate the factorial of a number using recursion.
// n: The number for which to calculate the factorial.
// Returns: The factorial of n.
long long int factorial(int n) {
    // Base case: factorial of 0 or 1 is 1.
    if (n <= 1) {
        return 1;
    }
    // Recursive step: n! = n * (n-1)!
    return n * factorial(n - 1);
}

// Function to find the nth Fibonacci number using recursion.
// n: The index in the Fibonacci series (e.g., n=5 for the 5th number).
// Returns: The nth Fibonacci number.
long long int fibonacci(int n) {
    // Base cases for the Fibonacci series.
    if (n <= 1) {
        return n;
    }
    // Recursive step: F(n) = F(n-1) + F(n-2)
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int num_factorial;
    int num_fibonacci;

    // --- Factorial Calculation ---
    printf("Enter a non-negative integer to find its factorial: ");
    scanf("%d", &num_factorial);

    if (num_factorial < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        long long int result_factorial = factorial(num_factorial);
        printf("Factorial of %d is %lld.\n", num_factorial, result_factorial);
    }

    // --- Fibonacci Series Display ---
    printf("\nEnter a positive integer to display the Fibonacci series up to that term: ");
    scanf("%d", &num_fibonacci);

    if (num_fibonacci <= 0) {
        printf("The Fibonacci series can only be displayed for a positive integer.\n");
    } else {
        printf("Fibonacci Series up to term %d:\n", num_fibonacci);
        for (int i = 0; i < num_fibonacci; i++) {
            // Note: Calling fibonacci(i) inside a loop is inefficient for large numbers
            // due to redundant calculations. An iterative approach is more efficient.
            // This is just to demonstrate the recursive function's usage.
            printf("%lld", fibonacci(i));
            if (i < num_fibonacci - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }

    return 0;
}
