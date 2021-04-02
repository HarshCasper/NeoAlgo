// Kotlin program to count the no. of negative elements in a row and column sorted (descending) matrix

import java.util.Scanner

fun main(args: Array <String>) {

    val input = Scanner(System.`in`)

    val noOfRows = input.nextInt()
    val noOfColumns = input.nextInt()

    val matrix = arrayListOf<ArrayList<Int>>()
    for(row in 0 until noOfRows) {
        val rows = arrayListOf<Int>()
        for(column in 0 until noOfColumns) {
            val element = input.nextInt()
            rows.add(element)
        }
        matrix.add(rows)
    }

    val countOfNegatives = countNegativeInSortedMatrix(matrix)
    println("The no. of negative elements in the given sorted matrix is : $countOfNegatives")
}

fun countNegativeInSortedMatrix(matrix: ArrayList<ArrayList<Int>>): Int {

    var countOfNegatives = 0
    var row = 0
    var column = matrix[0].size - 1
    while(row <= matrix.size - 1 && column >= 0) {

        // If the element is less than zero, then it is always sure that the elements below it is going to be
        // negative, so it is added to the count and the pointer is moved to previous column
        if(matrix[row][column] < 0) {
            countOfNegatives += matrix.size - row
            column--
        }

        // If the element is greater than or equal to 0, since it is a sorted matrix in descending order
        // we move to the next row
        else
            row++
    }

    return countOfNegatives
}

// Time Complexity: O(n + m)
// Auxiliary Space Complexity: O(1)

/* Sample Test Cases:
Test - 1:
    Input
        3 4
        4 3  2 -1
        3 2 -1 -2
        1 1 -3 -10
    Output
        The no. of negative elements in the given sorted matrix is : 5
Test - 2:
    Input
        2 1
        -1
        -1
    Output
        The no. of negative elements in the given sorted matrix is : 2
 */
