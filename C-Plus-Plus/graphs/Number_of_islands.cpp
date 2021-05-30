/*
  Following is the code to find the number of islands given a matrix of 0's and 1's where
  1 represents land and 0 represents sea
  Approach:
      1.  Construct a visited 2D array
      2.  Construct a depth first search function
      3.  In the main function traverse the given matrix such that if the current cell has a
          one and has not been visited
      4.  This way we will visit all the ones that are connected together and the number of
          time dfs function gets called will be the number of islands that are present in the matrix.
*/
#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j)
{
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())return;
    if(visited[i][j] || grid[i][j]==0)return;
    visited[i][j]=true;
    dfs(grid,visited,i-1,j);                    //up
    dfs(grid,visited,i+1,j);                    //down
    dfs(grid,visited,i,j-1);                    //left
    dfs(grid,visited,i,j+1);                    //right
}

int main()
{
    int m,n;
    cout<<"Enter number of rows and columns: ";
    cin>>m>>n;
    vector<vector<int>> grid(m,vector<int>(n,0));
    vector<vector<bool>>visited(m,vector<bool>(n,0));
    cout<<"Enter the elements: ";
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>grid[i][j];
        }
    }
    int no_of_islands=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!visited[i][j] && grid[i][j]==1)
            {
                dfs(grid,visited,i,j);
                no_of_islands++;
            }
        }
    }
    cout<<"Total number of islands: "<<no_of_islands<<endl;
    return 0;
}
/*
    Sample Input:
    Enter number of rows and columns:4 5
    Enter the elements:
    1 1 1 1 0
    1 1 0 1 0
    1 1 0 0 0
    0 0 0 0 0

    Sample Output:
    Total number of islands: 1

    Time Complexity: O(m*n)
    Space Complexity: O(m*n)
*/
