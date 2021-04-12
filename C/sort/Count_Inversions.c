/*
Problem Statement:
Given an array of integers. Find the Inversion Count in the array.
Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
*/

#include <stdio.h>

// answer stores the inversion count.
int answer = 0;

// Merge function helps us to calculate the inversion count.
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

int main()
{
    printf("Enter the size of the input array\n");
    int SIZE;
    scanf("%d", &SIZE);
    int input[SIZE];
    printf("Enter the elements of the input array\n");
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d", &input[i]);
    }
    MergeSort(input, 0, SIZE - 1);
    printf("Number of inversions in the input array are %d.", answer);
}

/*
Time Complexity  : O(SIZE*log(SIZE)).
Space Complexity : O(SIZE).

Input:
Enter the size of the input array
5
Enter the elements of the input array
2 4 1 3 5
Output:
Number of inversions in the input array are 3.

*/

