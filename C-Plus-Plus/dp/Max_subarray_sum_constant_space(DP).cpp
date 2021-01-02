/*

We can easily solve this problem in linear time using kadane’s algorithm.
The idea is to maintain maximum (positive sum) sub-array “ending” at each index of the given array.
This subarray is either empty (in which case its sum is zero) or consists of one more element than the maximum subarray ending at the previous index.
And, To Cover Both Positive and Negative Cases, approach requires two traversals of the input array.

*/

#include <bits/stdc++.h>

#define ll long long int
using namespace std;

// Function to find contiguous sub-array with the largest sum
// in given set of integers (handles negative numbers as well)

int kadane(ll arr[], ll n)
{
    // stores maximum sum sub-array found so far
    ll max_so_far = arr[0]; 

    // stores maximum sum of sub-array ending at current position
    ll max_ending_here = arr[0]; 

    for (ll i = 1; i < n; i++)
    {
        // update maximum sum of sub-array "ending" at index i (by adding current element to maximum sum ending at previous index i-1)
        max_ending_here = max_ending_here + arr[i];   
        
        // maximum sum is should be more than the current element
        max_ending_here = max(max_ending_here, arr[i]); 
        
        // update result if current sub-array sum is found to be greater
        max_so_far = max(max_so_far, max_ending_here); 
    }

    return max_so_far;
}

int main()
{
    ll n;
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "" << kadane(arr, n);

    return 0;
}

/*

Time Complexity : O(n)
Space Complexity: O(1)

Sample Input: 

8
-2 1 -3 4 -1 2 1 -5 4

Sample Output:

6

*/
