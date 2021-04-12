/*
kotlin program to check happy numbers

A happy number is a number, if we reach to 1 after replacing the number by the squares of the digits of the number

Following examples will help to understand better:-

Input: n = 19
Output: True
19 is Happy Number,
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
As we reached to 1, 19 is a Happy Number.

Input: n = 20
Output: False
20 is not a happy number
2^2 + 0^2 = 4
4^2 = 16
As we cannot reach to 1, 20 is not a happy number
*/

import java.util.*

fun squaredSum(n: Int): Int{
    var sum_of_square:Int = 0
    var c:Int = n
    while(c!=0){
        sum_of_square += c%10 * (c % 10)
        c /= 10
    }
    return sum_of_square
}

//defining a boolean function to check whether the number is happy number or not
fun Happynumber(number: Int): Boolean {
    var slow: Int
    var fast: Int

    fast = number
    slow = fast
    do {

        slow = squaredSum(slow)

        fast = squaredSum(squaredSum(fast))
    } while (slow != fast)

    return slow == 1
}

//Testing code
fun main(){
    val input = Scanner(System.`in`)

    println("Enter the number which you want to check")
    val n = input.nextInt()
    if (Happynumber(n))
        println("$n is a Happy number")
    else
        println("$n is not a happy number")
}

/*
Enter the number which you want to check
19
19 is a Happy number

Enter the number which you want to check
20
20 is not a happy number
*/

/*
Time complexity :- O(N)
Space complexity :- O(1), which is constant
 */
