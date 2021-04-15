/* C++ code for 3-way quick sort 
   In simple QuickSort algorithm, we used to select an element as pivot, 
   partition the array around a pivot and recur for subarrays on the left and right of the pivot.
   Whereas in 3 way Quick Sort we process all occurrences of the pivot. */

#include <bits/stdc++.h>
using namespace std;

/* This function divides vector `a` into 3 sections:
   First containing all elements smaller than pivot
   Second containing all occurrences of pivot
   Third containing all elements greater than pivot */ 
void partition(vector<int> &a, int left, int right, int &i, int &j)
{
    if (right - left <= 1)
    {
        /* Swapping is done such that smaller goes on left,
           greater goes on right */
        if (a[right] < a[left])   
            swap(a[right], a[left]);

        i = left;
        j = right;
        return;
    }

    int mid = left;
    int pivot = a[right];
    /*swaps elements such that elements left of `i` are smaller than pivot,
      elements betn `i` and `j` are equal to pivot 
      and element after `j` are greater than pivot */   
    while (mid <= right)
    {
        if (a[mid] < pivot)
            swap(a[left++], a[mid++]);
        else if (a[mid] == pivot)
            mid++;
        else
            swap(a[right--], a[mid]);
        i = left - 1;
        j = mid;
    }
}

/* recursive function to quicksort the array */
void  three_way_quickSort(vector<int> &a, int left, int right)
{
    if (left >= right)
        return;

    // int k = left + (right - left) / 2;
    int i, j;
    partition(a, left, right, i, j);
    three_way_quickSort(a, left, i);
    three_way_quickSort(a, j, right);
}

/* Driver Function */
int main()
{
    int n;
    cout << "Enter the length : \n";
    cin >> n;
    vector<int> a(n);
    /* Input the numbers to sort */
    cout << "Enter the elements : \n";
    for (int i = 0; i < a.size(); i++)
        cin >> a[i];

    /* Call the sort function */
    three_way_quickSort(a, 0, a.size() - 1);

    /* Print the sorted array */
    cout << "Sorted manner of elements : \n";
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << ' ';
}

/*
SAMPLE I/O =>

1)
Enter the length : 
4
Enter the elements : 
10 1 5 3
Sorted manner of elements : 
1 3 5 10

2)
Enter the length : 
5
Enter the elements : 
3 7 2 6 1
Sorted manner of elements : 
1 2 3 6 7

Time complexity : O(n^2)
Space complexity : O(log(n))

*/
