import 'dart:io';

// Calculate factorial of number
int get_factorial(int number) {
  int count = 1;
  int factorial = 1;

  // Iterate from 1 till number
  while (count <= number) {
    factorial *= count;
    count++;
  }

  return factorial;
}

// Main Function, with driver code
void main() {
  print("Enter a number:");
  int input = int.parse(stdin.readLineSync()!);

  // Call factorial function
  int factorial = get_factorial(input);
  print("Factorial of $input is $factorial");
}
/**
 *  Sample input/output:
 * Enter a number:
 * 5
 * Factorial of 5 is 120
 * 
 * Enter a number:
 * 12
 * Factorial of 12 is 479001600
 */
