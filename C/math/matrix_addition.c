// C program to implement Matrix Addition
#include <stdio.h>
void matrix_add(int [][10],int [][10],int [][10],int,int,int,int);
int main()
{
    int r1, c1, r2, c2;
    printf("Enter the number of rows and columns of the first matrix:  ");
    scanf("%d %d", &r1, &c1);
    printf("Enter the number of rows and columns of the second matrix: ");
    scanf("%d %d", &r2, &c2);

    //If the given matrices differ in thier number of rows and columns, they cannot be added
    if ((r1 != r2) || (c1 != c2))
    {
        printf("Given Matrices cannot be added!!!");
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
    matrix_add(C,A,B,r1,r2,c1,c2);
    printf("The resultant matrix is:\n");
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }
    return 0;
}
void matrix_add(int C[][10],int A[][10],int B[][10],int r1,int r2,int c1,int c2)
{
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            // Add the corresponding values of both the matrices
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

/*
Time Complexity: O(r * c), where 'r' is the number of rows and 'c' is the number of columns 
Space Complexity: O(r * c)

SAMPLE INPUT AND OUTPUT

Enter the number of rows and columns of the first matrix:  2 2
Enter the number of rows and columns of the second matrix:  2 2
Enter the values of the first matrix
2 2
2 2
Enter the values of the second matrix
2 2
2 2
The resultant matrix is:
4 4
4 4

*/

