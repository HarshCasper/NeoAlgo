/** CONCEPT
 This code computes the number of insertions and deletions required to convert one string to another
 *Calculate the length of the longest common subsequence
 *Characters not present in the string X but present in string Y need to be inserted
 *Characters not present in the string Y but present in string X need to be deleted
**/
#include <bits/stdc++.h>
using namespace std;

void minInsertDel(string x, string y, int n, int m)
{
    int dp[n + 1][m + 1];

    /*Base conditions
    For calculating the longest common subsequence
    If the length of any one of the string is zero, then the length of common subsequence will be zero
    */
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    //Displaying the minimum number of insertions and deletions
    cout << "Minimum insertions=" << m - dp[n][m] << "\nMinimum deletions=" << n - dp[n][m] << "\n";
}

//Driver Code
int main()
{
    string x, y;
    cin >> x >> y;
    int n = x.length();
    int m = y.length();
    minInsertDel(x, y, n, m);
}
/*
 *TIME COMPLEXITY- O(n^2)
 *INPUT:
  X= abcdef
  Y= abcdg
  OUTPUT:
  Minimum insertions=1
  Minimum deletions=2
*/
