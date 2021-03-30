/*  K-TH LARGEST NUMBER
    To find the k-th largest number from an array of distinct numbers
    * The array is sorted in descending order
    * arr[k-1] gives the k-th largest number
*/

#include <stdio.h>
#include <stdlib.h>

//to merge the sorted arrays
void merge(int *ar, int l, int mid, int r)
{
    int i = l, j = mid + 1, k = 0, c[r - l + 1];
    while (i <= mid && j <= r)
    {
        if (ar[i] >= ar[j])
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
        int mid = (l + r) / 2;
        merge_sort(ar, l, mid);
        merge_sort(ar, mid + 1, r);
        merge(ar, l, mid, r);
    }
}

//to find the k-th largest number
int k_largest(int *ar, int k)
{
    return ar[k - 1];
}

//driver code
int main()
{
    int n, k;
    //accept the array and k as user inputs
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *ar = (int *)malloc(sizeof(int) * n);
    printf("Enter the array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &ar[i]);
    printf("Enter the value of k: ");
    scanf("%d", &k);
    merge_sort(ar, 0, n - 1);
    printf("%d", k_largest(ar, k));
    return 0;
}

/*
    Sample Input:
    Enter the number of elements: 6
    Enter the array: 1 5 3 6 2 7
    Enter the value of k: 3

    Sample Output:
    5

    Time Complexity: O(n^2)
    Space complexity: O(n)
*/
