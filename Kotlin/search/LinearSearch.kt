/*Linear search algorithm is an algorithm which checks if an element is present in the given list by comparing it with every element in the list.
  Linear search is the simplest search algorithm;it is a special case of brute-force search and in worst-case, cost is proportional to the number
  of elements in the list. Hence name is Linear search.This is a linear search algorithm in Kotlin.*/

//we need to import util as we are using the scanner object 
import java.util.*

fun linearsearch(array:IntArray,number:Int){
   
   var i = 0 
   //we iterate through the array
   for( index in array.indices ){ 
      if( array[index] == number){
         //print the number and at what index it is present
         println("we have ${number} at index : ${index}")
         i++
      }
   }  
   //Print this message if the element is not found in the array/List
   if(i==0){
      print("The number given is not there in the given List")
   }  
}     
      
fun main(){
   
   val scan = Scanner(System.`in`)
   print("Enter the number of elements :")
   //Taking input from user
   val array = IntArray(scan.nextInt())
   print("Enter the elements :")
   for(element in array.indices){
     array[element] = scan.nextInt()
   } 
   print("Enter the number you want to search for :")
   val number = scan.nextInt()
   scan.close()
   //calling linearsearch function
   linearsearch(array,number)
}
/*
   We can compile and run this code with the commands as:
   $kotlinc LinearSearch.kt -include-runtime -d LinearSearch.jar
   $java -jar LinearSearch.jar
   
   Sample I/O :
   
   Enter the number of elements :4
   Enter the elements :1 2 2 4
   Enter the number you want to search for :2
   we have 2 at index : 1
   we have 2 at index : 2
*/
