import java.util.*;

/// 0/1 Knapsack can be solved using the dynamic approach wherein
/// re-computation of same sub problems can be avoided by using a temporary
/// dp array in bottom-up manner.

/// Solving 0/1 Knapsack using DP reduces the extra work produced
/// by working on same cases as seen in recursive approach

class Knapsack_01 {

    /// Returns the maximum value that can
    /// be put in a knapsack of capacity W
    static int knapSack(int W, int[] wt, int[] val, int n) {

        int i, j;
        int[][] grid = new int[n + 1][W + 1];  /// no. of rows = no. of elements+1, no. of col = total knapsack weight+1

        /// Build table grid[][] in bottom up manner
        for (i = 0; i <= n; i++)
        {
            for (j = 0; j <= W; j++)
            {
                if (i == 0 || j == 0) {

                    /// 0th row and column will be 0
                    grid[i][j] = 0;

                }else if (wt[i - 1] <= j) {

                    /// At a given point, there may be 2 or more than 2 weights that fit in the given range
                    /// Compare and consider the maximum one
                    grid[i][j] = Math.max(val[i - 1] + grid[i - 1][j - wt[i - 1]], grid[i - 1][j]);

                }else{
                    /// If current weight is less than the required weight
                    /// consider the value from the above row of same column
                    grid[i][j] = grid[i - 1][j];
                }

            }
        }

        return grid[n][W];
    }

    /// Driver code
    public static void main(String[] args) {

        Scanner infile = new Scanner(System.in);
        int w,n,i;

        System.out.println("Enter the number of elements: ");
        n = infile.nextInt();

        System.out.println("Enter the maximum weight of knapsack: ");
        w = infile.nextInt();

        int[] val = new int[n];
        int[] weights = new int[n];

        System.out.println("Enter the weight of each element: ");
        for (i=0; i<n; i++){
            weights[i] = infile.nextInt();
        }

        System.out.println("Enter the value of each element: ");
        for (i=0; i<n; i++){
            val[i] = infile.nextInt();
        }

        infile.close();

        System.out.println(knapSack(w, weights, val, n));
    }
}


/*

Test Case:
    Input:
        Enter the number of elements:
        4
        Enter the maximum weight of knapsack:
        5
        Enter the weight of each element:
        1 2 3 4
        Enter the value of each element:
        60 100 120 170

    Output:
        230

Explanation:

	[0  0   0   0   0   0
	 0 60  60  60  60  60
	 0 60 100 160 160 160
	 0 60 100 160 180 180
	 0 60 100 160 180 230 ]

	 Here, we will use the elements with weight 1 and 4 as it will yield the maximum value.

Time Complexity : O(N*W)   /// As we pre-compute a dp array of size N*W
Space Complexity : O(N*W)  /// As we use a 2D array to store dynamic values.

where,
/// N = number of elements
/// W = capacity of knapsack

*/
