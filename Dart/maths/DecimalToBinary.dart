/*
Conversion of a decimal number to binary form can be achieved by continously dividing the number
number by 2 until the quotient becomes zero. The remained obtained in each step is combined to form
give the resultant binary form of the number
*/

import 'dart:io';

// Function to return binary conversion of number
int toBinary(int num) {
  int binary = 0;
  int index = 1;

  // Iterate till all divisions complete
  while (num > 0) {
    binary = binary + ( num % 2 * index);
    num ~/= 2;
    index *= 10;
  }
  return binary;
}

// Main Function with driver code
void main() {
  print("Enter a number :");
  int num = int.parse(stdin.readLineSync()!);

  // Call binary conversion function
  int binary = toBinary(num);
  print("Binary conversion of $num is $binary");  
}

/**
Space Complexity O(1)
Time Complexity  O(n)

Sample input/output:
Enter a number :
13
Binary conversion of 13 is 1101

Enter a number :
25
Binary conversion of 25 is 11001
*/

