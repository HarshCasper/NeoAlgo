// C++ Program to calculate last digit number of fibonacci series

#include <iostream>
using namespace std;

// Constraints for this function is 0≤𝑛≤10^7.

int get_fibonacci_last_digit(long long n) {
	int first = 0; // first integer of fibonacci series
	int second = 1; // second integer of fibonacci series

	int result;

	for (int i = 2; i <= n; i++) {
		result = (first + second) % 10; // storing the remainder in result instead of whole fibonacci series
		first = second;
		second = result;
	}

	return result;
}

// Below algorithm is taken from Geeksforgeeks

// Finds nth fibonacci number
long long int  fib(long long int f[], long long int n) {
	// 0th and 1st number of
	// the series are 0 and 1
	f[0] = 0;
	f[1] = 1;

	// Add the previous 2 numbers
	// in the series and store
	// last digit of result
	for (long long int i = 2; i <= n; i++)
		f[i] = (f[i - 1] + f[i - 2]) % 10;

	return f[n];
}

// Returns last digit of n'th Fibonacci Number
int findLastDigit(int n) {
	long long int f[60] = {0};

	// Precomputing units digit of
	// first 60 Fibonacci numbers
	fib(f, 60);

	return f[n % 60];
}


int main() {
	int number;
	cin >> number;
	//int result = get_fibonacci_last_digit(number);
	int result = findLastDigit(number);
	cout << result << '\n';

	return 0;
}

/*
Sample I/O:
Input:
200
Output:
5

Time Complexity: O(1) for findLastDigit() and O(n) for get_fibonacci_last_digit()
Space Complexity : O(1) for findLastDigit() and O(n) for get_fibonacci_last_digit()

*/
