/*
   Monoalphabetic substitution cipher basically replaces
   each letter of a plaintext by another letter or symbol,
   depending only on the letter. The same plaintext letter
   is always replaced by the same ciphertext letter and 
   the same letter can be replaced by letter itself.
   
   Example if a is there we replace it with B to Z .....so on.

   Here in this particular case we use the cipherer as a => z
   b => y .... so on. The user can change depending upon his/her
   requirment

*/

package main

import (

  "fmt"
  "unicode"
  "bufio"
  "os"
  "strings"

)

//Global Variables
var plaintext string
var ciphertext string

/* We use this list of alphabets to check what letter we have
   in plaintext*/
var list string = "abcdefghijklmnopqrstuvwxyz"

/* We use this list of alphabets as the corresponding cipher  
   letters for corresponding input letters in plaintext */
var cipherer string = "zyxwvutsrqpomnlkjihgfedcba"

var output string

/*
 This function formats the given ciphertext according to
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

/* This is the function where we cipher the plaintext using 
   the cipherer into small letters */
func monoaplhabeticcipher() {

      // Converting the plaintext to small letters
      plaintext = strings.ToLower(plaintext)

      var temporary string
      /* Here we replace all the space charecter with underscore
         for out convinence*/
      for k:=0;k<len(plaintext);k++ {

          if(string(plaintext[k]) == " ") {

		temporary += string("_")

          }else {

		temporary += string(plaintext[k])

          }
      }

      plaintext = temporary

      /* If the inputted plaintext had space we give sapce in
         the cipher text also */
      for i:=0 ;i < len(plaintext); i++ {

          if(string(plaintext[i]) == "_") {

                ciphertext += " "

          }else {
                /* We replace the letter with corresponding letter 
                   from the cipherer */
                for j:=0 ; j<26 ; j++ {

                     if( string(plaintext[i]) == string(list[j]) ) {

                          ciphertext += string(cipherer[j])

                     }

                }

          }

      }

}

// driver function
func main () {

     // Taking the plaintext as input from user
     fmt.Print("Enter the plaintext : ")
     scanner := bufio.NewScanner(os.Stdin)
     scanner.Scan()

     plaintext = scanner.Text()

     // copy of plaintext
     temp := plaintext

     /* calling the monoaplhabetic cipher function
        to encrypt the input string leaving out 
        the space in to small letters*/
     monoaplhabeticcipher()

     /* calling the format function to format the 
        calculated cipher text in accorfing to the 
        plaintext format */
     format(temp)

     // Printing the cipher text out
     fmt.Print("The cipher text is : ",output)

}

/*

     Sample I/O :

     a) All small letters :

     Enter the plaintext : hello world
     The cipher text is : svool dliow 

     b) All Capital letters :

     Enter the plaintext : HELLO WORLD
     The cipher text is : SVOOL DLIOW

     c) Mix of small and capital letters :  
 
     Enter the plaintext : Hello World
     The cipher text is : Svool Dliow

*/

