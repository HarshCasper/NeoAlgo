// C++ program to count
// trailing 0s in n!
#include <iostream>
using namespace std;

// Function to return trailing
// 0s in factorial of n
int findTrailingZeros(int n)
{
	// Initialize result
	int count = 0;

	// Keep dividing n by powers of
	// 5 and update count
	for (int i = 5; n / i >= 1; i *= 5)
		count += n / i;

	return count;
}

int main()
{
	int n = 100;
	cout << "Count of trailing 0s in " << 100
		<< "! is " << findTrailingZeros(n);
	return 0;
}


// Examples : 

// Input: n = 5
// Output: 1 
// Factorial of 5 is 120 which has one trailing 0.

// Input: n = 20
// Output: 4
// Factorial of 20 is 2432902008176640000 which has
// 4 trailing zeroes.

// Input: n = 100
// Output: 24