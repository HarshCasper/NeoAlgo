#include<bits/stdc++.h>
using namespace std;

/* Encrypts the plain text message into a cipher text 
by simply replacing each letter of a given text by 
some places down the alphabet. */
string encode(string plain, int shift) {
	
	string encrypt = "";
	int length = plain.length();
	for(int i = 0;i < length; ++i) {
		if(plain[i] <= 91) {
			//uppercase letter
			encrypt += char((plain[i] - 65 + shift)%26 + 65);
		} else if(plain[i] > 97) {
			//lowercase letter
			encrypt += char((plain[i] - 97 + shift)%26 + 97);
		}
	}

	return encrypt;
}

int main() {
	
	string plain,encrypt;
	int shift;
	cout<<"Enter the plain text: ";
	cin>>plain;
	
	cout<<"Enter the integer key to shift: ";
	cin>>shift;
	
	encrypt = encode(plain,shift);
	cout<<"Cipher Text: "<<encrypt<<endl;
	
}

/*
Example:
Text : TESSERACTCODING
Shift: 4
Cipher: XIWWIVEGXGSHMRK

Text : NEOALGO
Shift: 2
Cipher: PGQCNIQ

Time Complexity: O(n)
Space Complexity: O(n)
*/