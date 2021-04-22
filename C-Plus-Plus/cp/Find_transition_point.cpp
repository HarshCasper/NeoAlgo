/*
Description : Given a sorted array containing only 0s and 1s, find the transition point. 
*/

#include <bits/stdc++.h>
using namespace std;

int transitionPoint(int arr[], int n)
{
    // code here
    if (arr[0])
        return 0;
    //using modified binary search
    //lb= lower bound
    //ub= upper bound
    int lb = 0;
    int ub = n - 1;
    while (lb <= ub)
    {
        int mid = (lb + ub) / 2;
        if (arr[mid] == 0)
        {
            lb = mid + 1;
        }
        else if (arr[mid] == 1)
        {
            if (arr[mid - 1] == 0)
                return mid;
            else
                ub = mid - 1;
        }
    }
    return -1;
}

int main()
{
    //size of an array
    int n;
    cout << "Enter the size of an array : " << endl;
    cin >> n;
    int a[n];
    cout << "Enter the data in the array : " << endl;
    //taking input in array
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Transition point in array : " << endl;
    cout << transitionPoint(a, n) << endl;
    return 0;
}

/*
Time complexity : O(log n)
Space complexity : O(n)
*/

/*
Test Case :
 Input :
 Enter the size of an array :
 5
 Enter the data in the array :
 0 0 0 1 1 

 Output :
 Transition point in array : 
 3
*/

