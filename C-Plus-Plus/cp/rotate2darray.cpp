/*
This code is for Rotating an NxN 2D array in 90 degrees anticlockwise direction.
*/

#include<bits/stdc++.h>
using namespace std;

//function to rotate the user  matrix anticlockwise
void rotate(int a[][1000], int n)
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
void display(int a[1000][1000], int n){
    for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << a[i][j];
    }
  }

}

int main()
{
  int a[1000][1000];
  int n;
  //input order of matrix
  cin >> n;
  //input the matrix data 
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> a[i][j];
    }
  }

  rotate(a, n);
  display(a, n);
}
/*EXECUTION:
SAMPLE INPUT:
3
4
3
2
6
5
4
7
6
5

SAMPLE OUTPUT:
245
356
467


*/