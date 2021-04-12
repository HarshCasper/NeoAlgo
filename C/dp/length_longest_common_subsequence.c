// C program to find to the length of the longest common subsequence
#include <stdio.h>

// Helper function to find the maximum of two elements
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

// Length of Longest Common subsequence
int lcs(char s1[], int n, char s2[], int m)
{

    /* Builds a 2D table in a bottom Up manner, storing info regarding the 
    length of longest common subsequence of both strings till that index. */
    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            // If one of the string size is zero, then the length of LCS is also zero
            if (i == 0 || j == 0)
                dp[i][j] = 0;

            // If the elements of both the strings match, then the value of LCS increments by one.
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;

            /* Either include the last element from one string and exclude it from the other and 
            compare them and vice versa and pick the one giving the maximum length out of the two */
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][m];
}

int main()
{
    int n, m, ans;
    printf("\nEnter the length of the first string? ");
    scanf("%d", &n);
    char s1[n];
    printf("Enter the first string: ");
    scanf(" %s", s1);

    printf("\nEnter the length of the second string? ");
    scanf("%d", &m);
    char s2[m];
    printf("Enter the second string: ");
    scanf(" %s", s2);

    ans = lcs(s1, n, s2, m);
    printf("\nThe length of the longest common subsequence is: %d", ans);
    return 0;
}

/*

Time Complexity: O(m*n), where m, n is the size of the input strings
Space Complexity: O(m*n)

SAMPLE INPUT AND OUTPUT

Enter the length of the first string? 6
Enter the first string: cuckoo
Enter the length of the second string? 8
Enter the second string: cucumber
The length of the longest common subsequence is: 3

*/
