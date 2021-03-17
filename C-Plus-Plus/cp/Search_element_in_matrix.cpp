/* 
Given a sorted n x n matrix and an element x, check if the element x is present in the matrix or not. 
If yes, then print the position of the element in the matrix otherwise print "Element not found".
*/

#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

static void binarySearch(int m[][MAX], int row, int col, int x, int k) // k is the row number
{
    // Applying binary search for the elements in row number k
    int left = 0, right = col - 1, mid;
    while (left <= right) 
    {
        mid = (left + right) / 2;
        if (m[k][mid] == x) 
        {
            cout<<"Found at ("<<k<<","<<mid<<") \n";
            return;
        }
        if (m[k][mid] > x)
            right = mid - 1;
        if (m[k][mid] < x)
            left = mid + 1;
    }
    cout<<"Element not found \n";
}

static void findRow(int m[][MAX], int row, int col, int x)
{
    int left = 0, right = row - 1, mid;
    while (left <= right) 
    {
        mid = (left + right) / 2;

        if (x == m[mid][0]) // checking leftmost element
        {
            cout<<"Found at ("<<mid<<",0) \n";
            return;
        }
 
        if (x == m[mid][col - 1]) // checking rightmost element
        {
            int t = col - 1;
            cout<<"Found at ("<<mid<<","<<t<<") \n";
            return;
        }
 
        if ((x > m[mid][0]) && (x < m[mid][col - 1])) // this means the element must be within this row
        {
            binarySearch(m, row, col, x, mid); // Applying binay search on this row
            return;
        }
 
        if (x < m[mid][0])
            right = mid - 1;
        if (x > m[mid][col - 1])
            left = mid + 1;
    }
}
   
int main() 
{
    int row = 4, col = 5;
    int mat[][MAX] = {{0, 6, 8, 9, 11},
                     {20, 22, 28, 29, 31},
                     {36, 38, 50, 61, 63},
                     {64, 66, 100, 122, 128}};

    int num;
    cout<<"Enter the element to be searched in the matrix : \n";
    cin>>num;

    findRow(mat, row, col, num);

}


/*
Input: 
31
Output: 
Found at (1,4)
Input: 
8
Output: 
Found at (0,2)
Input: 
27
Output: 
Element not found 

Time Complexity: O(log(m) + log(n))
Space Complexity: O(1)
*/

