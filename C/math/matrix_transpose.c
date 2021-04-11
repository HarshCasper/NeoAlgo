//C Program to implement Matrix Transpose
#include <stdio.h>
void transpose(int r, int c, int matrix[r][c])
{
    //Taking input of matrix
    printf("Enter the values in matrix  -->\n");
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            scanf("%d", &matrix[i][j]);
    printf("Transpose of a matrix is -->\n");
    for(int i = 0; i < c; i++)
    {   for(int j = 0; j < r; j++)
        {
            //Taking the transpose of a matrix
            printf("%d\t", matrix[j][i]);
        }
        printf("\n");
    }
}
int main()
{
    int i, j , r, c ;
    printf("\nEnter the number of rows in matrix = ");
    scanf("%d", &r);
    printf("\nEnter the number of columns in matrix = ");
    scanf("%d", &c);
    int matrix[r][c];
            transpose(r, c, matrix);
    }

/*
SAMPLE INPUT AND OUTPUT
Enter the number of rows in matrix = 4

Enter the number of columns in matrix = 3
Enter the values in matrix  -->
1   2   3
4   5   6
7   8   9
10  11  12
Transpose of a matrix is -->
1       4       7       10
2       5       8       11
3       6       9       12
*/