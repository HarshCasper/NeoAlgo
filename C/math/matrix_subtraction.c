//C program to implement Matrix Subtraction
#include <stdio.h>
void sub(int r1, int c1, int mat1[r1][c1], int mat2[r1][c1])
{
    int mat3[r1][c1];
    for(int i = 0; i < r1; i++)
        for(int j = 0; j < c1; j++)
        //Subtracting both the matrix
            mat3[i][j] = mat1[i][j] - mat2[i][j];
             printf("Matrix after subtraction is -->\n");
    for(int i = 0; i < r1; i++)
    {   for(int j = 0; j < c1; j++)
        {
            printf("%d\t", mat3[i][j]);
        }
        printf("\n");
    }
}
//Taking the input of both matrices
void input(int r1, int c1, int mat1[r1][c1], int mat2[r1][c1])
{
    printf("Enter the values in matrix 1 -->\n");
    for(int i = 0; i < r1; i++)
        for(int j = 0; j < c1; j++)
            scanf("%d", &mat1[i][j]);
    printf("\n\nEnter the values in matrix 2 -->\n");
    for(int i = 0; i < r1; i++)
        for(int j = 0; j < c1; j++)
            scanf("%d", &mat2[i][j]);
    printf("\n\n");
}
int main()
{
    int i, j , r1, r2, c1, c2;
    printf("\nEnter the number of rows in matrix 1 = ");
    scanf("%d", &r1);
    printf("\nEnter the number of columns in matrix 1 = ");
    scanf("%d", &c1);
    printf("\nEnter the number of rows in matrix 2 = ");
    scanf("%d", &r2);
    printf("\nEnter the number of columns in matrix 2 = ");
    scanf("%d", &c2);
    int mat1[r1][c1], mat2[r2][c2];
    //If number of rows and columns of matrix 1 and matrix 2 are different then they cannot be subtracted
            if (r1 == r2 && c1 == c2)
            {
                input(r1, c1, mat1, mat2);
                sub(r1, c1, mat1, mat2);
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