/*
   This is a simple program in go language to check if a given
   number is armstrong number or not. An armstrong number is
   a number that is equal to the sum of cubes of its individual digits.
   Example : 153 = 1^3+5^3+3^3 = 153!
*/

package main

import (

  "fmt"

)

// global variable 
var number int

// This fuction checks if the given number is armstrong or not
func check(sum int) {

    if(number == sum){

       fmt.Print("This is an Armstrong number ")

    }else{

        fmt.Print("This is not Armstrong number")
    }

}

// This function calculates the sum of cubes of digits 
func armstrongnumber() {

   var sum int
   var n int
   n = number
   sum = 0
   var r int
   r = 0

   for n != 0 {

      r = n%10
      sum += (r*r*r)
      n = n/10

   }

   // calling the check function
   check(sum)

}

// driver function
func main() {

   fmt.Print("Enter the number you want to check for :")
   // Taking the number as input we need to check
   fmt.Scan(&number)

   // calling the armstrong number
   armstrongnumber()
}

/*
   Simple I/O :

   a) Is an armstrong number :

   Enter the number you want to check for :153
   This is an Armstrong number

   b) Is not an armstrong number :

   Enter the number you want to check for :76
   This is not Armstrong number   

*/

