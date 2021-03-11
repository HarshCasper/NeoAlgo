/*Kotlin Program to check Given number is an Armstrong Number or not*/
import java.util.*

// Function for check Armstrong Number
fun isArmstrongNumber(num: Int, size: Int): Int {
    if (num<10) {
        return Math.pow(num.toDouble(), size.toDouble()).toInt()
    } else {
        return(Math.pow((num % 10).toDouble(), size.toDouble()).toInt() + isArmstrongNumber(num / 10, size))
    }
}

// Main Function, Entry Point of Program
fun main(arg: Array<String>) {
    val sc = Scanner(System.`in`)

    println("Enter Number: ")
    val num: Int = sc.nextInt()
    val size: Int = Integer.toString(num).length

    // Call function to check number is Armstrong
    if (num == isArmstrongNumber(num, size)) {
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
