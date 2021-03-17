/* Problem Statement =>
    Given a 2 x n board and tiles of size 2 x 1, count the number of ways to tile the given board using the 2 x 1 tiles. 
    A tile can either be placed horizontally i.e., as a 1 x 2 tile or vertically i.e., as 2 x 1 tile. */

/* Algorithm =>
  Approach used : Dynamic Programming
  
  Test cases handled explicitly: 
  Case 1: if n == 1 , only 1 configuration of tile is possible
  Case 2: if n == 2 , only 2 configurations are possible
  Case 3: if n > 2, then we got 2 possible subcases: 
      Subcase 1: if we place length wise, call dp[i-2];
      Subcase 2: if we place width wise, call dp[i-1]; 
  
  At last return, dp[n] for number of ways. */

import java.util.*;
public class Tiling_2xN{
    
    static Long numberOfWays(int n){
        int N = 1000000007;
        Long[] dp = new Long[n + 1];
        dp[1] = Long.parseLong("1");
        if (n == 1)
            return dp[1];

        dp[2] = Long.parseLong("2");
        if (n == 2)
            return dp[2];

        for (int i = 3; i <= n; i++){
            dp[i] = ((dp[i - 2] % N) + (dp[i - 1] % N) % N);
        }
        return dp[n] % N;
    }

    public static void main(String[] args){
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        System.out.println(numberOfWays(n));
        scn.close();
    }
}

/* Sample Input: n=3
  
  Sample Output: 3
  
  Expected Time Complexity: O(n)
  
  Expected Space Complexity: O(n) */

