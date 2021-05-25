/* 
Description: An integer matrix of size (M x N) has been given. Find 
out the minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).
The cost of a path is defined as the sum of each cell's values through
which the route passes.
*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
public class Solution {
    public static int minCostPathDP(int[][] input) {
    	  int m = input.length;
        int n = input[0].length;
        int storage[][] = new int[m][n];
        storage[m-1][n-1] = input[m-1][n-1];
        for(int j = n-2; j >= 0; j--) {
        	storage[m-1][j] = storage[m-1][j+1] + input[m-1][j];
        }
        for(int i = m-2; i >=0; i--) {
        	storage[i][n-1] = storage[i+1][n-1] + input[i][n-1];
        }
        for(int i = m-2; i>=0; i--) {
         	for(int j = n-2; j >= 0; j--) {
        		storage[i][j] = input[i][j] + Math.min(storage[i][j+1], Math.min(storage[i+1][j+1], storage[i+1][j]));
        	}
        }
        return storage[0][0];
    }
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static int[][] take2DInput() throws IOException {
        System.out.println("Enter the number of rows & columns: ");
        String[] strRowsCols = br.readLine().trim().split("\\s");
        int mRows = Integer.parseInt(strRowsCols[0]);
        int nCols = Integer.parseInt(strRowsCols[1]);
        if (mRows == 0) {
            return new int[0][0];
        }
        int[][] mat = new int[mRows][nCols];
        System.out.println("Enter The matrix elements: ");
        for (int row = 0; row < mRows; row++) {
            String[] strNums; 
            strNums = br.readLine().trim().split("\\s");
            for (int col = 0; col < nCols; col++) {
                mat[row][col] = Integer.parseInt(strNums[col]);
            }
        }
        return mat;
    }
  //Drive Code
  public static void main(String[] args) throws NumberFormatException, IOException {
        int[][] mat = take2DInput();
        System.out.println("Minimum cost to reach the destination: " + minCostPathDP(mat));
  }
}
/*
Sample Input:
Enter the number of rows & columns: 
3 4
Enter The matrix elements: 
3 4 1 2
2 1 8 9
4 7 8 1
Output :
Minimum cost to reach the destination: 13

Time Complexity: O(n^2)
Space Complexity: O(m*n)
*/
