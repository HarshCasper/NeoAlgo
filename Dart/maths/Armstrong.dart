import 'dart:math';
import 'dart:io';

// checks if num is armstrong or not
bool isArmstrong(int num) {
  bool isArmNum = false;
  int result = 0;
  int temp = num;

  // Count No Digits in numbers
  int numberOfDigits = temp.toString().length;

  while (temp > 0) {
    int remainder = temp % 10;
    result += pow(remainder, numberOfDigits).toInt();
    temp ~/= 10;
  }

  if (result == num) {
  isArmNum = true;
  }
  return isArmNum;
}

// Main Function, Entry Point of Program
void main() {
  print("Enter a number:");
  int num = int.parse(stdin.readLineSync()!);

  // Call function to check number is Armstrong
  if (isArmstrong(num)) {
    print("$num is an Armstrong Number");
  } else {
    print("$num is not an Armstrong Number");
  }
}
/**
 * Sample input/output:
 * Enter Number: 
 * 153
 * 153 is an Armstrong Number
 * 
 * Enter Number: 
 * 224
 * 224 is not an Armstrong Number
 */
