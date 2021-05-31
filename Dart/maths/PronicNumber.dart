/*
A pronic number is a number which is the product of two consecutive integers.
Such as 2=2*1 or 12=4*3
*/

import 'dart:io';
import 'dart:math';

// Check if number is pronic or no
bool isPronic(int number) {
  int sqt = sqrt(number).toInt();

  for (int index = 1; index <= sqt; index++) {
    // Check multiplication of contious numbers
    if (index * (index + 1) == number) {
      return true;
    }
  }

  return false;
}

// Main Function, with driver code
void main() {
  print("Enter a number:");
  int input = int.parse(stdin.readLineSync()!);

  // Call isPronic function on input
  if (isPronic(input)) {
    print("$input is a pronic number");
  } else {
    print("$input is not a pronic number");
  }
}

/**
Time Complexity: O(sqt(n))
Space Complexity: O(1)

Sample input/output:
Enter a number:
12
12 is a pronic number

Enter a number:
32
32 is not a pronic number
*/

