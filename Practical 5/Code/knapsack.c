#include <stdio.h>
#include <time.h>

/*
   0/1 Knapsack using Dynamic Programming
   For each item: either take it or skip it
*/
int knapsack(int weights[], int values[], int n, int capacity)
{
    int dp[n + 1][capacity + 1];
    int i, w;

    // fill table with 0
    for (i = 0; i <= n; i++)
        for (w = 0; w <= capacity; w++)
            dp[i][w] = 0;

    // fill DP table
    for (i = 1; i <= n; i++)
    {
        for (w = 1; w <= capacity; w++)
        {
            // if item can fit in knapsack
            if (weights[i - 1] <= w)
            {
                int take = values[i - 1] + dp[i - 1][w - weights[i - 1]];
                int skip = dp[i - 1][w];

                // choose better option
                if (take > skip)
                    dp[i][w] = take;
                else
                    dp[i][w] = skip;
            }
            else
            {
                // item too heavy, skip it
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main()
{
    int n, capacity, i;
    clock_t start, end;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int weights[n], values[n];

    printf("Enter weights of %d items:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &weights[i]);

    printf("Enter profits of %d items:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &values[i]);

    printf("Enter max weight (capacity): ");
    scanf("%d", &capacity);

    start = clock();
    int max_profit = knapsack(weights, values, n, capacity);
    end = clock();

    printf("\nWeights: ");
    for (i = 0; i < n; i++)
        printf("%d ", weights[i]);

    printf("\nProfits: ");
    for (i = 0; i < n; i++)
        printf("%d ", values[i]);

    printf("\nMax weight: %d\n", capacity);
    printf("Maximum profit: %d\n", max_profit);
    printf("Execution Time: %.8f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);
    printf("\nTime Complexity: O(n * W)\n");
    printf("Space Complexity: O(n * W)\n");

    return 0;
}
