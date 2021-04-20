/*
  Following is the code to find the minimum insertion steps required to make string a palindrome
  Approach:
      1.  Find the longest palindromic subsequence of the given string.Let it be
          stored in a variable len.
      2.  The minimum number of insertions required to make the given string a palindrome
          will be the difference of the given string and len (lps of the string).
*/
#include<bits/stdc++.h>
using namespace std;
int LongestPalindromicSubsequence(string a)
{
    int n=a.length();
    string b=a;

    //reversing the string
    reverse(a.begin(),a.end());

    //forming a 2d matrix to find lps
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i-1]==b[j-1])dp[i][j]=1+dp[i-1][j-1];
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][n];
}
int main()
{
    string a;
    cout<<"Enter string: ";
    cin>>a;
    int len=LongestPalindromicSubsequence(a);
    int ans=a.length()-len;
    cout<<"Minimum Insertions Required: "<<ans<<endl;
    return 0;
}
/*
Sample Input:
Enter string: mbadabgr

Sample Output:
Minimum Insertions Required: 3

Time Complexity: O(n^2)
Space Complexity: O(n^2)
*/
