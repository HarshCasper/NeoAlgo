/**
This function is a recursive function, which calls itself over and over
according to the number of digits in the number. Using that and adding each
digit raised to the power of the number of digits, it keeps adding them
and we get the sum we need to compare with the number input.
 */
import 'dart:io';
import 'dart:math';

// recursive function which add digits raised to the power of number of digits
int armstrong(int num, int len) {
  if(num < 10) {
    return pow(num, len).toInt();
  } else {
    return (pow(num % 10, len).toInt() + armstrong(num ~/ 10, len));
  }
}

// Main Function, Entry Point of Program
void main() {
  print("Enter a number:");
  int num = int.parse(stdin.readLineSync()!);
  int len = num.toString().length;

  // Call function to check number is Armstrong
  if (num == armstrong(num, len)) {
    print("$num is an Armstrong Number");
  } else {
    print("$num is not an Armstrong Number");
  }
}

/**
Sample Input and Output :
Enter a number:
153
153 is an Armstrong Number

Enter a number:
213
213 is not an Armstrong Number

Time complexity = O(n)
Space complexity = O(1)
 */
