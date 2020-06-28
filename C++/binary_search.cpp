/*
*   Author: Davide Pollicino (@omonimus1)
*   Date: 28/08/2020
*   Last update: 28/08/20, by Davide Pollicino (@omonimus1)
*   Summary: implementation of binary search algorithm to execute search of a target
*            inside a sorted list in O(Log N) time; 
*/

#include<iostream>

using namespace std;

bool binary_search(int arr[], int target, int n)
{
    int left = 0;
    int right = n-1;
    int middle;

    while(left <=right)
    {
        middle = left + (right-left) /2;
        if(arr[middle] == target)
            return true;
        
        if(arr[middle] > target)
            right = middle-1;
        else
            left = middle +1;
    }
    return false;
}


int main()
{
    /* 
    *  @Test 1: Search 5 inside arr1, output expected: 1 (True)
    */

    int size1 = 6;
    int arr1[size1] ={1,2,3,4,5,6};
    cout << binary_search(arr1, 5, size1);
    /* 
    *  @Test 2: Search 12 inside arr2, output expected: 0 (False)
    */
    int size2 = 8;
    int arr2[size2] ={1,2,3,4,5,6,9,14};
    cout << binary_search(arr1, 12, size2) <<endl;
    
    return 0;
}