/* This is a program in go language to check if the number given is kaprekar
   number or not. A kaprekar number is a number where sum of the half parts
   of the squared digits of the orginal number is same as the input number.
   Example : 9 -> 81 -> 8+1 -> 9
   So, 9 is a kaprekar number.
*/

package main

import (

  "fmt"
  "math"

)

//global variables we use
var n int
var digits int
var square int
var sum int

// This function calculates the count of the digit we send to it
func digitcnt(){

  digits = 0
  for square != 0 {

     digits += 1
     square = square/10
  }

  square = n*n
}

// This function tells us if a number is a kaprekar number or not
func kaprekar(n int) int {

   // Base case
   if(n == 1) {
     fmt.Printf("The given number is a kaprekar number!")
     return 1;

   }

   // calling the digits count
   digitcnt()

   //here we calculate if the number is kaprekar or not
   for i:=1;i<digits;i++  {

      //To avoid the numbers like 10,100..as they are not kaprekar numbers
      res := int(math.Pow(10.0,float64(i)))

      if (res == n){
          continue
      }

      // calculating the sum of the 2 half
      sum = (square/res) + (square%res)
      if (sum == n) {
         fmt.Printf("The given number is kaprekar number!")
         return 1;

      }

   }

   // if the above sum != n then n is not kaprekar number
   fmt.Printf("The given number is not a kaprekar number!")
   return 0;

}

//driver function
func main() {

  //Scanning the input here
  fmt.Print("Enter the number :")
  fmt.Scanln(&n)

  square = n*n

  //callingg kaprekar function
  kaprekar(n)

}

/* Sample I/O :
    
   a) Is a kaprekar number :   

   Enter the number :297
   The given number is kaprekar number!

   b) Is not a kaprekar number :

   Enter the number :3
   The given number is not a kaprekar number!    
*/

