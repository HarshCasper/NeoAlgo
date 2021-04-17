/* MATRIX MULTIPLICATION
    2 matrices are input and multiplied using following algorithm:
    START
    Input no. of rows m1 and columns n1 of first matrix
    For i = 0 to m1-1
        For j=0 to n1-1
            Input elements of first matrix and store in a[i][j]
    Input no. of rows m2 and columns n2 of second matrix
    For i = 0 to m2-1
        For j=0 to n2-1
            Input elements of second matrix and store in b[i][j]
    If (n1 != m2)
        Print "Multiplication is not possible"
    Else
        Initialize product matrix c[m1][n2] as 0 matrix
        For i = 0 to m1-1
            For j=0 to n2-1
                For k=0 to n1-1
                    c[i][j] =c[i][j]+( a[i][k] * b[k][j])
        For i = 0 to m1-1
            For j=0 to n2-1
                Print c[i][j] 
    STOP 

*/

//import package to accept input
import java.util.Scanner;

//class for matrix multiplication
public class Matrix {

    ////to multiply 2 matrices.2 matrices and corresponding rows and columns are arguments
    static void multiply(int a[][],int b[][],int m1,int n1,int m2,int n2){
        //check if no of columns of first matrix is 
        //equal to number of rows of second matrix 
        if (n1 != m2)
            System.out.println("Multiplication is not possible");

        else 
        {
            int i,j;
            //initialize new matrix to store product
            int c[][] = new int[m1][n2];

            //matrix multiplication
            for (i = 0; i < m1; i++) 
            {
                for (j = 0; j < n2; j++) 
                {
                    for (int k = 0; k < n1; k++)
                        c[i][j] += a[i][k] * b[k][j];
                }
            }
            //to print product matrix 
            System.out.println("Product:");
            for (i = 0; i < m1; i++) 
            {
                for (j = 0; j < n2; j++) 
                {
                    System.out.print(c[i][j]+" " );
                }
                System.out.println();
            }
        }
    }

    //driver code
    public static void main(String[] args) {
        int i, j, temp;
        //accept the matrices, rows and columns as user input
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the number of rows and columns in first matrix:");
        int m1 = s.nextInt();
        int n1 = s.nextInt();
        int a[][] = new int[m1][n1];
        System.out.print("Enter the elements of first matrix:");
        for (i = 0; i < m1; i++) 
        {
            for (j = 0; j < n1; j++)
                a[i][j] = s.nextInt();
        }
        System.out.print("Enter the number of rows and columns in second matrix:");
        int m2 = s.nextInt();
        int n2 = s.nextInt();
        int b[][] = new int[m2][n2];
        System.out.print("Enter the elements of second matrix:");
        for (i = 0; i < m2; i++) 
        {
            for (j = 0; j < n2; j++)
                b[i][j] = s.nextInt();
        }
        //call function to multiply the matrices
        multiply(a,b,m1,n1,m2,n2);
    }
}

/*  Sample I/O:
    Enter the number of rows and columns in first matrix:2 3                                                                                      
    Enter the elements of first matrix:1 2 3 4 5 6                                                                                                
    Enter the number of rows and columns in second matrix:3 2                                                                                     
    Enter the elements of second matrix:1 2 3 4 5 6                                                                                               
    Product:                                                                                                                                      
    22 28                                                                                                                                         
    49 64  
*/
/* Time Complexity: O(m1*n2*n1)
   Space Complexity: O(m1*n2)
*/
