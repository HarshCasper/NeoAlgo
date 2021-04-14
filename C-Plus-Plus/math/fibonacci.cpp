/* This program prints the nth term in the fibonacci sequence. Recursive method
is used here. Fibonacci(n) = Fibonacci(n-1) + Fibonacci(n-2)*/

#include <iostream>
using namespace std;

// This function returns the nth terms in fibonacci sequence
int fibonacci(int number) {
	// Base case for n = 0 and n = 1
	if(number == 0) 
		return 0;
	else if(number == 1) 
		return 1;
	// Recursively call the function for n-1 and n-2
	return fibonacci(number - 1) + fibonacci(number - 2);
}

int main() {

	// Take number as input from the user
	int number;
	cout << "Enter a number: ";
	cin >> number;

	// If number is less than 0, exit
	if(number < 0) {
		cout << "\nPlease enter a non-negative number." << endl;
		exit(0);
	}

	// Else call the function and print the nth term
	cout << "\nThe term at index " << number << " of the fibonacci sequence is " << fibonacci(number) << endl;
	return 0;
}

/*
Sample I/O:

1)
Enter a number: 7

The term at index 7 of the fibonacci sequence is 13

2)
Enter a number: -23

Please enter a non-negative number.

*/
