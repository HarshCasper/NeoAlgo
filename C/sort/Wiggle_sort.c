/* 
WIGGLE SORT
This program accepts an array of unsorted numbers and
sorts the array such that arr[0]<arr[1]>arr[2]<arr[3]...
*/

#include<stdio.h>
#include <stdlib.h>

//to merge the sorted arrays
void merge(int *ar, int l, int mid, int r)
{
    int i = l, j = mid + 1, k = 0, c[r - l + 1];
    while (i <= mid && j <= r)
    {
        if (ar[i] <= ar[j])
            c[k++] = ar[i++];
        else
            c[k++] = ar[j++];
    }
    if (i > mid && j <= r)
    {
        for (int m = j; m <= r; m++)
            c[k++] = ar[m];
    }
    else if (i <= mid && j > r)
    {
        for (int m = i; m <= mid; m++)
            c[k++] = ar[m];
    }
    for (int m = 0; m < k; m++)
        ar[l++] = c[m];
}

//to sort the array using merge sort
void merge_sort(int *ar, int l, int r)
{
    if (l < r)
    {
        int mid = l + (r-l) / 2;
        merge_sort(ar, l, mid);
        merge_sort(ar, mid + 1, r);
        merge(ar, l, mid, r);
    }
}

void wiggle_sort(int n, int* arr)
{
    int left, right;
    //A new vector res is initialized to store sorted array
    int* res = malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
        res[i]=arr[i];
    //res is sorted with the built-in sort() function.
    merge_sort(res,0, n-1);

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

    for (int i = 0; i < n; i++)
    { //for printing the wiggle sorted array
        printf("%d ",arr[i]);
    }
}

//driver code
int main()
{
    int element, i, no_of_elements;
    printf("Enter the size of array: ");
    scanf("%d", &no_of_elements);
    int *arr=malloc(sizeof(int)*no_of_elements);
    printf("Enter the array: ");
    for (int i = 0; i < no_of_elements; i++)
    { //The given array is stored in a vector arr
       scanf("%d",&arr[i]);
    }
    printf("Wiggle sorted array:\n");
    //to wiggle sort arr
    wiggle_sort(no_of_elements, arr);
    return 0;
}

/*
Sample input:
Enter the size of array: 6
Enter the array: 1 3 2 2 3 1
Sample output:
Wiggle sorted array:
2 3 1 3 1 2

Time Complexity : O(nlogn)   (Sorting takes O(n logn) and traversal takes O(n))
Space Complexity : O(n)   (New array to store the wiggle sorted elements)
*/
