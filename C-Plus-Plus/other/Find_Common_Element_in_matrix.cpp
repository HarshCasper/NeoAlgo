/*  Find a Common element in rows of a given row-wise sorted matrix. */

#include<bits/stdc++.h>
using namespace std;

/* Function to find common element in the matrix */
int solve()
{
    /* Input row = size of row.
       Input col = size of column. */
    int row,col;
    cin >> row >> col;

    /* Input elements in matrix. */
    int a[row][col];
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            cin >> a[i][j];
        }
    }
    
    /* Create a hash map to store 
     count of element */
    unordered_map<int, int> count;
  
    for (int i = 0; i < row; i++) {
        
        for (int j = 1; j < col; j++) {

            /* Insert elements of the first row and
               initialize them with a value of 1 */
            if (i == 0) {
                count[a[0][i]] = 1;
            }
            
            /* Check if the current element exists
               in the map and first in the current row */
            if (a[i][j] != a[i][j - 1])
                count[a[i][j]]++;
        }
    }
      
    /* Return the element having a count 1 */
    for (auto element : count) {
        if (element.second == row)
            return element.first;
    }

    /* Return the element having a count not equal to 1 */
    return -1;
}

int main()
{
    int common = solve();

    if (common == -1)
        cout << "No Common element"<< endl;
    else
        cout << "Common element is : " << common << endl;
    return 0;
}

/*
Test cases :
    
    Input 1 :

        4 5
        1 2 3 4 5
        2 4 5 8 10
        3 5 7 9 11
        1 3 5 7 9

    Output 1 :

        Common element is : 5

    Input 2 :

        4 5
        2 4 3 8 7
        1 3 5 6 8
        1 2 3 1 3
        4 5 0 2 3
    
    Output 2 :
    
        No Common element
    
    Time complexity: O(r*c)
    Space Complexity: O(1)
*/
