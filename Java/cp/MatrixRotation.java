/**
Given a Matrix of dimensions n*n, the program will 
print the matrix after rotating it with 90 degrees
in both clockwise and anticlockwise directions.
*/

import java.util.Scanner;

public class MatrixRotation {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		
		System.out.print ("Enter size of square matrix - ");
		int n = sc.nextInt();
		
		int[][] ar = new int[n][n];
		System.out.println("Enter elements -");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ar[i][j] = sc.nextInt();
			}
		}
		
		System.out.println("Original Matrix :");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				System.out.print(ar[i][j] + "\t");
			}
			System.out.println();
		}
		
		System.out.println("\nAnticlockwise Direction :");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				System.out.print(ar[j][n - 1 - i] + "\t");
			}
			System.out.println();
		}
		
		System.out.println("\nClockwise Direction :");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				System.out.print(ar[n-1-j][i] + "\t");
			}
			System.out.println();
		}
	}
}

/**
Time Complexity : O(n*n)
Space Complexity : O(n*n)

Input :

Enter size of square matrix - 4
Enter elements -
12 23 45 2
54 34 89 75
1 5 38 6
28 67 11 9

Output :

Original Matrix :
12	23	45	2	
54	34	89	75	
1	5	38	6	
28	67	11	9	

Anticlockwise Direction :
2	75	6	9	
45	89	38	11	
23	34	5	67	
12	54	1	28	

Clockwise Direction :
28	1	54	12	
67	5	34	23	
11	38	89	45	
9	6	75	2	

*/

