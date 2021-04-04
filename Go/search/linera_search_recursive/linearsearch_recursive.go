/* This is a simple program in go language to search 
   linearly in a recursive manner given an array.
*/

package main

import (

  "fmt"

)

// global variables
var array[100] int
var number int
var element int

// this function prints the result
func printfunction(res int) {

    if(res == -1) {
       fmt.Print("Element not found!")
    }else {
       fmt.Print("The entered element is at the index position : ",res)
    }

}

// This function searches linearly in recursive manner
func linearsearch(first,last int) int {

    if(array[first] == element){

         return first

    }else if(array[last] == element) {

         return last

    }else if(last<first) {

         return -1

    }else {

         last = last -1
         first = first+1
         return linearsearch(first,last)
    }
}

// driver function
func main() {

   // Taking inputs from user here
   fmt.Print("The number of elements :")
   fmt.Scan(&number)

   var n int
   fmt.Print("Enter the elements of the array :")
   for i:=0;i<number;i++ {
        fmt.Scan(&n)
        array[i] = n
   }

   fmt.Print("Enter the element you want to search for : ")
   fmt.Scan(&element)

   first := 0
   last := number-1

   // result after linear search
   result := linearsearch(first,last)

   // calling the print function
   printfunction(result)

}

/*
   Sample I/O :

   a) Element found :

   The number of elements :5
   Enter the elements of the array :1 2 3 4 5
   Enter the element you want to search for : 5
   The entered element is at the index position : 4 
  
   b) Element not found :

   The number of elements :4
   Enter the elements of the array :1 2 3 6 
   Enter the element you want to search for : 90
   Element not found! 

*/

