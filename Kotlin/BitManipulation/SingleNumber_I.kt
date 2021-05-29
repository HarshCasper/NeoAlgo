/*

A Kotlin Program to find the element that is occurring odd no. of times.
It is given that there is only one element that is occurring odd no. of times and all other elements occurs even no. of times.

*/

import java.util.Scanner

fun main(args: Array <String>) {

    val input = Scanner(System.`in`)

    // Get the required input from the user
    println("Enter the size of the array : ")
    val arraySize: Int = input.nextInt()

    val array = arrayListOf<Int>()
    println("Enter the elements of the array : ")
    for(index in 0 until arraySize) {
        val element = input.nextInt()
        array.add(element)
    }

    val result = findSingleNumber(array)
    println("The Single Number that is occurring odd no. of times is : $result")
}

// Defining a function that will take an array and return the element that is occurring only once
fun findSingleNumber(array: ArrayList<Int>): Int {

    // Initially let the result be 0
    var result = 0

    for(element in array) {
        // Every element is performed xor with result, so that even occurring element result in 0 and odd occurring element is stored in result
        result = result xor element
    }

    return result
}

/*
Sample Test Cases:

    Test case 1:
        Enter the size of the array :
        5
        Enter the elements of the array :
        1 1 1 2 2
        The Single Number that is occurring odd no. of times is : 1

    Test Case 2:
        Enter the size of the array :
        9
        Enter the elements of the array :
        6 5 5 7 7 7 8 7 6
        The Single Number that is occurring odd no. of times is : 8
*/

/*
    Time complexity: O(n)
    Space complexity: O(1)
 */
