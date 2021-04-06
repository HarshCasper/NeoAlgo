// Description: Find out the minimum cost to reach from the cell (0, 0) to (m - 1, n - 1) for a given m x n array.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
public class Solution {
//	Recursive function
	public static int minCostPathRecursion(int[][] input) {
        return minCostPathRecursion(input, 0, 0); // Helper function call
	}	
//	Helper function
    private static int minCostPathRecursion(int[][] input, int i, int j) {
        int m = input.length;
        int n = input[0].length;
        if(i<0 || j<0 || i > m-1 || j>n-1){
            return Integer.MAX_VALUE;
        }
        if(i == m-1 && j == n-1){
            return input[i][j]; // Base case
        }
        //Checking in different directions
        int op1 = minCostPathRecursion(input, i, j+1); // check towards Right
        int op2 = minCostPathRecursion(input, i+1, j+1); // check Diagonally
        int op3 = minCostPathRecursion(input, i+1, j); // check towards down
        return (input[i][j] + Math.min(op1, Math.min(op2, op3)));
    }
//    Dynamic Programming function
    public static int minCostPathDP(int[][] input) {
    	int m = input.length;
        int n = input[0].length;
        int storage[][] = new int[m][n]; // storage array
//       Filling up storage array
//       Base cases
        storage[m-1][n-1] = input[m-1][n-1];
        // Last row
        for(int j = n-2; j >= 0; j--) {
        	storage[m-1][j] = storage[m-1][j+1] + input[m-1][j];
        }
        // Last column
        for(int i = m-2; i >=0; i--) {
        	storage[i][n-1] = storage[i+1][n-1] + input[i][n-1];
        }
//        Complete array
        for(int i = m-2; i>=0; i--) {
         	for(int j = n-2; j >= 0; j--) {
        		storage[i][j] = input[i][j] + Math.min(storage[i][j+1], Math.min(storage[i+1][j+1], storage[i+1][j]));
        	}
        }
        return storage[0][0];
    }
//    Take input
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static int[][] take2DInput() throws IOException {
        String[] strRowsCols = br.readLine().trim().split("\\s");
        int mRows = Integer.parseInt(strRowsCols[0]);
        int nCols = Integer.parseInt(strRowsCols[1]);
        if (mRows == 0) {
            return new int[0][0];
        }
        int[][] mat = new int[mRows][nCols];
        for (int row = 0; row < mRows; row++) {
            String[] strNums; 
            strNums = br.readLine().trim().split("\\s");
            for (int col = 0; col < nCols; col++) {
                mat[row][col] = Integer.parseInt(strNums[col]);
            }
        }
        return mat;
    }
//    Main function
  public static void main(String[] args) throws NumberFormatException, IOException {
        int[][] mat = take2DInput();
        System.out.println("Solution Dynamic Programming:" + minCostPathDP(mat));
        System.out.println("Solution Recursion:" + minCostPathRecursion(mat));
  }
}
/*
Sample Input 1 :
3 4
3 4 1 2
2 1 8 9
4 7 8 1
Sample Output 1 :
13

Sample Input 2 :
3 4
10 6 9 0
-23 8 9 90
-200 0 89 200
Sample Output 2 :
76

Time Complexity:
Recursion: O(2^n)
Dynamic Programming: O(n^2)
  
Space Complexity:
Recursion: O(2^n)
Dynamic Programming: O(m*n)
*/
