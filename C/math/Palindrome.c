/* Below code checks if the given input string is
a palindrome or not. The string is traversed till
its middle index and beginning and end of the string
is compared.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum length of input string
#define MAXLENGTH 100

// This function checks if string is a palindrome
int check_palindrome(char* string) {
	
	// Iterate till the middle of the string
	for(int i = 0; i < (strlen(string) - 1) / 2; i++) {
		/* Check if character at beginning index of the
		string matches the end of the string at same index*/
		if(string[i] != string[strlen(string) - 2 - i]) {
			// If it does not then return -1
			return -1;
		}
	}
	// If everything matches then return 1
	return 1;
}

int main() {

	// Take string as input from the user
	char string[MAXLENGTH];
	printf("Enter a string to check if it is a palindrome: ");
	fgets(string, MAXLENGTH, stdin);

	// Calling the function to check
	int result = check_palindrome(string);
	
	// If the string is a palindrome
	if(result == 1) {
		printf("The given string is a palindrom.\n");
	}
	// If the string is not a palindrome
	else {
		printf("The given string is not a palindrom.\n");
	}
	
	return 0;
}

/* Sample I/O:
	Enter a string to check if it is a palindrome: This is a si sihT
	The given string is a palindrom.
*/

