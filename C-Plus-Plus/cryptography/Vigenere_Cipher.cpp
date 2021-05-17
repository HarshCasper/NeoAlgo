/*Vigenere Cipher Algorithm is a famous cryptographic algorithm.
Vigenère cipher is a method of encrypting alphabetic text by using a series of interwoven Caesar ciphers*/

#include <bits/stdc++.h>
using namespace std;

string encryption(string message, int x, string key) {
	string cipher;
	for (int i = 0; i < message.size(); ++i) {
		int t=(message[i] + key[i%x])%26;
		cipher+=('A'+t);
	}
	return cipher;
}

string decryption(string cipher, int x, string key) {
	string message;
	for (int i = 0; i < cipher.size(); ++i) {
		int t=(cipher[i] - key[i%x] +26)%26;
		message+=('A'+t);
	}
	return message;
}

int main() {

	//use only uppercase character
	int choice;
	cout << "Choose 1 if you want to ENCRYPT or 2 if you want to DECRYPT: ";
	cin >> choice;

	if(choice == 1) {
		string message;
		cout << "Enter a plaintext message: ";
		cin >> message;

		string key;
		cout << "Enter a keyword: ";
		cin >> key;

		cout << "\nEncrypted message: " << encryption(message, key.size(), key);
		cout << endl;
	}

	else if(choice == 2) {
		string ciphertext;
		cout << "Enter a ciphertext: ";
		cin >> ciphertext;

		string key;
		cout << "Enter a keyword: ";
		cin >> key;

		cout << "\nDecrypted message: " << decryption(ciphertext, key.size(), key);
		cout << endl;
	}

	else {
		cout << "\nInvalid choice." << endl;
	}
	return 0;
}

/* 
Sample I/O:

1)
Choose 1 if you want to ENCRYPT or 2 if you want to DECRYPT: 1
Enter a plaintext message: NEOALGO
Enter a keyword: MARS

Encrypted message:  ZEFSXGF

2)
Choose 1 if you want to ENCRYPT or 2 if you want to DECRYPT: 2
Enter a ciphertext: ZEFSXGF
Enter a keyword: MARS

Decrypted message: NEOALGO
*/
