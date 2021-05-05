/*

 * Dart program to check if a number is a palindrome or not

 * A palindromic number is a number that remains the same when its digits are reversed.

 */

import 'dart:io';

int isPallindrome(int num) {
  int temp = num;
  int rev = 0;
  /*First reverse the number and then compare it with the given number to check pallindrome*/
  while (temp != 0) {
    int rem = temp % 10;
    rev = rev * 10 + rem;
    temp = (temp / 10).floor();
  }

  if (rev == num) {
    print("The given number is a palindrome number");
  } else {
    print("The given number is not a palindrome number");
  }

  return 0;
}

int main() {
  stdout.write("Enter the number:  ");
  int num = int.parse(stdin.readLineSync()!);

  isPallindrome(num);

  return 0;
}

/*

Time Complexity: O(log(n)), where 'n' is the given number
Space Complexity: O(1)

SAMPLE INPUT AND OUTPUT

SAMPLE 1

Enter the number:  24324
The given number is not a palindrome number

SAMPLE 2

Enter the number:  73137
The given number is a palindrome number

*/
