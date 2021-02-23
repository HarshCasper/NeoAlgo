/*
Selection Sort Algorithm:
The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning.
The algorithm maintains two subarrays in a given array.
1) The subarray which is already sorted.
2) Remaining subarray which is unsorted.
In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray
*/

#include <bits/stdc++.h>
using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
    cout << "Sorted Array:" <<"\n";
    for (i = 0;i < n;i++)
    {
        cout << arr[i] <<"\n";
    }
}
// Driver program to test above functions
int main()
{
    int n;
    cout << "Enter size of array: "<<endl;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    selectionSort(a, n);
    return 0;
}


/*
Sample Input : Enter size of array:
               n = 5
               12
               5
               -9
               8
               6
Sample Output : Sorted Array:
                -9 5 6 8 12
Time Complexity : O(n^2)
Space Complexity : O(1)
*/
