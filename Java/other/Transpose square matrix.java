//Transpose of a matrix is obtained by changing rows to columns and columns to rows. In other words, transpose of A[][] is obtained by changing A[i][j] to A[j][i].

import java.util.Scanner;
public class MatrixTranspose 
{
    public static void main(String args[])  
    {
        int i, j;
        System.out.println("Enter total rows and columns: ");
        Scanner s = new Scanner(System.in);
        int row = s.nextInt(); 
        int column = s.nextInt();
        int array[][] = new int[row][column];
        System.out.println("Enter matrix:");
        for(i = 0; i < row; i++)
        {
            for(j = 0; j < column; j++) 
                {
                    array[i][j] = s.nextInt(); // for taking input
                    System.out.print(" "); //new line
                }
        }
        System.out.println("The above matrix before Transpose is ");
        for(i = 0; i < row; i++)
        {
            for(j = 0; j < column; j++)
            {
                System.out.print(array[i][j]+" "); //Priting matrix as entered
            }
            System.out.println(" ");
        }
        System.out.println("The above matrix after Transpose is ");
        for(i = 0; i < column; i++)
        {
            for(j = 0; j < row; j++)
            {
                System.out.print(array[j][i]+" "); //Printing transposed matrix
            }
            System.out.println(" ");
            }
        }
    }
}

/*Enter total rows and columns: 
3 3
Enter matrix:
1
2
3
4
5
6
7
8
9
The above matrix before Transpose is 
1 2 3  
4 5 6  
7 8 9  
The above matrix after Transpose is 
1 4 7  
2 5 8  
3 6 9
*/
