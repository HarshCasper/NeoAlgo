// Kadane's Algorithm for finding the maximum subarray sum

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;
    while (t--)
    {
        // Taking input from the user
        int n, currSum = 0, maxSum = 0;
        cout << "Enter the size of the array: ";
        cin >> n;
        int a[50];

        cout << "Enter the elements of the array: ";
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        // Kadane's Algorithm for Maximum Subarray Sum
        for (int i = 0; i < n; i++)
        {
            currSum += a[i];
            if (currSum < 0)
            {
                currSum = 0;
            }

            // Update the maxSum if currSum is greater than the maxSum
            maxSum = max(maxSum, currSum);
        }
        cout << "Maximum Sum: " << maxSum << endl;
    }
    return 0;
}

/*

Time Complexity: O(n)
Space Complexity: O(1)

Sample I/O:

Enter the number of test cases: 3

Enter the size of the array: 8
Enter the elements of the array: -2 -3 4 -1 -2 1 5 -3
Maximum Sum: 7

Enter the size of the array: 9
Enter the elements of the array: -2 1 -3 4 -1 2 1 -5 4
Maximum Sum: 6

Enter the size of the array: 8
Enter the elements of the array: 1 -3 5 -2 9 -8 -6 4
Maximum Sum: 12

*/