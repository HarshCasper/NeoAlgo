// C++ program to find the factorial of very large number.

#include<bits/stdc++.h>
using namespace std;

// Function to find factorial
string Factorial(long long n) {
	if (n == 0)
		return "1";

	long long i, fact = 0;

	for (i = 1; i <= n; i++)
		fact += log(i);
	string str;
	str = to_string(round(exp(fact)));
	return str;
}

int main() {
	long long n;
	cout << "Enter the number: ";
	cin >> n;
	string str;
	str = Factorial(n);
	cout << "The factorial of " << n << " = " << str;
	return 0;
}

/*
	Sample input/output:

	Enter the number: 51
	The factorial of 51 = 712058632688933793172711302775443308528933084537552896.000000

	Time Complexity= O(n)
	Space Complexity= O(1)
*/
