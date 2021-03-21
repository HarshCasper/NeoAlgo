// C++ program to reverse the bits of a number

/*
Given an integer, reverse its bits in its binary equivalent and 
print the new number obtained in its decimal form
*/

#include <bits/stdc++.h>
using namespace std;

/*
The code first stores the lsb of the given number in a variable and then left shifts
the given number and gives this number to the lsb of the answer variable and then right
shifts it
*/
int reverse_bits(int n)
{

    int rev = 0, rem;

    // Traverse while there exist bits for the given number
    while (n)
    {
        // Shift the bit of the reversed(answer) number to the right
        rev = rev << 1;
        //Stores the temporary lsb of the given number
        rem = n & 1;
        //Set the lsb of the answer variable with the stored value
        rev = rem | rev;
        //Drops the already processed lsb of the given number
        n = n >> 1;
    }
    return rev;
}

int main()
{
    int n, ans;
    cout << "\nEnter the number? ";
    cin >> n;

    //Call the function
    ans = reverse_bits(n);
    cout << "The bits-reversed number is: " << ans << endl;
    return 0;
}

/*

Time Complexity: O(n)
Space Complexity: O(1)

SAMPLE INPUT AND OUTPUT

Enter the number? 39
The bits-reversed number is: 57

*/
