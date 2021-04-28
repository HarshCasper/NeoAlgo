//Kotlin program to implement ternary search using recursive approach

import java.util.*

// A function to declare ternary search
fun ternarySearch(left:Int, right:Int, key:Int, array: ArrayList<Int>): Int{
    if (right >= left) {

        // Finding the midterms
        val mid1 = left + (right - left) / 3
        val mid2 = right - (right - left) / 3

        // Check if the value is present in the first mid term
        if (array[mid1] == key) {
            return mid1
        }

        // Check if the value is present in the second mid term
        if (array[mid2] == key) {
            return mid2
        }

        // If the element is not present in the mid positions, the following cases can be a possibility.

        // Checking if the value is less than mid1 element
        if (key < array[mid1]) {

            return ternarySearch(left, mid1 - 1, key, array)
        }

        // Checking if the value is greater than mid2 element
        else if (key > array[mid2]) {
            return ternarySearch(mid2 + 1, right, key, array)
        }

        // The last possibility is that, the element may be present between the mid1 and mid2
        else {
            return ternarySearch(mid1 + 1, mid2 - 1, key, array)
        }
    }
    // If all the possibilities fail, the element is not present inside the array
    return -1
    }

//Testing code
fun main(){

    val input = Scanner(System.`in`)

    println("Enter the length of the array")
    val arrayLength = input.nextInt()
    val arrayOfElements = arrayListOf<Int>()

    println("Enter the elements of the array in ascending order")
    for(index in 0 until arrayLength) {
        val element = input.nextInt()
        arrayOfElements.add(element)
    }

    print("Enter the number you want to search for :")
    val number = input.nextInt()
    input.close()
    val left:Int = -1
    val right:Int = arrayLength - 1

    // Search the number using ternarySearch
    val position = ternarySearch(left, right, number, arrayOfElements) + 1

    if(position == 0)
        println("Key: $number is not present in the array")
    else
        println("Key: $number is present in the array at position $position")
}

/*
    Sample Test Cases:-

    Test Case 1:-
    Enter the length of the array
    5
    Enter the elements of the array in ascending order
    1 2 3 4 5
    Enter the number you want to search for :5
    Key: 5 is present in the array at position 5

    Test Case 2:-
    Enter the length of the array
    5
    Enter the elements of the array in ascending order
    10 20 30 40 50
    Enter the number you want to search for :60
    Key: 60 is not present in the array

    Time Complexity:- The time complexity of this algorithm is O(log3n), where n is the size of the array
    Space cComplexity:- The space complexity of this algorithm is O(1), which is constant, irrespective of any case.
 */
