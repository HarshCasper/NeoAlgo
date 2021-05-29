/*Problem Statement: 
Piyush and Nimit are playing a coin game. They are given n coins with values x1, x2 …. xn where 'n' is always even.
They take alternate terms. In each turn, 
a player picks either the first coin or the last coin from the row and removes it from the row.
The value of coin is received by that player. 
Determine the maximum value that Piyush can win with if he moves first. Both the players play optimally. */

#include <bits/stdc++.h>
using namespace std;

int dp[100][100]={};
int optimalGameStrategy(int *coins,int i,int j)
{
    if(i>j)
    {
        return 0;
    }
    //If sum already exists, then pick from the dp array
    if(dp[i][j]!=0)
    {
        return dp[i][j];
    }
    int sum=0;
    /* If the player 1 chooses, he will either choose from first or last,
    which will leave either of 2 options */
    int option1=min(optimalGameStrategy(coins,i+2,j),optimalGameStrategy(coins,i+1,j-1));
    int option2=min(optimalGameStrategy(coins,i,j-2),optimalGameStrategy(coins,i+1,j-1));
    sum+=max(coins[i]+option1,coins[j]+option2);
    return dp[i][j]=sum;
}

int main() 
{
    int n;
    cout<<"Enter total coins: "<<endl;
    cin>>n;
    int *coins=new int[n];
    int sum=0;
    cout<<"Enter coin values: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>coins[i];
        sum+=coins[i];
    }
    int ans=optimalGameStrategy(coins,0,n-1);
    cout<<"Maximum value for Piyush to win: "<<max(ans,sum-ans)<<endl;
    return 0;
}
/*
Example:-

Input:-
Enter total coins: 
4
Enter coin values: 
1 2 3 4

Output:-
Maximum value for Piyush to win: 6

Time Complexity: O(n)
Space Complexity: O(n)
*/

