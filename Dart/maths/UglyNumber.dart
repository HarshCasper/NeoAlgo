/*
Ugly numbers are numbers whose only prime factors are 2, 3 or 5. 
For example consider 12
Factorisation of 12 is 12 = 2 x 2 x 3 
As 2 and 3 are its only prime factors it is a ugly number.
*/

import 'dart:io';

// Check if number is ugly number or no
int checkUglyNumber(int number) {
  // Base case for true
  if (number == 1) {
    return 1;
  }
  // Base cases for false
  if (number <= 0) {
    return 0;
  }

  // Recursive cases to check divisibility
  if (number % 2 == 0) {
    return (checkUglyNumber(number ~/ 2));
  }
  if (number % 3 == 0) {
    return (checkUglyNumber(number ~/ 3));
  }
  if (number % 5 == 0) {
    return (checkUglyNumber(number ~/ 5));
  }

  // No case matched then return 0
  return 0;
}

// Main Function, with driver code
void main() {
  print("Enter a number:");
  int input = int.parse(stdin.readLineSync()!);

  // Call checkUglyNumber function on input
  if (checkUglyNumber(input) == 1) {
    print("$input is a ugly number");
  } else {
    print("$input is not a ugly number");
  }
}
/**
Time Complexity: O(n)
Space Complexity: O(1)

Sample input/output:
Enter a number:
15
15 is a ugly number

Enter a number:
11
11 is not a ugly number
*/

