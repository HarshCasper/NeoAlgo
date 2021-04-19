/* This is a simple program in go language to find if a give number
   is a automorphic number or not. An automorphic number is an
   integer whose square ends with the given integer, as (25)2 = 625,
   and (76)2 = 5776.
*/

package main

import (

  "fmt"

)

// This is a global variable
var n int

// This function tells us if the number is automorphic number or not 
func automorphicnumber() {

   var number int
   var b int
   b = n
   number = n*n
   i := 1

   //to construct the last digits
   for b != 0  {

     i = i*10
     b = b/10
   }

   //checking if the last digits form the orginal number
   if((number%i) == n) {

      fmt.Print("The given number is Automorphic number!")

   }else{

     fmt.Print("The given number is not Automorphic number!")
   }

}

// driver function
func main() {

   fmt.Print("Enter the number you want to check :")
   fmt.Scan(&n)

   // calling automorphic function 
   automorphicnumber()
}

/*
   Sample I/O :

   a) Is Automorphic Number :

   Enter the number you want to check :76
   The given number is Automorphic number!

   b) Is not Automorphic Number :

   Enter the number you want to check :7
   The given number is not Automorphic number! 
*/

