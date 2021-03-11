// C++ program to implement In Place Merge Sort
#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(n)

// Merges two subarrays in an inPlace mode
void inplace_merge(int arr[], int beg, int mid, int end)
{
    int sec_beg = mid + 1;

    // If the last element of the first subarray is greater than the first element
    // of the second subarray, then the both arrays are already in sorted order
    if (arr[mid] <= arr[sec_beg])
    {
        return;
    }

    // beg points to the beginning of the first subarray and sec_beg to that of second
    while (beg <= mid && sec_beg <= end)
    {

        // Compare the first element of both the subarrays, to find the smaller one
        //If the first one is smaller, increment beg
        if (arr[beg] <= arr[sec_beg])
        {
            beg++;
        }
        else
        {
            int pos = sec_beg;
            int val = arr[sec_beg];

            // Else Shift all the elements to the right till the second element and
            // place the second element at the first element's position
            for (; pos != beg; pos--)
            {
                arr[pos] = arr[pos - 1];
            }
            arr[beg] = val;

            // Increment the pointers
            beg++;
            mid++;
            sec_beg++;
        }
    }
}

void merge_sort(int arr[], int beg, int end)
{
    if (beg < end)
    {

        //Finds the mid index of the concerned array
        int mid = beg + (end - beg) / 2;

        // Recursively call the function for the first and the second part of the array
        merge_sort(arr, beg, mid);
        merge_sort(arr, mid + 1, end);

        // Merge the two arrays
        inplace_merge(arr, beg, mid, end);
    }
}

int main()
{
    int n;
    cout << "\nHow many numbers do you want to sort? ";
    cin >> n;
    int arr[n];

    if (n <= 0)
    {
        cout << "There are no numbers to sort!!!";
        return 0;
    }
    // Input the numbers to sort
    cout << "Enter the numbers: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    merge_sort(arr, 0, n - 1);

    cout << "The numbers in sorted order is: ";
    // Print the sorted array
    for (int i = 0; i < n; i++)
        printf(" %d ", arr[i]);
    cout << "\n";

    return 0;
}

/*
SAMPLE INPUT AND OUTPUT

SAMPLE 1

How many numbers do you want to sort? 5
Enter the numbers: 1 3 5 2 4
The numbers in sorted order is:  1  2  3  4  5

SAMPLE 2

How many numbers do you want to sort? 0
There are no numbers to sort!!!

*/
