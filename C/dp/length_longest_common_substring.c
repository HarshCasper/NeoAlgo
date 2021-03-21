// C program to find to the length of the longest common substring
#include <stdio.h>

// Helper function to find the maximum of two elements
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

// Length of Longest Common substring
int lcs(char s1[], int n, char s2[], int m)
{
    /*
    Builds a 2D table in a bottom Up manner, storing info 
    regarding the length of longest common substring till that index.
    */
    int dp[n + 1][m + 1], ans = 0;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            // If one of the string size is zero, then the length of LCS is also zero
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            /* If the elements of both the strings match, then the value of LCS increments by one.
            Also Check if the value of lcs has reached the max till now.
            */
            else if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                ans = max(ans, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }

    return ans;
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
    printf("The length of the longest common substring is: %d", ans);
    return 0;
}

/*

Time Complexity: O(m*n), where m, n is the size of the input strings
Space Complexity: O(m*n)

SAMPLE INPUT AND OUTPUT

Enter the length of the first string? 8
Enter the first string: cucumber

Enter the length of the second string? 6
Enter the second string: cuckoo
The length of the longest common substring is: 3

*/
