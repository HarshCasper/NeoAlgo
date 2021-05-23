/*
We can use binary search to reduce the number of comparisons in normal insertion sort.
Binary Insertion Sort uses binary search to find the proper location to insert the selected item at each iteration. 
In normal insertion sort, it takes O(n) comparisons (at nth iteration) in the worst case.
We can reduce it to O(log n) by using binary search.
*/

#include<bits/stdc++.h>
using namespace std;

//searching element in array a by binary search algoritm
int binarySearch(int a[], int element, int low, int high)
{
    if (high <= low){
        return (element > a[low]) ? (low + 1) : low;
    }
    int mid = (low + high) / 2;
    if (element == a[mid]){
        return mid + 1;
    } 
    if (element > a[mid]){
        return binarySearch(a, element, mid + 1, high);
    }
    return binarySearch(a, element, low, mid - 1);
}
// sorting using insertion sort
void insertionSort(int arr[], int n)
{
    // initializing variables
    int i, place, j, k, selected;
    for (i = 1; i < n; ++i) 
    {
        j = i - 1;
        selected = arr[i];

        // location where selected sould be inseretd
        place = binarySearch(a, selected, 0, j);

        // Move all elements after location to create space
        while (j >= place) 
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = selected;
    }
}

signed main()
{
    //Taking Input
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //Applying Sort
    //calling sort function
    insertionSort(a, n);
    cout<<"Sorted Array is :-";
    for (int i = 0; i < n; i++){ 
        cout<<arr[i]<<" ";
    }
    return 0;
}
/* Sample Input
11
35 23 12 17 12 72 31 46 180 88 54
*/
/* Sample Output
Sorted Array is:- 12 12 17 23 31 35 46 54 72 88 180
*/

// Time Complexity -O(n^2)
//Space Complexity -O(n)
