/**
To find whether is it possible to
reach target by taking sum of any subset
of the given set.
*/

import java.util.Scanner;

public class SubsetSumToTarget {

    private static boolean subsetSumBottomUP(int[] ar, int target) {

		boolean[][] dp = new boolean[ar.length + 1][target + 1];

		// base case :
		// when target=0 then always true.
		// when no element is taken then always false.

		for (int i = 0; i < ar.length + 1; i++) {
			for (int j = 0; j <= target; j++) {

				if (i == 0 && j == 0) {
					dp[i][j] = true;
					
				} else if (i == 0) {
					// when no element is considered
					dp[i][j] = false;
					
				} else if (j == 0) {
					// when target itself is 0
					dp[i][j] = true;
					
				} else {
					// when ith element is not included
					boolean a = dp[i - 1][j]; 
					boolean b = false;
					
					if (j >= ar[i - 1]) {
						// when ith element is included.
						b = dp[i - 1][j - ar[i - 1]]; 
					}

					dp[i][j] = a || b;
				}
			}
		}

		return dp[ar.length][target];
	}

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		
		System.out.print ("Enter no. of elemnets in the set - ");
		int n = sc.nextInt();

		int[] ar = new int[n];
		System.out.print ("Enter elemnets in the set - ");
		for (int i = 0; i < n; i++) {
			ar[i] = sc.nextInt();
		}
		
		System.out.print ("Enter target - ");
		int target = sc.nextInt();

		boolean isPossible = subsetSumBottomUP(ar, target);
		
		System.out.print ("Is it possible to reach target ? ");
		if (isPossible) {
			System.out.println ("Yes.");
		} else {
			System.out.println ("No.");
		}

	}
    
}

/**
Time Complexity  : O(N*T) -> N:length of array, T:value of target
Space Complexity : O(N*T)

Input-1 :

Enter no. of elemnets in the set - 5
Enter elemnets in the set - 1 2 3 4 5
Enter target - 6

Output-1 :

Is it possible to reach target ? Yes.

Input-2 :

Enter no. of elemnets in the set - 6
Enter elemnets in the set - 10 5 7 12 15 2
Enter target - 50

Output-2 :

Is it possible to reach target ? No.
*/
