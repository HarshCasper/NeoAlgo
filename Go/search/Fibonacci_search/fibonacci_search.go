/*
    This is a simple in go language to search 
    the given array using fibonacci numbers for
    a given number inputted.

    Note : we need to the give the input as a 
           sorted array 

    Here we use the fibonacci number starting 
    form 0 and so on.....

    i.e, 0,1,1,2,3,5,8,13,21 ....

*/

package main

import (

   "fmt"

)

// global variables
var array[100] int
var number int
var x int

//  n,n-1 and n-1 th fibonacci numbers
var a int = 0
var b int = 1
var c int = a+b
var index int = 0
var i int = -1

// We print the result using this function
func printfunction(res int) {

   if(res == 0) {
      fmt.Print("The element not found!")
   }else {
      fmt.Print("The element is at the index position :",res)
   }

}

/* We use this function to validate the n-1th 
   fibonacci number*/
func validate() {

   if( a+i<number-1 ) {
        index = a+i
   }else{
        index = number-1
   }

}

/* This function calculates the nth n-1th and 
   n-2th fibonacci numbers where n is the 
   smallest fibonacci number greater tha or 
   equal to the input array size */
func fibonaccinumber() {

     for(c<number){
         a = b
         b = c
         c = a+b
     }

}

/* This is the function where we search for 
   the inputted number*/
func fibonaccisearch() int{

     for c>1 {

        // validating the n-2th fib number
        validate()

         /* if x is greater than array element 
            we recur for subarray after index*/
        if(array[index] < x ) {

            /* move the three Fibonacci variables 
               one Fibonacci down*/
            c = b
            b = a
            a = c-b
            i = index

        /* if x is smaller than the array element
           we recur for the subarray before index*/
        }else if (array[index] > x ) {

            /*move the three Fibonacci variables 
              two Fibonacci down */
            c = a
            b = b -a
            a = c - b

        // if x is same as element
        }else {

            // we return the index position
            return index
        }

     }

     // checking if the number-1 th element is x or not
     if (b>0 && array[number-1] == x){
           return number-1
     }

     // if the element is not found in the array
     return 0

}

// driver function
func main() {

    // Taking the number of elements here
    fmt.Print("Enter the number of elements : ")
    fmt.Scan(&number)

    // Taking the array elements here
    fmt.Print("Enter the array elements :")
    var n int
    for i:=0;i<number;i++ {

        fmt.Scan(&n)
        array[i] = n

    }

    // Taking the element we need to search for
    fmt.Print("Enter the element you want to search for :")
    fmt.Scan(&x)

    /* calling the fibonacci number function 
       to cal fib numbers*/
    fibonaccinumber()

    /* calling fibonacci search to check for 
       the element if present or not*/
    res := fibonaccisearch()

    // calling the printing function
    printfunction(res)

}

/*
    Sample I/O :

    a) Element not found :

    Enter the number of elements : 10
    Enter the array elements :1 2 3 4 5 6 7 8 9 10
    Enter the element you want to search for :56
    The element not found!   

    b) Element found :

    Enter the number of elements : 6
    Enter the array elements :1 2 3 4 5 6
    Enter the element you want to search for :6
    The element is at the index position :5

*/

