// Kotlin program to implement Binary Search using Iterative Approach

import java.util.Scanner

fun main(args: Array<String>) {

    val input = Scanner(System.`in`)

    var arrayLength = input.nextInt()
    var arrayOfElements = arrayListOf<Int>()

    for(index in 0 until arrayLength) {
        var element = input.nextInt()
        arrayOfElements.add(element)
    }

    var key = input.nextInt()
    var index = binarySearch(arrayOfElements , key)

    if(index == -1)
        println("Key: $key is not present in the array")
    else
        println("Key: $key is present in the array at index $index")

}

// Function to return the index of the key if it is present in the array, else returns an invalid index -1
fun binarySearch(arrayOfElements: ArrayList<Int>, key: Int): Int {

    // Lower and Upper bound of the array
    var low = 0
    var high = arrayOfElements.size - 1

    while(low <= high) {

        // To find the middle position for the given bounds of the array
        var mid = low + (high - low) / 2;

        // If the key is found, return the index
        if(arrayOfElements[mid] == key)
            return mid

        // If the key is smaller, then it is just required to search the left sub-array
        else if(arrayOfElements[mid] > key)
            high = mid - 1

        // If the key is larger, then is it just required to search the right sub-array
        else
            low = mid + 1
    }

    // Return an invalid index if key is not present
    return -1
}

// Time Complexity: O(logn)
// Auxiliary Space Complexity: O(1)

/* Sample Test Cases:
Test - 1:
    Input
        7
        12 34 47 100 231 387 789
        387

    Output
        Key: 387 is present in the array at index 5

Test - 2:
    Input
        5
        10 12 45 67 89
        1000

    Output
        Key: 1000 is not present in the array
 */
