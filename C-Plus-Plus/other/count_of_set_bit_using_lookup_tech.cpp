/*A CPP implementation of count of set bits in an integer using a LookUp 
table technique - Piyush Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    int arr[] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4}; // An array containg count of set bits from 0 - 15

    long long int number, count = 0;
    cout << "Enter the Integer value : ";
    cin >> number; // Input

    while (number != 0)
    {
        count += arr[number & 0xF];
        number >>= 4;
    }
    cout << "Number of set bits in the given integer are : " << count;
    return 0;
}

/* Time Complexity : Worst case - O((logn)/k)
                     Best case  - O(1)
Space Complexity : k - bit approach - O(2^k) 
where n is the given integer and k is the number of bits in each nibble
4 - bit - form :
                    0 - 0000
                    1 - 0001
                    2 - 0010
                    .... 
Sample Input - 9 (1001)
Sample Output - 2 
Sample Input - 124(0111 1100)
Sample Output - 5  --> 3 in upper nibble ,2 in lower nibble*/