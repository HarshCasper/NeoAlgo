/**
Given that a person can climb stairs in
steps of 1 and 2, find in how many ways the 
person can reach the top stair
2 2 1
1 2 2
are different sequences i.e., relative ordering 
matters
**/

import java.io.*;
import java.util.*;

public class ClimbingStairs {

    private static int climbStairs(int n) {
        if(n < 3)
            return n == 2 ? n : 1;
        int[] arr = new int[n+1];
        arr[0] = 1;
        arr[1] = 1;
        arr[2] = 2;
        // compute the dp table
        for(int i = 3; i <= n; i++)
            arr[i] = arr[i-1] + arr[i-2];
        return arr[n];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println(climbStairs(n));
    }
}

/**

Input :
3
Output :
3
Explanation :
1 1 1
1 2
2 1

Time Complexity : O(n)
Space Complexity : O(n)

**/

