/* Row with max 1s = Here given a boolean 2D array where each row is sorted, so here find which first row contain maximum number of 1's.

  ALGORITHM:
* 1st take value row and col by user input where row = No of row, col = No of column and then we create a 2D vector (matrix)
* Then we created a function find_Max1s
  * find_Max1s = 1. 1st initialize i, j=col-1, index = -1
                 2. for i=0 to row
                        while j>=0 
                           if a[i][j]==1
                              index=i
                              j--
                           else
                              break
                 3. return index

*/

#include <bits/stdc++.h>
using namespace std;

// finding row with max 1s
int find_Max1s(vector<vector<int>> a, int row, int col)
{
    int i, j = col - 1, index = -1;
    for (i = 0; i < row; i++)
    {
        while (j >= 0)
        {
            //when a[i][j]==1 then j decrement
            if (a[i][j] == 1)
            {
                //here store the row index i
                index = i;
                j--;
            }
            else
                break;
        }
    }
    return index;
}

int main()
{
    int row, col;
    cout << "No of row : ";
    cin >> row;
    cout << "No of column : ";
    cin >> col;
    vector<vector<int>> a(row, vector<int>(col));
    cout << "Taking the matrix : " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> a[i][j];
        }
    }
    int ans = find_Max1s(a, row, col);
    cout << "Output : ";
    cout << ans << endl;
    return 0;
}

/*

INPUT:
No of row : 5
No of column : 5
Taking the matrix : 
0 0 0 1 1
1 1 1 0 1
1 1 0 0 0
0 0 0 0 0
1 1 1 0 0
Output : 1

Time Complexity : O(row x col) 
Space Complexity : O(1)

*/






