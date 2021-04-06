/* The rail fence cipher (also called a zigzag cipher) 
   is a form of transposition cipher. It derives its 
   name from the way in which it is encoded. Given a
   plain-text message and a numeric key, it cipher the
   given text using Rail Fence algorithm(here key == 2). 
*/

package main

import (

  "fmt"
  "unicode"
  "bufio"
  "os"
  "strings"

)

// Global variables
var plaintext string
var ciphertext string

// In this array we store the elements in step wise 
var array[2][100] string
var output string

/* This function formats the given ciphertext according to
   the orginal plaintext recieved from the user as input.
   In the monoalphabeticcipher function below, we converet
   the given plaintext into lowercase for our cinvinence of 
   checking. So, the ciphertext we get is also in all 
   lowercase. Here, we format the ciphertext so that wherever
   there is capital letter in the plaintext, same follows 
   in the ciphertext.*/
func format(temp string) {

    /* Checking if the given letter in plaintext is capital 
       or not and changint it to capttal if it was*/
    for i:=0; i < len(temp); i++ {

       if (unicode.IsUpper (rune(temp[i]) ) ) {

           output += strings.ToUpper(string(ciphertext[i]))

       }else {

          output += string(ciphertext[i])

       }

    }

}

/* In this function we store the given plaintext in form of
   step in the 2D array then we concatenate the letters in 
   the first row and then the second row*/
func railfencecipher() {


     // storing them step wise
     for i:=0;i<len(plaintext);i++ {

        for j:=0;j<2;j++ {

             array[j][i] = string(plaintext[i])

        }

     }

     k:=0
     // concatenating the 2 rows
     for k<len(plaintext) {

          for a:=0;a<2;a++ {

               b := a
               for b<len(plaintext) {

                    ciphertext += string(array[a][b])
                    k += 1
                    b += 2

               }

          }


     }


}

// driver function
func main() {

     // Taking the plaintext as input from user
     fmt.Print("Enter the plaintext : ")
     scanner := bufio.NewScanner(os.Stdin)
     scanner.Scan()

     plaintext = scanner.Text()
     temp := plaintext

     /* calling the railfence cipher function
        to encrypt the input string leaving the
        space in to small letters*/
     railfencecipher()

     /* calling the format function to format the 
        calculated cipher text in according to the 
        plaintext format */
     format(temp)

     // Printing the cipher text out
     fmt.Print("The cipher text is :",output)
}

/*
     Sample I/O :
 
     a) All small letters :

     Enter the plaintext : hello world
     The cipher text is :hlowrdel ol    

     b) All Capital letters :

     Enter the plaintext : HELLO WORLD
     The cipher text is :HLOWRDEL OL      

     c) Mix of small and capital letters :

     Enter the plaintext : Hello World
     The cipher text is :HloWrdEl ol

*/

