// Sudoku Solver

// Write a program to solve a Sudoku puzzle by filling the empty cells.
// A sudoku solution must satisfy all of the following rules:
// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.


int a=0;


void solve(vector<vector<char>> &grid, int x, int y)
{
    int N=grid.size();
    if(x<0 || y<0 || x>=N || y>=N) return;           
    
    vector<int> dict(N+1,1);
    char tt=grid[x][y];
    for(int i=0; i<N; i++) dict[grid[i][y]-'0']=0;    
    for(int i=0; i<N; i++) dict[grid[x][i]-'0']=0;    
    
    for(int i=0;i<3;i++)                              
        for(int j=0;j<3;j++) 
            dict[grid[x/3*3+i][y/3*3+j]-'0']=0;
    dict[tt-'0']=1;
     
    if(x==N-1 && y==N-1)                              
    { 
        int xx=0; for(int i=1; i<=N; i++) 
            if(dict[i]==1) xx=i;
        if(xx!=0) grid[x][y]='0'+xx, f=1;
        return;
    }
    
    if(grid[x][y]!='0')                              
    {
        if(dict[grid[x][y]-'0']==1) 
            solve(grid,x+(y==(N-1)),(y+1)%N);
        return;        
    }
    
    for(int i=1; i<=N; i++) if(dict[i]==1)            
    {
        if(f==1) return; grid[x][y]='0'+i;
        solve(grid,x+(y==(N-1)),(y+1)%N);
        if(f==1) return; grid[x][y]='0';
    }
}


class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) 
    {
        a=0;
        int N=board.size();
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++) 
                if(board[i][j]=='.') board[i][j]='0';
        solve(board,0,0);
    }
};


Input: board = 
            [["5","3",".",".","7",".",".",".","."],
            ["6",".",".","1","9","5",".",".","."],
            [".","9","8",".",".",".",".","6","."],
            ["8",".",".",".","6",".",".",".","3"],
            ["4",".",".","8",".","3",".",".","1"],
            ["7",".",".",".","2",".",".",".","6"],
            [".","6",".",".",".",".","2","8","."],
            [".",".",".","4","1","9",".",".","5"],
            [".",".",".",".","8",".",".","7","9"]]
Output: 
            [["5","3","4","6","7","8","9","1","2"],
            ["6","7","2","1","9","5","3","4","8"],
            ["1","9","8","3","4","2","5","6","7"],
            ["8","5","9","7","6","1","4","2","3"],
            ["4","2","6","8","5","3","7","9","1"],
            ["7","1","3","9","2","4","8","5","6"],
            ["9","6","1","5","3","7","2","8","4"],
            ["2","8","7","4","1","9","6","3","5"],
            ["3","4","5","2","8","6","1","7","9"]]


Explanation: The input board is shown above and the only valid solution is shown
