/**
A backtracking algorithm to solve 9X9 suduko
0's in the input are treated empty cells
Assumption : Given configuration is correct
**/

import java.io.*;
import java.util.*;

public class SudukoSolver {
  public static void display(int[][] board){
    for(int i = 0; i < board.length; i++){
      for(int j = 0; j < board[0].length; j++){
        System.out.print(board[i][j] + " ");
      }
      System.out.println();
    }
  }
  
  // backtracking soln
  public static boolean solve(int[][] board, int i, int j, 
    boolean[][] rows, boolean[][] cols, boolean[][][] boxes) {
      
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

  public static void solveSudoku(int[][] board, int x, int y) {
    // write yopur code here
    boolean[][] rows = new boolean[9][9];
    boolean[][] cols = new boolean[9][9];
    boolean[][][] boxes = new boolean[9][3][3];
    
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

  public static void main(String[] args) throws Exception {
    Scanner scn = new Scanner(System.in);
    int[][] arr = new int[9][9];
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        arr[i][j] = scn.nextInt();
      }
    }

    solveSudoku(arr, 0, 0);
  }
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