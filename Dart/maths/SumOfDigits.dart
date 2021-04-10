import 'dart:io';

// Find sum of digits of number 
int sum_digits(int number) {
  int sum = 0;

  // Extract individual digits and add to sum
  while (number > 0) {
    int digit = number % 10;
    number ~/= 10;
    sum += digit;
  }
  return sum;
}

// Main Function, with driver code
void main() {
  print("Enter a number:");
  int input = int.parse(stdin.readLineSync()!);

  // Call sum of digits function
  int sum_of_digits = sum_digits(input);
  print("Sum of digits in $input is $sum_of_digits");
}
/**
Time Complexity: O(log(n))
Space Complexity: O(1)

Enter a number:
401
Sum of digits in 401 is 5

Enter a number:
123
Sum of digits in 123 is 6
*/
