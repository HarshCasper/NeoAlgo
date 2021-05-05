// C program to implement Stooge  Sort
/*
The function of the stooge sort function is to check if the value at index 0 is 
greater than the value at last index, if YES then to swap those values.

Call the Stooge sort function recursively on initial 2/3rd of the array, last 2/3rd
and again initial 2/3rd to get the given array sorted
*/
#include <stdio.h>

// Helper function to swap two values
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void stooge_sort(int arr[], int start, int end)
{
    // If the value at last index is smaller than the value at index 0, Swap them.
    if (arr[start] > arr[end])
        swap(&arr[start], &arr[end]);

    // For finding the first and last two by third elements in the array
    if (end - start + 1 > 2)
    {
        int twobythird = (end - start + 1) / 3;

        //Recursively call the function on the initial two by third, last two by third followed by the initial two by third
        if ((end - twobythird) >= start)
            stooge_sort(arr, start, end - twobythird);
        if (end >= (start + twobythird))
            stooge_sort(arr, start + twobythird, end);
        if ((end - twobythird) >= start)
            stooge_sort(arr, start, end - twobythird);
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
    stooge_sort(arr, 0, n - 1);

    printf("The numbers in sorted order is: ");
    // Print the sorted array
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

/*
Time Complexity: O(n^2.7095), slower than bubble sort
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
