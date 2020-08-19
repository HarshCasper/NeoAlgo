#include <bits/stdc++.h>
using namespace std;

//Edit distance Recursive approach
int edit_distance_recursive (string &x, string &y, int m, int n)
{
    //base case
    if (m==0) return n;
    if (n==0) return m;

    if(x[m-1]==y[n-1]) //if matches
    {
      return edit_distance_recursive(x,y,m-1,n-1);
    }

    return 1+min( min(edit_distance_recursive(x,y,m,n-1),edit_distance_recursive(x,y,m-1,n)), edit_distance_recursive(x,y,m-1,n-1));

}

//Edit distance DP approach
int edit_distance_dp (string &x, string &y)
{
    int m=x.length();
    int n=y.length();

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
    string str1,str2;
    cout <<"Enter first string: ";
    cin>>str1;
    cout <<"Enter second string: ";
    cin>>str2;

    int m=str1.length();
    int n=str2.length();

    cout<<"minimum number of edits to convert string1 to string2 Using Recursive approach: ";
    cout<<edit_distance_recursive(str1,str2,m,n)<<endl;

    cout<<"minimum number of edits to convert string1 to string2 Using DP approach: ";
    cout<<edit_distance_dp(str1,str2)<<endl;
}

//working
//input: sunday saturday
//output:3
