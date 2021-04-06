/* Below is an implementation of Burrows Wheeler Transform in Go. It restructures
the given plaintext to forms the ciphertext. It first forms all possible cyclic
rotations of the plaintext, and then sorts the rotations lexicographically. Then,
ciphertext is formed by taking the last character of each rotation sorted in
lexicographical order. This code is implemented keeping in mind that characters
in the plaintext are all unique.*/

package main

import (
	"fmt"
	"os"
)

// Define the size of the n (Globally)
var n int = 4

// This function generates all cyclic rotations of given plaintext
func gen_rotations(plaintext string, combinations [][]string) {

	var indx int = 0
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			combinations[i][j] = string(plaintext[(indx + j) % n])
		}
		indx += 1;
	}
}

// This function sorts the above rotations lexicographically.
func sort(plaintext string, combinations [][]string, arr []int) {

	// Calling the generate function to generate all rotations
	gen_rotations(plaintext, combinations)

	var count int = 0

	for k := 0; k < n; k++ {

		// Iterate through the first column
		for i := 0; i < 1; i++ {
			/* Character { is lexicograqphically greater than
			[A-Z] and [a-z]. So, we use it here as a maximum.*/
			var min string = "{"
			var indx int

			// Iterate though first element of each row
			for j := 0; j < n; j++ {
				if(combinations[j][i] < min) {
					// Find the minimum
					min = combinations[j][i]
					// Store its index
					indx = j
				}
			}
			// Add the index to the array
			arr[count] = indx
			count += 1
			// Replace the minimum with {
			combinations[indx][i] = "{"
		}
	}
}

// This is the encrpytion function
func encrypt(plaintext string, combinations [][]string) string {

	var arr = make([]int, n)

	// Calling the sort function to get the sorted order
	sort(plaintext, combinations, arr)

	var encrypted string

	// Adding last element of sorted rotation to the encrypted text
	for i := 0; i < n; i++ {
		encrypted += combinations[arr[i]][n - 1]
	}
	// Returning the encrypted message
	return encrypted
}

func main() {

	fmt.Print("----------Burrows Wheeler Transform----------\n")
	fmt.Print("\nCurrent value of n is: ", n, "\n\n")

	// Taking plaintext as input from user
	fmt.Print("Enter a plaintext of size ", n, ": ")
	var plaintext string
	fmt.Scan(&plaintext)

	// Check if size of plaintext is equal global var n
	if(len(plaintext) != n) {
		fmt.Print("Invalid message entered.\n")
		os.Exit(0)
	}

	// Decalring matrix to store the rotations
	var combinations = make([][]string, n)
	for i := range combinations {
		combinations[i] = make([]string, n)
	}

	// Calling the encrypted fuction and printing ciphertext
	var encrypted string = encrypt(plaintext, combinations)
	fmt.Print("\nEncrypted plaintext is: ", encrypted, "\n")
}

/* Sample I/O:

a)
----------Burrows Wheeler Transform----------

Current value of n is: 10

Enter a plaintext of size 10: ThisISBurr

Encrypted plaintext is: SsIrThuriB

b)
----------Burrows Wheeler Transform----------

Current value of n is: 4

Enter a plaintext of size 4: hell

Encrypted plaintext is: hlel

*/
