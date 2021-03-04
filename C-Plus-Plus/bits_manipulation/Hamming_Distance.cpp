// Hamming Distance
/*
For given x and y, return the number of positions where their values differ in their binary representations as a 32-bit integer.

Input
x = 10
y = 6
Output
2
*/

/* Implementation: x = 10 (1010) and y = 6 (0110) if we apply xor to x and y the resultant ans = 12 (1100).
XOR is 0 when 2 bits are equal and 1 when 2 bits contrasts
Number of bits in ans = 2
*/

#include<bits/stdc++.h> 
using namespace std;

int solve(int x, int y) {
    int ans = x^y;
    return __builtin_popcount(ans); // O(N) time complexity
}

int main(){
    int x,y; cin>>x>>y;
    cout<<solve(x,y)<<endl;
}

