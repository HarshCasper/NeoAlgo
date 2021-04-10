//A palindromic number is a number that remains the same when its digits are reversed

import java.util.*

//Function to check Palindrome Number
fun isPalindrome(number: Int): Boolean {
	var isPalindromeNumber = false
	var sum = 0
	var tempNum = number

	while (tempNum > 0) {
		val r = tempNum % 10
		sum = sum * 10 + r
		tempNum /= 10
	}
	if (sum == number) {
		isPalindromeNumber = true
	}
	return isPalindromeNumber
}

//Main Function, Entry Point of Program
fun main(arg: Array<String>) {
	val sc = Scanner(System.`in`)

	//  Input Number
	println("Enter Number  : ")
	val num: Int = sc.nextInt()

	//Call Function to check Number
	if (isPalindrome(num)) 
		println("$num is a Palindrome Number") 
	else 
		println("$num is not a Palindrome Number")
}

/*Sample Test Case:
Enter Number  :
12321
12321 is a Palindrome Number
*/
