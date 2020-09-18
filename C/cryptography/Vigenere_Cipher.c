/*Vigenere Cipher Algorithm is a famous cryptographic algorithm.
Vigenère cipher is a method of encrypting alphabetic text by using a series of interwoven Caesar ciphers*/

#include <stdio.h>
#include <string.h>

char key[100];
int x;

void encryption(char message[]) {
	for (int i = 0; i < strlen(message); ++i) {
		int t=(message[i] + key[i%x])%26;
    	message[i]=('A'+t);
	}
}

void decryption(char message[]) {
	for (int i = 0; i < strlen(message); ++i) {
	    int t=(message[i] - key[i%x] +26)%26;
	    message[i]=('A'+t);
	}
}

int main() {
	char message[100];
	printf("Enter Message To Encode: ");
	scanf("%s", message);
	//use only uppercase characters (you can modify the code for lowercase characters)
	printf("\nEnter Key:");
	scanf("%s", key);
	x=strlen(key);

	printf("Generated Key: %s\n", key);
	encryption(message);
	printf("Encrypted Message: %s\n",message);

	decryption(message);
	printf("Decrypted Message: %s",message);
	return 0;
}

/*
OUTPUT
Generated Key: NEOALGO
Encrypted Message: GIGSPXOPXQOOOBTRSOLRUB
Decrypted Message: TESSERACTCODINGNEOALGO
*/
