// Normal & Simple Approach
// Loop through all bits in an integer, check if a bit is set and if it is then increment the set bit count.

#include <bits/stdc++.h>
using namespace std; 

int main()
{
    int n;
    cout << "Enter a Number" << endl; // input the digit
    cin >> n;
    unsigned int count = 0; // declared a counter to count set bits

    
    while(n) {
        count += n & 1; // take bitwise operation with 0001;
        n >>= 1; // right shift by 1
    }

    if (count > 1){
    cout << "Number of set bits or 1s in digit are " << count;
    }
    else {
    cout << "Number of set bits or 1s in digit is " << count;   
    }
}