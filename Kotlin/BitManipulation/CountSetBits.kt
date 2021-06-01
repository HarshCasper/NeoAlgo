import java.util.Scanner

/*

A Kotlin Program to find the XOR of 1 to N.

*/

fun main(args: Array <String>) {

    val input = Scanner(System.`in`)

    // Get the required input from the user
    println("Enter the number to count no. of set bits in it : ")
    val n: Int = input.nextInt()

    val result = countSetBits(n)
    println("The no. of set bits is : $result")

}

// Defining a function that will take an number and return the count of set bits in it
fun countSetBits(n: Int): Int {
    var count = 0
    var num = n

    // In every iteration, the last set bit of the number is made unset
    // Therefore, the count of set bits, would be the no. of times the last set bit can be removed until zero occurs
    while(num != 0) {
        num = num and (num - 1);
        count++
    }

    return count
}

/*
Sample Test Cases:

    Test case 1:
        Enter the number to count no. of set bits in it :
        10453
        The no. of set bits is : 7

    Test Case 2:
        Enter the number to count no. of set bits in it :
        1023
        The no. of set bits is : 10
*/

/*
    Time complexity: O(No. of Set Bits)
    Space complexity: O(1)
*/
