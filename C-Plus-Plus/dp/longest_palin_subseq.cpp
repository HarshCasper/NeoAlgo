/*
Length of the longest palindromic subsequence in a string
 ALGORITHM
 *Reverse the string
 *Find the longest common subsequence between the string and its reverse
 */
#include<bits/stdc++.h>
using namespace std;
int longestPalinSubseq(string X,int n)
{
    string Y=X;
    reverse(Y.begin(),Y.end());
    
    int dp[n+1][n+1];
    //Base conditions
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            if(i==0 || j==0)
            dp[i][j]=0;
        }
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(X[i-1]==Y[j-1])
            dp[i][j]=1+dp[i-1][j-1];
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][n];
}
int main()
{
    string X;
    cin>>X;
    int n=X.length();
    cout<<longestPalinSubseq(X,n)<<"\n";
}
/*
Time complexity:O(n^2)
INPUT:
X=ayan
OUTPUT:
3
*/
