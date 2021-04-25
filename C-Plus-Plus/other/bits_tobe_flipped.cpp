//Program to count bits to be flipped to convert a to b in c++
#include <iostream>
using namespace std;

int main()
{
    int a, b, n, count = 0;
    cin >> a >> b;
    //n calculates count of set bits in a XOR b
    n = a ^ b;
    //loop counts set bits
    while (n > 0)
    {
        count++;
        n &= (n - 1);
    }
    cout << count << endl;
    return 0;
}

/*
Input : a = 5, b = 3
Output : 2
Binary representation of a : 101
Binary representation of b : 011
We will flip 2 bits of a to make it b.

Input : a = 7, b = 10
Output : 3
Binary representation of a : 00000111
Binary representation of b : 00001010
We will flip 3 bits of a to make it b.
*/

/*
Time Complexity : O(set bits)
Space Complexity : O(1)
*/
