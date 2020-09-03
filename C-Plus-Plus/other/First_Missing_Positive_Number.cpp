/*
Given an array of integers, find the first missing positive integer in linear time and constant space. In other words, 
find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.

For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

You can modify the input array in-place.

*/

#include<bits/stdc++.h>

using namespace std;

// finding the first missing positive number
int firstMissingNumber(int arr[], int n)
{
    int index, temp;
    // traversing the array
    for (index = 0; index < n; index++)
    {
        // We will ignore the negative numbers and the numbers greater than the array size
        // Also, check if the elements are in correct position, if they is not then do swap
        // operation
        while (arr[index] != arr[arr[index] - 1] && arr[index] >= 1 && arr[index] <= n)
        {
            // Swap operation
            temp = arr[arr[index] - 1];
            arr[arr[index] - 1] = arr[index];
            arr[index] = temp;
        }
    }
    // traversing the array one more time
    for (index = 0; index < n; index++)
    {
        // checking if all the elements are in the correct position
        // The one which is not in the correct position is the first 
        // missing positive number
        if ((index + 1) != arr[index])
            return index + 1;
    }
    return n + 1;
}

// DRIVER FUNCTION
int main()
{
    // size of the array
    int n;
    cout<<"Enter the size of the array: \n";
    // getting the size of the array
    cin >> n;
    int arr[n], index, res;
    cout<<"Enter the elements of the array: \n";
    // getting the array elements
    for (index = 0; index < n; index++)
        cin >> arr[index];
    printf("\n");
    // finding the first positive missing number
    res = firstMissingNumber(arr, n);
    cout <<"The First Missing Positive Number in the given array is: "<<res;
    return 0;
}
/*
For ex:
Example1:
Input:
4
3 4 7 1

Output:
2

Example 2:
Input:
4
3 4 -1 1

Output:
2
*/