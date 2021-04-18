// C++ program to implement Maximum Sum Decreasing Subsequence
/*
In this problem, given an array we have to find the maximum sum a decreasing subsequence of that array can make.
This problem is a slight modification to the Longest Decreasing subsequence problem.
The problem can be solved using Dynamic Programming
*/
#include <bits/stdc++.h>
using namespace std;

int max_sum_decreasing_subsequence(int arr[], int n)
{
    int dp[n], max_sum = 0;

    /* Initialize the dp array with the array values, as the maximum sum 
       at each point is atleast as the value at that point         */
    for (int i = 0; i < n; i++)
        dp[i] = arr[i];

    // Now Lets Fill the dp array in Bottom-Up manner
    /* Compare Each i'th element to its previous elements from 0 to i-1, 
       If arr[i] < arr[j], then it qualifies for decreasing subsequence and
       If dp[i] < dp[j] + arr[i], then that subsequence sum qualifies for being the maximum one */
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (arr[i] < arr[j] && dp[i] < dp[j] + arr[i])
                dp[i] = dp[j] + arr[i];

    //Now Find the maximum element in the 'dp' array
    max_sum = *max_element(dp, dp + n);

    return max_sum;
}

int main()
{
    int n, max_sum;
    cout << "\nWhat is the length of the array? ";
    cin >> n;
    int arr[n];
    cout << "Enter the numbers: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    max_sum = max_sum_decreasing_subsequence(arr, n);

    cout << "The maximum sum of an decreasing subsequence of the given array is " << max_sum;
    return 0;
}

/*
Time Complexity: O(num ^ 2), where 'num' is the size of the given array
Space Complexity: O(num)

SAMPLE INPUT AND OUTPUT

SAMPLE 1

What is the length of the array? 10
Enter the numbers: 23 14 5 84 24 222 321 43 123 432
The maximum sum of an  decreasing subsequence of the given array is 444

SAMPLE 2

What is the length of the array? 5
Enter the numbers: 5 4 3 2 1
The maximum sum of an  decreasing subsequence of the given array is 15
*/
