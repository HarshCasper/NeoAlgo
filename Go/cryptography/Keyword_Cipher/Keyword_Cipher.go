/*Below is an implementation of keyword cipher in Go. It is a form of
monoalphabetic substitution. A encryption is formed of alphabets from
[a-z] such that the first part of encrption contains unique letters of
the keyword and the rest are the remaining alphabets from [a-z]. That is,
until the keyword is used up, whereupon the rest of the ciphertext letters
are used in alphabetical order, excluding those already used in the key.*/

package main

import (
	"fmt"
	"unicode"
	"bufio"
	"os"
	"strings"
)

// This function generates the pad using the keyword
func padgen(key string) string {

	pad := [26]string{}
	count := 0
	i := 0

	for i < len(key) {

		// Ignoring the spaces in the given keyword
		if(string(key[i]) == " ") {
			i = i + 1
			continue
		}

		// Checking keyword alphabet-wise
		missing := 0
		for j := 0; j < len(key); j++ {
			if(string(key[i]) != string(pad[j])) {
				missing += 1
			}
		}

		// Adding the unique words of key to pad
		if(missing == len(key)) {
			pad[count] = string(key[i])
			count += 1
		}
		i = i + 1
	}
	// Till here we get the first half of the pad

	// Declaring ciphertext string
	var enc string
	var alphabet string = "abcdefghijklmnopqrstuvwxyz"

	i = 0
	// This while loop forms the remaining pad
	for i < 26 {

		not_present := 0
		for j := 0; j < 26; j++ {
			if(string(alphabet[i]) != string(pad[j])) {
				not_present += 1
			}
		}

		/* Whatever alphabets from [a-z] are not present
		in the pad till now, add them to the pad.*/
		if(not_present == 26) {
			pad[count] = string(alphabet[i])
			count = count + 1
		}
		i += 1
	}

	for i := 0; i < len(pad); i++ {
		if(pad[i] != " ") {
			enc += pad[i]
		}
	}

	// Return the length 26 pad
	return enc
}

// This is the encryption function
func encryption(plaintext, key string) string {

	// Generate the pad using the above function
	var pad string = padgen(strings.ToLower(key))
	var alphabet string = "abcdefghijklmnopqrstuvwxyz"

	// Replace all sapces in plaintext with underscores
	var message string
	for j := 0; j < len(plaintext); j++ {
		if(string(plaintext[j]) == " ") {
			message += string("_")
		} else {
			message += string(plaintext[j])
		}
	}

	// Declare the encrypted string
	var encrypted string

	for i := 0; i < len(plaintext); i++ {

		/*If the message has space, add space to the
		encrypted message at the same index.*/
		if(string(message[i]) == "_") {
			encrypted += " "
		} else {
			/*else replace it with the corresponding
			position in the pad*/
			index := 0
			for j := 0; j < len(alphabet); j++ {
				if(string(message[i]) == string(alphabet[j])) {
					index = j
				}
			}
			encrypted += string(pad[index])
		}
	}

	// Return the encrypted message
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

	// Take plaintext as input from the user
	fmt.Print("Enter the plaintext  : ")
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	plaintext := scanner.Text()

	// Taking keyword as input from the user
	fmt.Print("Enter the keyword    : ")
	scanner.Scan()
	key := scanner.Text()

	// Calling the encrypt function and formatting the ciphertext
	var ciphertext string = encryption(strings.ToLower(plaintext), strings.ToLower(key))
	var encrypted string = format(plaintext, ciphertext)

	// Printing the ciphertext
	fmt.Print("\nThe encrypted text is: ", encrypted, "\n")
}

/* Sample I/O:

Enter the plaintext  : This Is A Secret
Enter the keyword    : Mercury

The encrypted text is: Qbdp Dp M Purouq

*/
