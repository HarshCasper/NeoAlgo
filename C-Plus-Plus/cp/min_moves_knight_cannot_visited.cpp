/*Problem Statement: 
A knight is a piece used in the game of chess. The chessboard itself is square array of cells. 
Each time a knight moves, its resulting position is two rows and one column, 
or two columns and one row away from its starting position. 
Thus a knight starting on row r, column c – which we’ll denote as (r,c) – can move to any of the squares (r-2,c-1),
(r-2,c+1), (r-1,c-2), (r-1,c+2), (r+1,c-2), (r+1,c+2), (r+2,c-1), or (r+2,c+1).
Of course, the knight may not move to any square that is not on the board.
Suppose the chessboard is not square, but instead has rows with variable numbers of columns, 
and with each row offset zero or more columns to the right of the row above it. 
The figure to the left illustrates one possible configuration. 
How many of the squares in such a modified chessboard can a knight, 
starting in the upper left square (marked with an asterisk), 
not reach in any number of moves without resting in any square more than once? Minimize this number. */

#include<bits/stdc++.h>
using namespace std;

int n,cols,empty,board[10][10],sum=0,visited;
void knight_squares(int i,int j,int count)
{
    if(i<0 || i>=10 || j<0 || j>=10 || board[i][j] == 0)
    {
        return;
    }
    int ans = 0;
    board[i][j] = 0;
    visited = max(visited,count+1);
    /* Going to all possible moves,
    the knight can visit */
    knight_squares(i-1,j-2,count+1);
    knight_squares(i-2,j-1,count+1);
    knight_squares(i+1,j-2,count+1);
    knight_squares(i+2,j-1,count+1);
    knight_squares(i-1,j+2,count+1);
    knight_squares(i-2,j+1,count+1);
    knight_squares(i+1,j+2,count+1);
    knight_squares(i+2,j+1,count+1);
    //backtracking
    board[i][j] = 1;
}

int main()
{
    cout<<"Enter the side of square: "<<endl;
    cin>>n;
    sum = 0;
    cout<<"Enter cells: "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>board[i][j];
            if(board[i][j])
            {
                sum++; 
            }
        }
    }
    visited=0;
    knight_squares(0,0,0);
    cout<<"Minimum no of squares that the knight cannot visited: "<<(sum-visited)<<endl;
    return 0;
}
/*Example:-

Input:-
Enter the side of square: 
3
Enter cells: 
1 1 1
1 1 1
1 1 1

Output:-
Minimum no of squares that the knight cannot visited: 1

Time Complexity: O(n)
Space Complexity: O(n)
*/

