/*Problem Statement: 
Given n wines in a row, with integers denoting the cost of each wine respectively. 
Each year you can sell the first or the last wine in the row. 
Let the initial profits from the wines be P1, P2, P3…Pn. 
In the Yth year, the profit from the ith wine will be Y*P[i]. 
The goal is to calculate the maximum profit that can be earned by selling all the wines. */

#include<bits/stdc++.h>
using namespace std;

int profit(int wines[],int i,int j,int year, int dp[][10])
{
    if(i>j)
    {
        return 0;
    }
    if(dp[i][j]!=0)
    {
        return dp[i][j];
    }
    int op1=wines[i]*year+profit(wines,i+1,j,year+1,dp);
    int op2=wines[j]*year+profit(wines,i,j-1,year+1,dp);
    return max(op1,op2);
}

int main()
{
    int n;
    cout<<"Enter total number of wines: "<<endl;
    cin>>n;
    int wines[100],dp[10][10]={0};
    cout<<"Enter wine prices: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>wines[i];
    }
    cout<<"The maximum profit is: "<<profit(wines,0,n-1,1,dp)<<endl;
    return 0;
}
/*
Example:-

Input:-
Enter total number of wines:
5
Enter wine prices:
2 4 6 2 5

Output:-
The maximum profit is: 64

Time Complexity: O(n)
Space Complexity: O(n)
*/

