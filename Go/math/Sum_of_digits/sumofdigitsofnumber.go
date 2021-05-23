/* This is a simple program in go language to calculate the sum of
   the individual digits of a given number taken as input and
   prints the output sum */

package main

import(

 "fmt"

)

// global variables: number,reminder and sum
var n int
var r int
var sum int

//function to print the output sum
func printfunction(){

  fmt.Printf("The sum of digits of the number given is :%d",sum)

}

//function to calculate the sum of digits
func Sum(n int) {

  for n != 0{

     r = n%10
     sum += r
     n = n/10

  }

}

//driver function
func main() {

  fmt.Print("Enter the number :")
  fmt.Scanln(&n)

  //calling the sum function to calculate the sum of digits 
  Sum(n)

  //calling print function to print the output sum
  printfunction()

}
/*
   Sample I/O :

   Enter the number :1234
   The sum of digits of the number given is :10
*/

