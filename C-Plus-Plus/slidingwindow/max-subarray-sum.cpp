/*
    Problem: Maximum Sum Subarray of Size K
    Language: C++
    Author: <Umang Chandra>
    Description: Find the maximum sum of any contiguous subarray of size K using the Sliding Window technique.
*/

#include <bits/stdc++.h>
using namespace std;

int maxSumSubarray(vector<int>& arr, int k) {
    int n = arr.size();
    if (n < k) return -1;

    int windowSum = 0, maxSum = INT_MIN;

    // Compute sum of first window
    for (int i = 0; i < k; i++) windowSum += arr[i];
    maxSum = windowSum;

    // Slide window
    for (int i = k; i < n; i++) {
        windowSum += arr[i] - arr[i - k];
        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}

int main() {
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;
    cout << "Maximum sum of subarray of size " << k << " = " << maxSumSubarray(arr, k) << endl;
    return 0;
}

/*
Sample Output:
Maximum sum of subarray of size 3 = 9
*/
