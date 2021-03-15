// Problem Link- https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/climb-stairs-with-minimum-moves-official/ojquestion
/* You are given a number n (the number of stairs in a staircase)
 * You are on the 0th step and are required to climb to the top.
 * You are given n numbers, where ith element's value represents till how far from the step you could jump to in a single move.
 * You are required to print the number of minimum moves in which you can reach the top of staircase.
*/

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        int res = countStairMin(arr);
        System.out.println(res);
    }

    public static int countStairMin(int[] arr) {
        // We will use tabulation Method (Bottom Up Dynamic Programming)
        Integer[] dp = new Integer[arr.length + 1];
        // smallest problem is at end (i.e. 0 move)
        dp[arr.length] = 0;
        for (int i = arr.length - 1; i >= 0; i--) {
            // if having more than 0 steps
            if (arr[i] > 0) {
                int min = Integer.MAX_VALUE;
                // loop for number of steps
                for (int j = 1; j <= arr[i] && i + j < dp.length; j++) {
                    // getting minimum of all moves
                    if (dp[i + j] != null) {
                        min = Math.min(min, dp[i + j]);
                    }
                    if (min != Integer.MAX_VALUE) {
                        dp[i] = min + 1;
                    } else {
                        dp[i] = null;
                    }
                }
            }
        }
        return dp[0];
    }
}

/*
 * Sample input- 10 3 3 0 2 1 2 4 2 0 0 
 * Sample Output- 4
 */

 /* Time Complexity: O(N) 
  * Auxiliary Space: O(N)
*/
