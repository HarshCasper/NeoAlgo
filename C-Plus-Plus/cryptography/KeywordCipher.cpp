/*Below is an implementation of keyword cipher in C++. It is a form of
monoalphabetic substitution. A encryption is formed of alphabets from
[a-z] such that the first part of encrption contains unique letters of
the keyword and the rest are the remaining alphabets from [a-z]. That is,
until the keyword is used up, whereupon the rest of the ciphertext letters
are used in alphabetical order, excluding those already used in the key.*/

#include <bits/stdc++.h>
using namespace std;

// This function generates the pad using the keyword
string generate_pad(string key) {

	int i = 0;
	string pad = "00000000000000000000000000";
	int count = 0;
	
	// Ignoring the spaces in the given keyword
	while(i < key.length()) {	
		if(key.at(i) == ' ') {
			i = i + 1;
			continue;
		}

		// Checking keyword alphabet-wise
		int missing = 0;
		for(int j = 0; j < key.length(); j++) {
			if(key.at(i) != pad.at(j)) {
				missing += 1;
			}
		}

		// Adding the unique words of key to pad
		if(missing == key.length()) {
			pad.at(count) = key.at(i);
			count += 1;
		}
		i = i + 1;
	}
	// Till here we get the first half of the pad

	string alphabet = "abcdefghijklmnopqrstuvwxyz";

	i = 0;
	// This while loop forms the remaining pad
	while(i < 26) {
		int not_present = 0;
		for(int j = 0; j < 26; j++) {
			if(alphabet.at(i) != pad.at(j)) {
				not_present += 1;
			}
		}
		
		/* Whatever alphabets from [a-z] are not present
		in the pad till now, add them to the pad.*/
		if(not_present == 26) {
			pad.at(count) = alphabet.at(i);
			count++;
		}
		i++;
	}
	// Return the length 26 pad
	return pad;
}

// This is the encryption function
string encrypt(string plaintext, string key) {
	
	// Generate the pad using the above function
	string pad = generate_pad(key);
	string alphabet = "abcdefghijklmnopqrstuvwxyz";

	// Replace all sapces in plaintext with underscores
	for(int i = 0; i < plaintext.length(); i++) {
		if(plaintext.at(i) == ' ') {
			plaintext.at(i) = '_';
		}
	}

	// Declare and initialize the encrypted string
	string encrypted;
	for(int i = 0; i < plaintext.length(); i++) {
		encrypted += "0";
	}
	
	for(int i = 0; i < plaintext.length(); i++) {
		
		/*If the message has space, add space to the
		encrypted message at the same index.*/
		if(plaintext.at(i) == '_') {
			encrypted.at(i) = ' ';
		}
		
		/*else replace it with the corresponding
		position in the pad*/
		else {
			int index = 0;
			for(int j = 0; j < alphabet.length(); j++) {
				if(plaintext.at(i) == alphabet.at(j)) {
					index = j;
				}
			}
			encrypted.at(i) = pad.at(index);
		}
	}
	// Return the encrypted message
	return encrypted;
}

int main() {

	// Take plaintext as input from the user
	string plaintext;
	cout << "Enter a plaintext to encrypt: ";
	getline(cin, plaintext);
	// Converting the plaintext to all lowercase
	transform(plaintext.begin(), plaintext.end(), plaintext.begin(), ::tolower);

	// Taking keyword as input from the user
	string key;
	cout << "Enter a key to encrypt      : ";
	getline(cin, key);
	// Converting the keyword to all lowercase
	transform(key.begin(), key.end(), key.begin(), ::tolower);

	// Calling the encrypt function and printing the ciphertext
	cout << "The encrypted plaintext is  : " << encrypt(plaintext, key) << endl;
	return 0;
}

/* Sample I/O:
	Enter a plaintext to encrypt: this is a secret
	Enter a key to encrypt      : mercury
	The encrypted plaintext is  : qbdp dp m purouq
*/

