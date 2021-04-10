// Kotlin program to implement Staircase Search using Iterative Approach

import java.util.Scanner

fun main(args: Array <String>) {

    val input = Scanner(System.`in`)

    val noOfRows = input.nextInt()
    val noOfColumns = input.nextInt()

    val matrix = ArrayList <ArrayList <Int>> ()
    for(row in 0 until noOfRows) {
        var rows = ArrayList <Int> ()
        for(column in 0 until noOfColumns) {
            var element = input.nextInt()
            rows.add(element)
        }
        matrix.add(rows)
    }

    val key = input.nextInt()
    stairCaseSearch(matrix , key)
}

fun stairCaseSearch(matrix: ArrayList<ArrayList<Int>>, key: Int) {

    var noOfRows = matrix.size
    var noOfColumns = matrix[0].size
    var row = 0
    var column = noOfColumns - 1
    var isKeyPresent = false

    while(row <= noOfRows - 1 && column >= 0) {

        // If key is equal to the current element, print the indices values and break
        if(matrix[row][column] == key) {
            isKeyPresent = true
            println("Key: $key is present at Row: ${row + 1} and Column: ${column + 1}")
            break
        }

        // If current element is greater than key, then since it is column sorted matrix, the
        // previous column would have smaller element than the current column
        else if(matrix[row][column] > key) {
            column--
        }

        // If the current element is smaller than key, then since it is row sorted matrix, the
        // next row would have greater element than the current row
        else {
            row++
        }
    }

    // If the element is not present in the matrix
    if(!isKeyPresent)
        println("Key: $key is not present in the matrix")
}

// Time Complexity: O(n + m)
// Auxiliary Space Complexity: O(1)

/* Sample Test Cases:
Test - 1:
    Input
        3 4
        1 2  3  4
        5 6  7  8
        9 10 11 12
        11

    Output
        Key: 11 is present at Row: 3 and Column: 3

Test - 2:
    Input
        2 1
        10
        20
        -10
    Output
        Key: -10 is not present in the matrix
 */

