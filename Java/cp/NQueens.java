/**
N-Queens problem is a famous problem
The paradigm used to solve the problem is backtracking
**/

import java.io.*;
import java.util.*;

public class NQueens {
    
  public static void solve(boolean[][] board, boolean[] cols, 
    boolean[] ndiag, boolean[] rdiag, int row, String asf) {
        
        if(row == board.length) {
            System.out.println(asf+'.');
            return;
        }
        
        for(int col=0; col<board.length; col++) {
            if(cols[col] == false && ndiag[row+col] == false && 
                rdiag[row-col+board.length-1] == false) {
                    cols[col] = true;
                    ndiag[row+col] = true;
                    rdiag[row-col+board.length-1] = true;
                    board[row][col] = true;
                    solve(board, cols, ndiag, rdiag, row+1, asf+row+'-'+col+", ");
                    cols[col] = false;
                    ndiag[row+col] = false;
                    rdiag[row-col+board.length-1] = false;
                    board[row][col] = false;
                }
        }
    }

  public static void main(String[] args) throws Exception {
    Scanner scn = new Scanner(System.in);
    int n = scn.nextInt();
    boolean[][] board = new boolean[n][n];
    //write your code here
    
    boolean[] cols = new boolean[n];
    boolean[] ndiag = new boolean[2*n-1];
    boolean[] rdiag = new boolean[2*n-1];
    
    solve(board, cols, ndiag, rdiag, 0, "");
  }

}

/**

Input :
4
Output :
0-1, 1-3, 2-0, 3-2, .
0-2, 1-0, 2-3, 3-1, .

Space Complexity : O(n^2)
Time Complexity : upperbounded by O(n^n)

**/