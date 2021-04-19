/*
INVERSE OF AN ARRAY   
If the array elements are swapped with their corresponding indices,
the array finally results is inverse of an array. 
*/

#include <bits/stdc++.h>
using namespace std;

void inverse(int a[], int n, int b[])
{
    for (int i = 0; i < n; i++)
    {
        int temp = a[i];
        b[temp] = i;
    }
    for (int i = 0; i < n; i++)
        cout << b[i] << " ";
}

int main()
{
    // Driver code begins
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int ori[n];
        int inv[n];

        for (int i = 0; i < n; i++)
            cin >> ori[i];

        inverse(ori, n, inv);
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

