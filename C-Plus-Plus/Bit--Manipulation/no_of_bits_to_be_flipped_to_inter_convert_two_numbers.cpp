// C++ program to find the number of bits to be flipped to convert one number to another
#include <bits/stdc++.h>
using namespace std;

/*
Inorder to compare the individual bits of given the numbers, we can compute the number of
set bits in thier XOR, as we know that XOR operation yields set bits, only when two same
bits are XORed.
*/
int get_num_flips(int n1, int n2) {
    int count = 0, n = n1 ^ n2;

    // Loop till 'n' becomes zero
    while (n) {
        // If the lsb is set, increase the count by 1
        if (n & 1)
            count++;
        // Shift the bits to right by 1.
        n = n >> 1;
    }

    return count;
}

int main() {
    int n1, n2;
    cout << "\nEnter the two numbers: ";
    cin >> n1 >> n2;

    cout << "Number of flips required to inter-convert the given numbers is ";
    cout << get_num_flips(n1, n2);
    return 0;
}

/*

Time Complexity: O(log(n)), where n is the greater of the input number
Space Complexity: O(1)

SAMPLE INPUT AND OUTPUT

Enter the two numbers: 12 24
Number of flips required to inter-convert the given numbers is 2

*/
