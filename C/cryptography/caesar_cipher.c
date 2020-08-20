/* Caesar Cipher Algorithm

Caesar Cipher Algorithm is an old encryption methodology used for encryption of data. Also known as Caesar Shift or
Caesar’s Code, it is one of the most straightforward and prevalent encryption technique. This Caesar Cipher
encryption algorithm is a kind of substitution cipher wherein every character in the plain-text or the user
input is replaced by another character which is defined with a fixed number of positions away from the existing character.
It is a method in which every letter or character in the plain text is altered and shifted. Every text character replaced
 by a specific character depending upon the algorithm.

The Caesar Cipher Algorithm is one of the oldest and easiest algorithms for encryption and decryption algorithm
in C programming language.

*/

#include<stdio.h>
#include<stdlib.h>

char data[50], temp;
int key, count;

/* Cipher_Caesar Encryption */
void encryption()
{
	for (count = 0; data[count] != '\0'; count++) {
		temp = data[count];
		if (temp >= 'a' && temp <= 'z') {
			temp = temp + key;
			if (temp > 'z') {
				temp = temp - 'z' + 'a' - 1;
			}
			data[count] = temp;
		} else if (temp >= 'A' && temp <= 'Z') {
			temp = temp + key;
			if (temp > 'Z') {
				temp = temp - 'Z' + 'A' - 1;
			}
			data[count] = temp;
		}
	}
	printf("Encrypted Message:\t%s\n", data);
}

/* Cipher_Caesar Decryption */
void decryption()
{
	for (count = 0; data[count] != '\0'; count++) {
		temp = data[count];
		if (temp >= 'a' && temp <= 'z') {
			temp = temp - key;
			if (temp < 'a') {
				temp = temp + 'z' - 'a' + 1;
			}
			data[count] = temp;
		} else if (temp >= 'A' && temp <= 'Z') {
			temp = temp - key;
			if (temp < 'A') {
				temp = temp + 'Z' - 'A' + 1;
			}
			data[count] = temp;
		}
	}
	printf("Decrypted Message:\t%s\n", data);
}

int main()
{
	printf("Enter a String:\t");
	scanf("%[^\n]s", data);

	printf("Enter a Key:\t");
	scanf("%d", &key);

	encryption();
	decryption();

	printf("\n");
	return 0;
}


/* Sample Output:

Enter a String: HACKINCODES
Enter a Key:    4
Encrypted Message:      LEGOMRGSHIW
Decrypted Message:      HACKINCODES

*/
