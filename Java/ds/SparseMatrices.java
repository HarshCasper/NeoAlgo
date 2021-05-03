//                      SPARSE MATRIX

//          Java program for Sparse Matrix Representation using Array

/*
    *A matrix can be defined with a 2-dimensional array.
    *Any array with 'm' columns and 'n' rows represent a m X n matrix. 
    *There may be a situation in which a matrix contains more number of ZERO values
    than NON-ZERO values. 
    *Such matrix is known as sparse matrix.

    *Triplet Representation (Array Representation)
    *Only non-zero values along with their row and column index values are considered
    *The 0th row stores the total number of rows, total number of columns 
    and the total number of non-zero values in the sparse matrix.
    *The subsequent rows are used for storing non zero values and indices of row and column
    of that non zero element
*/

import java.util.*;

public class SparseMatrices {
    // Varibale Declaration
    static int rows;
    static int columns;
    // Matrix Variable to store the input from the user
    static int inputMatrix[][] = new int[20][20];
    static int sparseMatrix[][] = new int[20][3];
    static int i;
    static int j;
    static int k;
    static int count = 0;

    // Function to read the input matrix from the user
    public static void initializeMatrix() {
        // Creating Scanner Object to read input from user
        Scanner s = new Scanner(System.in);

        System.out.println("Enter the number of rows of the matrix");
        // Reading the number of rows of the matrix from the user
        rows = s.nextInt();

        System.out.println("Enter the number of columns of the matrix");
        // Reading the number of columns of the matrix from the user
        columns = s.nextInt();

        System.out.println("Enter the elements of the matrix");
        for (i = 0; i < rows; i++) {
            for (j = 0; j < columns; j++) { // Reading the elements of the matrix from the user
                inputMatrix[i][j] = s.nextInt();
            }
        }

    }

    // Function to Display the input matrix
    public static void displayMatrix() {
        System.out.println("Displaying the elements of given matrix");
        for (i = 0; i < rows; i++) {
            for (j = 0; j < columns; j++) {
                System.out.print(inputMatrix[i][j] + " ");
            }
            // printing a new line after each row of the matrix
            System.out.println();
        }

    }

    /*
     * Function to tranfrom the given input matrix into sparse matrix and to display
     * the resulting sparse matrix
     */
    public static void displaySparseMatrix() {
        // First row's first column denotes the number of rows of a matrix in sparse
        // matrix
        sparseMatrix[0][0] = rows;
        // First row's second column denotes the number of columns of a matrix in sparse
        // matrix
        sparseMatrix[0][1] = columns;
        k = 1;
        for (i = 0; i < rows; i++) {
            for (j = 0; j < columns; j++) {
                // If a particular input of matrix is non-zero
                if (inputMatrix[i][j] != 0) {
                    // Storing the row index of that particular non zero number
                    sparseMatrix[k][0] = i;

                    // Storing the column index of that particular non zero number
                    sparseMatrix[k][1] = j;
                    sparseMatrix[k][2] = inputMatrix[i][j];
                    k++;

                    // count variable keeps a track on non-zero entries in the given matri
                    count += 1;
                }
            }

            /*
             * First row's third column denotes number of non - zero elements in
             * sparseMatrix
             */
            sparseMatrix[0][2] = count;

        }

        // Loop to represent the sparse Matrix

        System.out.println("Displaying the effecient representation of sparse matrix\n");
        for (i = 0; i < count + 1; i++) {
            for (j = 0; j < 3; j++) {
                System.out.print(sparseMatrix[i][j] + " ");
            }
            System.out.println();
        }

    }

    public static void main(String[] args) {
        // Function to read the input matrix from the user
        initializeMatrix();

        // Function to Display the input matrix
        displayMatrix();

        /*
         * Function to tranfrom the given input matrix into sparse matrix and to display
         * the resulting sparse matrix
         * 
         */
        displaySparseMatrix();

    }

}


/*
 *              TEST CASES
 * 
 *  Enter the number of rows of matrix
 *  4 
 *  Enter the number of columns of matrix 
 *  5
 *  Enter the elements of the matrix 
 *  0 0 3 0 4 
 *  0 0 5 7 0 
 *  0 0 0 0 0 
 *  0 2 6 0 0
 *  Displaying the elements of given matrix 
 *  0 0 3 0 4 
 *  0 0 5 7 0 
 *  0 0 0 0 0 
 *  0 2 6 0 0
 *  Displaying the effecient representation of sparse matrix 
 *  4 5 6 
 *  0 2 3 
 *  0 4 4
 *  1 2 5 
 *  1 3 7 
 *  3 1 2 
 *  3 2 6
 * 
 */
  

 /*             COMPLEXITY
 
    Time Complexity:O(noOfTerms*noOfcolumnS)
    Space Complexity:O(1)
 
 */
