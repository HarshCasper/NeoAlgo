/* This is a simple program to check if we have a noble number or not
   from the given array. An integer is said to be Noble in an array
   if the number of integers greater than integer is equal to integer.
*/

package main

import (

  "fmt"

)

// global variables
var number int
var arr [100]int

//This function helps us in finding the noble number
func nobleInteger() int{

    for i:=0;i<number;i++ {

      count :=0
      for j:=0;j<number;j++ {
         if(arr[i]<arr[j]){
            count += 1
         }
      }

      // if the count of greater elements = arr[i]
      if(count == arr[i]){
         fmt.Print("Noble integer is ",arr[i])
         return 1
      }

    }

    fmt.Printf("Noble integer not found")
    return 0
}

// driver function
func main(){

    fmt.Print("Enter the no of elements of the Array :")
    //taking the array size
    fmt.Scan(&number)

    var n int
    fmt.Print("Enter the elements of the array :")
    // scanning the elements of the array
    for i:=0;i<number;i++ {
       fmt.Scan(&n)
       arr[i] = n
    }

    //calling the noble integer function 
    nobleInteger()

}

/* Sample I/O :

   a) If no noble integer :

   Enter the no of elements of the Array :5
   Enter the elements of the array :1 2 3 4 5
   Noble integer not found

   b) If there is noble number :

   Enter the no of elements of the Array :5
   Enter the elements of the array :10 3 20 40 2
   Noble integer is 3   
*/

