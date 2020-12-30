#include<bits/stdc++.h>
using namespace std;

/* Encrypts the plain text message into a cipher 
text by simply replacing each letter of a given 
text by a letter '3' places down the alphabet. */
string encode(string plain) {
	
	string encrypt = "";
	int length = plain.length();
	for(int i = 0;i < length; ++i) {
		if(plain[i] <= 91) {
			//uppercase letter
			encrypt += char((plain[i] - 65 + 3)%26 + 65);
		} else if(plain[i] > 97) {
			//lowercase letter
			encrypt += char((plain[i] - 97 + 3)%26 + 97);
		}
	}

	return encrypt;
}

int main() {
	
	string plain,encrypt;
	cout<<"Enter the plain text: ";
	cin>>plain;
	
	encrypt = encode(plain);
	cout<<"Cipher Text: "<<encrypt<<endl;

}

/*
Example:
Text : TESSERACTCODING
Shift: 3
Cipher: WHVVHUDFWFRGLQJ

Text : NEOALGO
Shift: 3
Cipher: QHRDOJR

Time Complexity: O(n)
Space Complexity: O(n)
*/