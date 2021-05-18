/*
Description :
        Given an array(0-based indexing), you have to find the max sum of i*A[i] where A[i] is the element at index i in the array.
        The only operation allowed is to rotate(clock-wise or counter clock-wise) the array any number of times.
*/

#include <bits/stdc++.h>
using namespace std;

// function to find the combination of the number and sum
int maxi_sum(int A[], int N)
{
    // c_s = current sum
    int c_s = 0;
    for (int i = 0; i < N; i++)
    {
        c_s += A[i];
    }
    int c_v = 0;
    for (int i = 0; i < N; i++)
    {
        c_v = c_v + i * A[i];
    }
    int ans = c_v;
    for (int i = 1; i < N; i++)
    {
        int n_v = c_v - (c_s - A[i - 1]) + A[i - 1] * (N - 1);

        c_v = n_v;
        ans = max(ans, n_v);
    }

    return ans;
}

int main()
{
    // input number
    int num;
    cout << "Enter the size of array : " << endl;
    cin >> num;
    // array to store input
    int arr[num];

    cout << "Enter the elements in the array : " << endl;
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
    cout << "Maximum sum which can be obtained : " << endl;
    cout << maxi_sum(arr, num) << endl;
    return 0;
}

/*
Time complexity - O(N)
Space complexity - O(1)
*/

/*
Test Case :
 Input :
 Enter the size of array : 
 4
 Enter the elements in the array : 
 8 3 1 2

 Output :
 Maximum sum which can be obtained :
 29
*/

