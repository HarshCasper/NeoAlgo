/* Vernam Cipher

Vernam Cipher is a symmetric key cryptographic algorithm and is one of the transposition technique that converts plain text into ciphertext.
In this algorithm the size of the key and plain text must be same. */


#include<bits/stdc++.h>
using namespace std;

string encrypt(string plain,string key){
	string enc="";
	int n=key.length();
    for(int i=0;i<n;i++){
		int y = plain[i]+key[i]-130;
		if(y>=26) {
      y = y-26;
    }
		enc+=char(y+65);
	}
	return enc;
}

string decrypt(string enc,string key){
	string dec="";
	int n=enc.length();
	for(int i=0;i<n;i++){
		if(enc[i]>=key[i]){
			dec+=char(enc[i]-key[i]+65);
		}
		else{
			dec+=char(enc[i]-key[i]+91);  
		}
	}
	return dec;
	
}
int main(){
	string plain,encrypted,decrypted,key;
	cout<<"USE UPPERCASE LETTERS"<<endl;
	cout<<"Enter the Key: ";
	cin>>key;
  transform(key.begin(), key.end(), key.begin(), ::toupper);
	
	cout<<"\nEnter the plain text of same size as that of key: ";
	cin>>plain;
  transform(plain.begin(), plain.end(), plain.begin(), ::toupper);
	
	int n=key.length();
  if(plain.length()<key.length()){
    cout<<"Invalid";
    return 0;
  }
	
	encrypted = encrypt(plain,key);
	cout<<"\nCipher text: "<<encrypted<<endl;
	
	decrypted = decrypt(encrypted,key);
	cout<<"Decrypted text: "<<decrypted<<endl;	
}


/* Output
USE UPPERCASE LETTERS
Enter the Key: TESSERACTCODING

Enter the plain text of same size as that of key: OPENSOURCESTART

Cipher text: HTWFWFUTVGGWIEZ
Decrypted text: OPENSOURCESTART */
