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
Test Case 1:
Input : a = 5, b = 3
Output : 2

Test Case 2:
Input : a = 7, b = 10
Output : 3

*/

/*
Time Complexity : O(set bits)
Space Complexity : O(1)
*/
