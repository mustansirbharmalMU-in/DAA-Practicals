#include <stdio.h>
#include <limits.h>
#include <time.h>

/*
   Matrix Chain Multiplication using Dynamic Programming
   Find minimum cost to multiply a chain of matrices
*/
int matrixChainOrder(int p[], int n)
{
    // n = number of matrices = len(p) - 1
    int dp[n][n];
    int i, j, k, length, cost;

    // cost of one matrix is 0
    for (i = 0; i < n; i++)
        dp[i][i] = 0;

    // length = size of chain (2, 3, 4, ...)
    for (length = 2; length <= n; length++)
    {
        for (i = 0; i < n - length + 1; i++)
        {
            j = i + length - 1;
            dp[i][j] = INT_MAX;

            // try every split position k
            for (k = i; k < j; k++)
            {
                cost = dp[i][k] + dp[k + 1][j]
                       + p[i] * p[k + 1] * p[j + 1];

                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }

    return dp[0][n - 1];
}

int main()
{
    int m, i;
    clock_t start, end;

    // m = number of dimension values
    // for 5 matrices we need 6 numbers
    printf("Enter number of dimension values: ");
    scanf("%d", &m);

    int dimensions[m];

    printf("Enter %d dimensions:\n", m);
    for (i = 0; i < m; i++)
        scanf("%d", &dimensions[i]);

    int n = m - 1;   // number of matrices

    start = clock();
    int min_cost = matrixChainOrder(dimensions, n);
    end = clock();

    printf("\nMatrix Chain Multiplication\n");
    printf("--------------------------------\n");
    printf("Matrix dimensions: ");
    for (i = 0; i < m; i++)
        printf("%d ", dimensions[i]);
    printf("\n");
    printf("Minimum number of scalar multiplications: %d\n", min_cost);
    printf("Execution time: %.8f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);
    printf("\nTime Complexity: O(n^3)\n");
    printf("Space Complexity: O(n^2)\n");

    return 0;
}
