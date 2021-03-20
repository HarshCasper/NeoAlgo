/*
You are given an array arr containing 2N+2 positive numbers, out of which 2N numbers exist in pairs whereas the
other two number occur exactly once and are distinct. You need to find the other two numbers and print them in
ascending order.
*/

#include <bits/stdc++.h>

using namespace std;

// DRIVER FUNCTION
int main()
{
    int t, n, size;
    // Getting the Number of test cases as input
    cin >> t;
    while (t--)
    {
        //Getting the value N
        cin >> n;
        //The Array contains 2N+2 numbers
        size = 2 * n + 2;
        int arr[size], index;
        //Declare a vector for storing the result
        vector<int> res(2);
        //Declare a map for storing the frequency of numbers
        map<int, int> mp;
        //Getting the array input
        for (index = 0; index < size; index++)
            cin >> arr[index];

        //Storing the frequencies of the elements in the map
        for (index = 0; index < size; index++)
            mp[arr[index]]++;

        int resInd = 0;
        //Declare an iterator to traverse through the map
        map<int, int>::iterator it;

        for (it = mp.begin(); it != mp.end(); it++)
        {
            //Checking if the an element occurred odd number of times
            //if so, we will add that element to the resultant vector
            if ((it->second) % 2 != 0)
            {
                res[resInd++] = it->first;
            }
        }
        //Since we need to print the other two numbers in ascending order,
        //the resultant vector is sorted
        sort(res.begin(), res.end());
        //print the two numbers stored in the resultant vector
        for (int ind = 0; ind < res.size(); ind++)
            cout << res[ind] << " ";
    }

    return 0;
}
/*
For example:

Example 1:
Input:
1
2
1 2 3 2 1 4

Output:
3 4

Example 2:
Input:
1
1
2 1 3 2

Output:
1 3
*/