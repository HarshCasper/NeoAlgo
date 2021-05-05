/* This program calculates nth Catalan number using Dynamic programming.
The solutions to the nth Catalan number is calculated in bottom-up manner.
There by reducing the time complexity.*/

#include <iostream>
using namespace std;

// This function returns nth catalan number
long long int n_catalan(long int number) {

	// Makes an array to store the catalan numbers
	long long int array[number + 1];

	// Base cases
	array[0] = 1;
	array[1] = 1;

	// Initializing the array to all zeroes.
	for(int i = 2; i < number + 1; i++) {
		array[i] = 0;
	}

	// Using DP recursive solution to get nth catalan number
	for(int i = 2; i < number + 1; i++) {
		for(int j = 0; j < i; j++) {
			array[i] += array[j] * array[i - j - 1];
		}
	}

	// Return the nth catalan number
	return array[number];
}

int main() {

	// Take number as input from the user
	long int number;
	cout << "Enter a number: ";
	cin >> number;

	if(number < 0) {
		cout << "\nPlease enter a non-negative number." << endl;
		exit(0);
	}

	// Print the nth catalan number
	cout << "\nCatalan number at index " << number << " is " << n_catalan(number) << endl;
	return 0;
}

/*
Sample I/O:

1)
Enter a number: 10

Catalan number at index 10 is 16796

2)
Enter a number: -23

Please enter a non-negative number.

*/
