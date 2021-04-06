/*
Problem Statement:
Given an array of integers. Find the Inversion Count in the array.
Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
*/

#include <stdio.h>

// answer stores the inversion count.
int answer = 0;

// Merge function helps us to caluculate the inversion count.
void Merge(int input[], int start, int end, int mid)
{
    // temp is an array, which finally stores the elements of input array in sorted manner.
    int temp[end - start + 1];
    int left = start, right = mid + 1, new_ind = 0;
    while (left <= mid && right <= end)
    {
        if (input[left] <= input[right])
        {
            temp[new_ind++] = input[left++];
        }
        else
        {
            // In this case, inversions are possible.
            answer += (mid - left + 1);
            temp[new_ind++] = input[right++];
        }
    }
    while (left <= mid)
    {
        temp[new_ind++] = input[left++];
    }
    while (right <= end)
    {
        temp[new_ind++] = input[right++];
    }
    for (int index = start; index <= end; index++)
    {
        input[index] = temp[index - start];
    }
    return;
}

void MergeSort(int input[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = start + (end - start) / 2;
    MergeSort(input, start, mid);
    MergeSort(input, mid + 1, end);
    Merge(input, start, end, mid);
}

// driver code.
int main()
{
    // n is the size of the input array.
    int n;
    scanf("%d", &n);
    int input[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &input[i]);
    }
    MergeSort(input, 0, n - 1);
    printf("%d", answer);
}

/*
Time Complexity  : O(nlogn).
Space Complexity : O(n).

Input:
5
2 4 1 3 5
Output:
3

*/

