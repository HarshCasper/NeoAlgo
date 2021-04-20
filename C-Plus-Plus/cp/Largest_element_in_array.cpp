/*
Description :
        Given an array and we  have to find the largest element in it.
*/

#include <bits/stdc++.h>
using namespace std;

//function for finding largest element
int large(int arr[], int n)
{
    int res = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > res)
        {
            res = arr[i];
        }
    }
    return res;
}
int main()
{
    //maximum size of array
    int arr[1000];
    int n;
    cout << "Enter the size of array : " << endl;
    cin >> n;
    cout << "Enter the data in the array : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "The largest data in array  : " << endl;
    //displaying output
    cout << large(arr, n) << " ";
    return 0;
}
/*
Time complexity : O(n)
Space complexity :O(1)
*/

/*
Test Case :
 Input :
 Enter the size of array : 
 4
 Enter the data in the array : 
 83 23 56 23

 Output :
 The largest data in array  : 
 83
*/

