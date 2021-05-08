/* This is a simple program in go language to check if a given number is neon number
   or not. A neon number is a number where the sum of digits of the square of the
   number should be equal to the initial number.
*/

package main

import (

  "fmt"

)

// variables declared globally
var n int
var r int
var sum int
var square int

// This function calculates the sum of digits of a number
func Sum(square int) {

   for square != 0{

      r = square%10
      sum += r
      square = square/10

   }

}

// This function checks if a number is a neon number or not
func neon() {

   //calling sum function to calculate the sum
   Sum(square)

   if (sum == n){
      fmt.Print("The given number is a neon number !")

   }else{

      fmt.Print("The given number is not a neon number !")
   }

}

//driver function
func main() {

  fmt.Print("Enter the number here :")
  fmt.Scanln(&n)

  square = n*n

  //calling the neon function
  neon()

}

/*
   Sample I/O :

   a) Is a neon number :

   Enter the number here :9
   The given number is a neon number ! 

   b) Is not a neon number :

   Enter the number here :12
   The given number is not a neon number !  
*/

