/*
The Fibonacci series is a series where the next term is the sum of pervious two terms.
The first two terms of the Fibonacci sequence is 0 followed by 1.

The Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21, ...
*/
import java.util.Scanner                    

fun main(args: Array<String>) {
   
   val reader = Scanner(System.`in`)       
   print("Enter any number: ")  
   var number :Int = reader.nextInt()            
  
    var index = 1
    var term1 = 0
    var term2 = 1

    print("Fibonacci series upto $number : ")

    while (index <= number) {
        print("$term1 , ")

        val sum = term1 + term2
        term1 = term2                      
        term2 = sum

        index++
    }
}

/*
Sample Test case:
Enter any number: 5
Fibonacci series upto 5: 0 , 1 , 1 , 2 , 3
*/

/*
Time Complexity : O(n)
Auxiliary Space : O(1)
*/

