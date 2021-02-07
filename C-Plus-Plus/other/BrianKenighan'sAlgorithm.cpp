// This is a preferred approach to count no. of set bits of a digit.

//  Brian Kernighan’s Algorithm:
// Concept -> If we subtract 1 from a decimal number, it will flip all the bits
// after the rightmost set bit i.e 1 including that rightmost bit too.
// As 10 is 0000 1010, 9 is 0000 1001
// you can see in above example rightmost set bit in 10 is at second position
// therefore in number (10 - 1) = 9 that second position and after that 1st position
// flips away. 
// So, we do bitwise of n and (n-1), then we unset the rightmost unset bit and we set
// a counter to count the number of times loop executes we set bit count.   
// In brief, no. of times loop runs is equal to count of set bits.


#include <bits/stdc++.h>
using namespace std; 

int main()
{
    int n;
    cout << "Enter a Number" << endl; // input the digit
    cin >> n;
    unsigned int count = 0; // declared a counter to count set bits

    while(n) {
        n &= (n-1); // take bitwise with one less number
        count++; // increase the counter till loop executes 
    }

    if (count > 1){
    cout << "Number of set bits or 1s in digit are " << count;
    }
    else {
    cout << "Number of set bits or 1s in digit is " << count;   
    }
}
