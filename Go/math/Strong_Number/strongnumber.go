/* This is Program in go language to check whether a given number is
   Strong number or not. Strong number is a special number whose
   sum of factorial of digits is equal to the original number.
   Eg: 145 is strong number. Since, 1! + 4! + 5! = 145   
*/

package main

import (

  "fmt"

)

//global variable
var a int

//This function will return us the factorial of a given number
func factorial(n int)int {

  if(n == 0){
     return 1
  }else{
     return n*factorial(n-1)
  }

}

//This function tells us if the given number is a strong number or not
func strongnumber() {

  var number int
  number = a
  var sum int
  sum = 0
  var digits int
  /* we calculate the sum of the factorials of individual digits 
     of the number given*/
  for number!=0 {

    digits = number%10
    sum += factorial(digits)
    number /= 10
  }

  // checking if the sum is same as orginal number
  if (sum == a){

    fmt.Print("The given number is a strong number!")

  }else{

    fmt.Print("The given number is not a strong number!")
  }

}

//driver function
func main() {

   fmt.Print("Enter the number we need to check :")
   // Taking the input for the number we need to check
   fmt.Scan(&a)

   //calling the strongnumber function
   strongnumber()
}

/*
   Simple I/O :

   a) Is a strong number :

   Enter the number we need to check :40585
   The given number is a strong number!

   b) Is not a strong number :

   Enter the number we need to check :45
   The given number is not a strong number!   
*/

