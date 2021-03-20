/* Matrix Chain Multiplication is an optimization problem which is used to find
   the most efficient way to multiply the given sequence of matrices. The problem
   is not actually proforming the multiplications but it is to decide the sequence
   of multiplications involved.
   So, the development of Dynamic Programming algorithm goes like:
   1. Characterize the structure of an optimal solution.
   2. Define the value of an optimal solution recursively.
   3. Compute the value of an optimal solution in a bottom-up or top-down fashion.
   4. Construct the optimal solution from the computed information.
*/
import java.util.Scanner;
public class MatrixChainMultiplication {
	// To find efficient way to multiply given matrices and hence finding optimal cost.
	public static int matrixChain(int[] dimension, int i, int j) {
		// case 1: when only one matrix is there
		if (j <= i + 1) {
			return 0;
		}
		/*
     minMult : stores the minimum number of scalar multiplications (i.e., cost)
		 needed to compute matrix `M[i+1] … M[j] = M[i…j]`
    */
		int minMult = Integer.MAX_VALUE;
		/*
       take the minimum over each possible position at which the
		   sequence of matrices can be split

            (M[i+1]) × (M[i+2]………………M[j])
            (M[i+1]M[i+2]) × (M[i+3…………M[j])
            …
            …
            (M[i+1]M[i+2]…………M[j-1]) × (M[j])
    */
		for (int k = i + 1; k <= j - 1; k++) {
			int cost = matrixChain(dimension, i, k);
			cost += matrixChain(dimension, k, j);
			cost += dimension[i] * dimension[k] * dimension[j];
			if (cost < minMult) {
				minMult = cost;
			}
		}
		// return minimum cost to multiply `M[j+1]…M[j]`
		return minMult;
	}

	// Matrix Chain Multiplication Problem
	public static void main(String[] args) {
		int n;
		Scanner sc = new Scanner(System. in );
		System.out.print("Enter the number of matrices you want to multiply: ");
		/*
       Matrix `M[i]` has dimension `dimension[i-1] × dimension[i]` for `i = 1…n`
		   Storing value 1 more than the entered number as dimensions
		   As dimensions of 3 matrices are  `10 × 30` matrix, `30 × 5` matrix, `5 × 60` matrix
		   in case of int[] dimension = { 10, 30, 5, 60 };
    */
		n = sc.nextInt();
		int[] dimension = new int[n + 1];
		System.out.print("Enter the dimensions in a continuous non repeating form (for 'n' matrices 'n+1' dimensions should be entered): ");
		for (int i = 0; i < n + 1; i++) {
			//reading dimensions from the user
			dimension[i] = sc.nextInt();
		}
		System.out.print("The minimum/optimal cost is " + matrixChain(dimension, 0, dimension.length - 1));
	}
}
/* Sample Input/Output:
                        Input: Enter the number of matrices you want to multiply: 4
                               Enter the dimensions in a continuous non repeating
                               form (for 'n' matrices 'n+1' dimensions should be entered): 10 20 30 40 30

                               ( The matrix will be seen as dimension[] = {10, 20, 30, 40, 30}

                        Output: 30000

                        There are 4 matrices of dimensions 10x20, 20x30, 30x40 and 40x30.
                        Let the input 4 matrices be A, B, C and D.  The minimum number of
                        multiplications are obtained by putting parenthesis in following way
                        ((AB)C)D --> 10*20*30 + 10*30*40 + 10*40*30

    Time and space complexity for this approach:
    Time Complexity: O(n^3)
    Auxiliary Space: O(n^2)
*/
