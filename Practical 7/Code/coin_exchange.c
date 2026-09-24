#include <stdio.h>
#include <limits.h>
#include <time.h>

/*
   Coin Exchange using Dynamic Programming
   Find minimum number of coins to make given amount
*/
int coinChange(int coins[], int n, int amount)
{
    int dp[amount + 1];
    int i, j;

    // initialize: impossible amounts = very large number
    for (i = 0; i <= amount; i++)
        dp[i] = INT_MAX;

    // 0 coins needed to make amount 0
    dp[0] = 0;

    // for every amount from 1 to target
    for (i = 1; i <= amount; i++)
    {
        // try every coin
        for (j = 0; j < n; j++)
        {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX)
            {
                int option = dp[i - coins[j]] + 1;

                if (option < dp[i])
                    dp[i] = option;
            }
        }
    }

    // if still INT_MAX, amount cannot be formed
    if (dp[amount] == INT_MAX)
        return -1;

    return dp[amount];
}

int main()
{
    int n, amount, i, result;
    clock_t start, end;

    printf("Enter number of coin types: ");
    scanf("%d", &n);

    int coins[n];

    printf("Enter %d coin values:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &coins[i]);

    printf("Enter the amount: ");
    scanf("%d", &amount);

    start = clock();
    result = coinChange(coins, n, amount);
    end = clock();

    printf("\nCoins: ");
    for (i = 0; i < n; i++)
        printf("%d ", coins[i]);

    printf("\nAmount: %d\n", amount);

    if (result == -1)
        printf("The amount cannot be formed using the given coins.\n");
    else
        printf("Minimum number of coins required: %d\n", result);

    printf("Execution time: %.8f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);
    printf("Time Complexity: O(n * A)\n");
    printf("Space Complexity: O(A)\n");

    return 0;
}
