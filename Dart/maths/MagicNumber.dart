/*
A magic number is a number that reduces to 1 after a sequential operation wherein each step we
replace the original number by the sum of its digits until the sum reaches a single digit.
*/

import 'dart:io';

// Function to check if number is a Magic Number
bool isMagicNumber(int num) {
  int sum = num;

  // iterate until sum is reduces to single digit
  while(sum > 9){
    int copy = sum;
    sum = 0;

    // calculating sum of all  digits
    while(copy > 0){
      int digit = copy % 10;
      sum += digit;
      copy ~/= 10;
    }
  }
  
  if(sum == 1){
    return true;
  }
  return false;
}

void main() {
  print("Enter a number :");
  int num = int.parse(stdin.readLineSync()!);

  // Call function to check if number is a Magic number
  if (isMagicNumber(num)) {
    print("$num is a Magic Number");
  } else {
    print("$num is not a Magic Number");
  }
}

/**
Space Complexity O(1)
Time Complexity  O(nlog(n))

Sample input/output:

Enter a number :
532
532 is a Magic Number

Enter a number :
123
123 is not a Magic Number
*/

