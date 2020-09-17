/*Vigenere Cipher Algorithm is a famous cryptographic algorithm.
Vigenère cipher is a method of encrypting alphabetic text by using a series of interwoven Caesar ciphers*/

#include <stdio.h>
#include <string.h>

char key[]="NEOALGO";
int x=strlen(key);

int main() {
  char message[] = "TESSERACTCODINGNEOALGO";
  int n=strlen(message);
  //use only uppercase characters (you can modify the code for lowercase characters)
  char new_message[n];
  for (int i = 0; i < n; ++i) {
    int t=(message[i] + key[i%x])%26;
    new_message[i]=('A'+t);
  }
  printf("Encrypted Message: %s\n",new_message);
  
  char original_message[n];
  for (int i = 0; i < n; ++i) {
    int t=(new_message[i] - key[i%x] +26)%26;
    original_message[i]=('A'+t);
  }
  printf("Decrypted Message: %s",original_message);
  return 0;
}

/*
OUTPUT:
Encrypted Message: GIGSPXOPXQOOOBTRSOLRUB
Decrypted Message: TESSERACTCODINGNEOALGO
*/
