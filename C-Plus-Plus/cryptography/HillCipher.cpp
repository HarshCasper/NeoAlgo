/* This code is an implementation of Hill Cipher. It
   is a polygraphic substitution cipher. It forms a 
   nxn matrix of key and nx1 matrix(s) of the plaintext
   and then multiplies the two matrices to obtains the
   matrix of ciphertext.*/

#include<bits/stdc++.h>
using namespace std;
#define SIZE 3

//This function prints the cipher text
void printciphertext(int cipherMatrix[SIZE][1]){
    
    string output;
    for(int i=0;i<SIZE;i++){
        output += cipherMatrix[i][0]+97;
    }

    cout<<"The cipher text is :"<<output;
}

//This function calculates the matrix multiplication
void cipher(int cipherMatrix[SIZE][1],int keyMatrix[SIZE][SIZE],int plaintextMatrix[SIZE][1]){

      //calculating the multiplication 
      for(int i=0;i<SIZE;i++){
          cipherMatrix[i][0] = 0;
          for(int j=0;j<SIZE;j++){
              cipherMatrix[i][0] += keyMatrix[i][j]*plaintextMatrix[j][0];
          }

          cipherMatrix[i][0] = cipherMatrix[i][0]%26;
      }     
}

//This function builds the key matrix
void buildkeyMatrix(int keyMatrix[SIZE][SIZE],string key){
 
    int counter =0;
    //storing the key in matrix
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            keyMatrix[i][j] = key[counter]%97;
            counter++; 
        }
    }
}

//This function builds the plaintext matrix
void buildplaintextMatrix(int plaintextMatrix[][1],string plaintext){

    //storing the plaintext in matrix form
    for(int i=0;i<SIZE;i++){
        plaintextMatrix[i][0] = (plaintext[i])%97;
    }
}

//This fuinction helps us in calling all the functions in sequential order
void hillcipher(string plaintext,string key){

    int plaintextMatrix[SIZE][1];
    buildplaintextMatrix(plaintextMatrix,plaintext);

    int keyMatrix[SIZE][SIZE];
    buildkeyMatrix(keyMatrix,key);

    int cipherMatrix[SIZE][1];
    cipher(cipherMatrix,keyMatrix,plaintextMatrix);

    printciphertext(cipherMatrix);
}

int main(){

    string plaintext;
    string key;

    cout<<"The plaintext size you need to enter is :"<<SIZE<<endl;

    cout<<"Enter the plaintext here same :";
    //Taking plaintext from here
    cin>>plaintext;
   
    cout<<"Enter the key here :";
    //Taking key from here
    cin>>key; 

    int size1 = plaintext.length();
    int size2 = key.length(); 

    //validating for the input given 
    if(size2 != size1*size1 || size1 != SIZE){
        cout<<"The key input is wrong!"<<endl;
        return 0;
    }
    else 
        hillcipher(plaintext,key);

    return 0;
}
/*
    Sample I/O :

    The plaintext size you need to enter is :3
    Enter the plaintext here same :ask
    Enter the key here :thisiskey
    The cipher text is :yma
*/
