// C++ to solve Sudoku problem 
#include <bits/stdc++.h>
using namespace std;
 //size of thr grid
int grid[9][9];   
// Checks whether it will be legal 
// to assign num to the given row, col 
bool safe(int row,int col,int num)
{
    int i,j;
    for(i=0;i<9;i++)
    {
        if(grid[i][col]==num)
            return false;
    }
    for(i=0;i<9;i++)
    {
        if(grid[row][i]==num)
            return false;
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(grid[i+3*(row/3)][j+3*(col/3)]==num)
                return false;
        }
    }
    return true;
}
bool solvesudoku(int row,int col)
{
    int i,j;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            if(grid[i][j]==0)
            {
                int num;
                for(num=1;num<=9;num++)
                {
                    if(safe(i,j,num)==true)
                    {
                        grid[i][j]=num;
                        if(solvesudoku(i,j))
                        	 //success
                            return true;   
                        grid[i][j]=0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}
// Driver Code 
int main()
{
    //Here 0 represents unassigned cell
    int grid1[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},  
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},  
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},  
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},  
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},  
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},  
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},  
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},  
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    int i,j;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            grid[i][j]=grid1[i][j];
        }
    }
    if(solvesudoku(0,0)==true)
    {
    	cout<<"\tSOLVED !\n";
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else
    {
        cout<<"No solution exists!";
    }
    return 0;
}
