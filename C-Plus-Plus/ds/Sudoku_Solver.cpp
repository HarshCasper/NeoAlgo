// Sudoku Solver

// Write a program to solve a Sudoku puzzle by filling the empty cells.
// A sudoku solution must satisfy all of the following rules:
// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.

// The following code can be used to solve a sudoku which is done using recursion and backtracking.


class Solution {
public:
    bool isSafe(vector<vector<char>> grid, int row,int col, char num)      //we check if block is safe or not
    {
    for (int x = 0; x <= 8; x++){                                           //if no same value is present in the same row
        if (grid[row][x] == num)
            return false;
    }
    for (int x = 0; x <= 8; x++){                                           //if no same value is present in the same column
        if (grid[x][col] == num)
            return false;
    }
    int startRow = row - row % 3,startCol = col - col % 3;
   
    for (int i = 0; i < 3; i++){                                            //if no same value is present in the same 3*3 box
        for (int j = 0; j < 3; j++){
            if (grid[i+startRow][j+startCol] == num)
                return false;
        }
    }
 
    return true;
}
    bool recur(int i,int j,vector<vector<char>>& board){
        if(j==9){                                                           //if j excedes the boundry means we need to move to new row
          i++;  j=0;
        }
        if(i==9)
            return true;
        if(board[i][j]=='.'){                                               //we enter here if block is empty
            for(int k=1;k<=9;k++){                                          //check for all values from [1,9], to see which suites better
                if(isSafe(board,i,j,k+'0')){
                    board[i][j]=char(k+'0');
                    if(recur(i,j+1,board))                                  //if ones true,return same for all previous recursion calls
                        return true;
                    board[i][j]='.';
                }
            }
        }
        else{                                                               //if block is already filled we just move to other bolck
                if(recur(i,j+1,board))
                    return true;
        }
        return false;                                                       //if no value suites the position we return false
    }
    void solveSudoku(vector<vector<char>>& board) {
        recur(0,0,board);
    }
};


// Simple Input and Output
// Input: board = 
//             [["5","3",".",".","7",".",".",".","."],
//             ["6",".",".","1","9","5",".",".","."],
//             [".","9","8",".",".",".",".","6","."],
//             ["8",".",".",".","6",".",".",".","3"],
//             ["4",".",".","8",".","3",".",".","1"],
//             ["7",".",".",".","2",".",".",".","6"],
//             [".","6",".",".",".",".","2","8","."],
//             [".",".",".","4","1","9",".",".","5"],
//             [".",".",".",".","8",".",".","7","9"]]
<p align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png"  />
</p>

// Output: 
//             [["5","3","4","6","7","8","9","1","2"],
//             ["6","7","2","1","9","5","3","4","8"],
//             ["1","9","8","3","4","2","5","6","7"],
//             ["8","5","9","7","6","1","4","2","3"],
//             ["4","2","6","8","5","3","7","9","1"],
//             ["7","1","3","9","2","4","8","5","6"],
//             ["9","6","1","5","3","7","2","8","4"],
//             ["2","8","7","4","1","9","6","3","5"],
//             ["3","4","5","2","8","6","1","7","9"]]

<p align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/3/31/Sudoku-by-L2G-20050714_solution.svg/250px-Sudoku-by-L2G-20050714_solution.svg.png"  />
</p>

// Explanation: The input board is shown above and the only valid solution is shown


// Here we have used the same logic as that of N-queens problem
// Time taken will be O(9^(n*n))
// Space complexity O(n*n)