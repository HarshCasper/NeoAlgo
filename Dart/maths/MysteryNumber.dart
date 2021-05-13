/*
A mystery number is that number which can be expressed as a sum of two 
numbers and those two numbers must be the reverse of each other
*/

import 'dart:io';

// Function to check if number is a Magic Number
bool isMysteryNumber(int number) {
  for (int count = 1; count < number / 2; count++) {
    if (count + rev(count) == number) {
      return true;
    }
  }
  return false;
}

// Function to reverse of a number
int rev(int number) {
  int temp = number;
  int reverse = 0;
  // Iterate through the number to reverse it
  while (temp != 0) {
    int rem = temp % 10;
    reverse = reverse * 10 + rem;
    temp = (temp / 10).floor();
  }
  return reverse;
}

// Main function with driver code
void main() {
  print("Enter a number :");
  int num = int.parse(stdin.readLineSync()!);

  // Call function to check if number is a Mystery number
  if (isMysteryNumber(num)) {
    print("$num is a Mystery Number");
  } else {
    print("$num is not a Mystery Number");
  }
}

/**
Space Complexity O(1)
Time Complexity  O(nlog(n))

Sample input/output:

Enter a number :
121
121 is a Mystery Number

Enter a number :
1234
1234 is not a Mystery Number
*/

