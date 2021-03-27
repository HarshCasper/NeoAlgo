//This problem is of placing n queens on n*n chessboard which is solved using backtracking so no two queens can attack each other
// like we place n queens in n*n chessboard in such a way so that no two queens should be placed in same row, same column and same diagonal
#include <iostream>
using namespace std;

// To check whether the curren posotion is safe for placing the queen or not
bool isSafe(int board[][10],int i,int j,int n){
    // To check whether the queen is placed in current column or not
    for(int row=0;row<i;row++){
        if(board[row][j] == 1){
            return false;
        }
    }

    // To check whether the queen is placed in current left diagonal or not
    int x = i;
    int y = j;
    while(x>=0 && y>=0){
        if(board[x][y] == 1){
            return false;
        }
        x--;
        y--;
    }

    // To check whether the queen is placed in current column or not
     x = i;
     y = j;
    while(x>=0 && y<n){
        if(board[x][y] == 1){
            return false;
        }
        x--;
        y++;
    }

    // if we can place our queen in the current cell then return true
    return true;
}

// A recursive function to solve n queen problem
bool solveNqueen(int board[][10], int i, int n){
    //base case
    if(i == n){
        // we have successfully placed all the n queens from row(0 to n)
        // therefore print the board
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 1){
                    cout<<"1 ";
                }
                else{
                    cout<<"0 ";
                }
            }
            cout<<endl;
        }
        // We are return false here to print all the ways to plave n queens
       cout<<endl<<endl;
       return false;
    }

    // recusive case
    for(int j=0;j<n;j++){
        // we will check whether a given cell is save for placing queen or not
        if(isSafe(board,i,j,n)){
            board[i][j] = 1;  // if safe we will place the queen
            //we will check for next row if the cell placed in current cell is safte
            bool nextQueenPlaced = solveNqueen(board,i+1,n);
            if(nextQueenPlaced){
                return true;
            }
            // it means our assumptio is wrong it is not the right position to place our queen
            board[i][j] = 0;
        }
    }

     // if we have tried all the position in current row then we will return the false
    return false;
}

//Driver code
int main() {
    //n is no. of queens to be placed 
    int n;
    cin>>n;
    int board[10][10] = {0};
    solveNqueen(board,0,n);
    return 0;
}

/*
Input: 4
Output:
0 0 1 0
1 0 0 0
0 0 0 1
0 1 0 0
time complexity - O(n*n)
space complexity - O(n)
*/
