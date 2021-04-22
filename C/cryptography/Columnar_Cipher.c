/*In Columnar Cipher, we are given a plaintext and a key. The plaintext is written out in rows and the ciphertext
 * is formed by reading out columns one by one according to the order of the key given. Key is converted to its 
 * corresponding numerical(Ex A-0, B-1, C-2, ...... , Z-25). Cipher text is formed by reading the columns corresponding
 * to the lowest numerical value in the key to highest numerical value.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

//Defining maximum length of plaintext and key
#define MAXLENGTH 100

//Sort function, returns sorted integer array
int* sort(int arr[], int len) {

	//Bubble sort is used here
	for(int i = 0; i < len - 1; i++) {
		for(int j = 0; j < len - 1 - i; j++) {
			if(arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	return arr;
}

/*This function returns the corresponding numerical value 
  of the key in the form of an array
*/
int* order(char* key) {

	int length = strlen(key);

	static int order_key[MAXLENGTH];
	
	/*We find the numerical value of each alphabet
	  corresponding to the key*/
	for(int i = 0; i < length; i++) {
		order_key[i] = key[i] - 0;
		order_key[i] -= 65;
	}

	static int temp[MAXLENGTH];

	//Storing the numerical value temporarily
	for(int i = 0; i < length; i++) {
		temp[i] = order_key[i];
	}

	/*Finding the relative numbering of
	  each alphaet in the key*/
	int* sorted;
	sorted = sort(order_key, length);

	static int index[MAXLENGTH];

	for(int i = 0; i < length; i++) {
		for(int j = 0; j < length; j++) {
			if(temp[i] == sorted[j]) {
				index[i] = j+1;
			}
		}
	}
	/*Returning the array containing the numerical
	  value of key in relative order*/
	return index;
}

/*This is the encrypt function that takes
  plaintext and key as input*/
char* encrypt(char* message, char* key) {

	//varible to store the correspoding cipher text
	static char decrypted_message[MAXLENGTH];

	int length_key = strlen(key);
	int length_message = strlen(message) - 1;

	/*Replacing any spaces in the plaintext with
	  underscores*/
	for(int i = 0; i < length_message; i++) {
		if(message[i] == ' ') {
			message[i] = '_';
		}
	}
	
	/*If in the matrix any row is left vacant at the
	  end, we fill the blank spaces with underscores*/
	if((length_message % length_key) != 0) {
		int extra = length_key - length_message % length_key;
		for(int i = 0; i < extra; i++) {
			message[length_message + i] = '_';
		}
		//Update the length of the message accordingly
		length_message = strlen(message);
	}

	//Define the matrix to transpose and get the cipher
	char matrix[(length_message / length_key)][length_key];

	int count = 0;
	int* columns;
	columns = order(key);

	//Fill in the values of plaintext in the matrix row by row
	for(int i = 0; i < (length_message/length_key); i++) {
		for(int j = 0; j < length_key; j++) {
			matrix[i][columns[j] - 1] = message[count];
			count++;
		}
	}

	int* sorted;
	sorted = sort(columns, length_key);
	int cnt = 0;
	
	/* Now create the ciphertext by reading values from the matrix 
	   in a column by column fashion*/
	for(int i = 0; i < length_key; i++) {
		for(int j = 0; j < (length_message / length_key); j++) {
			//If there is a space, replace it with an underscore
			if(matrix[j][sorted[i] - 1] == ' ') {
				decrypted_message[cnt] = '_';
			}
			else {
				decrypted_message[cnt] = matrix[j][sorted[i] - 1];
			}
			cnt++;
		}
	}
	//return the encrypted ciphertext
	return decrypted_message;
}

int main() {

	//Declaring variables for the message and key
	char key[MAXLENGTH];
	char plaintext[MAXLENGTH];

	//Taking message and key as input from the user
	printf("Enter plaintext       : ");
	fgets(plaintext, MAXLENGTH, stdin);
	printf("Enter key             : ");
	scanf("%s", key);

	//Print the encrypted message by calling the encrypt function
	printf("The encrypted text is : %s\n", encrypt(&plaintext[0], &key[0]));

	return 0;
}

/*Sample I/O :
 
  	Enter plaintext       : NeoAlgoIsAwesome
	Enter key             : HACK
	The encrypted text is : egAooowmNlssAIee
	
 	Enter plaintext       : THIS IS A PLAINTEXT
	Enter key             : KEY
	The encrypted text is : H__PIE_TSS_ATTIIALNX_	
 */

