/*RAIL FENCE TRANSPOSITION TECHNIQUE
  It is a type of transposition cipher technique which encrypts the plain 
  text message into a cipher text by rearranging the characters of the 
  plain text. The alternate characters are picked first, starting from the 
  first character. */

#include<bits/stdc++.h>
using namespace std;

//we use this function to encrypt the plaintext
void encrypt(string s,int key) {
    
    int n = s.length();
    char array[key][n]; 
    // To diffrentiate between filled slots and empty slots
    for(int i=0;i<key;i++){
        for (int j=0;j<n;j++){
            array[i][j] = '_';
        }
    }   
    
    bool flag = false;
    int a=0;
    int b=0;
  
    /*we check the direction of flow and reverse the direction
      if we filled the top or bottom rail*/
    for(int i=0;i<n;i++){
    
        if (a==0 || a==key-1){
            flag = !flag;
        }
        array[a][b++] = s[i];
        if(flag == true)
           a++;
        else
           a--;
    }   
  
    string cipher;
    //computing the cipher string here
    for (int i=0;i<key;i++){
        for (int j=0;j<n;j++){
            if (array[i][j]!='_'){
                cipher.push_back(array[i][j]);
            }
        }
    }   
    cout<<"Encrypted plaintext is              : "<<cipher<<endl;
}

/*
  Sample I/O :

  Enter a message you want to encrypt : This is Rail Fence Cipher
  Enter a key to encrypt the message  : 4
  Encrypted plaintext is              : Ts  rhi lFeCei Riecihsanp

  Time Complexity: O(nm)
  Space Complexity: O(mn)
*/
