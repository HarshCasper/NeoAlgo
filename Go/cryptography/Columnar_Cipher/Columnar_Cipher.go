/* In Columnar Cipher, we are given a plaintext and a key. The plaintext
is written out in rows and the ciphertext is formed by reading out columns
one by one according to the order of the key given. Key is converted to its
corresponding numerical(Ex A-0, B-1, C-2, ...... , Z-25). Cipher text is formed
by reading the columns corresponding to the lowest numerical value in the key to
the highest numerical value. */

package main

import (
	"fmt"
	"bufio"
	"os"
)

//Sort function, returns sorted integer array
func sort(array []int, length int) {

	//Bubble sort is used here
	for i := 0; i < length - 1; i++ {
		for j := 0; j < length - 1 - i; j++ {
			if(array[j] > array[j + 1]) {
				var temp int = array[j]
				array[j] = array[j + 1]
				array[j + 1] = temp
			}
		}
	}
}

/*This function returns the corresponding numerical
value of the key in the form of an array*/
func order(key string) []int {

	order_key := make([]int, len(key))

	/*We find the numerical value of each
	alphabet corresponding to the key*/
	for i := 0; i < len(key); i++ {
		order_key[i] = int(key[i])
		order_key[i] -= 65
	}

	temp := make([]int, len(key))

	//Storing the numerical value temporarily
	for i := 0; i < len(key); i++ {
		temp[i] = order_key[i]
	}

	/*Store according to relative numbering of
	each alphaet in the key*/
	sort(order_key, len(key))

	index := make([]int, len(key))

	for i := 0; i < len(key); i++ {
		for j := 0; j < len(key); j++ {
			if(temp[i] == order_key[j]) {
				index[i] = j+1
			}
		}
	}
	/*Returning the array containing the numerical
        value of key in relative order*/
	return index
}

/*This is the encrypt function that takes
plaintext and key as input*/
func encrypt(plaintext, key string) string {

	decrypted_message := [26]string{}

	var length_key int = len(key)
	var length_message int = len(plaintext)

	/*Replacing any spaces in the plaintext with
	underscores*/
	var message string
	for j:= 0; j < length_message; j++ {
		if(string(plaintext[j]) == " ") {
			message += string("_")
		} else {
			message += string(plaintext[j])
		}
	}

	/*If in the matrix any row is left vacant at the
	end, we fill the blank spaces with underscores*/
	if((length_message % length_key) != 0) {
		var extra int = length_key - length_message % length_key
		for i := 0; i < extra; i++ {
			message += "_"
		}
		//Update the length of the message accordingly
		length_message = len(message)
	}

	//Define the matrix to transpose and get the cipher
	var matrix = make([][]string, (length_message / length_key))
	for i := range matrix {
		matrix[i] = make([]string, length_key)
	}

	var count int = 0
	var columns []int = order(key)

	var cnt int = 0

	//Fill in the values of plaintext in the matrix row by row
	for i := 0; i < (length_message/length_key); i++ {
		for j := 0; j < length_key; j++ {
			matrix[i][columns[j] - 1] = string(message[count])
			count++
		}
	}

	sort(columns, length_key);

	/* Now create the ciphertext by reading values from the matrix
	in a column by column fashion*/
	for i := 0; i < length_key; i++ {
		for j := 0; j < (length_message / length_key); j++ {
			//If there is a space, replace it with an underscore
			if(matrix[j][columns[i] - 1] == " ") {
				decrypted_message[cnt] = "_"
			} else {
				decrypted_message[cnt] = matrix[j][columns[i] - 1]
			}
			cnt += 1
		}
	}

	var enc string

	// Convert the asrray to string
	for i := 0; i < len(decrypted_message); i++ {
		if(string(decrypted_message[i]) == "_") {
			enc += " "
		} else {
			enc += decrypted_message[i]
		}
	}

	//return the encrypted ciphertext
	return enc
}

func main() {

	// Taking plaintext as input from the user
	fmt.Print("Enter the plaintext  : ")
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	plaintext := scanner.Text()

	// Taking keyword as input from the user
	fmt.Print("Enter the keyword    : ")
	scanner.Scan()
	key := scanner.Text()

	//Print the encrypted message by calling the encrypt function
	var ciphertext string = encrypt(plaintext, key)
	fmt.Print("\nEncrypted plaitext is: ", ciphertext, "\n")
}

/* Sample I/O:

Enter the plaintext  : THIS IS A PLAINTEXT
Enter the keyword    : KEY

Encrypted plaitext is: H  PIE TSS ATTIIALNX

*/
