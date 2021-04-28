/*The Affine Cipher is a type of monoalphabetic substitution cipher.
Here each letter in a message is first converted to a number and then
encrypted using a simple mathematical function. Then the numbers are
converted back to ASCII.*/

#include <bits/stdc++.h>
using namespace std;

// Key values declared as global variables
int a;
int b;
int m = 26;

// This is the encryption function
string encryption(string message) {

	string cipher;

	/* Encrypted Message(x) = ( a * x + b ) mod m
	 modulus m: size of the alphabet, here 26 a and
         b: key of the cipher. a and m should be coprime.*/
	
	for (int i = 0; i < message.size(); ++i) {

		// Spaces should not be encrypted
		if (message[i] != ' ') {
			// to make in range of ASCII "A" is added
			cipher += (char)((a * (message[i] - 'A') + b) % 26 + 'A');
		}
		else {
			cipher += message[i];
		}
	}

	// Return the ciphertext
	return cipher;
}

// This is the decryption function
string decryption(string cipher) {

	string message;
	int a_inv = 0;

	for (int i = 0; i < 26; ++i) {
		if ((a * i) % 26 == 1) {
			a_inv = i;
			break;
		}
	}

	/* Decrypted Message(x) = a_inv ( x - b ) mod m
	a_inv : modular multiplicative inverse of a modulo m
	1 = (a * a_inv) mod m .*/

	for (int i = 0; i < cipher.size(); ++i) {
		// Spaces should not be encrpyted
		if (cipher[i] != ' ') {
			// to make it in range of ASCII "A" is added
			message += (char)(a_inv * (cipher[i] + 'A' - b) % 26 + 'A');
		}
		else {
			message += cipher[i];
		}
	}
	
	// Return the underlying plaintext
	return message;
}

int main() {

	int choice;

	cout << "----------Affine Cipher----------\n\n";

	cout << "1. Encryption" << endl;
	cout << "2. Decryption" << endl;
	cout << "3. Exit" << endl;

	cout << "\nEnter your choice: ";
	cin >> choice;

	// Encryption
	if(choice == 1) {
		cout << "\nEnter the key 'a': ";
		cin >> a;
		cout << "Enter the key 'b': ";
		cin >> b;
		string message;
		cout << "Enter a message: ";
		cin >> message;

		transform(message.begin(), message.end(), message.begin(), ::toupper);
		cout << "\nEncrypted message is: " << encryption(message) << endl;

	}
	// Decryption
	else if(choice == 2) {
		cout << "\nEnter the key 'a': ";
		cin >> a;
		cout << "Enter the key 'b': ";
		cin >> b;
		string ciphertext;
		cout << "\nEnter a ciphertext: ";
		cin >> ciphertext;

		transform(ciphertext.begin(), ciphertext.end(), ciphertext.begin(), ::toupper);
		cout << "\nDecrypted message is: " << decryption(ciphertext) << endl;
	}
	else if(choice == 3) {
		cout << "\nExiting program." << endl;
		exit(0);
	}
	else {
		cout << "\nInvalid choice." << endl;
	}
       	return 0;
}

/*
Sample I/O:

1)
----------Affine Cipher----------

1. Encryption
2. Decryption
3. Exit

Enter your choice: 1

Enter the key 'a': 17
Enter the key 'b': 21
Enter a message: NEOALGO

Encrypted message is: ILZVATZ

2)
----------Affine Cipher----------

1. Encryption
2. Decryption
3. Exit

Enter your choice: 2

Enter the key 'a': 17
Enter the key 'b': 21

Enter a ciphertext: ILZVATZ

Decrypted message is: NEOALGO

Time complexity - O(n)

Space complexity - O(1)

*/

