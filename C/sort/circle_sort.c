// C++ program to implement Circle  Sort
#include <stdio.h>

// Helper function to swap to values
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
/*
Performs recursive circular swaps and returns value 1 if atleast one swap occurs
*/
int rec_sort(int arr[], int beg, int end)
{
    int isSwap = 0;

    // If concerned array is empty, Return
    if (beg == end)
        return 0;

    // Storing the values of beg, end to later use in the recursive call
    int begA, endA;
    for (begA = beg, endA = end; begA < endA; begA++, endA--)
    {
        //Compares the first and last elements
        if (arr[begA] > arr[endA])
        {
            swap(&arr[begA], &arr[endA]);
            isSwap = 1;
        }
    }

    // If the array has odd number of elements
    if (begA == endA)
        if (arr[begA] > arr[endA + 1])
        {
            swap(&arr[beg], &arr[endA + 1]);
            isSwap = 1;
        }

    int mid = (end - beg) / 2;
    int isSwapA = rec_sort(arr, beg, beg + mid);
    int isSwapB = rec_sort(arr, beg + mid + 1, end);

    return (isSwap || isSwapA || isSwapB);
}

void circle_sort(int arr[], int n)
{
    while (rec_sort(arr, 0, n - 1))
    {
    }
}

int main()
{
    int n;
    printf("\nHow many numbers do you want to sort? ");
    scanf("%d", &n);
    int arr[n];

    if (n <= 0)
    {
        printf("There are no numbers to sort!!!");
        return 0;
    }
    // Input the numbers to sort
    printf("Enter the numbers: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    //Call the sort function
    circle_sort(arr, n);

    printf("The numbers in sorted order is: ");
    // Print the sorted array
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}

/*

Time Complexity: O(n*log(n))
Space Complexity: O(n)

SAMPLE INPUT AND OUTPUT

SAMPLE 1

How many numbers do you want to sort? 5
Enter the numbers: 1 3 5 2 4
The numbers in sorted order is:  1  2  3  4  5

SAMPLE 2

How many numbers do you want to sort? 0
There are no numbers to sort!!!

*/
