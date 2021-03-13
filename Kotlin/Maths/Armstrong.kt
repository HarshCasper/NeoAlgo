/*Kotlin Program to check Given number is an Armstrong Number or not*/
import java.util.*

// Function for check Armstrong Number
fun isArmstrong(num: Int): Boolean {
    var isArmNum = false
    var result : Int= 0
    var temp = num

    // Count No Digits in numbers
    val numberOfDigits = temp.toString().length

    while (temp > 0) {
        val remainder = temp % 10
        result += Math.pow(remainder.toDouble(), numberOfDigits.toDouble()).toInt()
        temp /= 10
    }

    if (result == num) {
        isArmNum = true
    }
    return isArmNum
}


// Main Function, Entry Point of Program
fun main(arg: Array<String>) {
    val sc = Scanner(System.`in`)

    println("Enter Number: ")
    val num: Int = sc.nextInt()

    // Call function to check number is Armstrong
    if (isArmstrong(num)) {
        println("$num is an Armstrong Number")
    } else {
        println("$num is not an Armstrong Number")
    }
}

/**
 * Sample input/output:
 * 
 * Enter Number: 
 * 153
 * 153 is an Armstrong Number
 * 
 * Enter Number: 
 * 224
 * 224 is not an Armstrong Number
 */
