//* Algorithm ==>
// * In this algorithm we use dynamic programming approach .Here we make 2d dp array and on each step we see how many
// * max gold can we earn by reaching that cell.
// * For this algorithm we move column wise as our src as well as destination lies in first and last column respectively.
// * There are 3 possible paths for each cell. One to top right , second to right , third to bottom right.
// * Taking max out of all possible paths , we can earn maximum profit.

class Solution {
    static int maxGold(int n, int m, int arr[][]) {
        // * Code here
        // * 2d dp array
        int dp[][] = new int[n][m];

        // * Initialising dp array with Integer Minimum value.
        for (int[] row : dp) {
            Arrays.fill(row, Integer.MIN_VALUE);
        }

        // * The 0th col value in dp array will be same as that in input arr
        for (int i = 0; i < n; i++) {
            dp[i][0] = arr[i][0];
        }

        // * Outer loop runs on col wise in 2d array
        for (int j = 1; j < m; j++) {

            // * Inner loop works on row wise chcking out all the possibility
            for (int i = 0; i < n; i++) {

                // * If only 1 row
                if (i == 0 && i == (n - 1)) {
                    dp[i][j] = dp[i][j - 1] + arr[i][j];
                }

                // * If last row
                else if (i == (n - 1)) {
                    dp[i][j] = Math.max(dp[i][j - 1], dp[i - 1][j - 1]) + arr[i][j];
                }

                // * If 0th row
                else if (i == 0) {
                    dp[i][j] = Math.max(dp[i][j - 1], dp[i + 1][j - 1]) + arr[i][j];
                }

                // * If any of the intermediate row
                else {
                    dp[i][j] = Math.max(dp[i - 1][j - 1], Math.max(dp[i][j - 1], dp[i + 1][j - 1])) + arr[i][j];
                }
            }
        }

        // * Running the loop on last column and getting max value of gold
        int ans = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            ans = Math.max(ans, dp[i][m - 1]);
        }

        // * Returning the max value of gold.
        return ans;
    }
}
