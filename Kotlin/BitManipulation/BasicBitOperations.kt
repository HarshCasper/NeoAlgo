/*Bitwise and bit shift operators are used on only two integral types
(Int and Long) to perform bit-level operations.
*/
import java.util.Scanner

fun main(args: Array<String>) {

   val sc  = Scanner(System.`in`)
   println("Enter 2 Numbers: ")
    val number1 : Int = sc.nextInt();
    val number2 : Int = sc.nextInt();

    var result: Int

    println("Basic Bit Operations are")

    result = number1 or number2                          
    println("OR Operation :$result")

    result = number1 and number2                  
    println("AND Operation :$result")

    result = number1 xor number2                  
    println("XOR Operations :$result")

    result = number1.inv()                        
    println("Complement Operation :$result")
}

/*
Sample test case 
**************************************************************************
Enter 2 Numbers : 12 25
OR Operation :29
AND Operation :8
XOR Operation :21
Complement Operation :-13

*/

/*
Time Complexity = O(1)
Space Complexity = O(1)
*/

