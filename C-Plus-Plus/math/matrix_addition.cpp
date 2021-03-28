// C++ program to implement Matrix Addition
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r1, c1, r2, c2;
    cout << "Enter the number of rows and columns of the first matrix:  ";
    cin >> r1 >> c1;
    cout << "Enter the number of rows and columns of the second matrix: ";
    cin >> r2 >> c2;

    //If the given matrices differ in thier number of rows and columns, they cannot be added
    if ((r1 != r2) || (c1 != c2))
    {
        cout << "Given Matrices cannot be added!!!";
        return 0;
    }
    int A[r1][c1], B[r2][c2], C[r1][c1] = {0};

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

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            // Add the corresponding values of both the matrices
            C[i][j] = A[i][j] + B[i][j];
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
