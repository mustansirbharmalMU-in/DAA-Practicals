#include <stdio.h>
#include <time.h>

long long factorial_recursive(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial_recursive(n - 1);
    }
}

int main()
{
    int n;
    long long result;
    clock_t start_time, end_time;
    double execution_time;

    printf("Enter a number: ");
    scanf("%d", &n);

    start_time = clock();

    result = factorial_recursive(n);

    end_time = clock();
    execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\n--- Recursive Method ---\n");
    printf("Number: %d\n", n);
    printf("Factorial: %lld\n", result);
    printf("Execution Time: %.8f seconds\n", execution_time);
    printf("Time Complexity: O(n)\n");
    printf("Space Complexity: O(n)\n");

    return 0;
}
