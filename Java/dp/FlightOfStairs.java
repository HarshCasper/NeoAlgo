/*Problem link: https://binarysearch.com/problems/A-Flight-of-Stairs-Sequel

Problem Statement:
You are given positive integers n and k and you are currently at stair 0 and want to climb to stair n. 
You can either climb 1, 2, or 3 stairs at a time, but you can only climb 3 stairs at most k times.
Return the number of ways to climb to the nth stair.
*/

import java.util.Scanner;

public class FlightOfStairs{

    public static int ans(int[][] memo, int n, int k) {

        /*base conditions*/
        if (n == 0)
            return 1;
        else if (n < 0)
            return 0;
        else if (memo[n][k] != 0)
            return memo[n][k];

        /*recursive calls for 1 step and 2 steps respectively*/
        memo[n][k] = ans(memo, n - 1, k) + ans(memo, n - 2, k);

        /*recursive call for 3 steps only if k satisfies*/
        if (k > 0)
            memo[n][k] += ans(memo, n - 3, k - 1);

       /*returning memoized answer*/
        return memo[n][k];

    }
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the value of n");
        int n = sc.nextInt();
        System.out.println("Enter the value of k");
        int k = sc.nextInt();

        /*array to initiate memoization*/
        int[][] memo = new int[n+1][k+1];

        /*passing arguments to the function and displaying answer*/
        System.out.println("The answer is: "+ans(memo, n, k));
        sc.close();
    }
}

/*
Sample Input :
Enter the value of n
4
Enter the value of k
1
Output :
The answer is: 7
*/

/*
Time complexity: O(n*k) 
Space complexity: O(n*k)
 */
