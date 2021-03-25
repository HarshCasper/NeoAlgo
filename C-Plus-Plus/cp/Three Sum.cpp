/*
Description :
     Given an array and a value, find if there exists three
     number whose sum is equal to the given value.
     If found then output will be true else false.

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; //n=number of element in the array
    cin >> n;
    int target; //sum of the number to be found
    cin >> target;

    vector<int> arr(n); //array of n size
    for (auto &i : arr)
    {
        cin >> i;
    }
    bool found = false;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        int low = i + 1, high = n - 1; //using two sum method
        while (low < high)
        {
            int curr = arr[i] + arr[low] + arr[high]; //adding digit to make a sum
            if (curr == target)                       //checking wether the sum(curr) is equal to target or not
            {
                found = true;
            }
            if (curr < target)
            {
                low++;
            }
            else
            {
                high--;
            }
        }
    }
    if (found)
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
    return 0;
}

/*
Time complexity : O(n2)
Space complexity : O(n)
*/

/*
Test Case 1: 
    Input : 6 24 12 3 6 9 34 25
    Output : True

Test Case 2 :
    Input : 4 3 8 9 34 45
    Output : False  
*/

