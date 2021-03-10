class Solution{
    static int maxGold(int n, int m, int arr[][])
    {
        // code here
        // 2d dp array
        int dp[][]= new int[n][m];

        // Initialising dp array with Integer Minimum value.
        for(int[] row:dp){
            Arrays.fill(row, Integer.MIN_VALUE);
        }

        //the 0th col value in dp array will be same as that in input arr
        for(int i=0;i<n;i++){
            dp[i][0] = arr[i][0];
        }

        //outer loop runs on col wise in 2d array
    for(int j=1;j<m; j++){

        //inner loop works on row wise chcking out all the possibility
        for(int i=0;i<n;i++){   

            //if only 1 row
                if(i==0 && i==(n-1)){
                    dp[i][j]= dp[i][j-1] + arr[i][j];
                }

                //if last row
                else if(i==(n-1)){
                    dp[i][j]= Math.max(dp[i][j-1], dp[i-1][j-1]) + arr[i][j];
                }

                //if 0th row
                else if(i==0){
                    dp[i][j]= Math.max(dp[i][j-1], dp[i+1][j-1]) + arr[i][j];
                }

                //if any of the intermediate row
                else{
                    dp[i][j]= Math.max(dp[i-1][j-1], Math.max(dp[i][j-1], dp[i+1][j-1])) + arr[i][j];
                }
            }
        }

        //running the loop on last column and getting max value of gold
        int ans=Integer.MIN_VALUE;
        for(int i=0; i<n;i++){
            ans = Math.max(ans, dp[i][m-1]);
        }

        //returning the max value of gold.
        return ans;
    }
}