/*
Description : 
    An array of even size, task is to find minimum value that can be 
    added to an element so that array become balanced. An array is 
    balanced if the sum of the left half of the array elements is 
    equal to the sum of right half.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minValueToBalance(int a[], int n)
    {
        //first half sum
        int f_sum = 0;
        //second half sum
        int s_sum = 0;
        int mid = n / 2;
        int result = 0;

        //for first half of an array
        for (int i = 0; i < mid; i++)
        {
            f_sum += a[i];
        }
        //for second half of an array
        for (int j = mid; j < n; j++)
        {
            s_sum += a[j];
        }

        if (f_sum > s_sum)
        {
            result = f_sum - s_sum;
        }
        else
        {
            result = s_sum - f_sum;
        }
        return result;
    }
};

int main()
{
    int size;
    cout << "Enter the lenght of an array : " << endl;
    cin >> size;
    int a[size];
    cout << "Enter " << size << " number of elements in array :" << endl;
    for (auto i = 0; i < size; i++)
    {
        cin >> a[i];
    }
    Solution obj;
    cout << "To make the array balanced you can add : " << endl;
    cout << obj.minValueToBalance(a, size);

    return 0;
}

/*
Time complexity : O(n)
Space complexity : O(n)
*/

/*
Test Cases:
Test Case 1 :
    Input :
    Enter the lenght of an array : 
    4
    Enter 4 number of elements in array :
    1 5 3 2

    Output:
    To make the array balanced you can add :
    1

Test case 2:
    Input :
    Enter the lenght of an array : 
    6
    Enter 6 number of elements in array :
    1 2 1 2 1 3

    Output :
    To make the array balanced you can add :
    2
*/

