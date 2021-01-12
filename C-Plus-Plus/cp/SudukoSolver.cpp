/**
A backtracking algorithm to solve 9X9 suduko
0's in the input are treated empty cells
Assumption : Given configuration is correct
**/

#include <bits/stdc++.h>
using namespace std;

#define N 9

void display(int board[N][N]){
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cout << board[i][j] << ' ';
    }
    cout << '\n';
  }
}

// backtracking soln
bool solve(int board[N][N], int i, int j, 
  bool rows[N][N], bool cols[N][N], bool boxes[N][3][3]) {
    
    if(i == 9)
      return true;
      
    if(board[i][j] == 0) {
        
      for(int k=0; k<9; k++) {
          
        if(rows[k][i] == false && cols[k][j] == false
          && boxes[k][i/3][j/3] == false) {
            board[i][j] = k+1;
            rows[k][i] = true;
            cols[k][j] = true;
            boxes[k][i/3][j/3] = true;
              
            if(solve(board, i+j/8, (j+1)%9, rows, cols, boxes))
              return true;
              
            board[i][j] = 0;
            rows[k][i] = false;
            cols[k][j] = false;
            boxes[k][i/3][j/3] = false;
          }
      }
      
      return false;
    } else
      return solve(board, i+j/8, (j+1)%9, rows, cols, boxes);
  }

void solveSudoku(int board[N][N], int x, int y) {
  // write yopur code here
  bool rows[N][N], cols[N][N], boxes[9][3][3];

  // intialization
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++) {
      rows[i][j] = false;
      cols[i][j] = false;
    }

  // intialization
  for(int i=0; i<N; i++)
    for(int j=0; j<3; j++)
      for(int k=0; k<3; k++)
        boxes[i][j][k] = false;
  
  for(int i=0; i<9; i++)
    for(int j=0; j<9; j++)
      if(board[i][j] != 0) {
        int num = board[i][j]-1;
        rows[num][i] = true;
        cols[num][j] = true;
        boxes[num][i/3][j/3] = true;
      }
      
  solve(board,0,0,rows,cols,boxes);
  display(board);
}

int main() {
  int arr[N][N];

  // taking input
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      cin >> arr[i][j];

  solveSudoku(arr, 0, 0);
  return 0;
}

/**
Input :
3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0
Output :
3 1 6 5 7 8 4 9 2 
5 2 9 1 3 4 7 6 8 
4 8 7 6 2 9 5 3 1 
2 6 3 4 1 5 9 8 7 
9 7 4 8 6 3 1 2 5 
8 5 1 7 9 2 6 4 3 
1 3 8 9 4 7 2 5 6 
6 9 2 3 5 1 8 7 4 
7 4 5 2 8 6 3 1 9 
Space Complexity : O(1)
Time Complexity : O(1)
The size of input is fixed, so the complexity does not change
**/