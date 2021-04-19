/*Problem Statement: 
A robot is designed to move on a rectangular grid of M rows and N columns. 
The robot is initially positioned at the top-left cell. 
The robot has to reach the (M, N) grid cell. In a single step, 
robot can move only to the cells to its immediate east and south directions. 
That means if the robot is currently at (i, j), it can move to either (i + 1, j) or (i, j + 1) cell, 
provided the robot does not leave the grid.
Now somebody has placed several obstacles in random positions on the grid, 
through which the robot cannot pass. The positions of the blocked cells are initialised to -1 in the matrix. 
Your task is to count the number of paths that the robot can take to move from (0, 0) to (M, N). */

#include<bits/stdc++.h>
using namespace std;

int numWays(int row,int col, int dp[10][10])
{
    if(dp[0][0]==-1)
    {
        return 0;
    }
    for(int i=0;i<col;i++)
    {
        if(dp[0][i]==-1)
        {
            break;
        }
        dp[0][i]=1;
    }
    for(int j=0;j<row;j++)
    {
        if(dp[j][0]==-1)
        {
            break;
        }
        dp[j][0]=1;
    }
    for(int i=1;i<row;i++)
    {
        for(int j=1;j<col;j++)
        {
            if(dp[i][j]==-1)
            {
                continue;
            }
            dp[i][j]=0;
            if(dp[i][j-1]!=-1)
            {
                dp[i][j]=dp[i][j-1];
            }
            if(dp[i-1][j]!=-1)
            {
                dp[i][j]=(dp[i][j]+dp[i-1][j]);
            }
        }
    }
    return dp[row-1][col-1];
}

int main()
{
    int row,col;
    int arr[10][10],dp[10][10]={0};
    cout<<"Enter row and column respectively: "<<endl;
    cin>>row>>col;
    cout<<"Enter matrix elements: "<<endl;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<"The number of paths: "<<numWays(row,col,dp)<<endl;
    return 0;
}
/*
Example:-

Input:-
Enter row and column respectively:
3 3
Enter matrix elements:
1 -1 2
3 -1 4
5 6 7

Output:-
The number of paths: 6

Time Complexity: O(n)
Space Complexity: O(n)
*/

