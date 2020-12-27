// The Boyer–Moore majority vote algorithm in C++

#include <bits/stdc++.h>
using namespace std;

// To find majority element
int majority(int arr[], int arrsize)
{
    int count = 0;
    for (int i = 0; i < arrsize - 1; i++) {
        count = 1;
        for (int j = i + 1; j < arrsize; j++) {
            // Counting occurance of elements.
            if (arr[j] == arr[i]) {
                count++;
            }
        }
        // checking for majority
        if (count > arrsize / 2)
            return arr[i];       
    }
    return -1;
}

int main()
{
    int n;
    cout << "Enter no of elements:";
    cin >> n;
    cout << "\nEnter elements: ";
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int result = majority(arr, n);
    if (result != -1)
        cout << "Majority of a sequence is" << result << endl;
    else
        cout << "There is no majority \n";
    return 0;
}

/* input/output:
Enter no of elements:5
Enter elements: 1 1 1 1 2
Majority of a sequence is 1

Enter no of elements:5
Enter elements: 1 2 3 2 4
There is no Majority.

Time complexity : O(n^2)
Space complexity: O(1)
*/
