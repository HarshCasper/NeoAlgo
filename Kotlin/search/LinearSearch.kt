//This is a program that allows us to do linear search in kotlin

import java.util.*
fun main(){

   val scan = Scanner(System.`in`)
   
   print("Enter the number of elements :")
   //Here we take the size of the input array/List
   val array = IntArray(scan.nextInt())
   
   print("Enter the elements :")
   //Taking the elements and storing them in array
   for(element in array.indices){
     array[element] = scan.nextInt()
   } 
    
   print("Enter the number you want to search for :")
   //The number we want to search for
   val number = scan.nextInt()
   scan.close()

   var i = 0
   //Here we iterate through the array and check if the number is there in the given list/array
   for( index in array.indices ){ 
     if( array[index] == number){
        println("we have ${number} at index : ${index}")
        i++
      }

   }
   //Print this message if the element is not found in the array/List
   if(i==0){
      print("The number given is not there in the given List")
   }

}

/*

  Sample I/O :
  
  Enter the number of elements :7
  Enter the elements :1 9 3 7 10 4 8
  Enter the number you want to search for :10
  we have 10 at index : 4

  Enter the number of elements :4
  Enter the elements :1 2 2 4
  Enter the number you want to search for :2
  we have 2 at index : 1
  we have 2 at index : 2

  Enter the number of elements :4
  Enter the elements :1 2 3 4
  Enter the number you want to search for :5
  The number given is not there in the given List 

*/

