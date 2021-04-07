/*Bitwise and bit shift operators are used on only two integral types
(Int and Long) to perform bit-level operations.
*/

fun main(args: Array<String>) {

   println("Enter 2 Numbers: ")
    val number1 : Int = sc.nextInt();
    val number2 : Int = sc.nextInt();

    val result: Int

    result = number1 or number2                    // result = number1.or(number2)      
    println("OR Operation :$result")

    result = number1 and number2                  // result = number1.and(number2)
    println("AND Operation :$result")

    result = number1 xor number2                  // result = number1.xor(number2)
    println("XOR Operations :$result")

    result = number1.inv()                        //Bitwise complement
    println("Complement Operation :$result")
}

/*
Sample test case 
**************************************************************************
Enter 2 Numbers : 12 25
OR Operation :29
AND Operation :8
XOR Operation :21
Complement Operation :-36

*/

/*
Time Complexity = O(1)
Space Complexity = O(1)
*/

