/*  Find Kth smallest element in a row-wise and column-wise sorted Matrix.

    Given an r x c matrix, where every row and column is sorted in
    non-decreasing order. Find the kth smallest element in the given
    Matrix.

    Example 1 :

    Input 1 :  10 20 30 40
            15 25 35 45
            24 29 37 48
            32 33 39 50 

            k = 3
    
    Output 1 : 20

    Example 2 :

    Input 2 :  10 20 30 40
            15 25 35 45
            24 29 37 48
            32 33 39 50 

            k = 7
    
    Output 2 : 30

    Algorithm :

    1) Define a min-heap priority queue.
    2) Add the elements from the first row of mat[][] (input matrix) into priority queue.
    3) Now, run a loop k-times. The loop variable is i, inside that loop perform steps below :
       - Pop an element from pq and store the popped element into kthsmall.
       - Add the element lying in mat[][] just below kthsmall into pq.
    4) After the loop ends, return the last element value stored in kthsmall (ie kthsmall.num).

*/

//CODE :-
#include<bits/stdc++.h>
using namespace std;

// Function to find kth smallest element in the matrix
int solve()
{
    // Input r = size of row.
    // Input c = size of column.
    int r,c;
    cin >> r >> c;

    // Input elements in matrix.
    int a[r][c];
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            cin >> a[i][j];
        }
    }    
    
    // Input 
    int k;
    cin >> k;

    // Define a min-heap priority queue
    priority_queue<int, vector<int>> pq;

    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        { 
            // Add the elements in first row of matrix
            if(pq.size() < k)
            {
                pq.push(a[i][j]);
            }
            else
            {
                // Pop an element and store the element.
                // Add the element lying in matrix into priority queue.
                if(a[i][j] < pq.top())
                {
                   pq.pop();
                   pq.push(a[i][j]);
                }
            }
        }
    }
    // Return last element value store in priority queue.
    return pq.top();
}

int main()
{
    // Input the test cases.
    int t;
    cin >> t;
    while(t--)
    {
        int k = solve();
        cout << "kth Smallest Element is : " << k << endl;
    }
    return 0;
}

/*
Test cases :
    
    Input :
        3
        4 4
        10 20 30 40
        15 25 35 45
        24 29 37 48
        32 33 39 50
        3
        4 4
        10 20 30 40
        15 25 35 45
        24 29 37 48
        32 33 39 50
        7
        3 3
        1 5 9 
        10 11 13
        12 13 15
        8

    Output :
        kth Smallest Element is : 20
        kth Smallest Element is : 30
        kth Smallest Element is : 13

    
    Time complexity: O(r*c)
    Space Complexity: O(1)
*/
