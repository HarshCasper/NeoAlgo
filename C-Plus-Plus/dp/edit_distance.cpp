#include <bits/stdc++.h>
using namespace std;

int edit_distance (char *x, char *y)
{
    int m=strlen(x);
    int n=strlen(y);

    int dp[101][101];

    //base case
    //making last row and column of dp array 0
    for(int i=0;i<=m;i++)
        dp[i][0]=i;
    for(int j=0;j<=n;j++)
        dp[0][j]=j;

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(x[i-1]==y[j-1]) //if matches
                dp[i][j] = dp[i-1][j-1];
            else     //if doesn't match
                dp[i][j] = 1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
        }

    }

    return dp[m][n];   //return last element
}


int main()
{
    char str1[100],str2[100];
    cin>>str1>>str2;

    cout<<edit_distance(str1,str2);
}

//working
//input: sunday saturday
//output:3
