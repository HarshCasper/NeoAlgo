/*
A number is said to be a neon number when the sum of digits of the square of the number
is equal to the number itself
*/
import 'dart:io';

// Function to check if number is a neon number
bool isNeon(int num) {
  int sum = 0;
  int square = num*num;

  while (square > 0) {
    int digit = square % 10;
    sum += digit;
    square ~/= 10;
  }
  if (sum == num) {
    return true;
  }
  return false;
}

// Main Function with driver code
void main() {
  print("Enter a number :");
  int num = int.parse(stdin.readLineSync()!);

  // Call function to check if number is a neon number
  if (isNeon(num)) {
    print("$num is a Neon Number");
  } else {
    print("$num is not a Neon Number");
  }
}

/**
Space Complexity O(1)
Time Complexity  O(log(n))

Sample input/output:
Enter a number :
9
9 is a Neon Number

Enter a number :
12
12 is not a Neon Number
*/
