/*
A number is said to be a Harshad Number if it is divisible by the sum of its digits.
For example: The number 84 is divisible by the sum (12) of its digits (8, 4).
*/

import 'dart:io';

// Check if a number is a Harshad number
bool isHarshad(int number) {
  int sum = 0;
  int copy = number;

  // Seperate individual digits and add to sum
  while (number > 0) {
    int digit = number % 10;
    number ~/= 10;
    sum += digit;
  }

  // Check if number is divisible by sum
  if (copy % sum == 0) {
    return true;
  }
  return false;
}

// Main Function, with driver code
void main() {
  print("Enter a number:");
  int input = int.parse(stdin.readLineSync()!);

  // Call isHarshad function
  if (isHarshad(input)) {
    print("$input is a Harshad Number");
  } else {
    print("$input is not a Harshad Number");
  }
}
/**
Time Complexity: O(log(n))
Space Complexity: O(1)

Sample Input/Output
Enter a number:
18
18 is a Harshad Number

Enter a number:
123
Sum of digits in 123 is 6
*/

