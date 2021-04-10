// C program to implement Matrix Addition
#include <stdio.h>

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
    int A[r1][c1], B[r2][c2], C[r1][c1];
    //Initialize the resultant matrix with value 0
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            C[i][j] = 0;
        }
    }

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

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            // Add the corresponding values of both the matrices
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    printf("The resultant matrix is:\n");
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    return 0;
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
