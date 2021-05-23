/*

A Kotlin Program to find the XOR of 1 to N.

*/

import java.util.Scanner

fun main(args: Array <String>) {

    val input = Scanner(System.`in`)

    // Get the required input from the user
    println("Enter the limit till which XOR should be found : ")
    val n: Int = input.nextInt()

    val result = XOROfOneToN(n)
    println("The XOR of 1 to N is : $result")

}

// Defining a function that will take an element and return the xor from 1 to that element
fun XOROfOneToN(n: Int): Int {

    // Xor of 1 to any multiple of 4 is always 0, therefore it is just enough to find xor of remaining numbers
    return when {
        n % 4 == 0 -> {
            0
        }
        n % 4 == 1 -> {
            n
        }
        n % 4 == 2 -> {
            n xor (n - 1)
        }
        else -> {
            n xor (n - 1) xor (n - 2)
        }
    }
}

/*
Sample Test Cases:

    Test case 1:
        Enter the limit till which XOR should be found :
        111
        The XOR of 1 to N is : 108

    Test Case 2:
        Enter the limit till which XOR should be found :
        12345678
        The XOR of 1 to N is : 3
*/

/*
    Time complexity: O(1)
    Space complexity: O(1)
*/
