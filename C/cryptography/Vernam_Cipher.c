/*In Vernam cipher(also known as the One-Time Pad), the length of the plaintext, ciphertext, and key is the same.
  Below is an implementation of Vernam cipher in the C language.*/

/*Basically, here the ith letter of the cipher text is fomred by shifting the ith letter of the plaintext with 
 * the ith letter of key.
 * */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//This defines the maximum length of the string in which we want to perform encrypt and decrypt operations.
#define LENGTH_MAX 100 

// This is the decrypt function which takes ciphertext and key as input
char *decrypt(char *ciphertext, char *key) { 

	static char decrypted[LENGTH_MAX];

	for(int i = 0; i < strlen(key); i++) {

		//Convert the character to ASCII
		int ct = ciphertext[i] - 0;

		ct -= 65;
		//We number alphabets as A-0, B-1, ..... , Z-25. So, 
		//We shift the obtained ASCII value by 65.	

		//We perform similar steps for the key.
		int k = key[i] - 0;
		k -= 65;
		
		//The plaintext is obtained by shifting the ciphertext backwards by the key
		int pt = ct - k;
		
		//If the value goes below 0, we add 26 to it, as number of cycle doesn't matter
		//Since, at last we take mod by 26.	
		while(pt < 0) {
			pt += 26;
		}

		pt = pt % 26;
		
		//We add back 65 to convert it back to ASCII and then to char
		pt += 65;

		char plaintext = pt;

		decrypted[i] = plaintext;
	}
	//Return the decrypted message	
	return decrypted;	
}

// This is the encrypt function which takes plaintext and key as input
char* encrypt(char *plaintext, char *key) { 

	static char encrypted[LENGTH_MAX];

	for(int i = 0; i < strlen(key); i++) {
	
		//Convert the character to ASCII
		int pt = plaintext[i] - 0;

		//We number alphabets as A-0, B-1, ..... , Z-25. So, 
		//We shift the obtained ASCII value by 65.
		pt -= 65;

		//We perform similar steps for the key.
		int k = key[i] - 0;
		k -= 65;

		//The ciphertext is obtained by shifting the ciphertext backwards by the key
		int cipher = pt + k;
		cipher = cipher %  26;

		//We add back 65 to convert it back to ASCII and then to char
		cipher += 65;

		char enc = cipher;

		encrypted[i] = enc;
	}

	//Return the decrypted message
	return encrypted;               
}

int main() {
	
	//while true
	while(1) {

	//Ask user for input on what he wants to perform
	printf("\nVERNAM CIPHER\n");

	printf("\n1. Encrypt a plaintext\n");

	printf("2. Decrypt a ciphertext\n");

	printf("3. Exit\n\n");
	
	printf("Enter your choice - ");

	int choice;
	
	//Take choice of user
	scanf("%d", &choice);
	
	//If user has chosen to exit
	if(choice == 3) 
		exit(0);
	
	//If the user has chosen to encrypt
	else if(choice == 1) {
		
		char message[LENGTH_MAX];
		
		printf("Enter the plaintext you want to encrypt         - ");
		
		//Take the plaintext message as input from the user
		scanf("%s", message);

		int len_plaintext = strlen(message);

		// Converts all characters to upper case to maintain unity
		for (int i = 0; message[i] != '\0'; i++) { 
			
			if(message[i] >= 'a' && message[i] <= 'z') {
      			
				message[i] -= 32;
   			}
		}

		char key[LENGTH_MAX];

		printf("Enter the key of the same size as the plaintext - ");

		scanf("%s", key);

		int len_key = strlen(key);

		// Checks if the length of the key is equal to that of plaintext or not
		// If not then prompts user for entering another key
		while(len_key != len_plaintext) { 
						  		
			printf("\nPlease enter a key whose length is same as that of the plaintext.\n");
			printf("Key - ");
			scanf("%s", key);
			len_key = strlen(key);
		}

		// Converts all characters to upper case to maintain unity
		for(int i = 0; key[i] != '\0'; i++) {

			if(key[i] >= 'a' && key[i] <= 'z') {
				key[i] -= 32;
			}
		}
		
		//Print the encrypted text
		printf("\nThe encrypted text is %s\n", encrypt(&message[0], &key[0]));
	
	}
	
	//If the user has chosen to decrypt
	else if(choice == 2) {
		
		char ciphertext[LENGTH_MAX];

		printf("Enter the ciphertext you want to decrypt         - ");
		
		//Take ciphertext as input from user
		scanf("%s", ciphertext);

		int len_ciphertext = strlen(ciphertext);

		// Converts all characters to upper case to maintain unity
		for (int i = 0; ciphertext[i] != '\0'; i++) {

   			if(ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
	
				ciphertext[i] -= 32;
   			}
		}

		char key[LENGTH_MAX];

		printf("Enter the key of the same size as the ciphertext - ");

		scanf("%s", key);

		int len_key = strlen(key);

		// Checks if the length of the key is equal to that of ciphertext or not
		// If not then prompts user for entering another key
		while(len_key != len_ciphertext) {

			printf("\nPlease enter a key whose length is same as that of the ciphertext.\n");
			printf("Key - ");
			scanf("%s", key);
			len_key = strlen(key);
		}

		// Converts all characters to upper case to maintain unity
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

/*Test Case - 

VERNAM CIPHER

1. Encrypt a plaintext
2. Decrypt a ciphertext
3. Exit

Enter your choice - 1
Enter the plaintext you want to encrypt         - thisisatestcase
Enter the key of the same size as the plaintext - thisisthereqkey

The encrypted text is MOQKQKTAIJXSKWC

VERNAM CIPHER

1. Encrypt a plaintext
2. Decrypt a ciphertext
3. Exit

Enter your choice - 2
Enter the ciphertext you want to decrypt         - moqkqktaijxskwc
Enter the key of the same size as the ciphertext - thisisthereqkey

The decrypted text is THISISATESTCASE

VERNAM CIPHER

1. Encrypt a plaintext
2. Decrypt a ciphertext
3. Exit

Enter your choice - 4

Please enter a valid choice.

VERNAM CIPHER

1. Encrypt a plaintext
2. Decrypt a ciphertext
3. Exit

Enter your choice - 3
 *
 * */



