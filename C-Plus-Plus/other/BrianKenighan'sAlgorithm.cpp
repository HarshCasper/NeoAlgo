/* 
This is a preferred approach to count no. of set bits of a digit.
Brian Kernighan’s Algorithm:
Concept -> If we subtract 1 from a decimal number, it will flip all the bits
after the rightmost set bit i.e 1 including that rightmost bit too.
As 10 is 0000 1010, 9 is 0000 1001
you can see in above example rightmost set bit in 10 is at second position
therefore in number (10 - 1) = 9 that second position and after that 1st position
flips away. 
So, we do bitwise of n and (n-1), then we unset the rightmost unset bit and we set
a counter to count the number of times loop executes we set bit count.   
In brief, no. of times loop runs is equal to count of set bits.
*/

#include <bits/stdc++.h>
using namespace std;
 
unsigned int countSetBits(int n){  
    // declared a counter to count set bits
    unsigned int count = 0; 

    while(n) {
        // take bitwise with one less number
        n &= (n-1); 
        // increase the counter till loop executes 
        count++; 
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
Sample Input : Enter a number
               9
Sample Output : Number of set bits or 1s in the number is : 2
Explanation: Binary representation of 9 is 1001 and has 2 set bits
Time Complexity: O(logn)
*/
