// C program to implement Matrix Multiplication
#include <stdio.h>
void matrix_mult(int [][10],int [][10],int [][10],int,int,int,int);
int main()
{
    int r1, c1, r2, c2;
    printf("Enter the number of rows and columns of the first matrix:  ");
    scanf("%d %d", &r1, &c1);
    printf("Enter the number of rows and columns of the second matrix: ");
    scanf("%d %d", &r2, &c2);

    //If the number of columns of the second matrix and the number of rows of first matrix differ, they cannot be added
    if (c1 != r2)
    {
        printf("Given Matrices cannot be multiplyable!!!");
        return 0;
    }

    int A[10][10], B[10][10], C[10][10];
    // Input the values of the matrices
    printf("Enter the values of the first matrix\n");
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
            scanf("%d", &A[i][j]);
    }
    printf("Enter the values of the second matrix\n");
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
            scanf("%d", &B[i][j]);
    }
    matrix_mult(C,A,B,r1,r2,c1,c2);
    printf("The resultant matrix is:\n");
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }
    return 0;
}
void matrix_mult(int C[][10],int A[][10],int B[][10],int r1,int r2,int c1,int c2)
{
    // Multiply both the matrices
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < c1; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }

}

/*
Time Complexity: O(r1 * c2 * c1), where 'r1' is the number of rows of first matrix and 'c2' is the number of columns 
                 of second matrix and 'c1' is the number of columns of first matrix   
Space Complexity: O(r1 * c2)

SAMPLE INPUT AND OUTPUT

Enter the number of rows and columns of the first matrix:  2 2
Enter the number of rows and columns of the second matrix: 2 2
Enter the values of the first matrix
1 1
1 1
Enter the values of the second matrix
1 1
1 1
The resultant matrix is:
2 2
2 2

*/

