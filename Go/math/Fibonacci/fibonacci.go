/*
   This is a simple program written in go language.
   This program takes in a number as an input an 
   returns the Fnth term in the fibonacci sequence.

   Here the base case is Fo =1 and F1 =1
   Formula goes as : Fn = Fn-1 + Fn-2

*/

package main

import (

  "fmt"

)

/* This function takes the given number and 
   returns the fibonacci number*/
func fibonacci(n int) int{

   // base case as Fo =1 and F1 =1
   if(n == 0 || n == 1){

        return n

    }else {

        // Fn = Fn-1 + Fn-2
        return fibonacci(n-1) + fibonacci(n-2)

    }

}

//driver function
func main() {

   var number int
   fmt.Print("Enter the number :")
   //taking the input from here
   fmt.Scan(&number)

   var res int
   res = 0

   /* calling the fibonacci functuion to return 
      the value and printing it out*/
   res = fibonacci(number)
   fmt.Print("The number is : ",res)

}

/*
   Sample I/O :

   a) Base Case :   

   Enter the number :0
   The number is : 0 

   Enter the number :1
   The number is : 1   

   b) At random number n : 

   Output-1:

   Enter the number :20
   The number is : 6765      

   Output-2:

   Enter the number :40
   The number is : 102334155   

*/

