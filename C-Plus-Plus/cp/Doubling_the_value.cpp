/*
Description :
        Given an array and an integer target, traverse the array (from the beginning) 
        and if the element in array is target, double the tagret and continue traversal.
        Find the value of B after the complete traversal.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //function for finding the value after complete traversal
    long long sol(int n, long long arr[], long long target)
    {
        sort(arr, arr + n);
        long long maxi = arr[n - 1];
        while (target <= maxi)
        {
            //in-built method
            if (binary_search(arr, arr + n, target))
            {
                target = target * 2;
            }
            else
            {
                return target;
            }
        }
        return target;
    }
};

int main()
{
    // size of an array
    int size;
    cout << "Enter the size of an array : " << endl;
    cin >> size;
    //element to be searched and then traversed
    int target;
    cout << "Enter the target element : " << endl;
    cin >> target;
    long long arr[size];
    cout << "Enter the data in the array : " << endl;

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    Solution obj;
    long long result = obj.sol(size, arr, target);
    cout << "Value of target after complete traversal : " << endl;
    //output
    cout << result << endl;
    return 0;
}

/*
Time complexity : O(n)
Space complexity : O(n)
*/

/*
Test Case: 
 Input :
 "Enter the size of an array : 
 5
 Enter the target element : 
 2
 Enter the data in the array : 
 1 2 3 4 8

 Output :
 Value of target after complete traversal : 
 16
*/

