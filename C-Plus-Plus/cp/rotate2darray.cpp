/*
This code is for Rotating an NxN 2D array in 90 degrees anticlockwise direction.
*/

#include <bits/stdc++.h>
using namespace std;

//function to rotate the user  matrix anticlockwise
void rotatematrix(int a[][10], int n)
{
  //reversing each row
  for (int row = 0; row < n; row++)
  {
    int start_col = 0;
    int end_col = n - 1;
    while (start_col < end_col)
    {
      swap(a[row][start_col], a[row][end_col]);
      start_col++;
      end_col--;
    }
  }
  //taking transpose
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i < j)
      {
        swap(a[i][j], a[j][i]);
      }
    }
  }
}
//function for displaying the rotated 2darray/matrix
void display(int a[10][10], int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << a[i][j]<<" ";
    }
    cout<<endl;
  }
}

//driver function
int main()
{
  int a[10][10];
  //'n' here is declared for the order of your matrix
  int n;
  //taking input for the order of matrix
  cout << "enter the order for your square matrix:" << endl;
  cin >> n;

  //taking input for the matrix data
  cout << "please enter the elements of your matrix to be Rotated:" << endl;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> a[i][j];
    }
  }

  cout << "the matrix to be rotated:" << endl;
  //calling the function for displaying the initial matrix
  display(a, n);
  //calling the function for rotating the matrix
  rotatematrix(a, n);
  cout << "the matrix after rotation:" << endl;
  //calling the function for displaying the rotated matrix
  display(a, n);
}
/*EXECUTION:-

SAMPLE OUTPUT-1:
enter the order for your square matrix:
2
please enter the elements of your matrix to be Rotated:
1
2
3
4
the matrix to be rotated:
1 2
3 4
the matrix after rotation:
2 4
1 3

SAMPLE OUTPUT-2:
enter the order for your square matrix:
3
please enter the elements of your matrix to be Rotated:
2
3
4
5
6
7
8
9
1
the matrix to be rotated:
2 3 4
5 6 7
8 9 1
the matrix after rotation:
4 7 1
3 6 9
2 5 8

The time complexity of the code is O(N2) for an N × N matrix 
and it doesn’t require any extra space therefore the space complexity is O(1).
*/
