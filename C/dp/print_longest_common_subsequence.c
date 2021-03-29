//Program to find Longest Common Subsequence (LCS) of two strings

#include <stdio.h>

//Helper function to find length of two integers
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

//Print LCS of two strings
void lcs(char *x, char *y, int m, int n)
{
    //create table
    int L[m+1][n+1];
    int i, j;

    //Building up table
    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                L[i][j] = 0;  //Empty Subsequence
            }
            else if (x[i - 1] == y[j - 1])
            {
                L[i][j] = L[i-1][j-1] + 1;   //Character in LCS
            }
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);  //Pass
        }
        
    }
    //Length of LCS
    int index = L[m][n];
    //LCS string
    char lcs_string[index + 1];
    lcs_string[index] = '\0';

    i = m;
    j = n;
    while (i > 0 && j > 0)
    {
        /*If current character in X[] and Y are same, then
        current character is part of LCS*/
        if (x[i-1] == x[j-1])
        {
            lcs_string[index-1] = x[i-1]; // Put current character in result
            i--; j--; index--;     
        }
    
        /* If not same, then find the larger of two and
        go in the direction of larger value*/
        else if (L[i-1][j] > L[i][j-1])
            i--;
        else
            j--;
    }
  
   // Print the lcs
   printf("LCS of %s and %s: %s", x, y, lcs_string);
}

int main()
{
    int m, n;
    printf("Enter length of first string: ");
    scanf("%d", &m);
    char a[m+1];
    printf("Enter first string: ");
    scanf("%s", &a);
    printf("Enter length of second string: ");
    scanf("%d", &n);
    char b[n+1];
    printf("Enter second string: ");
    scanf("%s", &b);
    lcs(a, b, m, n);

}

/*Time Complexity: O(m*n), m and n are size of respective input strings

Example:
Enter length of first string: 5
Enter first string: focus
Enter length of second string: 5
Enter second string: locus
LCS of focus and locus: ocus
*/