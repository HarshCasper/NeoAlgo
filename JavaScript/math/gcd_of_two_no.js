/*
A program to find Greatest Common Divisor(GCD) of two Numbers.
GCD of two integers is the largest positive integer that divides each of the integers.
*/

var number1 = 10;
var number2 = 15;

//Smaller of the two number
var smaller_number = Math.min(number1, number2);

//Iterating from smaller number till 1
for (var i = smaller_number; i >= 1; i--) {
  if (number1 % i == 0 && number2 % i == 0) {
    console.log("HCF: " + i);
    break;
  }
}

/*

Time Complexity:O(smaller(n1,n2))
Space Complexity:O(1)

Input:
5 10

Output:
5

Input:
4 7

Output:
1

*/
