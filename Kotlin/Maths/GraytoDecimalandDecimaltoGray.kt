/*
The reflected binary code or Gray code is an ordering of the binary numeral system
 such that two successive values differ in only one bit (binary digit).

 In this script we are going to convert gray code to its decimal equivalent and vice versa.
*/

import java.util.*

//defining a function to get the gray code equivalent number from decimal numbers
fun dec_to_gray_code(num:Int): Int{
//    we have to right shift the number by 1, by doing the xor operation with the original number
    return num xor (num shr 1)
}

//defining a function to get the decimal equivalent number from Gray code
fun gray_code_to_decimal(num:Int):Int{
    var c:Int = num
    var inv:Int = 0
//    we are taking xor until c becomes 0
    while (c!=0) {
        inv = inv xor c
        c = c shr 1
    }
//    returning the equivalent number
    return inv
}

//Testing code
fun main(){
    val scan = Scanner(System.`in`)
    var num_in_decimal:Int = 0
    var num_in_gray_code = 0

    println("What do you want? ")
    println("Press 1 for conversion of decimal number to gray code and 2 for Gray code to decimal number")
    var choice = scan.nextInt()

//    pressing 1 to get Gray code equivalent numbers from decimal numbers
    if (choice == 1){
        println("Enter the number in decimal: ")
        num_in_decimal = scan.nextInt()
        num_in_gray_code = dec_to_gray_code(num_in_decimal)
        println("The gray code value for decimal number $num_in_decimal is: $num_in_gray_code")
    }

    //    pressing 2 to get decimal equivalent numbers from gray code numbers
    else if(choice == 2){
        println("Enter the number in Gray Code: ")
        num_in_gray_code = scan.nextInt()
        num_in_decimal = gray_code_to_decimal(num_in_gray_code)
        println("The decimal value for Gray Code number $num_in_gray_code is: $num_in_decimal")
    }
    else{
        println("Enter a valid choice")
    }
}

/*
    Sample Test Cases:-

    Test case 1:-

    What do you want?
    Press 1 for conversion of decimal number to gray code and 2 for Gray code to decimal number
    2
    Enter the number in Gray Code:
    4
    The decimal value for Gray Code number 4 is: 7

    Test Case 2:-
    What do you want?
    Press 1 for conversion of decimal number to gray code and 2 for Gray code to decimal number
    1
    Enter the number in decimal:
    10
    The gray code value for decimal number 10 is: 15
 */

/*
    Time complexity for converting decimal numbers to its Gray code equivalent:- O(1), which is constant
    Time complexity for converting Gray code to its decimal equivalent is:- O(N)
    Space complexity for both the functions :- O(1), which is constant
 */
