// The idea is to get sum in one of the two given numbers. The numbers can then be swapped using the sum and subtraction from sum. 

// C++ program to swap three variables
// without using temporary variable.
#include <iostream>
using namespace std;

// Assign c's value to a, a's value to b and
// b's value to c.
void swapThree(int &a, int &b, int &c)
{
	// Store sum of all in a
	a = a + b + c; // (a = 60)

	// After this, b has value of a
	b = a - (b+c); // (b = 60 – (20+30) =10)

	// After this, c has value of b
	c = a - (b+c); // (c = 60 – (10 + 30) = 20)

	// After this, a has value of c
	a = a - (b+c); //(a = 60 – (10 + 20) = 30)
}

int main()
{
	int a = 10, b = 20, c = 30;

	cout << "Before swapping a = " << a << ", b = "
		<< b << ", c = " << c << endl;

	swapThree(a, b, c);

	cout << "After swapping a = " << a << ", b = "
		<< b << ", c = " << c << endl;

	return 0;
}
