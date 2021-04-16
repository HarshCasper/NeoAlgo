/*
Inplace rotation of matrix by 90 degrees.

For a given matrix your task is to rotate it by 90 degrees
in anti clockwise direction and return the matrix thus formed.
It is given that the rotation should be performed 
without using any extra space.
*/

#include <bits/stdc++.h>

using namespace std;

//for solving this problem we first find the transpose of the
//given matrix and then reverse the columns without any extra space

//function to swap elements of columns for 
//finding anti clockwise rotation of the given matrix by 90 degrees 
void reverseCol(int matrix[][], int row, int column)
{
    for(int pass = 0; pass < column; pass++)
    {
        for(int upperptr = 0, lowerptr = column - 1;
             upperptr < lowerptr; upperptr++, lowerptr--)
        {
            //swap
            int temp = matrix[upperptr][pass];
            matrix[upperptr][pass] = matrix[lowerptr][pass];
            matrix[lowerptr][pass] = temp;
        }
    }
}

//function to find the transpose of matrix
void transposeOfMat(int matrix[][], int row, int column)
{
    for(int pass = 0; pass < row; pass++)
    {
        for(int upperptr = pass; upperptr < column; upperptr++)
        {
            //swap
            int temp = matrix[pass][upperptr];
            matrix[pass][upperptr] = matrix[upperptr][pass];
            matrix[upperptr][pass] = temp;
        }
    }
}

///function for printing the new matrix which we obtain
void printMatrix(int matrix[][], int row, int column)
{
    for(int pass1 = 0; pass1 < row; pass1++)
    {
        for(int pass2 = 0; pass2 < column; pass2++)
        {
            //printing
            cout << matrix[pass1][pass2] << " ";
        }
        cout << endl;
    }
}

//function to finally rotate the matrix by 90 degrees
void rotateBy90Deg(int matrix[][], int row, int column)
{
    //to rotate by 90 degrees we first take transpose
    //and then reverse the matrix obtained after taking transpose
    transposeOfMat(matrix, row, column);
    reverseCol(matrix, row, column);
}

//driver code
int main()
{
    //taking input
    int row, column;
    cout << "Enter the number of rows: ";
    cin >> row;
    cout << "Enter the number of columns: "
    cin >> column;
    int matrix[row][column];
    cout << "Enter the elements of matrix: ";
    for( int i = 0; i < row; i++)
    {
        for( int j = 0; j < column; j++)
        {
            cin >> martix[i][j];
        }
    }
    //for output
    cout << "The rotated matrix is: "
    rotateBy90Deg(matrix, row, column);
    printMatrix(matrix, row, column);
    return 0;
}

/*
EXAMPLE--
Input:
Enter the number of rows: 4
Enter the number of columns: 4
Enter the elements of matrix: {[1, 2, 3, 4],
                                [5, 6, 7, 8],
                                [9, 10, 11, 12],
                                [13, 24, 15, 16]}
Output:
The rotated matrix is: 4 8 12 16
                       3 7 11 16
                       2 6 10 14
                       1 5 9 13

TIME COMPLEXITY --> O(ROW * COLUMN)
SPACE COMPLEXITY --> 0(1)
*/
