/*
Given two sequences, find the length of longest subsequence present in both of them.
A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.
*/

#include<bits/stdc++.h>
using namespace std;

int lcs(char *x,char *y)
{
    int m=strlen(x);
    int n=strlen(y);

    int dp[100][100];

    //base case
    //making first row and column 0
    for(int i=0;i<=m;i++)
        dp[i][0]=0;
    for(int j=0;j<=n;j++)
        dp[0][j]=0;

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int q=0;

            if(x[i-1]==y[j-1]) //if matches
                q=1+dp[i-1][j-1];
            else     //if doesn't match
                q=max(dp[i-1][j],dp[i][j-1]);

        dp[i][j]=q;
        }
    }

    return dp[m][n]; //return last element
}

int main()
{
    char str1[100],str2[100];
    cout<<"Enter string1 and string2: "
    cin>>str1>>str2;
    cout<<"output : "<<lcs(str1,str2);
}

/*
   Enter string1 and string2 : ABCDEFGH BDHCEG
   output : 4
*/

// Time and Space complexity : O(mn), where m = length of string1 and n = length of string2
