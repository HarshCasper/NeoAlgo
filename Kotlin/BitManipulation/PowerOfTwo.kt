/*

A Kotlin Program to find whether a given number is a power of 2 or not.

*/

import java.util.Scanner;

fun main(args: Array <String>) {

    val input = Scanner(System.`in`)

    // Get the required input from the user
    println("Enter the number to check whether it is a power of 2 or not : ")
    val n: Int = input.nextInt()

    val result = isPowerOfTwo(n)
    if(result)
        println("Number: $n is a Power of 2")
    else
        println("Number: $n is not a Power of 2")
}

// Defining a function which takes a number and returns whether it is a power of 2 or not.
fun isPowerOfTwo(n: Int): Boolean {

    // A number is said to be a Power of 2 if it has only 1 set bit.
    var setBitsCount = 0
    var num = n

    // Check the no. of set bits
    while(num > 0) {
        if(num % 2 == 1)
            setBitsCount++
        num /= 2
    }

    return setBitsCount == 1
}

/*
Sample Test Cases:

    Test case 1:
        Enter the number to check whether it is a power of 2 or not :
        4156
        Number: 4156 is not a Power of 2

    Test Case 2:
        Enter the number to check whether it is a power of 2 or not :
        4096
        Number: 4096 is a Power of 2
*/

/*
    Time complexity: O(logn)
    Space complexity: O(1)
*/
