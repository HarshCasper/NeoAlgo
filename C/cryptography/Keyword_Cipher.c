/*Keyword cipher is a form of monoalphabetic substitution, where a keyword is used as the key. Now
  a encryption is formed of alphabets from [a-z] such that the first part of encrption contains 
  unique letters of the keyword and the rest are the remaining alphabets from [a-z]. That is,
  until the keyword is used up, whereupon the rest of the ciphertext letters are used in alphabetical 
  order, excluding those already used in the key.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Defining max length of plaintext, keyword, ciphertext
#define MAXLENGTH 100

/*This is the encryption function that takes plaintext message
  and keyword as input*/
char* encrypt(char* message, char* keyword) {

	//This variable contains encrypted message
	static char encrypted_message[MAXLENGTH];
	//This the pad to be generated using keyword
	static char pad[MAXLENGTH];

	int count = 0;
	int i = 0;

	/*If the plaintext contains spaces, replace it by
	  underscores*/
	for(int i = 0; i < strlen(message) - 1; i++) {
		if(message[i] == ' ') {
			message[i] = '_';
		}
	}
	
	/*This while loop finds all the unique alphabets in the
	  keyword and is inserted at the beginning of the pad*/
	while(i < strlen(keyword) - 1) {

		//If the keyword alphabet is a space, then leave it
		if(keyword[i] == ' ') {
			i++;
			continue;
		}
	
		int not_present = 0;
		
		for(int j = 0; j < strlen(keyword) - 1; j++) {
			if(keyword[i] != pad[j]) {
				not_present += 1;
			}
		}
		
		//If the keyword alphabet is not present in the pad
		if(not_present == strlen(keyword) - 1) {
			//add it
			pad[count] = keyword[i];
			count++;
		}
		i++;
	}

	/*After this while loop, we get first half of our pad.
	  For example, if the keyword is "well", then "wel" is
	  added to the pad*/

	/*Now to fill the pad, all the remaining alphabets those are not previously present 
	  are added to it*/
	char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

	//This while loop completes the remaining of the pad
	i = 0;
	while(i < 26) {
		int np = 0;
		for(int j = 0; j < 26; j++) {
			if(alphabet[i] != pad[j]) {
				np += 1;
			}
		}
		if(np == 26) {
			pad[count] = alphabet[i];
			count++;
		}
		i++;
	}
	
	/*Now we the pad, and we have the plaintext message,
	  we replace alphabets of plaintext as per their
	  occurence in the pad*/
	for(int i = 0; i < strlen(message) - 1; i++) {

		/*If the message has space, add space to the
		  encrypted message also*/
		if(message[i] == '_') {
			encrypted_message[i] = ' ';
		}
		/*else replace it with the corresponding position
		  in the pad*/
		else {
			int index = 0;
			for(int j = 0; j < strlen(alphabet); j++) {
				if(message[i] == alphabet[j]) {
					index = j;
				}
			}
			encrypted_message[i] = pad[index];
		}
	}
	//return the encrypted message
	return encrypted_message;
}

int main() {

	//Declaring variables to store plaintext and keyword
	char plaintext[MAXLENGTH];
	char keyword[MAXLENGTH];

	//Taking input from the user
	printf("Enter the plaintext   : ");
	fgets(plaintext, MAXLENGTH, stdin);

	printf("Enter the keyword     : ");
	fgets(keyword, MAXLENGTH, stdin);
	
	//Printing the respective ciphertext by calling the encrypt function
	printf("The encrypted text is : %s\n", encrypt(&plaintext[0], &keyword[0]));

	return 0;
}

/*
 Sample I/O :

 	Enter the plaintext   : neo algo is awesome
	Enter the keyword     : a star
	The encrypted text is : kbl aidl fp awbpljb	
 */ 

