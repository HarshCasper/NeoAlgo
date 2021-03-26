/**
 * Maximum of Minimum for Every Window Size in an Array
 * Find the maximum of the minimum of every window size in a given 
 * positive integer array of size len. The size of windows in an array 
 * vary from 1 to len. 
 */

#include <bits/stdc++.h>
using namespace std;

void printMaxOfMin(int arr[], int len)
{ // Used to find previous and next smaller
    stack<int> s;

    // Arrays to store previous and next smaller
    int left[len + 1];
    int right[len + 1];

    // Initialize elements of left[] and right[]
    for (int i = 0; i < len; i++) {
        left[i] = -1;
        right[i] = len;
    }

    // Fill elements of left[]
    /* If stack is not empty, then pop an element from stack. 
       If the popped element is smaller than next, then 
    a) store it in left[]
    b) keep popping while elements are 
    smaller and stack is not empty */
    for (int i = 0; i < len; i++) {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();

        if (!s.empty())
            left[i] = s.top();
        /* push next to stack so that we can find next greater for it */
        s.push(i);
    }

    // Empty the stack as stack is going to be used for right[]
    while (!s.empty())
        s.pop();

    // Fill elements of right[] using same logic as left
    for (int i = len - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();

        if (!s.empty())
            right[i] = s.top();

        s.push(i);
    }

    // Create and initialize answer array
    int ans[len + 1];
    for (int i = 0; i <= len; i++)
        ans[i] = 0;

    // Fill answer array by comparing minimums of all
    // lengths computed using left[] and right[]
    for (int i = 0; i < len; i++) {
        // length of the interval
        int len = right[i] - left[i] - 1;

        // arr[i] is a possible answer for this length
        // 'len' interval, check if arr[i] is more than
        // max for 'len'
        ans[len] = max(ans[len], arr[i]);
    }

    // Some entries in ans[] may not be filled yet. Fill
    // them by taking values from right side of ans[]
    for (int i = len - 1; i >= 1; i--)
        ans[i] = max(ans[i], ans[i + 1]);

    // Print the result
    cout << "Array of maximum of the minimum of every window size from 1 to " << len << ": ";
    for (int i = 1; i <= len; i++)
        cout << ans[i] << " ";
}

int main()
{ //Take input from user
    int len;
    cout << "Enter length of array of integers: ";
    cin >> len;
    int arr[len];
    cout << "Enter array of integers: ";
    for (int i = 0; i < len; i++)
        cin >> arr[i];
    printMaxOfMin(arr, len);
    return 0;
}

/*
    Test Cases

    INPUT
    Enter length of array of integers: 9
    Enter array of integers: 8 6 5 3 5 6 7 7 10
    OUTPUT
    Array of maximum of the minimum of every window size from 1 to 9: 10 7 7 6 5 3 3 3 3 

    INPUT
    Enter length of array of integers: 5
    Enter array of integers: 7 4 3 1 5
    OUTPUT
    Array of maximum of the minimum of every window size from 1 to 5: 7 4 3 1 1 

    Time complexity: O(N)
    Space complexity: O(N)

*/
