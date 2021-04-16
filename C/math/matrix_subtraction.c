/*
Matrix is a 2-D Array.
The Subtraction of a matrix is possible by subtracting the element of another matrix having same order.
This code gives the output as as difference between two input matrices.
*/
#include <stdio.h>

//Function that computes Matrix Subtraction
void subtract(int row_1, int column_1, int matrix_1[row_1][column_1], int matrix_2[row_1][column_1])
{
    int matrix_3[row_1][column_1];
    for(int i = 0; i < row_1; i++)
        for(int j = 0; j < column_1; j++)
        //Subtracting both the matrix
            matrix_3[i][j] = matrix_1[i][j] - matrix_2[i][j];
            printf("Matrix after subtraction is -->\n");
    for(int i = 0; i < row_1; i++)
    {   for(int j = 0; j < column_1; j++)
        {
            printf("%d\t", matrix_3[i][j]);
        }
        printf("\n");
    }
}

//Function that takes input of both matrices
void input(int row_1, int column_1, int matrix_1[row_1][column_1], int matrix_2[row_1][column_1])
{
    printf("Enter the values in matrix 1 -->\n");
    for(int i = 0; i < row_1; i++)
        for(int j = 0; j < column_1; j++)
            scanf("%d", &matrix_1[i][j]);
            printf("\n\nEnter the values in matrix 2 -->\n");
    for(int i = 0; i < row_1; i++)
        for(int j = 0; j < column_1; j++)
            scanf("%d", &matrix_2[i][j]);
            printf("\n\n");
}

int main()
{
  int row_1, row_2, column_1, column_2;
  printf("\nEnter the number of rows in matrix 1 = ");
  scanf("%d", &row_1);
  printf("\nEnter the number of columns in matrix 1 = ");
  scanf("%d", &column_1);
  printf("\nEnter the number of rows in matrix 2 = ");
  scanf("%d", &row_2);
  printf("\nEnter the number of columns in matrix 2 = ");
  scanf("%d", &column_2);
  int matrix_1[row_1][column_1], matrix_2[row_2][column_2];
  if (row_1 == row_2 && column_1 == column_2)
   {
     input(row_1, column_1, matrix_1, matrix_2);
     subtract(row_1, column_1, matrix_1, matrix_2);
   }
  else
  printf("Subtraction of the given matrices is not possible.");
}

/*
Time Complexity: O(r * c), where 'r' is the number of rows and 'c' is the number of columns
Space Complexity: O(r * c)

SAMPLE INPUT AND OUTPUT
Enter the number of rows in matrix 1 = 2

Enter the number of columns in matrix 1 = 2

Enter the number of rows in matrix 2 = 2

Enter the number of columns in matrix 2 = 2
Enter the values in matrix 1 -->
4 5
6 7

Enter the values in matrix 2 -->
2 3
4 5

Matrix after Subtraction is -->
2       2
2       2
*/

