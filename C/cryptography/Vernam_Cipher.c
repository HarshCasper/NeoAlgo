/*In Vernam cipher(also known as the One-Time Pad), the length of the plaintext, ciphertext, and key is the same.
  Below is an implementation of Vernam cipher in the C language.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LENGTH_MAX 100 //This defines the maximum length of the string in which we want to perform encrypt and decrypt operations.

char *decrypt(char *ciphertext, char *key) { // This is the encrypt function which takes plaintext and key as input

	static char decrypted[LENGTH_MAX];

	for(int i = 0; i < strlen(key); i++) {

		int ct = ciphertext[i] - 0;
		ct -= 65;

		int k = key[i] - 0;
		k -= 65;

		int pt = ct - k;
		pt = pt % 26;

		pt += 65;

		char plaintext = pt;

		decrypted[i] = plaintext;
	}

	return decrypted;		//Return the encrypted message	
}

char* encrypt(char *plaintext, char *key) { // This is the decrypt function which takes ciphertext and key as input

	static char encrypted[LENGTH_MAX];

	for(int i = 0; i < strlen(key); i++) {
	
		int pt = plaintext[i] - 0;
		pt -= 65;

		int k = key[i] - 0;
		k -= 65;

		int cipher = pt + k;
		cipher = cipher %  26;

		cipher += 65;

		char enc = cipher;

		encrypted[i] = enc;
	}

	return encrypted;               //Return the decrypted message
}

int main() {

	while(1) {

	printf("\nVERNAM CIPHER\n");

	printf("\n1. Encrypt a plaintext\n");

	printf("2. Decrypt a ciphertext\n");

	printf("3. Exit\n\n");
	
	printf("Enter your choice - ");

	int choice;

	scanf("%d", &choice);

	if(choice == 3) 
		exit(0);

	else if(choice == 1) {
		
		char message[LENGTH_MAX];
		
		printf("Enter the plaintext you want to encrypt         - ");

		scanf("%s", message);

		int len_plaintext = strlen(message);

		for (int i = 0; message[i] != '\0'; i++) { // Converts all characters to upper case
			
			if(message[i] >= 'a' && message[i] <= 'z') {
      			
				message[i] -= 32;
   			}
		}

		char key[LENGTH_MAX];

		printf("Enter the key of the same size as the plaintext - ");

		scanf("%s", key);

		int len_key = strlen(key);

		while(len_key != len_plaintext) { // Checks if the length of the key is equal to that of plaintext or not
						  // If not then prompts user for entering another key		
			printf("\nPlease enter a key whose length is same as that of the plaintext.\n");
			printf("Key - ");
			scanf("%s", key);
			len_key = strlen(key);
		}

		for(int i = 0; key[i] != '\0'; i++) {

			if(key[i] >= 'a' && key[i] <= 'z') {
				key[i] -= 32;
			}
		}

		printf("\nThe encrypted text is %s\n", encrypt(&message[0], &key[0]));
	
	}

	else if(choice == 2) {
		
		char ciphertext[LENGTH_MAX];

		printf("Enter the ciphertext you want to decrypt         - ");

		scanf("%s", ciphertext);

		int len_ciphertext = strlen(ciphertext);

		for (int i = 0; ciphertext[i] != '\0'; i++) {

   			if(ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
	
				ciphertext[i] -= 32;
   			}
		}

		char key[LENGTH_MAX];

		printf("Enter the key of the same size as the ciphertext - ");

		scanf("%s", key);

		int len_key = strlen(key);

		while(len_key != len_ciphertext) {

			printf("\nPlease enter a key whose length is same as that of the ciphertext.\n");
			printf("Key - ");
			scanf("%s", key);
			len_key = strlen(key);
		}

		for(int i = 0; key[i] != '\0'; i++) {

			if(key[i] >= 'a' && key[i] <= 'z') {
			
				key[i] -= 32;
			}
		}

		printf("\nThe decrypted text is %s\n", decrypt(&ciphertext[0], &key[0]));
	
	}

	else {
		printf("\nPlease enter a valid choice.\n");
	}

	}

	return 0;
}
