// C++ program to implement Matrix Multiplication
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r1, c1, r2, c2;
    cout << "Enter the number of rows and columns of the first matrix:  ";
    cin >> r1 >> c1;
    cout << "Enter the number of rows and columns of the second matrix: ";
    cin >> r2 >> c2;

    //If the number of columns of the second matrix and the number of rows of first matrix differ, they cannot be added
    if (c1 != r2)
    {
        cout << "Given Matrices cannot be multiplyable!!!";
        return 0;
    }
    int A[r1][c1], B[r2][c2], C[r1][c2] = {0};

    // Input the values of the matrices
    cout << "Enter the values of the first matrix\n";
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
            cin >> A[i][j];
    }
    cout << "Enter the values of the second matrix\n";
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
            cin >> B[i][j];
    }

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

    cout << "The resultant matrix is:\n";
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }
    return 0;
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
