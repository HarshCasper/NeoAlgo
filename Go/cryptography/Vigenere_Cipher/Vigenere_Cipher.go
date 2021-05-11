/* Below code is an implementation of Vigenere Cipher in golang.
It is a form of substitution cipher. Given a plaintext and a key.
If the length of key is smaller than that of plaintext, then we 
repeat the contents of the key in a circular fashion till both of
their lengths is same. Plaintext and key are converted to number 
[0-25] and then each character of plaintext is shifted by character
present at the same index in the key to form the encrypted message.*/

package main

import (
	"fmt"
	"strings"
	"unicode"
)

/*This method generates the key if the length of key
is shorter than the length of the plaintext.*/
func keygen(key string, length int) string {

	if(len(key) < length) {
		var pad string
		for j := 0; j < len(key) ; j++ {
			pad += string(key[j])
		}
		/*In a circular fashion, we add the contents
		of the key from front to the end, till the
		length of the key becomes equal to the length
		of the plaintext.*/
		for i := 0; i < (length - len(key)); i++ {
			pad += string(key[i % len(key)])
		}
		return pad
	}
	// Return the final key to be used
	return key
}

// This is the encryption function
func encrypt(plaintext, key string) string {

	/* Calling the above function to ensure that
	the length of the key is same as length of
	the plaintext*/
	var pad string = keygen(key, len(plaintext))
	var encrypted string

	// Shifting the plaintext to generate the ciphertext
	for i := 0; i < len(plaintext); i++ {
		var temp int = (int(plaintext[i]) - 97 + int(pad[i]) - 97) % 26
		temp = temp + 97
		encrypted += string(temp)
	}
	// Returns the ciphertext
	return encrypted
}

/* This method formats the ciphertext according to
the plaintext. From the encrypt function above, we
send plaintext in lowercase. So, the ciphertext we
get is also in all lowercase. Here, we format the
ciphertext so that wherever there is capital letter
in the plaintext, same follows in the ciphertext.*/
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
	var plaintext string
	fmt.Print("Enter a plaintext to encrypt: ")
	fmt.Scan(&plaintext)

	// Taking key as input from the user
	var key string
	fmt.Print("Enter a key: ")
	fmt.Scan(&key)

	// Generating the ciphertext
	var ciphertext string = encrypt(strings.ToLower(plaintext), strings.ToLower(key))

	// Formatting the ciphertext
	var encrypted string = format(plaintext, ciphertext)
	fmt.Print("\nEncrypted plaintext is: ", encrypted, "\n")
}

/* Sample I/O:

Enter a plaintext to encrypt: ThisIsAPlainText
Enter a key: Mercury

Encrypted plaintext is: FlzuCjYBprkhKcjx

*/

