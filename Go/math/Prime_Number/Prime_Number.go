/* This program checks if a number is a prime number. A number is a
prime number if it has no other factor than 1 and the number itself.*/

package main

import (
	"fmt"
	"os"
)


// This function checks if a number is a prime number
func is_prime(n int) int {

	// Iterate from 2 to number - 1
	for i := 2; i < n; i++ {
		if(n % i == 0) {
			/* If the number is divisible by any of them
			then return -1, it is not a prime number.*/
			return -1
		}
	}
	// Else return 1, the number is a prime number
	return 1
}

func main() {

	// Take number as input from the user
	fmt.Print("Enter a number to check if it's a prime number: ")
	var n int
	fmt.Scan(&n)

	// If the number is less than equal to 1, exit.
	if(n <= 1) {
		fmt.Print("The number ", n, " is not a prime number.\n")
		os.Exit(0)
	}

	// Call the function
	var result int = is_prime(n)
	if(result == 1) {
		fmt.Print("\nThe number ", n, " is a prime number.\n")
	} else {
		fmt.Print("\nThe number ", n, " is not a prime number.\n")
	}
}

/* Sample I/O:

a)
Enter a number to check if it's a prime number: 11243

The number 11243 is a prime number.

b)
Enter a number to check if it's a prime number: 12334

The number 12334 is not a prime number.

*/
