/*
   This is a simple program in go language to calculate the
   catalan number if give a number as input.

   formula used : Co = 1 ; Cn+1 = summation from i = 0 to n (CiCn-1)

*/

package main

import (

  "fmt"

)

/* This function calculates and returns catalan number in a 
   recursive manner */
func catalannumber(n int) int {

   var catalan int
   catalan = 0

   if (n == 0 || n ==1 ) {

       return 1

   }else {

      for i:=0;i<n;i++ {

         catalan += catalannumber(i) * catalannumber(n-i-1);

      }

   }

   return catalan

}

// driver function
func main() {

   var number int

   // Taking the input from user here
   fmt.Print("Enter the number here :")
   fmt.Scan(&number)

   var catalan int
   catalan = 0 
   // calling the catalannumber function 
   catalan = catalannumber(number)

   // Printing the catalan number
   fmt.Print("The catalan number is : ",catalan)

}

/*
   Sample I/O :

   Enter the number here :5
   The catalan number is : 42 

*/

