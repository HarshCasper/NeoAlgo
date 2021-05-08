/* This program written in C checks if a number is a perfect
number. A perfect number is a number which is equal to the sum
of its divisors (excluding the number itself).*/

#include <stdio.h>
#include <stdlib.h>

// This function checks if a number is a perfect number
int is_perfect(int number) {

	// This variable stores the sum of divisors of number
	int sum_of_div = 0;
	// Iterate from 1 till the number
	for(int i = 1; i < number; i++) {
		if(number % i == 0) {
			// Add divisors
			sum_of_div += i;
		}
	}
	// If the sum of divisors is equal to the number
	if(sum_of_div == number) {
		// Return 1
		return 1;
	}
	// Else return -1
	return -1;
}

int main() {

	// Take number as input from the user
	int number;
	printf("Enter a number: ");
	scanf("%d", &number);

	// If the number is non-positive, exit
	if(number <= 0) {
		printf("\nPlease enter a positive number.\n");
		exit(0);
	}

	// Call the function
	int result = is_perfect(number);

	// If the result is 1, the number is a perfect number
	if(result == 1) {
		printf("\nThe number %d is a perfect number.\n", number);
		exit(0);
	}
	// Else it is not
	else {
		printf("\nThe number %d is not a perfect number.\n", number);
		exit(0);
	}
}

/*
Sample I/O:

1)
Enter a number: 28

The number 28 is a perfect number.

2)
Enter a number: -23

Please enter a positive number.

*/
