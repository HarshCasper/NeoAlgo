//Java implementation to sort the given matrix 

import java.io. * ;
import java.util. * ;

public class MatrixSorting {

  // function to sort the given matrix 
  static void sortMatrix(int mat[][], int size) {
    // temporary matrix of size^2 
    int tempmat[] = new int[size * size];
    int index = 0;
    // copy the elements of matrix one by one into tempmat[] 
    for (int row = 0; row < size; row++) {
      for (int col = 0; col < size; col++) {
        tempmat[index++] = mat[row][col];
      }
    }
    // sort temporary matrix tempmat[] 
    Arrays.sort(tempmat);
    // copy the elements of tempmat[] one by one in mat[][] 
    index = 0;
    for (int row = 0; row < size; row++) {
      for (int col = 0; col < size; col++) {
        mat[row][col] = tempmat[index++];
      }
    }
  }

  // Driver program to test above 
  public static void main(String args[]) {
    Scanner sc = new Scanner(System. in );
    System.out.println("Input : ");
    System.out.println("Enter the size of matrix : ");
    int size = sc.nextInt();
    int matrix[][] = new int[size][size];
    System.out.println("Enter the elements of square matrix:");
    for (int row = 0; row < size; row++) {
      for (int col = 0; col < size; col++) {
        matrix[row][col] = sc.nextInt();
      }
    }
    sortMatrix(matrix, size);
    System.out.println("Output : ");
    System.out.println("The Sorted Matrix is :");
    for (int row = 0; row < size; row++) {
      for (int col = 0; col < size; col++) {
        //print the given matrix 
        System.out.print(matrix[row][col] + " ");
      }
      System.out.println();
    }
  }
}

/* 
  Input :
  Enter the size of matrix :
  3
  Enter the elements of square matrix :
  7 8 9
  5 6 4
  3 1 2
  Output :
  Sorted Matrix :
  1 2 3
  4 5 6
  7 8 9

  Time Complexity: O(n2log2n)
  Space Complexity : Auxiliary Space: O(n2)
 */
