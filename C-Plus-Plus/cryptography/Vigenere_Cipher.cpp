/*Vigenere Cipher Algorithm is a famous cryptographic algorithm.
Vigenère cipher is a method of encrypting alphabetic text by using a series of interwoven Caesar ciphers*/

#include <bits/stdc++.h>
using namespace std;

string key="NEOALGO";
int x=key.size();

string encryption(string message) {
  string cipher;
  for (int i = 0; i < message.size(); ++i) {
    int t=(message[i] + key[i%x])%26;
    cipher+=('A'+t);
  }
  return cipher;
}

string decryption(string cipher) {
  string message;
  for (int i = 0; i < cipher.size(); ++i) {
    int t=(cipher[i] - key[i%x] +26)%26;
    message+=('A'+t);
  }
  return message;
}

int main() {
  string message = "TESSERACTCODINGNEOALGO";
  //use only uppercase characters (you can modify the code for lowercase characters)
  string new_message = encryption(message);
  cout << "Encrypted Message: " << new_message << "\n";
  string original_message = decryption(new_message);
  cout << "Decrypted Message: " << original_message;
  return 0;
}

/*
OUTPUT:
Encrypted Message: GIGSPXOPXQOOOBTRSOLRUB
Decrypted Message: TESSERACTCODINGNEOALGO
*/
