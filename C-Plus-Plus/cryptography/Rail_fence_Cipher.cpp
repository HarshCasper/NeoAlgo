//Rail Fence Cipher (Transposition Technique)

/*
It is a type of transposition cipher technique which encrypts the plain 
text message into a cipher text by rearranging the characters of the 
plain text. The alternate characters are picked first, starting from the 
first character.

Example:
Plain Text : TESSERACTCODING
Method: T	S	E   A   T   O   I   G  
		 E	 S	  R   C   C   D   N
Cipher Text: TSEATOIGESRCCDN

Plain Text : NEOALGO
Cipher Text: NOLOEAG

Time Complexity: O(n)
Space Complexity: O(1)

*/

#include<bits/stdc++.h>
using namespace std;

string encrypt(string s) {
	string s1="";
	string s2="";
	
	for(int i = 0; i < s.length(); i+=2) {
		s1+=s[i];
		if(i < s.length());
		s2+=s[i+1];
	}
	return s1+s2;
}

int main() {

	cout<<"Enter plain text"<<endl;
	string s;
	cin>>s;
	string enc = encrypt(s);
	cout<<"Cipher text: "<<enc<<endl;

}