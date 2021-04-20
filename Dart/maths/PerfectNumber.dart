/*
Perfect number is a number which is equal to the sum of its divisors except the number itself
For example consider 6 
Divisors of 6 are 1, 2, 3
Sum of divisors = 1 + 2 + 3 = 6.
*/

import 'dart:io';

// Check if number is perfect or no
bool isPerfect(int number) {
  int sum = 0;

  for (int index = 1; index < number; index++) {
    // if number is a factor add it to sum
    if (number % index == 0) {
      sum += index;
    }
  }

  if (sum == number) {
    return true;
  }
  return false;
}

// Main Function, with driver code
void main() {
  print("Enter a number:");
  int input = int.parse(stdin.readLineSync()!);

  // Call isPerfect function on input
  if (isPerfect(input)) {
    print("$input is a perfect number");
  } else {
    print("$input is not a perfect number");
  }
}
/**
Time Complexity: O(n)
Space Complexity: O(1)

Sample input/output:
Enter a number:
6
6 is a perfect number

Enter a number:
12
12 is not a perfect number
*/

