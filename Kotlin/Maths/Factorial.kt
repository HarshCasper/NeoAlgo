/*
The factorial of a positive number n is given by:
factorial of n (n!) = 1 * 2 * 3 * 4 * ... * n
*/

import java.util.Scanner     

fun main(args: Array<String>) {

   val reader = Scanner(System.`in`)       
   print("Enter any number: ")  
   var num :Int = reader.nextInt()            
  
    var factorial: Long = 1
    for (i in 1..num) {
        // factorial = factorial * i;
        factorial *= i.toLong()
    }
    println("Factorial of $num = $factorial")
}

/*
Sample Test case:
Enter any number: 10
Factorial of 10 = 3628800
*/

/*
Time Complexity : O(n)
Auxiliary Space : O(1)
*/

