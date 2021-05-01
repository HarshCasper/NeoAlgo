/* This code is an implementation of Hill Cipher in Go. It
is a polygraphic substitution cipher. It forms a nxn matrix
of key and nx1 matrix(s) of the plaintext and then multiplies
the two matrices to obtains the matrix of ciphertext.*/

package main

import (
	"fmt"
	"os"
	"unicode"
	"strings"
)

// Define the size of the n (Globally)
var n int = 3

/* This function forms the nxn matrix of keyword.
The value of n can be changed using the global var.*/
func gen_key_matrix(key string, keymatrix [][]int) {

	var count int = 0
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			/*Converting ascii to decimal. Here, 
			a = 97, b = 98 and so on. We want a = 0,
			b = 1 and so on. So, we subtract 97.*/
			keymatrix[i][j] = int(key[count]) - 97
			count += 1
		}
	}
}

/* This function forms the nx1 matrix of the plaintext.
Value of n can be changed using the global var.*/
func gen_message_matrix(plaintext string, messagematrix [][]int) {

	var count int = 0
	for i := 0; i < n; i++ {
		for j := 0; j < 1; j++ {
			/*Converting ascii to decimal. As we did above,
			similarly, we subtract 97 from the decimal value
			to start indexing from 0.*/
			messagematrix[i][j] = int(plaintext[count]) - 97
			count += 1
		}
	}
}

/* This function forms the nx1 ciphertext matrix. The matrix of decimal
is then converted to ascii value and combined and then returned.*/
func gen_ciphertext(plaintext, key string, ciphermatrix [][]int) string {

	// Forming the keyword matrix
	var keymatrix = make([][]int, n)
	for i := range keymatrix {
		keymatrix[i] = make([]int, n)
	}
	// Calling the keyord matrix function
	gen_key_matrix(key, keymatrix)

	// Forming the plaintext matrix
	var messagematrix = make([][]int, n)
	for i := range messagematrix {
		messagematrix[i] = make([]int, 1)
	}
	// Calling the plaintext matrix function
	gen_message_matrix(plaintext, messagematrix)

	/* Initializing the ciphertext matrix values to
	zero. Otherwise, it would store garbage values.*/
	for i := 0; i < n; i++ {
		for j := 0; j < 1; j++ {
			ciphermatrix[i][j] = 0
		}
	}

	/* Multiplying key matrix with plaintext matrix
	and forming the ciphertext matrix. */
	for i := 0; i < n; i++ {
		for j := 0; j < 1; j++ {
			for k := 0; k < n; k++ {
				ciphermatrix[i][j] += keymatrix[i][k] * messagematrix[k][j]
			}
		}
	}

	/* Taking mod 26 of obtained ciphertext values
	to ensure they lie within the range [0-25].*/
	for i := 0; i < n; i++ {
		for j := 0; j < 1; j++ {
			ciphermatrix[i][j] = ciphermatrix[i][j] % 26		}
	}

	// This variable is declared to store the ciphertext
	var encrypted string

	/* Since, we decremented 97 from the decimal values
	of plaintext and key, we add back 97 to the ciphertext
	values, in order to get proper ASCII.*/
	for i := 0; i < n; i++ {
		for j := 0; j < 1; j++ {
			encrypted += string(ciphermatrix[i][j] + 97)
		}
	}

	// Returning the ciphertext
	return encrypted;

}

/* This function formats the ciphertext according
to the plaintext.*/
func format(plaintext, ciphertext string) string {

	var enc string

	/* Check wherever the plaintext is capital and
	then capitalize that character in the ciphertext*/
	for i := 0; i < len(plaintext); i++ {
		if(unicode.IsUpper(rune(plaintext[i]))) {
			enc += strings.ToUpper(string(ciphertext[i]))
		} else {
			enc += string(ciphertext[i])
		}
	}
	// Return the final formatted ciphertext
	return enc
}

func main() {

	fmt.Print("\n--------------HILL CIPHER-----------------\n\n")
	fmt.Print("The value of plaintext must be same as n\n")
	fmt.Print("\nCurrent value of n is: ", n, "\n\n")

	// Taking plaintext as input from user
	fmt.Print("Enter a plaintext of size ", n, ": ")
	var plaintext string
	fmt.Scan(&plaintext)

	// Checking if proper message is provided or not.
	if(len(plaintext) != n) {
		fmt.Print("Enter a valid message.\n")
		os.Exit(0)
	}

	// Taking key as input from user
	fmt.Print("Enter a keyword of size ", n*n, ": ")
	var key string
	fmt.Scan(&key)

	// Checking if proper key is provided or not.
	if(len(key) != n*n) {
		fmt.Print("Enter a valid key.\n")
		os.Exit(0)
	}

	var ciphertext string

	// Declaring the ciphertext matrix
	var ciphermatrix = make([][]int, n)
	for i := range ciphermatrix {
		ciphermatrix[i] = make([]int, 1)
	}

	// Calling the function to get the encrypted plaintext
	ciphertext = gen_ciphertext(strings.ToLower(plaintext), strings.ToLower(key), ciphermatrix)
	fmt.Print("\nEncrypted plaintext is: ", format(plaintext, ciphertext), "\n")
}

/* Sample I/O:

a)

--------------HILL CIPHER-----------------

The value of plaintext must be same as n

Current value of n is: 4

Enter a plaintext of size 4: helo
Enter a keyword of size 16: thisisabigmessag

Encrypted plaintext is: hmiw

b)

--------------HILL CIPHER-----------------

The value of plaintext must be same as n

Current value of n is: 3

Enter a plaintext of size 3: hey
Enter a keyword of size 9: thisiskey

Encrypted plaintext is: psm

*/
