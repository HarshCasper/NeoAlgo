/*
A number is called happy if it leads to 1 after a sequence of steps
wherein each step number is replaced by the sum of squares of its digit
that is if we start with Happy Number and keep replacing it with digits square sum, we reach 1.

Examples of Happy numbers are:- 1, 7, 10, 13, 19, 23, 28, 31, 32, 44, 49, 68, 70,...
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
