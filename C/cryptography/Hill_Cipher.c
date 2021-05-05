/* This code is an implementation of Hill Cipher. It
   is a polygraphic substitution cipher. It forms a 
   nxn matrix of key and nx1 matrix(s) of the plaintext
   and then multiplies the two matrices to obtains the
   matrix of ciphertext.*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Define max-length for message, ciphertext and key
#define MAXLENGTH 100

// Define the size of the n.
#define size 3

/* This function forms the nxn matrix of keyword.
   The value of n can be changed from above macro*/
void get_key_matrix(char* key, int matrix_key[][size]) {

	int count = 0;
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			// Converting ascii to decimal
			matrix_key[i][j] = key[count] - 0;
			/* Here, a = 97, b = 98 and so on.
			   We want a = 0, b = 1 and so on.
			   So, we subtract 97.*/
			matrix_key[i][j] -= 97;
			count++;
		}
	}
}

/* This function forms the nx1 matrix of the plaintext.
   Value of n can be changed from the macro defined.*/
void get_plaintext_matrix(char* message, int message_matrix[][1]) {

	int count = 0;
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < 1; j++) {
			// Converting ascii to decimal
			message_matrix[i][j] = message[count] - 0;
			/* As we did above, similarly, we subtract
			   97 from the decimal value to start
			   indexing from 0.*/
			message_matrix[i][j] -= 97;
			count++;
		}
	}
}

/* This function forms the nx1 ciphertext matrix.
   The matrix of decimal is then converted to ascii
   value and combined and then returned.*/
char* get_ciphertext_matrix(char* message, char* keyword, int matrix_cipher[][1]) {

	// Forming the keyword matrix 
	int matrix_key[size][size];
	// Calling the keyord matrix function
	get_key_matrix(keyword, matrix_key);

	// Forming the plaintext matrix
	int message_matrix[size][1];
	// Callin the plaintext matrix function
	get_plaintext_matrix(message, message_matrix);

	/* Initializing the ciphertext matrix values
	   to zero. Otherwise, it would store garbage
	   values.*/
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < 1; j++) {
			matrix_cipher[i][j] = 0;
		}
	}

	/* Multiplying key matrix with plaintext
	   matrix and forming the ciphertext
	   matrix. */
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < 1; j++) {
			for(int k = 0; k < size; k++) {
				matrix_cipher[i][j] += matrix_key[i][k] * message_matrix[k][j];
			}
		}
	}

	/* Taking mod 26 of obtained ciphertext values
	   to ensure they lie within the range [0-25].*/
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < 1; j++) {
			matrix_cipher[i][j] = matrix_cipher[i][j] % 26;
		}
	}

	// This variable is declared to store the ciphertext
	static char encrypted[MAXLENGTH];

	/* Since, we decremented 97 from the decimal values
	   of plaintext and key, we add back 97 to the 
	   ciphertext values, in order to get proper ASCII.*/
	int cnt = 0;
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < 1; j++) {
			encrypted[cnt++] = matrix_cipher[i][j] + 97;
		}
	}

	// Returning the ciphertext
	return encrypted;
}


int main() {

	// Taking plaintext and key as input from user
	char plaintext[MAXLENGTH];
	char keyword[MAXLENGTH];

	printf("\n-----------------------HILL CIPHER--------------------------\n\n");
	printf("The value of plaintext must be same as n(Defined in the macro)\n");

	printf("\nCurrent value of n is: %d\n\n", size);

	printf("Enter a plaintext of size %d: ", size);
	scanf("%s", plaintext);

	// Checking if proper message is provided or not.
	if(strlen(plaintext) != size) {
		printf("Enter a valid message.\n");
		exit(0);
	}

	printf("Enter a key of size %d: ", size*size);
	scanf("%s", keyword);

	// Checking if proper key is provided or not.
	if(strlen(keyword) != size * size) {
		printf("Enter a valid key.\n");
		exit(0);
	}

	// Declaring the ciphertext matrix
	int matrix_cipher[size][1];

	char *encrypted_message;

	// Calling the function to get the encrypted plaintext
	encrypted_message = get_ciphertext_matrix(&plaintext[0], &keyword[0], matrix_cipher);

	printf("Encrypted plaintext is : %s\n", encrypted_message);

	return 0;
}

/* Sample I/O:

a) For n = 3


-----------------------HILL CIPHER--------------------------

The value of plaintext must be same as n(Defined in the macro)

Current value of n is: 3

Enter a plaintext of size 3: ask
Enter a key of size 9: thisiskey
Encrypted plaintext is : yma

b) For n = 4


-----------------------HILL CIPHER--------------------------

The value of plaintext must be same as n(Defined in the macro)

Current value of n is: 4

Enter a plaintext of size 4: mess
Enter a key of size 16: thisisabigkeymsg
Encrypted plaintext is : weio
*/

