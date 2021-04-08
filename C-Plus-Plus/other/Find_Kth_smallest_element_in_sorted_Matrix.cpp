/*  Find Kth smallest element in a row-wise and column-wise sorted Matrix. */

#include<bits/stdc++.h>
using namespace std;

/* Function to find kth smallest element in the matrix */
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
    
    /* Input k */
    int k;
    cin >> k;

    /* Define a min-heap priority queue */
    priority_queue<int, vector<int>> pq;

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        { 
            /* Add the elements in first row of matrix */
            if(pq.size() < k)
            {
                pq.push(a[i][j]);
            }
            else
            {
                /* Pop an element and store the element.
                   Add the element lying in matrix into priority queue. */
                if(a[i][j] < pq.top())
                {
                   pq.pop();
                   pq.push(a[i][j]);
                }
            }
        }
    }
    /* Return last element value store in priority queue. */
    return pq.top();
}

int main()
{
    int k = solve();
        cout << "kth Smallest Element is : " << k << endl;
    return 0;
}

/*
Test cases :
    
    Input 1 :

        4 4
        10 20 30 40
        15 25 35 45
        24 29 37 48
        32 33 39 50
        3

    Output 1 :

        kth Smallest Element is : 20

    Input 2 :

        4 4
        10 20 30 40
        15 25 35 45
        24 29 37 48
        32 33 39 50
        7

    Output 2 :

        kth Smallest Element is : 30
    
    Time complexity: O(r*c)
    Space Complexity: O(1)
*/
