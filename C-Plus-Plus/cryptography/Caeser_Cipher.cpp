#include<bits/stdc++.h>
using namespace std;

/* Encrypts the plain text message into a cipher 
text by simply replacing each letter of a given 
text by a letter 'key' places down the alphabet. */
string encode(string plain, int key) {
	
	string encrypt = "";
	int length = plain.length();
	for(int i = 0;i < length; ++i) {
		if(plain[i] <= 91) {
			//uppercase letter
			encrypt += char((plain[i] - 65 + key)%26 + 65);
		} else if(plain[i] >= 97) {
			//lowercase letter
			encrypt += char((plain[i] - 97 + key)%26 + 97);
		}
	}
	return encrypt;
}

/* Dencrypts the cipher text message into a plain
text by simply replacing each letter of a given
text by a letter 'key' places down the alphabet. */
string decode(string cipher, int key) {
	
	string decrypt = "";
	int length = cipher.length();
	for(int i = 0;i < length; ++i) {
		if(cipher[i] <= 91) {
			//uppercase letter
			decrypt += char((cipher[i] - 65 - key + 26)%26 + 65);
		} else if(cipher[i] >= 97) {
			//lowercase letter
			decrypt += char((cipher[i] - 97 - key + 26)%26 + 97);
		}
	}
	return decrypt;
}
int main() {
	
	int choice;
	cout << "Choose 1 for ENCRYPT and 2 for DECRYPT: ";
	cin >> choice;
	
	string text;
	int shift;
   	if(int(choice) == 1) {
        	cout << "Enter message to encrypt: ";
        	cin >> text;
        	cout << "Enter key value: ";
        	cin >> shift;
        	string encrypt = encode(text, shift);
        	cout << "\nEncrypted message: " + encrypt << endl;
	}
    	else if(int(choice) == 2) {
        	cout << "Enter message to decrypt: ";
        	cin >> text;
        	cout << "Enter key value: ";
        	cin >> shift;
        	string decrypt = decode(text, shift);
        	cout << "\nDecrypted message: " + decrypt << endl;
	}
    	else {
        	cout << "\nWrong Choice\n";
	}
}

/*
 
Sample I/O:

1)
Enter message to encrypt: NEOALGO
Enter key value: 12

Encrypted message: ZQAMXSA

2)
Choose 1 for ENCRYPT and 2 for DECRYPT: 2
Enter message to decrypt: ZQAMXSA
Enter key value: 12

Decrypted message: NEOALGO

Time Complexity: O(n)
Space Complexity: O(n)
*/
