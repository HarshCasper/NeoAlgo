/*
Inplace rotation of matrix by 90 degrees.

For a given matrix your task is to rotate it by 90 degrees
in anti clockwise direction and return the matrix thus formed.
It is given that the rotation should be performed 
without using any extra space.
*/

#include <bits/stdc++.h> 

using namespace std;

//for solving this problem we rotate the array in form of outer
//squares making a boundary i.e first row, last column
//last row and first column as 1 square and remaing inside elements considered similarly 

//function to find the rotated matrix inplace
void rotateBy90Deg(int matrix[][order])
{
    //we consider the squares one by one
    for(int squarCount = 0; squarCount < order / 2; squarCount++)
    {
        //we consider the elements in a sets of 4 elements one by one
        for(int i = squarCount; i < order - squarCount - 1; i++)
        {
            //swapping for rotation
            int tempmat = matrix[squarCount][i];
            //rotating
            matrix[squarCount][i] = matrix[i][order - squarCount - 1];
            matrix[i][order - squarCount - 1] = matrix[order - squarCount - 1][order - i - 1];
            matrix[order - squarCount - 1][order - i - 1] = matrix[order - i - 1][squarCount];
            matrix[order - i - 1][squarCount] = tempmat;
        }
    }
}

///function for printing the matrix 
void printMatrix(int matrix[][order])
{
    for(int pass1 = 0; pass1 < order; pass1++)
    {
        for(int pass2 = 0; pass2 < order; pass2++)
        {
            //printing
            cout << matrix[pass1][pass2] << " ";
        }
        cout << endl;
    }
}

//driver code
int main()
{
    //taking input
    int order;
    cout << "Enter the order of matrix: ";
    cin >> order;
    int matrix[order][order];
    cout << "Enter the elements of matrix: ";
    for( int i = 0; i < order; i++)
    {
        for( int j = 0; j < order; j++)
        {
            cin >> matrix[i][j];
        }
    }
    //for output
    cout << "The rotated matrix by 90 degrees is : ";
    rotateBy90Deg(matrix);
    printMatrix(matrix);
    return 0;
}

/*
EXAMPLE--
Input:
Enter the order of matrix: 4
Enter the elements of matrix: 1 2 3 4
                              5 6 7 8
                              9 10 11 12
                              13 24 15 16
Output:
The rotated matrix by 90 degrees is : 4 8 12 16
                                      3 7 11 15
                                      2 6 10 14
                                      1 5 9 13

TIME COMPLEXITY --> O(n ^ 2); where n is order of the matrix
SPACE COMPLEXITY --> 0(1)
*/
