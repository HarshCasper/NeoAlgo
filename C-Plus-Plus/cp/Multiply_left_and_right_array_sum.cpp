/*
Description :  We have to divide a array into two sub array (left and right)
               containing n/2 elements each and do the sum of the subarrays 
               and then multiply both the subarrays.
*/

#include <bitset/stdc++.h>
using namespace std;

int multiply(int arr[], int n)
{
    int sum_1 = 0;
    int sum_2 = 0;
    int result;
    int len = n / 2;
    for (int i = 0; i < len; i++)
    {
        sum_1 += arr[i];
    }
    for (int j = len; j < n; j++)
    {
        sum_2 += arr[j];
    }
    result = sum_1 * sum_2;
    return result;
}

int main()
{
    // n =  size of an array
    int n;
    cout << "Enter the size of the array : " << endl;
    cin >> n;
    //array of n size
    int a[n];
    cout << "Enter " << n << " number of elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Multiplication of left and right sub-array : " << endl;
    cout << multiply(a, n) << endl;
    return 0;
}

/*
Time Complexity : O(n)
space Complexity : O(n)
*/

/*
 Test Cases : 
 Test Case 1 :
    Input : 
    Enter the size of the array : 
    4
    Enter 4 number of elements : 
    1 2 3 4

    Output :
    Multiplication of left and right sub-array : 
    21
 Test case 2 :
    Input : 
    Enter the size of the array : 
    2
    Enter 2 number of elements : 
    1 2

    Output : 
    Multiplication of left and right sub-array : 
    2
 */

