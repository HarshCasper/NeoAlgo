/*
Description : 
        You are given an array arr[], you have to re-construct an array arr[].
        he values in arr[] are obtained by doing Xor of consecutive elements in the array.
*/

#include <bits/stdc++.h>
using namespace std;

//function performing the Xor opertation on consecutive elements
int *game_with_no(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        arr[i] = arr[i] xor arr[i + 1];
    }
    return arr;
}

int main()
{
    //size of an array
    int n;
    cout << "Enter the size of array : " << endl;
    cin >> n;
    int arr[n];

    cout << "Enter the data in array : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    //storing the result
    int *arr_2;
    arr_2 = game_with_no(arr, n);

    cout << "After performing Xor of consecutive elements :" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr_2[i] << " ";
    }
    return 0;
}
/*
Time complexity : O(n)
Space complexity : O(n)
*/

/*
Test Case :
 Input : 
 Enter the size of array : 
 5
 Enter the data in array : 
 10
 11
 1
 2
 3

 Output ;
 After performing Xor of consecutive elements :
 1 10 3 1 3
*/

