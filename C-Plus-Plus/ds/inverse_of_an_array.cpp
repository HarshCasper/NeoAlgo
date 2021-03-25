/*
INVERSE OF AN ARRAY   
/*
If the array elements are swapped with their corresponding indices,
the array finally results is inverse of an array. 
*/
#include <bits/stdc++.h>
using namespace std;

// ALGORITHM -->
// create two arrays, ori and inv.
// give input for ori array.
// create a temporary variable then, and store the element from the original array.
// In inv array for each value of temp, store the index of ori array.
// Display the inverse array.

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int ori[n];
        int inv[n];

        for (int i = 0; i < n; i++)
            cin >> ori[i];

        for (int i = 0; i < n; i++)
        {
            int temp = ori[i];
            inv[temp] = i;
        }
        for (int i = 0; i < n; i++)
            cout << inv[i] << " ";
    }
    return 0;
}
/*
time complexity -: O(n)
 
Sample input:
2
5
4 0 2 3 1
3
0 1 2

Sample Output
1 4 2 3 0
0 1 2
*/

