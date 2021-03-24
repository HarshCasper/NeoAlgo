// Given 2 integers lets say N and i. We need to set the ith bit in binary representation such that the final result will have Nth bit turned to 0. This is known as turning off "ith bit". The counting of bits starts from 0 from right to left.

#include <bits/stdc++.h>
// Int N is inputted. We need to make the first set bit of binary representation of N to 0 and return the new N. This is known as turning off the first set bit. The counting of bits starts from 0 from right to left.
using namespace std;

int turnOffFirstSetBit(int n){
return n & (n - 1);
}

int main() {
int n;

cin >> n;

cout<< turnOffFirstSetBit(n) <<endl;
	
return 0;
}

// if 4 is inputed then 0 is returned