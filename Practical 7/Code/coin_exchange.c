#include <stdio.h>

#define BIG 99999   // means "not possible yet"

/*
   Coin Exchange (Dynamic Programming)
   Find minimum coins needed to make the given money
*/
int minCoins(int coin[], int types, int money)
{
    int table[money + 1];

    // pay = Represents the current amount we are trying to make.
    // c = Represents the current coin we are testing.
    int pay, c;
    int using_this_coin;

    // at start, mark all amounts as not possible
    for (pay = 0; pay <= money; pay++)
        table[pay] = BIG;

    // 0 money needs 0 coins
    table[0] = 0;

    // make every amount from 1 to money
    for (pay = 1; pay <= money; pay++)
    {
        // try each coin
        for (c = 0; c < types; c++)
        {
            // coin can be used only if it is <= current amount
            if (coin[c] <= pay && table[pay - coin[c]] != BIG)
            {
                // 1 current coin + best for remaining money
                using_this_coin = table[pay - coin[c]] + 1;

                // keep smaller count
                if (using_this_coin < table[pay])
                    table[pay] = using_this_coin;
            }
        }
    }

    // still BIG means cannot make this money
    if (table[money] == BIG)
        return -1;

    return table[money];
}

int main()
{
    int types, money, i;
    int answer;

    printf("Enter number of coin types: ");
    scanf("%d", &types);

    int coin[types];

    printf("Enter %d coin values:\n", types);
    for (i = 0; i < types; i++)
        scanf("%d", &coin[i]);

    printf("Enter the amount: ");
    scanf("%d", &money);

    answer = minCoins(coin, types, money);

    printf("\nCoins: ");
    for (i = 0; i < types; i++)
        printf("%d ", coin[i]);

    printf("\nAmount: %d\n", money);

    if (answer == -1)
        printf("The amount cannot be formed using the given coins.\n");
    else
        printf("Minimum number of coins required: %d\n", answer);

    printf("Time Complexity: O(n * A)\n");
    printf("Space Complexity: O(A)\n");

    return 0;
}
