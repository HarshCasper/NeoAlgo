/*Sort an array using a single loop.*/

#include <bits/stdc++.h>
using namespace std;
void swapping(int *arr, int index)
{
    int temp = arr[index];
    arr[index] = arr[index + 1];
    arr[index + 1] = temp;
}
int main ()
{
    int length;
    cout << "Enter the size of array: ";
    cin >> length;
    int *arr = new int[length];

    for(int i = 0; i < length; i++)
    {
        cout << "Array[" << i << "] : ";
        cin >> arr[i];
    }

    for(int i = 0; i < length - 1; i++)
    {
        if(arr[i] > arr[i+1])
        {
            swapping(arr, i);
            i = -1;
        }
    }
    cout << "Sorted Array: ";
    for(int i = 0; i < length; i++)
        cout << arr[i] << "\t";
    delete[] arr;
    return 0;
}

/*
INPUT 1
Enter the size of array: 5
Array[0] : 89
Array[1] : 54
Array[2] : 654
Array[3] : 3
Array[4] : 15

OUTPUT
Sorted Array: 3 15      54      89      654

INPUT 2
Enter the size of array: 9
Array[0] : 0
Array[1] : 0
Array[2] : 0
Array[3] : 1
Array[4] : 1
Array[5] : 1
Array[6] : 0
Array[7] : 1
Array[8] : 6

OUTPUT
Sorted Array: 0 0       0       0       1       1       1       1       6

TIME COMPLEXITY
The time complexity does not change for sorting using single loop in comparison to more than one loop sorting techniques.

SPACE COMPLEXITY
O(n)

*/
