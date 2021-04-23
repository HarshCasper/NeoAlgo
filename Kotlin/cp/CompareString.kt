/* Program to compare two input string and check whether the given inputs are same or not .
We will be using == operator to check for the same.
*/


import java.util.Scanner       

fun main(args: Array<String>) {

   val reader = Scanner(System.`in`)       
   print("Enter 1st  string: ")  
   var s1 :String = reader.nextString()  
   print("Enter 2nd  string: ")  
   var s2 :String = reader.nextString() 

   if (s1 == s2) {

        println("Strings are equal")
    }  else {

        println("Strings are not equal")
    }

    val res = s1.compareTo(s2, true)

    if (res == 0) {

        println("Strings are equal")
    }  else {

        println("Strings are not equal")
    }
}

/*
Sample Test case:
Enter 1st String : Kotlin
Enter 2nd String : Kotlin
Strings are equal
*/

/*
Time Complexity : O(1)
Auxiliary Space : O(1)
*/

