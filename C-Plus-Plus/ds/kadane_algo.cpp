/*  (1) Kadane’s algorithm is used for “Maximum subarray sum” in any given array of integers.
    (2) An algorithm to find the contiguous sub-array within a one-dimensional numeric array which has the largest sum, called 'Kadane's Algorithm'.
    (3) There will be negative elements in the array which will decrease the sum of the whole array.
    (4) If all the elements of array are negative then the maximum sum will be the first element of the array
     because if we add negative numbers , it will decrease the sum.
    eg: arr[5] = {-1, -2, -3, -4, -5};
    here, maximum sum of subarray will be -1.
*/

#include <iostream>
using namespace std;

//create a function to give the maximum sum of a contiguous subarray in an array...
int maxSumOfSubArray(int arr[], int n)
{
    /*initially we take current sum and maximum sum as the first element of array arr[0] to handle that array
     which negative elements are negative.*/

    int cur_sum = arr[0];
    int max_sum = arr[0];

    for (int i = 0; i < n; i++)
    {
        //conditions to check the maximum sum...
        cur_sum = max(arr[i], cur_sum + arr[i]);
        max_sum = max(max_sum, cur_sum);
    }
    return max_sum;
}

int main()
{
    int n;
    cout << "Enter the size of array :" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array :" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    //call the function
    int maxSubArraySum = maxSumOfSubArray(arr, n);
    cout << "The maximum sum of a contiguous subarray is :" << endl;
    cout << maxSubArraySum;

    return 0;
}

/* (1)
   Sample Input :  
   Enter the size of array :
   5
   Enter the elements of the array :
   -1 -2 -3 -4 -5
   Sample Output :
   The maximum sum of a  contiguous subarray is :
   -1 

   (2)
   Sample Input :  
   Enter the size of array :
   8
   Enter the elements of the array :
   -2 -3 4 -1 -2 1 5 -3
   Sample Output :
   The maximum sum of a  contiguous subarray is :
   7

   Time Complexity : O(n)
   Space Complexity : O(1)
*/
