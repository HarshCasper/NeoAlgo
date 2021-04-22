/*
   This is a simple programe in go language to search for a given element in
   an array/list given. First we find a range we need to search for and then 
   we do a binary search on the that range to arrive at our element. If we find
   the element we return the index position else we give a message missing.

*/

package main

import (

  "fmt"

)

// Global variables
var number int
var array[100] int
var x int

// function to print the index and message
func printfunction(checker int) {

    if(checker == -1){
       fmt.Print("The entered element is not found");
    }else {
       fmt.Print("The entered element is at the index position : ",checker)
    }
}

//this function returns the minimum of given 2 numbers
func min(x,y int) int{

   if(x<y){
     return x
   }else{
     return y
   }
}

// We do binary search using this function
func binarysearch(l,r int) int{

   if(r<l){
      return -1

   }else if(r>=l) {

   mid := (l+r)/2

   if(array[mid] == x) {
      return mid
   }

   if(array[mid] > x) {
      return binarysearch(l,mid-1)
   }

   return binarysearch(mid+1, r)

   }
   return -1
}

// This function helps us to find the range we search for
func exponentialsearch() int{

   if(array[0] == x) {
        return 0
   }

   i := 1;
   for(i<number && array[i]<=x) {
        i = i*2
   }

   minimum := min(i, number-1)

   return binarysearch(i/2,minimum)
}

// driver function
func main() {

   var n int
   fmt.Print("Enter the number of elements :")
   fmt.Scan(&number)

   fmt.Print("Enter the elements of the array in sorted manner :")
   for i:=0;i<number;i++ {
       fmt.Scan(&n)
       array[i] = n
   }

   fmt.Print("Enter the element you want to search for :")
   fmt.Scan(&x)

   checker := exponentialsearch()
   printfunction(checker)
}

/*
   Sample I/O :

   Enter the number of elements :5
   Enter the elements of the array in sorted manner :1 2 3 4 5
   Enter the element you want to search for :5
   The entered element is at the index position : 4

*/

