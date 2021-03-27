// C Program to implement the Cutting a Rod problem
/*  
We are given a rod of length 'n' and the cost of the rod of different length from
1 to n. We need to find the maximum sell price that can be obtained by cutting the rod
at any lengths.
 
This problem can be solved by using Dynamic Programming, 
*/
#include <stdio.h>
#include <limits.h>
//Helper function to find the maximum of two values
int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

// We build a dp table in bottom-up manner
int max_sell_price(int n, int cost[])
{
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int curr_max = INT_MIN;
        for (int j = 0; j < i; j++)
            curr_max = max(curr_max, cost[j] + dp[i - j - 1]);

        // Stores the maximum cost achieved for a rod of length i
        dp[i] = curr_max;
    }

    return dp[n];
}

int main()
{
    int n;
    printf("\nWhat is the length of the rod? ");
    scanf("%d", &n);
    int cost[n], max_price;

    if (n <= 0)
    {
        printf("The given rod length is Invalid!!!");
        return 0;
    }
    // Input the cost of the rod of different length
    printf("Enter the cost of the rod for length 1 to  %d: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &cost[i]);

    max_price = max_sell_price(n, cost);

    printf("The maximized sell price of the: ");
    // Print the maximized sell price
    printf("%d ", max_price);
    return 0;
}

/*

Time Complexity- O(n^2), where 'n' is the length of the rod
Space Complexity- O(n)

SAMPLE INPUT AND OUTPUT

SAMPLE 1
What is the length of the rod? 5
Enter the cost of the rod for length 1 to  5: 2 5 7 8 10
The maximized sell price of the: 12 


SAMPLE 2
What is the length of the rod? 0
The given rod length is Invalid!!!

*/
