//* Algorithm ==>
// * In this algorithm we use dynamic programming approach .Here we make 2d dp array and on each step we see how many
// * max gold can we earn by reaching that cell.
// * For this algorithm we move column wise as our src as well as destination lies in first and last column respectively.
// * There are 3 possible paths for each cell. One to top right , second to right , third to bottom right.
// * Taking max out of all possible paths , we can earn maximum profit.

class Solution
{
public:
    int maxGold(int r, int c, vector<vector<int>> mine)
    {
        // * Code here
        vector<vector<int>> dp(r, vector<int>(c));

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (j == 0)
                {
                    dp[i][j] = mine[i][j]; // * To fill the left wall
                }
            }
        }

        // * Outer 'for' loop for columns and inner 'for' loops for rows
        for (int j = 1; j < c; j++)
        {
            for (int i = 0; i < r; i++)
            {
                if (r == 1)
                {

                    // * Only if 1 row
                    dp[i][j] = mine[i][j] + dp[i][j - 1];
                }
                else if (i == 0)
                {

                    // * If it is the first row
                    dp[i][j] = mine[i][j] + max(dp[i][j - 1], dp[i + 1][j - 1]);
                }
                else if (i == r - 1)
                {

                    // * If it is last row
                    dp[i][j] = mine[i][j] + max(dp[i][j - 1], dp[i - 1][j - 1]);
                }
                else
                {

                    // * If it is intermediate row
                    dp[i][j] = mine[i][j] + max(dp[i][j - 1], max(dp[i - 1][j - 1], dp[i + 1][j - 1]));
                }
            }
        }

        // * Returning maximum gold
        int max_gold = INT_MIN;
        for (int i = 0; i < r; i++)
        {
            max_gold = max(dp[i][c - 1], max_gold);
        }
        return max_gold;
    }
};