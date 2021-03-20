// Kotlin program to implement Linear Search using Iterative Approach

import java.util.Scanner

fun main(args: Array <String>) {

    val input = Scanner(System.`in`)

    val arrayLength = input.nextInt()
    var arrayOfElements = arrayListOf<Int>()

    for(index in 0 until arrayLength) {
        var element = input.nextInt()
        arrayOfElements.add(element)
    }

    val key = input.nextInt()
    var index = linearSearch(arrayOfElements , key)

    if(index == -1)
        println("Key: $key is not present in the array")
    else
        println("Key: $key is present in the array at index $index")

}

// Function to return the index of the key if it is present in the array, else returns an invalid index -1
fun linearSearch(arrayOfElements: ArrayList<Int>, key: Int): Int {

    // Traversing the elements of the array to find the key if it is present
    for(index in 0 until arrayOfElements.size) {

        // If key is found, return the index
        if(arrayOfElements[index] == key)
            return index
    }

    // Return an invalid index if key is not present
    return -1
}

// Time Complexity: O(n)
// Auxiliary Space Complexity: O(1)

/* Sample Test Cases:
Test - 1:
    Input
        7
        789 12 47 231 387 100 34
        47
    Output
        Key: 47 is present in the array at index 2
Test - 2:
    Input
        5
        100 312 55 67 -89
        -10
    Output
        Key: -10 is not present in the array
 */
