/* Hamming Distance
-----------------
Problem: 
For given x and y, return the number of positions where their values differ in their binary representations as a 32-bit integer.

Implementation:
x = 10 (1010) and y = 6 (0110) if we apply xor to x and y the resultant ans = 12 (1100).
XOR is 0 when 2 bits are equal and 1 when 2 bits contrasts
Number of bits in ans = 2
*/

#include<bits/stdc++.h> 
using namespace std;

// O(N) time complexity
int solve1(int x, int y) 
{
    int ans = x^y;
    return __builtin_popcount(ans); 
}

// O(1) time complexity
int solve2(int x, int y) 
{
    int count = 0;
    for (int i = 0; i < 32; i++)
        if ( (x & (1 << i)) != (y & (1 << i)) )
            count++;
    return count;
}
int main()
{
    int x,y; 
    cin>>x>>y;
    cout<<solve2(x,y)<<endl;
}

/*
Input:
x = 10
y = 6
Output
2
*/