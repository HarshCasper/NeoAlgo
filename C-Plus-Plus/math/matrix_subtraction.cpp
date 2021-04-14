/*
Matrix is a 2-D Array.
The Subtraction of a matrix is possible by subtracting the element of another matrix having same order.
This code gives the output as as difference between two input matrices.
*/
#include <bits/stdc++.h>
using namespace std;

//Function that computes Matrix Subtraction
void subtract(int row_1, int column_1, int matrix_1[][10], int matrix_2[][10])
{
    int matrix_3[10][10];
    for(int i = 0; i < row_1; i++)
        for(int j = 0; j < column_1; j++)
        //Subtracting both the matrix
            matrix_3[i][j] = matrix_1[i][j] - matrix_2[i][j];
            cout<<"Matrix after subtraction is -->\n";
    for(int i = 0; i < row_1; i++)
    {   for(int j = 0; j < column_1; j++)
        {
            cout<<matrix_3[i][j]<<"\t";
        }
        cout << "\n";
    }
}

//Function that takes input of both matrices
void input(int row_1, int column_1, int matrix_1[][10], int matrix_2[][10])
{
    cout<<"Enter the values in matrix 1 -->\n";
    for(int i = 0; i < row_1; i++)
        for(int j = 0; j < column_1; j++)
            cin >> matrix_1[i][j];
            cout<<"\n\nEnter the values in matrix 2 -->\n";
    for(int i = 0; i < row_1; i++)
        for(int j = 0; j < column_1; j++)
            cin >> matrix_2[i][j];
}

int main()
{
  int row_1, row_2, column_1, column_2;
  cout<<"\nEnter the number of rows in matrix 1 = ";
  cin >> row_1;
  cout <<"\nEnter the number of columns in matrix 1 = ";
  cin >> column_1;
  cout << "\nEnter the number of rows in matrix 2 = ";
  cin >> row_2;
  cout << "\nEnter the number of columns in matrix 2 = ";
  cin >> column_2;
  int matrix_1[10][10], matrix_2[10][10];
  if (row_1 == row_2 && column_1 == column_2)
   {
     input(row_1, column_1, matrix_1, matrix_2);
     subtract(row_1, column_1, matrix_1, matrix_2);
   }
  else
  cout << "Subtraction of the given matrices is not possible.";
}

/*
SAMPLE INPUT AND OUTPUT :
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

Time Complexity: O(r * c)
Space Complexity: O(r * c)
where,
       r = number of rows
       c = number of columns
*/
