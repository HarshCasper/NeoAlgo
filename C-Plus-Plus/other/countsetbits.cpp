/* 
Normal & Simple Approach
Loop through all bits in an integer, check if a bit is set and if it is then increment the set bit count.
*/
#include <bits/stdc++.h>
using namespace std; 

int main()
{
    int n;
    cout << "Enter a Number" << endl; 
    cin >> n;
    // declared a counter to count set bits
    unsigned int count = 0; 
    
    while(n) {
        
        // take bitwise operation with 0001;
        count += n & 1;
        // right shift by 1 
        n >>= 1; 
    }

    if (count > 1){
    cout << "Number of set bits or 1s in digit are " << count;
    }
    else {
    cout << "Number of set bits or 1s in digit is " << count;   
    }
}

/*
Sample Input : n = 9
Sample Output : 2
Explanation: Binary representation of 9 is 1001 and has 2 set bits
Time Complexity: (-)(logn) (Theta of logn)
*/