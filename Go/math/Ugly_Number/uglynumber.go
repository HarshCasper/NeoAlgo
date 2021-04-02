/*
   This is a simple program in go language to check
   if a given number is an ugly number or not.
   
   An Ugly number is a number whose only prime factors
   are 2, 3 or 5.

   Note : 1 is taken as base case and is considered
          as an ugly number
*/

package main

import (

  "fmt"

)

/* This function repeatedly divides a give number
    till its divisible by the second number*/
func divisible(x,y int) int {

     var r int
     r = x % y

     for r == 0 {

         x = x/y
         r = x % y

     }

     return x
}

/* This is the function where we check if a given 
   number is an ugly number or not*/
func uglynumber(n int) int{

    // these are the base cases
    if(n == 1 || n==2 || n==3 || n==5 ) {

       return 1

    }

    // checking divisibility by 2 and its multiples
    n = divisible(n,2)
    if(n == 1) {
        return 1
    }

    // checking divisibility by 3 and its multiples
    n = divisible(n,3)
    if(n == 1) {
        return 1
    }

    // checking divisibility by 5 and its multiples
    n = divisible(n,5)
    if(n == 1) {
        return 1
     }

    // if its not divisible by either of them
    return 0

}

// driver function
func main() {

    var number int
    fmt.Print("Enter the number you want to check for :")
    // taking the number as input from user
    fmt.Scan(&number)

    // validating the input
    if (number <= 0){

        fmt.Print("Enter a valid number!")

    }else {

        var checker int
        checker = 0

        checker = uglynumber(number)

        // checking if the number is ugly number or not
        if( checker == 1 ){

             fmt.Print("The given number is a ugly number!")

        }else {

             fmt.Print("The given number is not an ugly number")

        }

    }

}

/*
    Sample I/O :

    a) Is Ugly Number :

    Enter the number you want to check for :300
    The given number is a ugly number!      

    b) Is not an Ugly Number :      
    
    Enter the number you want to check for :56
    The given number is not an ugly number 

    c) Invalid Input : 

    Enter the number you want to check for :0
    Enter a valid number! 

*/

