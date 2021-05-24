/**
 * Maximum Sum Subarray od Size k
 * Cpp program to find the maximum currentSum of a subarray of fixed size k,
 * given an array of integers, using the 'Sliding Window Technique',
 */

#include <bits/stdc++.h>
using namespace std;

// Returns maximum Sum in a subarray of size k
int max_sum_subarray(int len, int arr[], int k)
{
    int currentSum = 0;
    int maxSum = INT_MIN;
    //Pointers to represent start and end of every window
    int start = 0, end = 0;
    //Finding sum of all possible k-sized windows, one by one
    while (end < len) {
        currentSum = currentSum + arr[end];
        //Increment end if current window size is less than k
        if (end - start + 1 < k)
            end++;
        else if (end - start + 1 == k) {
            maxSum = max(currentSum, maxSum);
            //Compute sums of remaining windows by removing
            // first element of previous window
            currentSum = currentSum - arr[start];
            //slide the  window
            start++;
            end++;
        }
    }
    return maxSum;
}

int main()
{
    //taking input from user
    int len, k;
    cout << "Enter length of array: ";
    cin >> len;
    cout << "Enter array elements: ";
    int arr[len];
    for (int start = 0; start < len; start++)
        cin >> arr[start];
    cout << "Enter size of window: ";
    cin >> k;
    cout << "Maximum currentSum of a subarray of size k: ";
    cout << max_sum_subarray(len, arr, k);
}

/*
    Test cases:

    INPUT:-
    Enter length of array: 7
    Enter array elements: 2 5 1 8 2 9 1
    Enter size of window: 3
    OUTPUT:
    Maximum currentSum of a subarray of size k: 19

    INPUT
    length of array: 10
    Enter array elements: 1 7 -2 4 5 2 1 6 11 -4
    Enter size of window: 3
    OUTPUT
    Maximum sum of a subarray of size 3: 18

    Time complexity: O(n)
    Space complexity: O(1)

*/
