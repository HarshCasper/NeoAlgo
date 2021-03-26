/**
 * Longest Subarray Having Sum k
 * Given an array of integers, find the length of the longest sub-array 
 * having sum equal to the given value k.
 */

#include <bits/stdc++.h>
using namespace std;

int LongestSubarraySum(int len, int arr[], int k)
{
    //Variable to store length of longest subarray with sum k
    int length = INT_MIN;
    //2 pointers indicating current window
    int start = 0, end = 0;
    //store cumulative sum as we traverse the array
    long long sum = 0;
    while (end < len) {
        sum = sum + arr[end];
        //If k is greater than sum then increase the size of current window
        if (sum < k)
            end++;
        //Checking if sum equals k then update length as max of window size and length
        //then increase window size
        else if (sum == k) {
            length = max(length, end - start + 1);
            end++;
        }
        //Check if cumulative sum is more than k then remove element
        //at start of current window until it is greater than k
        else if (sum > k) {
            while (sum > k) {
                sum = sum - arr[start];
                start++;
            }
            end++;
        }
    }

    return length;
}

int main()
{
    //Taking input from user
    int len;
    cout << "Enter length of array of integers: ";
    cin >> len;
    int arr[len];
    cout << "Enter array of integers: ";
    for (int i = 0; i < len; i++)
        cin >> arr[i];
    int k;
    cout << "Enter sum: ";
    cin >> k;
    cout << "Length of Longest Subarray having Sum " << k << ": ";
    cout << LongestSubarraySum(len, arr, k);
}

/*
	Test Cases:

    INPUT:
	Enter length of array of integers: 8
	Enter array of integers: 5 4 1 1 1 2 3 1
	Enter sum: 5
	OUTPUT:
    Length of Longest Subarray having Sum 5: 4

	INPUT:
	Enter length of array of integers: 6
    Enter array of integers: -5 8 -14 2 4 12
    Enter sum: -5
	OUTPUT:
	Length of Longest Subarray having Sum -5: 5


	Time complexity: O(N)
	Space complexity: O(1)

 */
