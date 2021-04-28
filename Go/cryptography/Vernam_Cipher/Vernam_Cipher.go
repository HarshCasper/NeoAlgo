/* This code is an implementation of Vernam Cipher in Go. In
Vernam cipher, also known as the One-Time Pad, the length of
the plaintext, ciphertext, and key is the same. Basically,
here the ith letter of the cipher text is fomred by shifting
the ith letter of the plaintext with the ith letter of key.
*/

package main

import (
	"fmt"
	"unicode"
	"strings"
	"os"
)

// This is the encryption function
func encryption(plaintext, key string) string {

	var encrypted string

	// Shifting the plaintext to generate the ciphertext
	for i := 0; i < len(plaintext); i++ {
		var temp int = (int(plaintext[i]) - 97 + int(key[i]) - 97) % 26
		temp = temp + 97
		encrypted += string(temp)
	}
	// Returns the ciphertext
	return encrypted
}

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

	// Taking plaintext as input from the user
	fmt.Print("Enter a message to encrypt: ")
	var plaintext string 
	fmt.Scan(&plaintext)

	// Taking key as input from the user
	fmt.Print("Enter a key of same length: ")
	var key string
	fmt.Scan(&key)

	/* If length of key is not equal to length
 	   of plaintext then exit the program.*/
	if(len(key) != len(plaintext)) {
		fmt.Print("\nInvalid key size.\n")
		os.Exit(0)
	}

	// Generating the ciphertext
	var ciphertext string = encryption(strings.ToLower(plaintext), strings.ToLower(key))

	// Formatting the ciphertext
	var encrypted string = format(plaintext, ciphertext)
	fmt.Print("\nEncrypted plaintext is    : ", encrypted, "\n")
}

/* Sample I/O:

a)
Enter a message to encrypt: ThisIsAMsg
Enter a key of same length: ThisisaKey

Encrypted plaintext is    : MoqkQkAWwe

b)
Enter a message to encrypt: PlaintextMessage
Enter a key of same length: Key

Invalid key size.
*/

