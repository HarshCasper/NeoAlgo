/* WIGGLE SORT
   This program accepts an array of unsorted numbers and
   sorts the array such that arr[0]<arr[1]>arr[2]<arr[3]...

*/

#include<bits/stdc++.h>
using namespace std;

void wiggle_sort(int n, vector<int> arr)
{
    int left, right;
    //A new vector res is initialized to store sorted array
    vector<int> res(arr);
    //res is sorted with the built-in sort() function.
    sort(res.begin(), res.end());

    /*res is partitioned into two such that left sub-array 
      contains elements less than the elements in right sub-array*/

    // left points to the end of left sub-array 
    left = (n - 1) / 2;
    // right points to the end of right sub-array
    right = n - 1;
    
    //Elements in the left sub-array  are added to the even indices of vector res
    for (int k = 0; k < n; k += 2)
        // left is decremented
        arr[k] = res[left--];

    //Elements in the right sub-array are added to the odd indices of vector x
    for (int k = 1; k < n; k += 2)
        // right is decremented
        arr[k] = res[right--];

    cout << "[";
    for (int i = 0; i < n; i++)
    { //for printing the wiggle sorted array
        cout << arr[i];
        if (i != n - 1)
            cout << ", ";
    }
    cout << "]"
         << "\n";
}

int main()
{
    int element, i, no_of_elements;
    cin >> no_of_elements;
    vector<int> arr;
    for (int i = 0; i < no_of_elements; i++)
    { //The given array is stored in a vector arr
        cin >> element;
        arr.push_back(element);
    }
    //to wiggle sort arr
    wiggle_sort(no_of_elements, arr);
    return 0;
}

/*1. Sample input:
     6
     1 3 2 2 3 1
     Sample output:
     [2,3,1,3,1,2]

  2. Sample input:
     10
     1 4 6 2 3 7 9 2 1 0
     [2, 9, 2, 7, 1, 6, 1, 4, 0, 3]
*/

/*
   Time Complexity : O(nlogn)   (Sorting takes O(n logn) and traversal takes O(n))
   Space Complexity : O(n)   (New array to store the wiggle sorted elements)
*/