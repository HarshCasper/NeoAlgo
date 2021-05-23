/* Program to reverse a given sentence using a recursive loop in Kotlin
We will create a recursive function and operate it till the end and store the reverse order.
*/


import java.util.Scanner       

fun main(args: Array<String>) {

   val reader = Scanner(System.`in`)       
   print("Enter any sentence: ")  
   var sentence :String = reader.nextString()  
   
    val reversed = reverse(sentence)
    println("The reversed sentence is: $reversed")
}

fun reverse(sentence: String): String {
    if (sentence.isEmpty())
        return sentence

    return reverse(sentence.substring(1)) + sentence[0]
}

/*
Sample Test case:
Enter any sentence: Hello Kotlin 
The reversed sentence is : niltoK olleH
*/

/*
Time Complexity : O(n)
Auxiliary Space : O(1)
*/

