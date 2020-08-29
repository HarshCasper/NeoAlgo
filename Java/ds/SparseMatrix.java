import java.util.Scanner;
// Java program for Sparse Matrix Representation using Array 

class SparseMatrix {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System. in );
    System.out.println("Input :");
    System.out.println("Enter the row size");
    int row = sc.nextInt();
    System.out.println("Enter the column size");
    int colmn = sc.nextInt();
    int sparseMatrix[][] = new int[row][colmn];
    System.out.println("Enter the element of 2-D matrix");
    for (int loop = 0; loop < row; loop++) {
      for (int inloop = 0; inloop < colmn; inloop++) {
        sparseMatrix[loop][inloop] = sc.nextInt();
      }
    }
    int count = 0;
    for (int loop = 0; loop < row; loop++) {
      for (int inloop = 0; inloop < colmn; inloop++) {
        if (sparseMatrix[loop][inloop] != 0) {
          count++;
        }
      }
    }
    /* number of columns in Triplet Matrix(count) must be 
         equal to number of non - zero elements in sparseMatrix */
    int tripletMatrix[][] = new int[count][3];
    /* Making of new matrix called TripletMatrix(row,column,value)
          all the non-zero elements are stored in revised Sparse Matrix */
    int index = 0;
    for (int loop = 0; loop < row; loop++) {
      for (int inloop = 0; inloop < colmn; inloop++) {
        if (sparseMatrix[loop][inloop] != 0) {
          tripletMatrix[index][0] = loop;
          tripletMatrix[index][1] = inloop;
          tripletMatrix[index][2] = sparseMatrix[loop][inloop];
          index++;
        }
      }
    }
    System.out.println("Output :");
    System.out.println("Triplet Matrix Representation :-");
    System.out.println("rows columns values");
    for (int loop = 0; loop < count; loop++) {
      for (int inloop = 0; inloop < 3; inloop++) {
        System.out.print(tripletMatrix[loop][inloop]);
      }
      System.out.println();
    }
  }
}
/*
  Input :
  Enter the row size 
  4
  Enter the column size
  5
  Enter the elements of 2-D matrix
  0 0 1 5 0
  0 0 6 0 0
  7 0 0 0 1
  0 8 0 0 0
  Output:
  Triplet Matrix Representation :-
  rows  columns values
  0     2       1
  0     3       5
  1     2       6
  2     0       7
  2     4       1
  3     1       8
 */
/*
  Time Complexity:O(noOfTerms*noOfcolumn)
  Space Complexity:O(1)
 */