//C++ Program to convert a positive decimal number into its equivalent binary number

#include <bits/stdc++.h>
using namespace std;

//Function to convert a positive decimal number into a binary number

long long convertDecimalToBinary(int n) {
	long long binaryNumber = 0;
	int remainder, i = 1;

	while (n != 0) {
		remainder = n % 2;
		n /= 2;
		binaryNumber += remainder * i;
		i *= 10;
	}
	return binaryNumber;
}

//Driver function
int main() {
	int decimal;
	//Prompts user for input
	cout << "Enter a decimal number to be converted into binary: ";
	cin >> decimal;

	//Display the resultant binary number
	cout << "Binary number: " << convertDecimalToBinary(decimal) << "\n";

	return 0;
}

/*
Input:
Enter a decimal number to be converted into binary: 13
Output:
Binary number: 1101

Input:
Enter a decimal number to be converted into binary: 57
Output:
Binary number: 111001

Input:
Enter a decimal number to be converted into binary: 100
Output:
Binary number: 1100100

Time complexity: O(N)
Space complexity: O(1)
*/
