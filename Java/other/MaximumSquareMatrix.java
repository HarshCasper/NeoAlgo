import java.util.Scanner;

public class MaximumSquareMatrix {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter number of rows and columns:");
        int r = scanner.nextInt();
        int c = scanner.nextInt();
        int[][] matrix = new int[r][c];
        System.out.println("Enter elements of the matrix:");
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }

        printMaxSquare(matrix);
    }

    private static void printMaxSquare(int[][] matrix) {

        int rows = matrix.length, cols = matrix[0].length, i, j, maxSquare, max_i, max_j;
        int[][] squareSizes = new int[rows][cols];

        // Set first column of squareSizes[][]
        for(i = 0; i < rows; i++) {
            squareSizes[i][0] = matrix[i][0];
        }

        // Set first row of squareSizes[][]
        for(j = 0; j < cols; j++) {
            squareSizes[0][j] = matrix[0][j];
        }

        // getting other entries for squareSizes
        for (i = 1; i < rows; i++) {
            for (j = 1; j < cols; j++) {
                if(matrix[i][j] == 1) {
                    squareSizes[i][j] = Math.min(squareSizes[i][j - 1],
                            Math.min(squareSizes[i - 1][j], squareSizes[i - 1][j - 1])) + 1;
                } else {
                    squareSizes[i][j] = 0;
                }
            }
        }

        // find max entry of squareSizes
        maxSquare = squareSizes[0][0]; max_i = 0; max_j = 0;
        for(i = 0; i < rows; i++)
        {
            for(j = 0; j < cols; j++)
            {
                if(maxSquare < squareSizes[i][j])
                {
                    maxSquare = squareSizes[i][j];
                    max_i = i;
                    max_j = j;
                }
            }
        }

        // print result
        System.out.println("Maximum size sub-matrix is: ");
        for(i = max_i; i > max_i - maxSquare; i--)
        {
            for(j = max_j; j > max_j - maxSquare; j--)
            {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }
}
/*
* Sample input/output:
* Enter number of rows and columns:
* 6 5
* Enter elements of the matrix:
* 0 1 1 0 1
* 1 1 0 1 0
* 0 1 1 1 0
* 1 1 1 1 0
* 1 1 1 1 1
* 0 0 0 0 0
* Maximum size sub-matrix is:
* 1 1 1
* 1 1 1
* 1 1 1
*
* Space and Time complexity = O(m*n)
*/
