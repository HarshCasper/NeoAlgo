// C++ program to implement Pigeon Hole  Sort

#include <bits/stdc++.h>
using namespace std;

struct LargestAndSmallest
{
    int largest;
    int smallest;
};

//To find the largest and Smallest elements in an array with minimum comparisons
struct LargestAndSmallest find_max_min_elements(int arr[], int n)
{
    struct LargestAndSmallest pair;
    int i;
    //If there is only one element
    if (n % 2 == 1)
    {
        pair.smallest = arr[0];
        pair.largest = arr[0];
        i = 1;
    }
    else //Else If there is more than one element
    {
        if (arr[0] > arr[1])
        {
            pair.smallest = arr[1];
            pair.largest = arr[0];
        }
        else
        {
            pair.smallest = arr[0];
            pair.largest = arr[1];
        }
        i = 2;
    }

    while (i < n - 1)
    {
        if (arr[i] > arr[i + 1])
        {
            if (arr[i] > pair.largest)
                pair.largest = arr[i];

            if (arr[i + 1] < pair.smallest)
                pair.smallest = arr[i + 1];
        }
        else
        {
            if (arr[i + 1] > pair.largest)
                pair.largest = arr[i + 1];

            if (arr[i] < pair.smallest)
                pair.smallest = arr[i];
        }
        i = i + 2;
    }
    return pair;
}

// Pigeon hole sort
void pigeon_hole_sort(int arr[], int n)
{
    LargestAndSmallest pair = find_max_min_elements(arr, n);

    // Find statistical range of the given array
    int range = pair.largest - pair.smallest + 1;

    // Declare an array with the size of the range.
    int holes[range];

    memset(holes, 0, sizeof(holes)); //Initialize the new array with value 0.

    //Filling the 'holes' array with the input array values
    for (int j = 0; j < n; j++)
        holes[arr[j] - pair.smallest]++;

    // Put the elements back into the array in ascending occurence order.
    int j = 0;
    for (int i = 0; i < range; i++)
        while (holes[i]-- > 0)
        {
            arr[j] = i + pair.smallest;
            j++;
        }
}

int main()
{
    int n;
    cout << "\nHow many numbers do you want to sort? ";
    cin >> n;
    int arr[n];

    if (n <= 0)
    {
        cout << "The array is Empty!!!";
        return 0;
    }
    // Input the numbers to sort
    cout << "Enter the numbers: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    //Call the sort function
    pigeon_hole_sort(arr, n);

    cout << "The numbers in sorted order is: ";
    // Print the sorted array
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

/*

Time Complexity: O(n+range), where 'range' is statistical range of the given input values
Space Complexity: O(n)

SAMPLE INPUT AND OUTPUT

SAMPLE 1
How many numbers do you want to sort? 5
Enter the numbers: 1 3 5 2 4
The numbers in sorted order is:  1  2  3  4  5

SAMPLE 2
How many numbers do you want to sort? 0
The array is Empty!!!

*/
