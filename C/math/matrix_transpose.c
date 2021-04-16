/*
Matrix is a 2-D Array.
The transpose of a matrix is formed by turning all the rows of a given matrix into column and vice-versa.
The code gives output as Transpose of a given matrix.
*/
#include <stdio.h>
//Function that computes Transpose of a Matrix
void transpose(int row, int column, int matrix[row][column])
{
    //Taking input as number of rows and columns
    printf("Enter the values in matrix  -->\n");
    for(int i = 0; i < row; i++)
    for(int j = 0; j < column; j++)
    scanf("%d", &matrix[i][j]);
    printf("Transpose of a matrix is -->\n");
    for(int i = 0; i < column; i++)
    {   for(int j = 0; j < row; j++)
        {
            //Taking the transpose of a matrix
            printf("%d\t", matrix[j][i]);
        }
            printf("\n");
    }
}
int main()
{
    int row, column;
    printf("\nEnter the number of rows in matrix = ");
    scanf("%d", &row);
    printf("\nEnter the number of columns in matrix = ");
    scanf("%d", &column);
    int matrix[row][column];
    //call the function that computes the Transpose
    transpose(row, column, matrix);
    }

/*

Sample Output:

Enter the number of rows in matrix = 3
Enter the number of columns in matrix = 3

Enter the values in matrix  -->
1   2   3
4   5   6
7   8   9

Transpose of a matrix is -->
1       4       7
2       5       8
3       6       9

Time Complexity : O(mn)
Space Complexity : O(mn)
where,
       m = number of rows
       n = number of columns
*/
