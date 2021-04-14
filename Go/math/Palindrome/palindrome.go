package main

import (
	"fmt"
	"bufio"
	"os"
)

// This function checks if string is a palindrome
func palindrome_check(str string) int {
	// Iterate till the middle of the string
	for i:=0; i < len(str) / 2; i++ {
		/* Check if character at beginning index of the
		string matches the end of the string at same index*/
		if(string(str[i]) != string(str[len(str) - 1 - i])) {
			// If it does not then return -1
			return -1
		}
	}
	// If everything matches then return 1
	return 1
}

func main() {

	// Take string as input from the user
	fmt.Print("Enter a string to check if it is a palindrome: ")

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	line := scanner.Text()

	// Calling the function to check
	var result int = palindrome_check(line)

	/* If the string is a palindrome.
	Else the string is not a palindrome*/
	if(result == 1) {
		fmt.Print("\nThe entered string is a palindrome.\n")
	} else {
		fmt.Print("\nThe entered string is not a palindrome.\n")
	}
}

/* Sample I/O:

Enter a string to check if it is a palindrome: check kcehc

The entered string is a palindrome.

Time Complexity - O(n)
Space Complexity - O(1)
*/

