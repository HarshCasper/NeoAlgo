/*
   The Playfair cipher( Playfair square ) encrypts pairs of letters (digraphs),
   instead of single letters as in the simple substitution cipher. The Playfair
   is thus significantly harder to break since the frequency analysis used for 
   simple substitution ciphers does not work with it.
*/

package main

import (

  "fmt"
  "bufio"
  "os"

)

// Global variables
var plaintext string
var key string
var keyMatrix[5][5] string
var output string
var list[4] int
var alph string = "abcdefghijklmnopqrstuvwxyz"

//This function will form the 5x5 key Matrix 
func keyTable() {

     i:=0
     j:=0
     c:=0
     var index[26] int;

     //initializing the array to 0 as it stores garbage values
     for z:=0;z<26;z++ {
         index[z] = 0;
     }

     var hash[100] int;
     //marking the alphabets in key
     for i=0;i<len(key);i++ {
         if(key[i] != 'j'){
            for j=0;j<26;j++ {
                if(key[i] == alph[j]){
                   index[j] = 2;
                   hash[c] = j;
                   c++;
                }
            }
         }
     }

     //marking alphabetic j
     index[9] = 1;
     i = 0;
     j = 0;

     //adding the marked alphabets  
     for k:=0;k<len(key);k++ {
         if(index[hash[k]] == 2) {
            index[hash[k]] -= 1;
            keyMatrix[i][j] = string(key[k]);
            j++;

            if(j==5){
              i++;
              j=0;
            }
         }
     }

     //adding the remaining alphabets
     for  k:=0;k<26;k++ {
         if(index[k] == 0){
            keyMatrix[i][j] = string(alph[k]);
            j++;

            if(j==5){
               i++;
               j=0;
            }
         }
     }
}

/* This function searches for the characters of the digraph in key matrix
   generated and gives their position*/
func search(x,y string) {

     //replacing j with i   
     if(x == "j'") {
         x = "i";
     }else if(y =="j") {
         y = "i";
     }

     //returning the positions of characters through list    
     for i:=0;i<5;i++ {
         for j:=0;j<5;j++ {
             if(keyMatrix[i][j] == x) {
                list[0] = i;
                list[1] = j;
             }else if(keyMatrix[i][j] == y) {
                list[2] = i;
                list[3] = j;
             }
         }
      }
}

// This function ciphers the plane text 
func cipher() {

     i := 0;
     //cipher the plain text with the key matrix we built
     for i<len(plaintext) {

         search(string(plaintext[i]),string(plaintext[i+1]))

         if(list[0] == list[2]) {
            output += string(keyMatrix[list[0]][(list[1]+1)%5]);
            output += string(keyMatrix[list[0]][(list[3]+1)%5]);
         } else if(list[1] == list[3]){
            output += string(keyMatrix[(list[0]+1)%5][list[1]]);
            output += string(keyMatrix[(list[2]+1)%5][list[1]]);
         }else{
            output += string(keyMatrix[list[0]][list[3]]);
            output += string(keyMatrix[list[2]][list[1]]);
         }
         i+=2;
     }
}

// This function will encript the plaintext to cipher in playfail cipher
func playfaircipher() {

    if(len(plaintext)%2 != 0 ){
         plaintext += "z";
    }

    //generating key table
    keyTable();

    //cipher the plane text
    cipher();

}

//driver function
func main() {

     // Taking the plaintext as input from user
     fmt.Print("Enter the plaintext : ")
     scanner := bufio.NewScanner(os.Stdin)
     scanner.Scan()

     plaintext = scanner.Text()

     // Taking the keyword as input from the user
     fmt.Print("Enter the keyword : ")
     scanner.Scan()
     key = scanner.Text()

     playfaircipher()

     // printing the cipher text
     fmt.Print("The cipher text is : ",output)

}

/*
     Sample I/O :

     Enter the plaintext : hello 
     Enter the keyword : world
     The cipher text is : kbekdv 

*/
