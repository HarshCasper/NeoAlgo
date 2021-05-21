/*
Minimum XOR value problem in C
Given an integer array A of N integers, find the minimum XOR value made by a  pair of integers in the array.
*/

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

//Comparator function used by qsort
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void min_xor(int *arr, int n)
{
    //Temporary variables to store the pair of elements
    int a, b;
    //res will store the minimum xor value
    int res = INT_MAX;
    for (int i = 0; i < n - 1; i++)
    {
        //x will store xor value for each possible pair of elements of array
        int x = arr[i] ^ arr[i + 1];
        if (x < res)
        {
            res = x;
            a = arr[i];
            b = arr[i + 1];
        }
    }
    printf("The Minimum xor value is : %d \n", res);
    printf("The corresponding pair of elements are : %d  and  %d ", a, b);
}

int main()
{
    //Input the size of the array
    int n;
    printf("Enter the size of array : ");
    scanf("%d", &n);
    printf("Enter the array : ");
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    //Sort the array in ascending order
    qsort(arr, sizeof(arr) / sizeof(*arr), sizeof(*arr), compare);
    min_xor(arr, n);
    return 0;
}

/*
Time Complexity : O(n * logn), where 'n' is the size of the array
Space Complexity : O(1)

SAMPLE INPUT AND OUTPUT  

Enter the size of array : 4
Enter the array : 1 2 3 4
The Minimum xor value is : 1 
The corresponding pair of elements are : 2  and  3
*/
