/*
Tim Sort is a stable sorting algorithm that combines the capabilities of  Merge sort and Insertion sort.
It first splits the array into  small segments and sort them using Insertion Sort, and then merges the small segments using merge operation.
*/

#include <bits/stdc++.h>
using namespace std;
const int SIZE = 16;

// Perform insertion sort
void insertion_sort(int arr[], int start, int end)
{
    for (int i = start + 1; i <= end; i++)
    {
        int temp = arr[i], j = i - 1;

        /* Shift elements of arr[0..i-1], that are
        greater than temp, to one position ahead
        of their current position */
        while (j >= start && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

// Merge operation to merge two sorted segments
void merge(int arr[], int start, int mid, int end)
{
    int n = mid - start + 1, m = end - mid;
    int arr1[n], arr2[m];

    for (int i = 0; i < n; i++)
        arr1[i] = arr[start + i];
    for (int i = 0; i < m; i++)
        arr2[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = start;

    while (i < n && j < m)
    {
        if (arr1[i] <= arr2[j])
        {
            arr[k] = arr1[i];
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < n)
    {
        arr[k] = arr1[i];
        k++;
        i++;
    }
    while (j < m)
    {
        arr[k] = arr2[j];
        k++;
        j++;
    }
}

// Sort the array using Tim Sort
void tim_sort(int arr[], int n)
{
    // Sort individual subarrays of size SIZE
    for (int i = 0; i < n; i += SIZE)
        insertion_sort(arr, i, min((i + 15), (n - 1)));

    // Merge all the small segments formed
    for (int size = SIZE; size < n; size = 2 * size)
    {
        // From the start of the array, we are going to merge two segments each of size SIZE.
        for (int left = 0; left < n; left += 2 * size)
        {
            // Find  mid point
            int mid = left + size - 1;
            int right = min((left + 2 * size - 1), (n - 1));
            // Merge the two subarrays
            merge(arr, left, mid, right);
        }
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

    tim_sort(arr, n);

    cout << "The numbers in sorted order is: ";
    // Print the sorted array
    for (int i = 0; i < n; i++)
        printf(" %d ", arr[i]);
    cout << "\n";

    return 0;
}

/*
Test Case :

1.
Input:
How many numbers do you want to sort? 5
Enter the numbers: 1 3 5 2 4
Output :
The numbers in sorted order is:  1  2  3  4  5

2.
Input:
How many numbers do you want to sort? 0
Output:
There are no numbers to sort!!!

Time Complexity- O(n*log(n)), where 'n' is the number of elements to sort
Space Complexity- O(n), where 'n' is the number of elements to sort
*/

