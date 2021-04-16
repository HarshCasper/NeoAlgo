/**
To find the Longest Common Subsequence of two
strings using Bottom Up approach such that 
we can change atmost K characters
to increase the size of LCS.
*/

import java.util.Scanner;

public class KOrderedLCS {
    
	private static void kOrderedLcsBottomUp(String a, String b, int k) {

		int[][][] dp = new int[k + 1][a.length() + 1][b.length() + 1];

		// for loop will start from last index of each string
		// in case any of the three strings is empty then
		// answer will be 0.
		for (int i = 0; i <= k; i++) {
			for (int j = a.length()-1; j >= 0; j--) {
				for (int l = b.length()-1; l >= 0; l--) {

					if (a.charAt(j) == b.charAt(l)) {
						dp[i][j][l] = 1 + dp[i][j + 1][l + 1];
						
					} else {
						int x = dp[i][j + 1][l];
						int y = dp[i][j][l + 1];
						int z = 0;
						
						// check if we can still convert a character
						// to make it a part og LCS.
						if (i > 0) {
							z = 1 + dp[i - 1][j + 1][l + 1];
						}

						dp[i][j][l] = Math.max(x, Math.max(y, z));
					}
				}
			}
		}
		System.out.println("Length of Longest Common Subsequence - " + dp[k][0][0]);
	}

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		System.out.print("Enter String A - ");
		String a = sc.next();
		System.out.print("Enter String B - ");
		String b = sc.next();
		System.out.print("Enter value of K - ");
		int k = sc.nextInt();

		kOrderedLcsBottomUp(a, b, k);
	}
}

/**
Time Complexity  : O(A*B*K)
Space Complexity : O(A*B*K)

Input:

Enter String A - abcdefgh
Enter String B - acjdfih
Enter value of K - 2

Output:

Length of Longest Common Subsequence - 6

*/
