/*
The Fibonacci series is a series where the next term is the sum of pervious two terms.
The first two terms of the Fibonacci sequence is 0 followed by 1.

The Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21, ...
*/
import java.util.Scanner                    //importing scanner

fun main(args: Array<String>) {
   
   val reader = Scanner(System.`in`)       
   print("Enter any number: ")  
   var n :Int = reader.nextInt()            //Obtaining input from user
  
    var i = 1
    var t1 = 0
    var t2 = 1

    print("Fibonacci series upto $n : ")

    while (i <= n) {
        print("$t1 + ")

        val sum = t1 + t2
        t1 = t2                      //swapping the terms 
        t2 = sum

        i++
    }
}

/*
Sample Test case:
Enter any number: 5
Fibonacci series upto 5: 0 + 1 + 1 + 2 + 3
*/

/*
Time Complexity : O(n)
Auxiliary Space : O(1)
*/

