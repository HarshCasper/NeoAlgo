/* Monoalphabetic substitution cipher basically replaces each letter of a plaintext by another letter or symbol, depending only on the letter.
   The same plaintext letter is always replaced by the same ciphertext letter and the same letter can be replaced by letter itself.
   Example if a is there we replace it with B to Z and so on for the others.*/

#include<stdio.h>
#include<string.h>

void monoalphebaticcipher(char input[100],int size){
     
     //this where we store output 
     char output[size-1]; 
     //this is the list which we use to cipher 
     char cipherer[26] = {'Z','Y','X','W','V','U','T','S','R','Q','P','O','N','M','L','K','J','I','H','G','F','E','D','C','B','A'};     
     //the list we use to check which alphebatic we recieved in plain text
     char list[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o','p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};  
     //we use this char to compare the space charecter
     char space = ' ';
     //this is where we iterate and check what alphabetic is in input and then replace ii with its corresponding cipher
     for(int i=0;i<size-1;i++){     
         for(int j=0;j<26;j++){
             if(input[i]==list[j])
                output[i] = cipherer[j];
             else if( input[i] == space)
                output[i] = space;    
         } 
     } 
  
     //printing out the cipher text
     printf("The Cipher text :");
     for(int j=0;j<size-1;j++)
         printf("%c",output[j]);  
}

int main(void){

     //we store input here
     char input[100];
     printf("Give the plain text here in small letters :");
     //we take input here
     fgets(input,100,stdin);
     int size = strlen(input);
     monoalphebaticcipher(input,size);
     return 0;
}
/*
  Sample I/O :
  Give the plain text here in small letters :hello world
  The Cipher text :SVOOL DLIOW
*/
