/*
   This is a simple program in go language 
   to find out if a number ios happy or not.
   Happy number is a number which eventually 
   reaches 1 when replaced by the sum of the 
   square of each digit. 

   Example : 10 => 1^2 +0^2 = 1
   So, 10 is happy number!

*/

package main

import (

   "fmt"

)

/* This function counts the number of digits 
   in the the given number*/
func digits(a int) int {

   var counter int
   counter = 0

   for a !=0 {

     a = a/10
     counter += 1

   }

   return counter
}

/* This function returns the sum of squares
   of the individual digits for a given number*/
func numbersquares(number int) int {

  var sum int
  sum = 0

  var digit int
  digit = 0

  var r int
  r = 0

  /* calling the digits function to return number
     of digits for the number we gave it has*/
  digit = digits(number)

  for i:=0;i<digit;i++ {

     r = number%10
     sum += r*r
     number = number/10

  }

  return sum

}

/* This function tells us if a given number number 
   is happy or not*/
func happynumber(n int) int{

    var final_sum int
    final_sum = n

    // base case as these are happy numbers
    if(n==1 || n==7){

       return 1

    }

    // if the sum is in double digits
    for final_sum > 9 {

       final_sum = numbersquares(n)

       if(final_sum == 1){

            return 1

       }

       n = numbersquares(n)

    }

    if(final_sum == 7){

       return 1

    }else{

      return 0

    }

}

// driver function
func main() {

   var number int

   // Taking the input here
   fmt.Print("Enter the number you want to check for :")
   fmt.Scan(&number)

   var checker int
   checker = happynumber(number)

   // we print out the message here
   if(checker == 1){

      fmt.Print("The number is Happy Number!")

   }else{

      fmt.Print("The number is not a Happy Number!")

   }

}

/*
   Sample I/O :

   a) Is a happy number :

   Enter the number you want to check for :10
   The number is Happy Number! 

   b) Is not a happy number :

   Enter the number you want to check for :5
   The number is not a Happy Number!  

*/

