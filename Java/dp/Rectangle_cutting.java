/*
Given an a×b rectangle, your task is to cut it into squares. On each move you can select a rectangle and cut it into two
rectangles in such a way that all side lengths remain integers. What is the minimum possible number of moves?

Input

The only input line has two integers a and b.

Output

Print one integer: the minimum number of moves.

Constraints

1≤a,b≤500

Example

Input:
3 5

Output:
3

*/

/*
                                APPROACH
            ----------------------------------------------------
            We will make all the horizontal cuts and try to find 
            after which move we have to make minimum moves to make 
            all squares,
            Similarly,
            We do the same with vertical moves,
            We will divide the recetanle in two parts and add the 
            result for both parts and find minimum among all moves
            which will be our ans.

            Time Complexity : O(a*b)
            Space Complexity : O(a*b) due to the 2d array of size (a+1) by (b+1)
*/
import java.util.Scanner;

class Rectangle_cutting {
    static int dp[][]; // declaring dp array for memorization.

    static int cutting(int a, int b) {
        // if side lengths are equal then no move required.
        if (a == b)
            return 0;
        // for a by 1 or 1 by b rectangle we have to make a-1 and b-1 cuts respectively.
        if (a == 1 || b == 1)
            return Math.max(a, b) - 1;

        // if the result is stored already return it.
        if (dp[a][b] != -1)
            return dp[a][b];

        int ans = Integer.MAX_VALUE;

        // recursivly making cuts.
        // loop to make all the horizontal cuts
        /*
         * iterate upto a/2 only wwwww
         */
        for (int i = 1; i <= a / 2; i++) {
            // making every position move and taking the minimum out of it.
            ans = Math.min(ans, cutting(i, b) + cutting(a - i, b));
        }

        // loop to make all the vertical cuts
        for (int i = 1; i <= b / 2; i++) {
            // making every position move and taking the minimum out of it.
            ans = Math.min(ans, cutting(a, i) + cutting(a, b - i));
        }
        return dp[a][b] = 1 + ans; // this 1 corressponds to one of the minimum move we have done above.
    }

    static int cutting_iterative(int a, int b) {
        int dp[][] = new int[a + 1][b + 1];

        // These 2 loops are for base case.
        for (int i = 1; i <= a; i++)
            dp[i][1] = i - 1;
        for (int i = 1; i <= b; i++)
            dp[1][i] = i - 1;
        for (int i = 2; i < a + 1; i++) {
            for (int j = 2; j < b + 1; j++) {
                if (i == j)
                    dp[i][j] = 0;
                else {
                    int ans = Integer.MAX_VALUE;
                    for (int k = 1; k <= i / 2; k++)
                        ans = Math.min(ans, dp[k][j] + dp[i - k][j]);
                    for (int k = 1; k <= j / 2; k++)
                        ans = Math.min(ans, dp[i][k] + dp[i][j - k]);
                    dp[i][j] = 1 + ans;
                }
            }
        }
        return dp[a][b];
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        dp = new int[501][501]; // because a,b <=500
        int a = sc.nextInt();
        int b = sc.nextInt();
        for (int i = 0; i <= a; i++)
            for (int j = 0; j <= b; j++)
                dp[i][j] = -1; // initialising the DP Array for Memorization.
        System.out.println(cutting(a, b));
        System.out.println(cutting_iterative(a, b));
        sc.close();
    }

}
