/*
An integer matrix of size (M x N) has been given. Find out the minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).

Description:
From a cell (i, j), you can move in three directions:
1. ((i + 1),  j) which is, "down"
2. (i, (j + 1)) which is, "to the right"
3. ((i+1), (j+1)) which is, "to the diagonal"
The cost of a path is defined as the sum of each cell's values through which the route passes.
*/

public class Solution {

	public static int minCostPath(int[][] input) {
		//Your code goes here
        return minCostPath(input, 0, 0);
	}
    
    private static int minCostPath(int[][] input, int i, int j) {
        int m = input.length;
        int n = input[0].length;
        if(i<0 || j<0 || i > m-1 || j>n-1){
            return Integer.MAX_VALUE;
        }
        if(i == m-1 && j == n-1){
            return input[i][j];
        }
        int op1 = minCostPath(input, i, j+1);
        int op2 = minCostPath(input, i+1, j+1);
        int op3 = minCostPath(input, i+1, j);
        
        return (input[i][j] + Math.min(op1, Math.min(op2, op3)));
    }
  
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
  
  public static void main(String[] args) throws NumberFormatException, IOException {
        int[][] mat = take2DInput();
        System.out.println(minCostPath(mat));
  }
}

/*
Input 1 :
3 4
3 4 1 2
2 1 8 9
4 7 8 1
Output 1 :
13

Input 2 :
3 4
10 6 9 0
-23 8 9 90
-200 0 89 200
Output 2 :
76
*/
