/*
Description :
        Given an array, you have to re-construct an array.
        The values in array are obtained by doing OR(bitwise or) of consecutive elements in the array.
*/

#include <bits/stdc++.h>
using namespace std;

//fucntion is used to obatin value using OR operator
int *bit_op(int arr[], int n)
{
    for (int j = 0; j < n - 1; j++)
    {
        arr[j] = arr[j] | arr[j + 1];
    }

    return arr;
}

int main()
{
    // size = length of an array
    int size;
    cout << "Enter the length of array : " << endl;
    cin >> size;
    int arr[size];

    cout << "Enter the elements in the array : " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int *arr_2;
    arr_2 = bit_op(arr, size);

    cout << "New array : " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr_2[i] << " ";
    }
    cout << "\n";

    return 0;
}
/*
Time complexity : O(n)
Space complexity : O(n)
*/

/*
Test Case :
  Input :
  Enter the length of array : 
  5
  Enter the elements in the array : 
  10 11 1 2 3

  Output :
  New array : 
  11 11 3 3 3
   
*/

