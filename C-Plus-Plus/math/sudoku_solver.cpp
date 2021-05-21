/* 
this is a backtracking problem which is used for solving sudoku
in sudoku there should be no repetition of number int same row, same column and same grid which of 3*3 size
*/
#include <bits/stdc++.h>
using namespace std;

// to check whether we can place a particular number in the given cell or not
bool isSafe(int mat[][9], int i, int j, int n, int number){
    /* we will check row and column of a cell whether given number is present or not
     if present then we will return false */
    for(int x=0;x<n;x++){
        if(mat[x][j] == number || mat[i][x] == number){
            return false;
        }
    }

    //sub grid check
    int root = sqrt(n);
    int sx = (i/root)*root;
    int sy = (j/root)*root;
    // iterating the grid
    for(int x=sx;x<sx+root;x++){
        for(int y=sy;y<sy+root;y++){
            if(mat[x][y] == number){
                return false;
            }
        }
    }

    //The number can be placed
    return true;
}

// function to create a sudoku solver
bool sudoku_solver(int mat[][9], int i, int j, int n){
    //base case
    if(i == n){
        // if all the rows are completely filled
        //print the solution
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }

    /*
    if all the columns of a particular row is filled then we will move to next row
    and will start from the 0th column  */
    if(j == n){
       return sudoku_solver(mat,i+1,0,n);
    }
    
    // if the number filled is not 0 then we will skip it move to next column
    if(mat[i][j] != 0){
       return sudoku_solver(mat,i,j+1,n);
    }

    /* recursive case
    fill the current cell with possible options */
    for(int number=1;number<=n;number++){
        if(isSafe(mat,i,j,n,number)){
            // assume that it is correct not at correct position
            mat[i][j] = number;
            bool canBePlaced = sudoku_solver(mat,i,j+1,n);
            if(canBePlaced == true){
                return true;
            }
        }
    }

    //back track here
    mat[i][j] = 0;
    // we were not able to solve this sudoku therefore returned false
    return false;
}

// driver code
int main() {
    int mat[9][9];
    // input size of sudoku board
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }

    //recursive call
    sudoku_solver(mat,0,0,n);
    return 0;
}

/*
Input -
9
5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9

Output-
5 3 4 6 7 8 9 1 2
6 7 2 1 9 5 3 4 8
1 9 8 3 4 2 5 6 7
8 5 9 7 6 1 4 2 3
4 2 6 8 5 3 7 9 1
7 1 3 9 2 4 8 5 6
9 6 1 5 3 7 2 8 4
2 8 7 4 1 9 6 3 5
3 4 5 2 8 6 1 7 9

Time-Complexity - O(9^(n*n))
Space-Complexity - O(n*n)
*/
