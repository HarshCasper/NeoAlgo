/*

  Double factorial  of a number n (denoted by n!!) is the product
  of all the integers from 1 up to n that have the same parity(odd or even) as n

*/

import 'dart:io';

// Iterative approach
int Iterative(int num) {
  int ans = 1;
  for (int i = num; i >= 0; i = i - 2) {
    if (i == 0 || i == 1) {
      return ans;
    } else {
      ans *= i;
    }
  }
  return ans;
}


// Recursive approach
int Recursive(int num) {
  if (num == 0 || num == 1) {
    return 1;
  }
  return num * Recursive(num - 2);
}

int main() {
  //taking input from the user
  stdout.write("Enter a number: ");
  int num = int.parse(stdin.readLineSync()!);

  print("Select a method you want to use to find Double Factorial");
  print("1. Iterative");
  print("2. Recursive");
  stdout.write("choice ( 1 or 2 )? : ");
  int choice = int.parse(stdin.readLineSync()!);

  if (choice == 1) {
    stdout.write("Double Factorial of $num: ");
    print(Iterative(num));
  } else if (choice == 2) {
    stdout.write("Double Factorial of $num: ");
    print(Recursive(num));
  } else {
    print("Invalid choice");
  }
  print(" ");

  return 0;
}

/*

  Time complexity: O(n) 
  Space complexity: O(1)

  Sample input/output
 
  SAMPLE 1
  (Trying Iterative method)
  Enter a number: 32
  Select a method you want to use to find Double Factorial
  1. Iterative
  2. Recursive
  choice ( 1 or 2 )? : 1
  Double Factorial of 32: 1371195958099968000

  (Trying Recursive method)
  Enter a number: 32
  Select a method you want to use to find Double Factorial
  1. Iterative
  2. Recursive
  choice ( 1 or 2 )? : 2
  Double Factorial of 32: 1371195958099968000
  
  SAMPLE 2
  Enter a number: 10
  Select a method you want to use to find Double Factorial
  1. Iterative
  2. Recursive
  choice ( 1 or 2 )? : 1
  Double Factorial of 10: 3840

  Enter a number: 10
  Select a method you want to use to find Double Factorial
  1. Iterative
  2. Recursive
  choice ( 1 or 2 )? : 2
  Double Factorial of 10: 3840

 */
