#include <stdio.h>
#include <time.h>

long long factorial_iterative(int n)
{
    long long result = 1;
    int i;

    for (i = 1; i <= n; i++)
    {
        result = result * i;
    }

    return result;
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

    result = factorial_iterative(n);

    end_time = clock();
    execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\n--- Iterative Method ---\n");
    printf("Number: %d\n", n);
    printf("Factorial: %lld\n", result);
    printf("Execution Time: %.8f seconds\n", execution_time);
    printf("Time Complexity: O(n)\n");
    printf("Space Complexity: O(1)\n");

    return 0;
}
