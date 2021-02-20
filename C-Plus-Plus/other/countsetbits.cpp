/* 
Normal & Simple Approach
Loop through all bits in an integer, check if a bit is set and if it is then increment the set bit count.
*/

#include <bits/stdc++.h>
using namespace std; 

unsigned int countSetBits(unsigned int n)
{
    unsigned int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int main()
{
    int n;
    cout << "Enter a Number" << endl; 
    cin >> n;
    cout << "Number of set bits or 1s in the number is : " << countSetBits(n);
    
}

/*
Sample Input : Enter a Number 
               9
Sample Output : Number of set bits or 1s in the number is : 2
Explanation: Binary representation of 9 is 1001 and has 2 set bits
Time Complexity: (-)(logn) (Theta of logn)
*/
