/**
To find the Longest Common Subsequence of three
strings using Bottom Up approach.
*/

import java.util.Scanner;

public class LCSThreeStrings {

	private static void longestCommonSubsequeneceBottomUp(String a, String b, String c) {

		int[][][] dp = new int[a.length() + 1][b.length() + 1][c.length() + 1];
		
		// for loop will start from last index of each string
		// in case any of the three strings is empty then
		// answer will be 0.
		for (int i = a.length() - 1; i >= 0; i--) {
			for (int j = b.length() - 1; j >= 0; j--) {
				for (int k = c.length() - 1; k >= 0; k--) {

					if (a.charAt(i) == b.charAt(j) && a.charAt(i) == c.charAt(k)) {
						
						dp[i][j][k] = 1 + dp[i + 1][j + 1][k + 1];
						
					} else {
						int x = dp[i + 1][j][k];
						int y = dp[i][j + 1][k];
						int z = dp[i][j][k + 1];

						dp[i][j][k] = Math.max(x, Math.max(y, z));
					}
				}
			}
		}

		System.out.println("Length of Longest Common Subsequence - " + dp[0][0][0]);
	}

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		
		System.out.print ("Enter String A - ");
		String a = sc.next();
		System.out.print ("Enter String B - ");
		String b = sc.next();
		System.out.print ("Enter String C - ");
		String c = sc.next();

		longestCommonSubsequeneceBottomUp(a, b, c);
	}    
}

/**
Time Complexity  : O(A*B*C)
Space Complexity : O(A*B*C)

Input:

Enter String A - adjkudg
Enter String B - bsdkdefg
Enter String C - dkelfudr

Output:

Length of Longest Common Subsequence - 3
*/
