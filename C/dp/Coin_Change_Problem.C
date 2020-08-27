/*Given a value V, if we want to make change for V cents, and we have infinite supply of each of C = { C1, C2, .. , Cm} valued coins, what is the minimum number of
coins to make the change?
Examples:
Input: coins[] = {25, 10, 5}, V = 30
Output: Minimum 2 coins required
We can use one coin of 25 cents and one of 5 cents 
Input: coins[] = {9, 6, 5, 1}, V = 11
Output: Minimum 2 coins required
We can use one coin of 6 cents and 1 coin of 5 cents */

#include <stdio.h>
#include <stdlib.h>
#include <climits>

int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

void coinChange(int n, int amount)
{
    int Max = amount + 1;
    int coins[n], dp[Max];
    int i, j;
    printf("Enter denominations of coins:-");
    for (i = 0; i < n; i++)
        scanf("%d", &coins[i]);

    for (i = 0; i < Max; i++)
        dp[i] = Max;

    dp[0] = 0;

    for (i = 1; i < Max; i++)
        for (j = 0; j < n; j++)
            if (coins[j] <= i)
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);

    if (dp[amount] > amount)
        printf("Not Possible to Change the amount with given set of coins.");
    else
        printf("Minimum Number of coins required for the given situation is:- %d", dp[amount]);
    return;
}

int main()
{
    int n, amount;
    printf("Enter Number of coins:-");
    scanf("%d", &n);
    printf("Enter Target amount:-");
    scanf("%d", &amount);

    coinChange(n, amount);

    return 0;
}