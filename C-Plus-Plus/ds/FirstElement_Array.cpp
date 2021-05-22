/* Given an array of n integers. The task is to find the first element that occurs k number of
times. If no element occurs k times the print -1. The distribution of integer elements could
be in any range.*/

#include <bits/stdc++.h>
using namespace std;

// function to find the first element
// occurring k number of times
int firstElement(int arr[], int n, int k)
{
    // unordered_map to count
    // occurrences of each element
    unordered_map<int, int> count_map;
    for (int i = 0; i < n; i++)
        count_map[arr[i]]++;

    for (int i = 0; i < n; i++)

        // if count of element == k ,then
        // it is the required first element
        if (count_map[arr[i]] == k)
            return arr[i];

    // no element occurs k times
    return -1;
}

// Driver program to test above
int main()
{
    int arr[] = {1, 7, 4, 3, 4, 8, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    cout << firstElement(arr, n, k);
    return 0;
}

/*Sample test cases
Input : {1, 7, 4, 3, 4, 8, 7}, 
        k = 2
Output : 7

Time Complexity: O(n)
Space Complexity: O(n)
*/