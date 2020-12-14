//Modified Caeser cipher

/*
It is a type of susbtitution cipher which encrypts the plain text 
message into a cipher text by simply replacing each letter
of a given text by some places down the alphabet.


Example:
Text : TESSERACTCODING
Shift: 4
Cipher: XIWWIVEGXGSHMRK

Text : NEOALGO
Shift: 2
Cipher: PGQCNIQ

Time Complexity: O(n)
Space Complexity: O(n)

Optimised method:
Change the plain text itself instead of initializing a new
string varibale if plain text is mutable.
Space complexity: O(1)
Time Complexity: O(n)

*/


#include<bits/stdc++.h>
using namespace std;

int main(){
	
	string plain,encrypt;
    cout<<"Enter the plain text: ";
	cin>>plain;
	
	int shift;
    cout<<"Enter the integer key to shift: ";
	cin>>shift;
	
	encrypt="";
	int length = plain.length();
	for(int i=0;i<length;i++){
		if(plain[i]<=91){
		//uppercase letter
			encrypt+=char((plain[i]-65+shift)%26+65);
		}
		else if(plain[i]>97) 
		//lowercase letter
			encrypt+=char((plain[i]-97+shift)%26+97);
	}
	
	cout<<encrypt<<endl;
}
