/*A CPP implementation of count of set bits in an integer using a LookUp 
table technique.

Piyush Kumar

 */

#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int arr[] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4}; // An array containg count of set bits from 0 - 15

    long long int n, count = 0;

    cin >> n; // Input

    while (n != 0)
    {
        count += arr[n & 0xF];
        n >>= 4;
    }

    cout << count;

    return 0;
}

/* 
Time Complexity : Worst case - O((logn)/k)
                  Best case  - O(1)

Space Complexity : k - bit approach - O(2^k) 

where n is the given integer and k is the number of bits in each nibble

4 - bit - form :
                    0 - 0000
                    1 - 0001
                    2 - 0010
                    ....

*/