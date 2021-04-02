/*
    This is a simple program in go language to conver a given
    number if in range ( i.e number <= 2147483647 ) into its
    binary equivalent and print it out.

*/

package main

import (

  "fmt"

)

// global variable
var array[32] int

// This funtion prints the binary equivalent of decimal number
func printnumbers(counter int) {

   fmt.Print("The binary equivalent of the given number is :")

   var i int
   for i = counter-1; i >= 0; i-- {

       fmt.Print(array[i])

   }

}

/* This function converts the entered number from decimal to 
   binary number and stores the elements in a array*/
func dectobin(n int) {

   var r int
   r = 0

   var counter int
   counter = 0

   /* We divide the number by 2 and store its remainder in
      an array and then update the number as the quotient
      divided by 2*/
   for n != 0 {

      r = n % 2
      array[counter] = r
      n = n/2

      counter +=1

   }

   //calling printnumbers function to print the binary number
   printnumbers(counter)

}

//driver function
func main() {

   var number int

   //The decimal number we need to convert
   fmt.Print("Enter the number you want to convert :")
   fmt.Scan(&number)

   // checking if the entered number is in range or not
   if(number <= 2147483647) {

       dectobin(number)

   }else {

       fmt.Print("The number entered not in range")

   }

}

/*
   Sample I/O :

   a) In range :

   Enter the number you want to convert :10
   The binary equivalent of the given number is :1010      

   b) Not in range :

   Enter the number you want to convert :2147483648 
   The number entered not in range

*/

