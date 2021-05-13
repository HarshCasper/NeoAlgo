/*
	Strassen's Algorithm is an algorithm for Matrix multiplication.
	It is faster(optimal) than the standard matrix multiplication algorithm and
	is useful in practice for large matrices. It uses the Divide N Conquer Approach
	and recursively divides a Matrix into four small matrices.
*/

import java.util.Scanner;

public class Strassens_Algo_for_Matrix_multiplication {

    // Function to multiply matrices
    // A and B are the two matrices to be multiplied
    public int[][] multiply(int[][] A, int[][] B) {
        // Order of matrix
        int n = A.length;

        // Creating a 2D square matrix with size n
        int[][] output = new int[n][n];

        // Base case
        // If there is only single element in the two matrices
        if (n == 1)

            // Returnng the simple multiplication of
            // two elements in matrices
            output[0][0] = A[0][0] * B[0][0];

        else {
            // Dividing the two Matrices into parts
            // by storing sub-parts to variables
            /*
             * A = [A11 A12 A21 A22]
             *
             * B = [B11 B12 B21 B22]
             */
            int[][] A11 = new int[n / 2][n / 2];
            int[][] A12 = new int[n / 2][n / 2];
            int[][] A21 = new int[n / 2][n / 2];
            int[][] A22 = new int[n / 2][n / 2];
            int[][] B11 = new int[n / 2][n / 2];
            int[][] B12 = new int[n / 2][n / 2];
            int[][] B21 = new int[n / 2][n / 2];
            int[][] B22 = new int[n / 2][n / 2];

            // Dividing matrix A into 4 halves i.e A11, A12, A21, A22
            split(A, A11, 0, 0);
            split(A, A12, 0, n / 2);
            split(A, A21, n / 2, 0);
            split(A, A22, n / 2, n / 2);

            // Dividing matrix B into 4 halves i.e B11, B12, B21, B22
            split(B, B11, 0, 0);
            split(B, B12, 0, n / 2);
            split(B, B21, n / 2, 0);
            split(B, B22, n / 2, n / 2);

            // Using Formulas as described in the algorithm
            // You can check it out on https://en.wikipedia.org/wiki/Strassen_algorithm

            // Calculating M1, M2, M3, M4, M5, M6, M7 by recursively calling multiply()

            // M1:=(A11+A22)×(B11+B22)
            int[][] M1 = multiply(add(A11, A22), add(B11, B22));

            // M2:=(A21+A22)×B11
            int[][] M2 = multiply(add(A21, A22), B11);

            // M3:=A11x(B12-B22)
            int[][] M3 = multiply(A11, sub(B12, B22));

            // M4:=A22×(B21−B11)
            int[][] M4 = multiply(A22, sub(B21, B11));

            // M5:=(A11+A12)×(B22)
            int[][] M5 = multiply(add(A11, A12), B22);

            // M6:=(A21-A11)×(B11+B12)
            int[][] M6 = multiply(sub(A21, A11), add(B11, B12));

            // M7:=(A12-A22)×(B21+B22)
            int[][] M7 = multiply(sub(A12, A22), add(B21, B22));

            // Output Matrix after multiplication:-
            /*
             * output = [C11 C12 C21 C22]
             */

            // C11:=M1+M4−M5+M7
            int[][] C11 = add(sub(add(M1, M4), M5), M7);

            // C12:=M3+M5
            int[][] C12 = add(M3, M5);

            // C21:=M2+M4
            int[][] C21 = add(M2, M4);

            // C22:=M1−M2+M3+M6
            int[][] C22 = add(sub(add(M1, M3), M2), M6);

            // Join 4 halves into one result matrix
            join(C11, output, 0, 0);
            join(C12, output, 0, n / 2);
            join(C21, output, n / 2, 0);
            join(C22, output, n / 2, n / 2);
        }

        // Step 4: Return result
        return output;
    }

    // Funtion to substract two matrices
    public int[][] sub(int[][] A, int[][] B) {
        int n = A.length;

        // Resultant Matrix
        int[][] C = new int[n][n];

        // Outer loop for rows
        for (int i = 0; i < n; i++)

            // Inner loop for columns
            for (int j = 0; j < n; j++)

                // Substracting corresponding elements
                // from matrices
                C[i][j] = A[i][j] - B[i][j];

        return C;
    }

    // Funtion to add two matrices
    public int[][] add(int[][] A, int[][] B) {
        int n = A.length;

        // Resultant matrix
        int[][] C = new int[n][n];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)

                // Adding corresponding elements
                // of matrices
                C[i][j] = A[i][j] + B[i][j];

        return C;
    }

    // Funtion to split the parent matrix
    // into child matrices
    public void split(int[][] P, int[][] C, int iP, int jP) {
        // iP and jP are starting indexes to split the Parent Matrix
        // Outer loop for rows
        for (int i1 = 0, i2 = iP; i1 < C.length; i1++, i2++)

            // i1 and j1 used to traverse child matrix
            // i2 and j2 used to traverse Parent matrix
            // Inner loop for columns

            for (int j1 = 0, j2 = jP; j1 < C.length; j1++, j2++)

                C[i1][j1] = P[i2][j2];
    }

    // Funtion to join child matrices
    // into the Parent matrix
    // iP and jP are starting indexes to join into the Parent Matrix
    public void join(int[][] C, int[][] P, int iP, int jP)

    {
        // Outer loop for rows
        for (int i1 = 0, i2 = iP; i1 < C.length; i1++, i2++)

            // Inner loop for columns
            for (int j1 = 0, j2 = jP; j1 < C.length; j1++, j2++)

                P[i2][j2] = C[i1][j1];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Strassen Multiplication Algorithm Implementation For Matrix Multipication :\n");

        Strassens_Algo_for_Matrix_multiplication s = new Strassens_Algo_for_Matrix_multiplication();

        System.out.println("Enter the order of the matrices:- ");
        int N = sc.nextInt();

        // Matrix A
        int[][] A = new int[N][N];
        System.out.println("Enter elements of Matrix A:- ");

        for (int i = 0; i < N; i++) {

            for (int j = 0; j < N; j++)

                A[i][j] = sc.nextInt();
            sc.nextLine();
        }

        // Matrix B
        int[][] B = new int[N][N];
        System.out.println("Enter elements of Matrix B:- ");

        for (int i = 0; i < N; i++) {

            for (int j = 0; j < N; j++)

                B[i][j] = sc.nextInt();
            sc.nextLine();
        }

        // Resultant Matrix after multiplying matrices A and B
        int[][] output = s.multiply(A, B);

        System.out.println("\nProduct of matrices A and B : ");

        for (int i = 0; i < N; i++) {

            for (int j = 0; j < N; j++)
                System.out.print(output[i][j] + " ");

            System.out.println();
        }
    }
}

/*
 * Note*:- This Algorithm is mainly used to multiply two square Matrices(NxN).
 * Also this Algorithm provides an optimized way to multiply two large matrices.
 *
 *
 * Time Complexity of Strassen's Algorithm:- O(n^2.81) log2(7) = 2.8073 i.e 2.81
 * Space Complexity:- O(n^2.81)
 */

/*
Sample Testcase:
A =  1 2 3 4
	 4 3 0 1
	 5 6 1 1
	 0 2 5 6

B =  1 0 5 1
	 1 2 0 2
	 0 3 2 3
	 1 2 1 2

output = 7 21 15 22
		 8  8 21 12
		12 17 28 22
		 8 31 16 31
*/
