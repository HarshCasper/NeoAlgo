/* This code is an implementation of caesar cipher. Here the 
plaintext is shifted by a fixed amount. The shift is chosen by
the user. Each alphabet of plaintext is then converted to decimal,
shifted, and then again converted back to ascii to form the 
ciphertext. Here the input plaintext must be all in lowercase*/

package main

import (
	"fmt"
	"bufio"
	"os"
)

// This is the encryption function
func caesar(plaintext string, shift int) string {

	/* Updating the plaintext by replacing all
	the spaces with underscores.*/
	var message string
	for j:= 0; j < len(plaintext); j++ {
		if(string(plaintext[j]) == " ") {
			message += string("_")
		} else {
			message += string(plaintext[j])
		}
	}

	// Cipher text string
	var cipher string
	// Iterating through each alphabet of plaintext
	for i:=0; i < len(message); i++ {
		/* Shift the alphabets of plaintext. If it is
		an underscore, add a space in ciphertext*/
		if(string(message[i]) != "_") {
			var temp int = (int(plaintext[i]) + shift - 97) % 26
			temp = temp + 97
			cipher += string(temp)
		} else {
			cipher += " "
		}
	}
	// Return the ciphertext
	return cipher
}

func main() {

	// Taking plaintext as input from the user
	fmt.Print("Enter a plaintext: ")
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	plaintext := scanner.Text()

	// Taking the shift amount as input from user
	var shift int
	fmt.Print("Enter the shift  : ")
	fmt.Scan(&shift)

	// Calling the encryption function, print the ciphertext
	var ciphertext string = caesar(plaintext, shift)
	fmt.Print("\nEncrypted plaintext is: ", ciphertext, "\n")
}

/* Sample I/O:

Enter a plaintext: this is a ciphertext
Enter the shift  : 7

Encrypted plaintext is: aopz pz h jpwolyalea

*/

