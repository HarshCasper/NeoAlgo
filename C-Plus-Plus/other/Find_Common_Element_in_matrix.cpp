/*  Find a Common element in rows of a given row-wise sorted matrix.

    Given a matrix where every row is sorted in increasing order.
    Write a function that finds and returns a common element in all rows.
    If there is no common element, then returns -1.

    Example 1 :

    Input 1 : 1 2 3 4 5
              2 4 5 8 10
              3 5 7 9 11
              1 3 5 7 9 
    
    Output 1 : Common element is : 5

    Example 2 :

    Input 2 : 2 4 3 8 7
              1 3 5 6 8
              1 2 3 1 3
              4 5 0 2 3
    
    Output 2 : No Common element

    Algorithm :
    Step1 : Create a Hash Table with all key as distinct elements 
            of row1. Value for all these will be 0.

    Step2 : Insert elements of the first row and initialize them with 
            a value of 1 and Check if the current element in the map
            and first in the current row Update the value of this key 
            in HashTable with current row number
        
    Step3 : Iterate over HashTable and print all those keys for 
            which value = 1 
*/

//CODE :-
#include<bits/stdc++.h>
using namespace std;

// Function to find common element in the matrix
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
    
    // Create a hash map to store 
    // count of element
    unordered_map<int, int> count;
  
    for (int i = 0; i < r; i++) {
        
        for (int j = 1; j < c; j++) {

            // Insert elements of the first row and
            // initialize them with a value of 1
            if (i == 0) {
                count[a[0][i]] = 1;
            }
            
            // Check if the current element exists
            // in the map and first in the current row
            if (a[i][j] != a[i][j - 1])
                count[a[i][j]]++;
        }
    }
      
    // Return the element having a count 1
    for (auto element : count) {
        if (element.second == r)
            return element.first;
    }

    // Return the element having a count not equal to 1
    return -1;
}

int main()
{
    // Input the test cases.
    int t;
    cin >> t;
    while(t--)
    {
        int common = solve();

        if (common == -1)
        cout << "No Common element"<< endl;
        else
        cout << "Common element is : " << common << endl;
    }
    return 0;
}

/*
Test cases :
    
    Input :
        3
        4 5
        1 2 3 4 5
        2 4 5 8 10
        3 5 7 9 11
        1 3 5 7 9
        4 5
        2 3 4 7 8
        1 3 4 6 7
        1 2 3 3 5
        1 2 3 4 5
        4 5
        2 4 3 8 7
        1 3 5 6 8
        1 2 3 1 3
        4 5 0 2 3
    
    Output :
        Common element is : 5
        Common element is : 3
        No Common element
    
    Time complexity: O(r*c)
    Space Complexity: O(1)
*/