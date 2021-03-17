import java.util.Scanner;
public class MatrixChainMultiplication{
  // To find efficient way to multiply given matrices and hence finding optimal cost.
    public static int matrixChain(int[] dimension, int i, int j)
    {
        // case 1: when only one matrix is there
        if (j <= i + 1) {
            return 0;
        }

        // minMult : stores the minimum number of scalar multiplications (i.e., cost)
        // needed to compute matrix `M[i+1] … M[j] = M[i…j]`
        int minMult = Integer.MAX_VALUE;

        // take the minimum over each possible position at which the
        // sequence of matrices can be split

        /*
            (M[i+1]) × (M[i+2]………………M[j])
            (M[i+1]M[i+2]) × (M[i+3…………M[j])
            …
            …
            (M[i+1]M[i+2]…………M[j-1]) × (M[j])
        */

        for (int k = i + 1; k <= j - 1; k++)
        {
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
    public static void main(String[] args)
    {
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of matrices you want to multiply: ");
        // Matrix `M[i]` has dimension `dimension[i-1] × dimension[i]` for `i = 1…n`
        // Storing value 1 more than the entered number as dimensions
        // As dimensions of 3 matrices are  `10 × 30` matrix, `30 × 5` matrix, `5 × 60` matrix
        // in case of int[] dimension = { 10, 30, 5, 60 };
        n = sc.nextInt();

        int[] dimension = new int[n+1];
        System.out.print("Enter the dimensions in a continuous non repeating form (for 'n' matrices 'n+1' dimensions should be entered): ");
        for(int i=0; i<n+1; i++)  {
              //reading dimensions from the user
              dimension[i]=sc.nextInt();
        }


        System.out.print("The minimum/optimal cost is " +
                matrixChain(dimension, 0, dimension.length - 1));
    }
}
