/*
Cyclically rotate the array by one

You are given an array arr[], 
your task is to cyclically rotate the elements clockwise
by one and return the array.
*/

#include <bits/stdc++.h>

using namespace std;

//function to rotate the array cyclically by 1
void rotateClockwiseby1(int arr[], int size)
{
    int last = arr[size - 1];
    for(int pass = size - 1; pass > 0; pass--)
    {
        //making the next element equal to last element
        arr[pass] = arr[pass - 1];
    }
    //making first element equal to the last one
    arr[0] = last;
}

//driver code
int main()
{
    int size;
    cout << "Enter the size of array : ";
    cin >> size;

    int arr[size];
    cout<< "Enter the elements of the array: " << endl;
    for (int i = 0; i < size; i++){
        cin >> arr[i];
    }

    rotateClockwiseby1(arr, size);

    cout<<"Rotated array is: ";
    for (int i = 0; i < size; i++){
        cout << arr[i];
    }
    cout << endl;
    return 0;
}

/*
EXAMPLE:-
Input--
Enter the size of array : 5
Enter the elements of the array: 1 3 5 9 0
Output--
Rotated array is: 0 1 3 5 9

TIME COMPLEXITY--> O(N)
SPACE COMPLEXITY--> O(1)
*/
