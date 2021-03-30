/*Below is an implementation of Burrows Wheeler Transform in C. It restructures
the given plaintext to forms the ciphertext. It first forms all possible cyclic
rotations of the plaintext, and then sorts the rotations lexicographically. Then,
ciphertext is formed by taking the last character of each rotation sorted in
lexicographical order. This code is implemented keeping in mind that characters
in the plaintext are all unique.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum length of plaintext, ciphertext
#define MAXLENGTH 100

// Define size of plaintext
#define size 6

// This function generates all cyclic rotations of given plaintext
void generate(char* plaintext, char combinations[][size]) {

	int index = 0;
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			// Mod is used to wrap around the index
			combinations[i][j] = plaintext[(index + j) % size];
		}
		index += 1;
	}
}

// This function sorts the above rotations lexicographically.
void sort(char* plaintext, char combinations[][size], int arr[size]) {

	// Calling the generate function to generate all rotations
	generate(&plaintext[0], combinations);

	int count = 0;
	int k = 0;

	while(k < size) {

		// Iterate through the first column
		for(int i = 0; i < 1; i++) {
			/* Char { is lexicograqphically greater than
			[A-Z] and [a-z]. So, we use it here as a maximum.*/
			char min = '{';
			int index;

			// Iterate though first element of each row
			for(int j = 0; j < size; j++) {
				if(combinations[j][i] < min) {
					// Find the minimum
					min = combinations[j][i];
					// Store its index
					index = j;
				}
			}
			// Add the index to the array
			arr[count++] = index;
			// Replace the minimum with {
			combinations[index][i] = '{';
		}
		k++;
	}
}

// This is the encrpytion function
char* encrypt(char* plaintext, char combinations[][size]) {

	int arr[size];

	// Calling the sort function to get the sorted order
	sort(plaintext, combinations, arr);

	// Declaring variable to store the ciphertext
	static char encrypted[MAXLENGTH];

	int count = 0;
	// Adding last element of sorted rotation to the encrypted text
	for(int i = 0; i < size; i++) {
		encrypted[count++]  = combinations[arr[i]][size - 1];
	}
	// Returning the encrypted message
	return encrypted;
}

int main() {

	printf("----------Burrows Wheeler Transform----------\n");
	printf("\nCurrent size of macro n is %d\n", size);

	// Taking plaintext as input from the user
	char plaintext[MAXLENGTH];
	printf("\nEnter plaintext of size %d: ", size);
	fgets(plaintext, MAXLENGTH, stdin);

	// Check if size of plaintext is equal to macro size
	if(strlen(plaintext) - 1 != size) {
		printf("Invalid message entered.\n");
		exit(0);
	}

	// Decalring matrix to store the rotations
	char combinations[size][size];

	// Calling the encrypted fuction and printing ciphertext
	char* encrypted = encrypt(&plaintext[0], combinations);
	printf("The encrypted plaintext is: %s\n", encrypted);

	return 0;
}

/* Sample I/O:
a)
----------Burrows Wheeler Transform----------

Current size of macro n is 10

Enter plaintext of size 10: plainwords
The encrypted plaintext is: lrapiwsodn

b)
----------Burrows Wheeler Transform----------

Current size of macro n is 6

Enter plaintext of size 6: iworld
The encrypted plaintext is: ldrwoi
*/

